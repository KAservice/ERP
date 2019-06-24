#include "vcl.h"
#pragma hdrstop


#include "UDMDocInvImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMDocInvImpl::TDMDocInvImpl()           
{                                            
Object=new TDMDocInv(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMDocInvImpl::~TDMDocInvImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMDocInvImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMDocInvImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMDocInv)                        
   {                                                                     
   *ppv=static_cast<IDMDocInv*> (this);                                
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
int TDMDocInvImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMDocInvImpl::kanRelease(void)                                  
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
int  TDMDocInvImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMDocInvImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMDocInvImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMDocInvImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMDocInvImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMDocInvImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMDocInvImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMDocInv
TDataSource * TDMDocInvImpl::get_DataSourceDoc(void)
{
return Object->DataSourceDoc;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_DataSourceDoc(TDataSource * DataSourceDoc)
{
Object->DataSourceDoc=DataSourceDoc;
}
//---------------------------------------------------------------
TDataSource * TDMDocInvImpl::get_DataSourceDocT(void)
{
return Object->DataSourceDocT;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_DataSourceDocT(TDataSource * DataSourceDocT)
{
Object->DataSourceDocT=DataSourceDocT;
}
//---------------------------------------------------------------
TDataSource * TDMDocInvImpl::get_DataSourceDocAll(void)
{
return Object->DataSourceDocAll;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_DataSourceDocAll(TDataSource * DataSourceDocAll)
{
Object->DataSourceDocAll=DataSourceDocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocInvImpl::get_DocAll(void)
{
return Object->DocAll;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_DocAll(TpFIBDataSet * DocAll)
{
Object->DocAll=DocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocInvImpl::get_Doc(void)
{
return Object->Doc;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_Doc(TpFIBDataSet * Doc)
{
Object->Doc=Doc;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocInvImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocInvImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocInvImpl::get_DocT(void)
{
return Object->DocT;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_DocT(TpFIBDataSet * DocT)
{
Object->DocT=DocT;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocInvImpl::get_IBTrDvReg(void)
{
return Object->IBTrDvReg;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_IBTrDvReg(TpFIBTransaction * IBTrDvReg)
{
Object->IBTrDvReg=IBTrDvReg;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocInvImpl::get_NumDoc(void)
{
return Object->NumDoc;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_NumDoc(TpFIBDataSet * NumDoc)
{
Object->NumDoc=NumDoc;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocInvImpl::get_IBQPoGrp(void)
{
return Object->IBQPoGrp;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_IBQPoGrp(TpFIBDataSet * IBQPoGrp)
{
Object->IBQPoGrp=IBQPoGrp;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocInvImpl::get_IBQPoGrpTNOM(void)
{
return Object->IBQPoGrpTNOM;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_IBQPoGrpTNOM(TFIBIntegerField * IBQPoGrpTNOM)
{
Object->IBQPoGrpTNOM=IBQPoGrpTNOM;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocInvImpl::get_IBQPoGrpCODENOM(void)
{
return Object->IBQPoGrpCODENOM;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_IBQPoGrpCODENOM(TFIBIntegerField * IBQPoGrpCODENOM)
{
Object->IBQPoGrpCODENOM=IBQPoGrpCODENOM;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocInvImpl::get_IBQPoGrpKF_INVT(void)
{
return Object->IBQPoGrpKF_INVT;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_IBQPoGrpKF_INVT(TFIBBCDField * IBQPoGrpKF_INVT)
{
Object->IBQPoGrpKF_INVT=IBQPoGrpKF_INVT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocInvImpl::get_IBQPoGrpKOLUCH_INVT(void)
{
return Object->IBQPoGrpKOLUCH_INVT;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_IBQPoGrpKOLUCH_INVT(TFIBBCDField * IBQPoGrpKOLUCH_INVT)
{
Object->IBQPoGrpKOLUCH_INVT=IBQPoGrpKOLUCH_INVT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocInvImpl::get_IBQPoGrpKOLFAKT_INVT(void)
{
return Object->IBQPoGrpKOLFAKT_INVT;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_IBQPoGrpKOLFAKT_INVT(TFIBBCDField * IBQPoGrpKOLFAKT_INVT)
{
Object->IBQPoGrpKOLFAKT_INVT=IBQPoGrpKOLFAKT_INVT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocInvImpl::get_IBQPoGrpPRICE_INVT(void)
{
return Object->IBQPoGrpPRICE_INVT;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_IBQPoGrpPRICE_INVT(TFIBBCDField * IBQPoGrpPRICE_INVT)
{
Object->IBQPoGrpPRICE_INVT=IBQPoGrpPRICE_INVT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocInvImpl::get_IBQPoGrpSUMF_INVT(void)
{
return Object->IBQPoGrpSUMF_INVT;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_IBQPoGrpSUMF_INVT(TFIBBCDField * IBQPoGrpSUMF_INVT)
{
Object->IBQPoGrpSUMF_INVT=IBQPoGrpSUMF_INVT;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocInvImpl::get_IBQ(void)
{
return Object->IBQ;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_IBQ(TpFIBDataSet * IBQ)
{
Object->IBQ=IBQ;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocInvImpl::get_GoodsDataSet(void)
{
return Object->GoodsDataSet;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_GoodsDataSet(TpFIBDataSet * GoodsDataSet)
{
Object->GoodsDataSet=GoodsDataSet;
}
//---------------------------------------------------------------
TFIBFloatField * TDMDocInvImpl::get_GoodsDataSetSUMKOL(void)
{
return Object->GoodsDataSetSUMKOL;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_GoodsDataSetSUMKOL(TFIBFloatField * GoodsDataSetSUMKOL)
{
Object->GoodsDataSetSUMKOL=GoodsDataSetSUMKOL;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocInvImpl::get_GoodsDataSetRSUM(void)
{
return Object->GoodsDataSetRSUM;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_GoodsDataSetRSUM(TFIBBCDField * GoodsDataSetRSUM)
{
Object->GoodsDataSetRSUM=GoodsDataSetRSUM;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocInvImpl::get_GoodsDataSetCODENOM(void)
{
return Object->GoodsDataSetCODENOM;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_GoodsDataSetCODENOM(TFIBIntegerField * GoodsDataSetCODENOM)
{
Object->GoodsDataSetCODENOM=GoodsDataSetCODENOM;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocInvImpl::get_OstatkiDataSet(void)
{
return Object->OstatkiDataSet;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_OstatkiDataSet(TpFIBDataSet * OstatkiDataSet)
{
Object->OstatkiDataSet=OstatkiDataSet;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocInvImpl::get_OstatkiDataSetCODENOM(void)
{
return Object->OstatkiDataSetCODENOM;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_OstatkiDataSetCODENOM(TFIBIntegerField * OstatkiDataSetCODENOM)
{
Object->OstatkiDataSetCODENOM=OstatkiDataSetCODENOM;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocInvImpl::get_OstatkiDataSetKFED(void)
{
return Object->OstatkiDataSetKFED;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_OstatkiDataSetKFED(TFIBBCDField * OstatkiDataSetKFED)
{
Object->OstatkiDataSetKFED=OstatkiDataSetKFED;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocInvImpl::get_OstatkiDataSetSUMKOL(void)
{
return Object->OstatkiDataSetSUMKOL;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_OstatkiDataSetSUMKOL(TFIBBCDField * OstatkiDataSetSUMKOL)
{
Object->OstatkiDataSetSUMKOL=OstatkiDataSetSUMKOL;
}
//---------------------------------------------------------------
TpFIBQuery * TDMDocInvImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocInvImpl::get_DocTCODENOM(void)
{
return Object->DocTCODENOM;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_DocTCODENOM(TFIBIntegerField * DocTCODENOM)
{
Object->DocTCODENOM=DocTCODENOM;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocInvImpl::get_DocTKF_INVT(void)
{
return Object->DocTKF_INVT;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_DocTKF_INVT(TFIBBCDField * DocTKF_INVT)
{
Object->DocTKF_INVT=DocTKF_INVT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocInvImpl::get_DocTKOLUCH_INVT(void)
{
return Object->DocTKOLUCH_INVT;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_DocTKOLUCH_INVT(TFIBBCDField * DocTKOLUCH_INVT)
{
Object->DocTKOLUCH_INVT=DocTKOLUCH_INVT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocInvImpl::get_DocTKOLFAKT_INVT(void)
{
return Object->DocTKOLFAKT_INVT;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_DocTKOLFAKT_INVT(TFIBBCDField * DocTKOLFAKT_INVT)
{
Object->DocTKOLFAKT_INVT=DocTKOLFAKT_INVT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocInvImpl::get_DocTPRICE_INVT(void)
{
return Object->DocTPRICE_INVT;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_DocTPRICE_INVT(TFIBBCDField * DocTPRICE_INVT)
{
Object->DocTPRICE_INVT=DocTPRICE_INVT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocInvImpl::get_DocTSUMF_INVT(void)
{
return Object->DocTSUMF_INVT;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_DocTSUMF_INVT(TFIBBCDField * DocTSUMF_INVT)
{
Object->DocTSUMF_INVT=DocTSUMF_INVT;
}
//---------------------------------------------------------------
TIntegerField * TDMDocInvImpl::get_DocTRECNO(void)
{
return Object->DocTRECNO;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_DocTRECNO(TIntegerField * DocTRECNO)
{
Object->DocTRECNO=DocTRECNO;
}
//---------------------------------------------------------------
TpFIBQuery * TDMDocInvImpl::get_QueryCancelDvReg(void)
{
return Object->QueryCancelDvReg;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg)
{
Object->QueryCancelDvReg=QueryCancelDvReg;
}
//---------------------------------------------------------------
TpFIBQuery * TDMDocInvImpl::get_QueryDvReg(void)
{
return Object->QueryDvReg;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_QueryDvReg(TpFIBQuery * QueryDvReg)
{
Object->QueryDvReg=QueryDvReg;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocInvImpl::get_GoodsDataSetIDNOM_DREVT(void)
{
return Object->GoodsDataSetIDNOM_DREVT;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_GoodsDataSetIDNOM_DREVT(TFIBBCDField * GoodsDataSetIDNOM_DREVT)
{
Object->GoodsDataSetIDNOM_DREVT=GoodsDataSetIDNOM_DREVT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocInvImpl::get_GoodsDataSetIDED_DREVT(void)
{
return Object->GoodsDataSetIDED_DREVT;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_GoodsDataSetIDED_DREVT(TFIBBCDField * GoodsDataSetIDED_DREVT)
{
Object->GoodsDataSetIDED_DREVT=GoodsDataSetIDED_DREVT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocInvImpl::get_OstatkiDataSetIDNOM(void)
{
return Object->OstatkiDataSetIDNOM;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_OstatkiDataSetIDNOM(TFIBBCDField * OstatkiDataSetIDNOM)
{
Object->OstatkiDataSetIDNOM=OstatkiDataSetIDNOM;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocInvImpl::get_OstatkiDataSetIDED(void)
{
return Object->OstatkiDataSetIDED;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_OstatkiDataSetIDED(TFIBBCDField * OstatkiDataSetIDED)
{
Object->OstatkiDataSetIDED=OstatkiDataSetIDED;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocInvImpl::get_IBQPoGrpIDGN(void)
{
return Object->IBQPoGrpIDGN;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_IBQPoGrpIDGN(TFIBBCDField * IBQPoGrpIDGN)
{
Object->IBQPoGrpIDGN=IBQPoGrpIDGN;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocInvImpl::get_IBQPoGrpID_INVT(void)
{
return Object->IBQPoGrpID_INVT;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_IBQPoGrpID_INVT(TFIBBCDField * IBQPoGrpID_INVT)
{
Object->IBQPoGrpID_INVT=IBQPoGrpID_INVT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocInvImpl::get_IBQPoGrpIDDOC_INVT(void)
{
return Object->IBQPoGrpIDDOC_INVT;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_IBQPoGrpIDDOC_INVT(TFIBBCDField * IBQPoGrpIDDOC_INVT)
{
Object->IBQPoGrpIDDOC_INVT=IBQPoGrpIDDOC_INVT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocInvImpl::get_IBQPoGrpIDNOM_INVT(void)
{
return Object->IBQPoGrpIDNOM_INVT;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_IBQPoGrpIDNOM_INVT(TFIBBCDField * IBQPoGrpIDNOM_INVT)
{
Object->IBQPoGrpIDNOM_INVT=IBQPoGrpIDNOM_INVT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocInvImpl::get_IBQPoGrpIDED_INVT(void)
{
return Object->IBQPoGrpIDED_INVT;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_IBQPoGrpIDED_INVT(TFIBBCDField * IBQPoGrpIDED_INVT)
{
Object->IBQPoGrpIDED_INVT=IBQPoGrpIDED_INVT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocInvImpl::get_DocAllIDDOC(void)
{
return Object->DocAllIDDOC;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_DocAllIDDOC(TFIBLargeIntField * DocAllIDDOC)
{
Object->DocAllIDDOC=DocAllIDDOC;
}
//---------------------------------------------------------------
TFIBDateTimeField * TDMDocInvImpl::get_DocAllPOSDOC(void)
{
return Object->DocAllPOSDOC;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_DocAllPOSDOC(TFIBDateTimeField * DocAllPOSDOC)
{
Object->DocAllPOSDOC=DocAllPOSDOC;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMDocInvImpl::get_DocAllPRDOC(void)
{
return Object->DocAllPRDOC;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_DocAllPRDOC(TFIBSmallIntField * DocAllPRDOC)
{
Object->DocAllPRDOC=DocAllPRDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocInvImpl::get_DocAllTDOC(void)
{
return Object->DocAllTDOC;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_DocAllTDOC(TFIBWideStringField * DocAllTDOC)
{
Object->DocAllTDOC=DocAllTDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocInvImpl::get_DocAllNUMDOC(void)
{
return Object->DocAllNUMDOC;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_DocAllNUMDOC(TFIBIntegerField * DocAllNUMDOC)
{
Object->DocAllNUMDOC=DocAllNUMDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocInvImpl::get_DocAllIDFIRMDOC(void)
{
return Object->DocAllIDFIRMDOC;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_DocAllIDFIRMDOC(TFIBLargeIntField * DocAllIDFIRMDOC)
{
Object->DocAllIDFIRMDOC=DocAllIDFIRMDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocInvImpl::get_DocAllIDSKLDOC(void)
{
return Object->DocAllIDSKLDOC;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_DocAllIDSKLDOC(TFIBLargeIntField * DocAllIDSKLDOC)
{
Object->DocAllIDSKLDOC=DocAllIDSKLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocInvImpl::get_DocAllIDKLDOC(void)
{
return Object->DocAllIDKLDOC;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_DocAllIDKLDOC(TFIBLargeIntField * DocAllIDKLDOC)
{
Object->DocAllIDKLDOC=DocAllIDKLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocInvImpl::get_DocAllIDDOGDOC(void)
{
return Object->DocAllIDDOGDOC;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_DocAllIDDOGDOC(TFIBLargeIntField * DocAllIDDOGDOC)
{
Object->DocAllIDDOGDOC=DocAllIDDOGDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocInvImpl::get_DocAllSUMDOC(void)
{
return Object->DocAllSUMDOC;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_DocAllSUMDOC(TFIBBCDField * DocAllSUMDOC)
{
Object->DocAllSUMDOC=DocAllSUMDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocInvImpl::get_DocAllIDUSERDOC(void)
{
return Object->DocAllIDUSERDOC;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_DocAllIDUSERDOC(TFIBLargeIntField * DocAllIDUSERDOC)
{
Object->DocAllIDUSERDOC=DocAllIDUSERDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocInvImpl::get_DocAllGID_DOC(void)
{
return Object->DocAllGID_DOC;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_DocAllGID_DOC(TFIBWideStringField * DocAllGID_DOC)
{
Object->DocAllGID_DOC=DocAllGID_DOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocInvImpl::get_DocAllPREFIKSDOC(void)
{
return Object->DocAllPREFIKSDOC;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_DocAllPREFIKSDOC(TFIBWideStringField * DocAllPREFIKSDOC)
{
Object->DocAllPREFIKSDOC=DocAllPREFIKSDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocInvImpl::get_DocAllIDDOCOSNDOC(void)
{
return Object->DocAllIDDOCOSNDOC;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_DocAllIDDOCOSNDOC(TFIBLargeIntField * DocAllIDDOCOSNDOC)
{
Object->DocAllIDDOCOSNDOC=DocAllIDDOCOSNDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocInvImpl::get_DocAllIDEXTDOC(void)
{
return Object->DocAllIDEXTDOC;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_DocAllIDEXTDOC(TFIBLargeIntField * DocAllIDEXTDOC)
{
Object->DocAllIDEXTDOC=DocAllIDEXTDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocInvImpl::get_DocAllTYPEEXTDOC(void)
{
return Object->DocAllTYPEEXTDOC;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_DocAllTYPEEXTDOC(TFIBIntegerField * DocAllTYPEEXTDOC)
{
Object->DocAllTYPEEXTDOC=DocAllTYPEEXTDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocInvImpl::get_DocAllIDBASE_GALLDOC(void)
{
return Object->DocAllIDBASE_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_DocAllIDBASE_GALLDOC(TFIBLargeIntField * DocAllIDBASE_GALLDOC)
{
Object->DocAllIDBASE_GALLDOC=DocAllIDBASE_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocInvImpl::get_DocAllIDPROJECT_GALLDOC(void)
{
return Object->DocAllIDPROJECT_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_DocAllIDPROJECT_GALLDOC(TFIBLargeIntField * DocAllIDPROJECT_GALLDOC)
{
Object->DocAllIDPROJECT_GALLDOC=DocAllIDPROJECT_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocInvImpl::get_DocAllFNAME_USER(void)
{
return Object->DocAllFNAME_USER;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_DocAllFNAME_USER(TFIBWideStringField * DocAllFNAME_USER)
{
Object->DocAllFNAME_USER=DocAllFNAME_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocInvImpl::get_DocAllNAME_SINFBASE_OBMEN(void)
{
return Object->DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN)
{
Object->DocAllNAME_SINFBASE_OBMEN=DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocInvImpl::get_DocAllNAMEFIRM(void)
{
return Object->DocAllNAMEFIRM;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_DocAllNAMEFIRM(TFIBWideStringField * DocAllNAMEFIRM)
{
Object->DocAllNAMEFIRM=DocAllNAMEFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocInvImpl::get_DocAllNAMESKLAD(void)
{
return Object->DocAllNAMESKLAD;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_DocAllNAMESKLAD(TFIBWideStringField * DocAllNAMESKLAD)
{
Object->DocAllNAMESKLAD=DocAllNAMESKLAD;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocInvImpl::get_DocID_INV(void)
{
return Object->DocID_INV;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_DocID_INV(TFIBLargeIntField * DocID_INV)
{
Object->DocID_INV=DocID_INV;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocInvImpl::get_DocIDDOC_INV(void)
{
return Object->DocIDDOC_INV;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_DocIDDOC_INV(TFIBLargeIntField * DocIDDOC_INV)
{
Object->DocIDDOC_INV=DocIDDOC_INV;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocInvImpl::get_DocPRIM_INV(void)
{
return Object->DocPRIM_INV;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_DocPRIM_INV(TFIBWideStringField * DocPRIM_INV)
{
Object->DocPRIM_INV=DocPRIM_INV;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocInvImpl::get_DocGID_INV(void)
{
return Object->DocGID_INV;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_DocGID_INV(TFIBWideStringField * DocGID_INV)
{
Object->DocGID_INV=DocGID_INV;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocInvImpl::get_DocIDTPRICE_INV(void)
{
return Object->DocIDTPRICE_INV;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_DocIDTPRICE_INV(TFIBLargeIntField * DocIDTPRICE_INV)
{
Object->DocIDTPRICE_INV=DocIDTPRICE_INV;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocInvImpl::get_DocIDINV_INV(void)
{
return Object->DocIDINV_INV;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_DocIDINV_INV(TFIBLargeIntField * DocIDINV_INV)
{
Object->DocIDINV_INV=DocIDINV_INV;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocInvImpl::get_DocTYPE_INV(void)
{
return Object->DocTYPE_INV;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_DocTYPE_INV(TFIBIntegerField * DocTYPE_INV)
{
Object->DocTYPE_INV=DocTYPE_INV;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocInvImpl::get_DocIDBASE_DINV(void)
{
return Object->DocIDBASE_DINV;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_DocIDBASE_DINV(TFIBLargeIntField * DocIDBASE_DINV)
{
Object->DocIDBASE_DINV=DocIDBASE_DINV;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocInvImpl::get_DocNAME_SINV(void)
{
return Object->DocNAME_SINV;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_DocNAME_SINV(TFIBWideStringField * DocNAME_SINV)
{
Object->DocNAME_SINV=DocNAME_SINV;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocInvImpl::get_DocTNAMEGN(void)
{
return Object->DocTNAMEGN;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_DocTNAMEGN(TFIBWideStringField * DocTNAMEGN)
{
Object->DocTNAMEGN=DocTNAMEGN;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocInvImpl::get_DocTIDGN(void)
{
return Object->DocTIDGN;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_DocTIDGN(TFIBLargeIntField * DocTIDGN)
{
Object->DocTIDGN=DocTIDGN;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocInvImpl::get_DocTNAMENOM(void)
{
return Object->DocTNAMENOM;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_DocTNAMENOM(TFIBWideStringField * DocTNAMENOM)
{
Object->DocTNAMENOM=DocTNAMENOM;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocInvImpl::get_DocTTNOM(void)
{
return Object->DocTTNOM;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_DocTTNOM(TFIBIntegerField * DocTTNOM)
{
Object->DocTTNOM=DocTTNOM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocInvImpl::get_DocTID_INVT(void)
{
return Object->DocTID_INVT;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_DocTID_INVT(TFIBLargeIntField * DocTID_INVT)
{
Object->DocTID_INVT=DocTID_INVT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocInvImpl::get_DocTIDDOC_INVT(void)
{
return Object->DocTIDDOC_INVT;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_DocTIDDOC_INVT(TFIBLargeIntField * DocTIDDOC_INVT)
{
Object->DocTIDDOC_INVT=DocTIDDOC_INVT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocInvImpl::get_DocTIDNOM_INVT(void)
{
return Object->DocTIDNOM_INVT;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_DocTIDNOM_INVT(TFIBLargeIntField * DocTIDNOM_INVT)
{
Object->DocTIDNOM_INVT=DocTIDNOM_INVT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocInvImpl::get_DocTIDED_INVT(void)
{
return Object->DocTIDED_INVT;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_DocTIDED_INVT(TFIBLargeIntField * DocTIDED_INVT)
{
Object->DocTIDED_INVT=DocTIDED_INVT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocInvImpl::get_DocTGID_INVT(void)
{
return Object->DocTGID_INVT;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_DocTGID_INVT(TFIBWideStringField * DocTGID_INVT)
{
Object->DocTGID_INVT=DocTGID_INVT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocInvImpl::get_DocTIDBASE_DINVT(void)
{
return Object->DocTIDBASE_DINVT;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_DocTIDBASE_DINVT(TFIBLargeIntField * DocTIDBASE_DINVT)
{
Object->DocTIDBASE_DINVT=DocTIDBASE_DINVT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocInvImpl::get_DocTNAMEED(void)
{
return Object->DocTNAMEED;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_DocTNAMEED(TFIBWideStringField * DocTNAMEED)
{
Object->DocTNAMEED=DocTNAMEED;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocInvImpl::get_DocAllFNAMEFIRM(void)
{
return Object->DocAllFNAMEFIRM;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_DocAllFNAMEFIRM(TFIBWideStringField * DocAllFNAMEFIRM)
{
Object->DocAllFNAMEFIRM=DocAllFNAMEFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocInvImpl::get_DocAllINNFIRM(void)
{
return Object->DocAllINNFIRM;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_DocAllINNFIRM(TFIBWideStringField * DocAllINNFIRM)
{
Object->DocAllINNFIRM=DocAllINNFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocInvImpl::get_DocAllPADRFIRM(void)
{
return Object->DocAllPADRFIRM;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_DocAllPADRFIRM(TFIBWideStringField * DocAllPADRFIRM)
{
Object->DocAllPADRFIRM=DocAllPADRFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocInvImpl::get_IBQPoGrpNAMEGN(void)
{
return Object->IBQPoGrpNAMEGN;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_IBQPoGrpNAMEGN(TFIBWideStringField * IBQPoGrpNAMEGN)
{
Object->IBQPoGrpNAMEGN=IBQPoGrpNAMEGN;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocInvImpl::get_IBQPoGrpNAMENOM(void)
{
return Object->IBQPoGrpNAMENOM;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_IBQPoGrpNAMENOM(TFIBWideStringField * IBQPoGrpNAMENOM)
{
Object->IBQPoGrpNAMENOM=IBQPoGrpNAMENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocInvImpl::get_IBQPoGrpNAMEED(void)
{
return Object->IBQPoGrpNAMEED;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_IBQPoGrpNAMEED(TFIBWideStringField * IBQPoGrpNAMEED)
{
Object->IBQPoGrpNAMEED=IBQPoGrpNAMEED;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocInvImpl::get_GoodsDataSetNAMENOM(void)
{
return Object->GoodsDataSetNAMENOM;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_GoodsDataSetNAMENOM(TFIBWideStringField * GoodsDataSetNAMENOM)
{
Object->GoodsDataSetNAMENOM=GoodsDataSetNAMENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocInvImpl::get_GoodsDataSetNAMEED(void)
{
return Object->GoodsDataSetNAMEED;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_GoodsDataSetNAMEED(TFIBWideStringField * GoodsDataSetNAMEED)
{
Object->GoodsDataSetNAMEED=GoodsDataSetNAMEED;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocInvImpl::get_OstatkiDataSetNAMENOM(void)
{
return Object->OstatkiDataSetNAMENOM;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_OstatkiDataSetNAMENOM(TFIBWideStringField * OstatkiDataSetNAMENOM)
{
Object->OstatkiDataSetNAMENOM=OstatkiDataSetNAMENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocInvImpl::get_OstatkiDataSetNAMEED(void)
{
return Object->OstatkiDataSetNAMEED;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_OstatkiDataSetNAMEED(TFIBWideStringField * OstatkiDataSetNAMEED)
{
Object->OstatkiDataSetNAMEED=OstatkiDataSetNAMEED;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocInvImpl::get_DocAllIDBUSINOP_GALLDOC(void)
{
return Object->DocAllIDBUSINOP_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_DocAllIDBUSINOP_GALLDOC(TFIBLargeIntField * DocAllIDBUSINOP_GALLDOC)
{
Object->DocAllIDBUSINOP_GALLDOC=DocAllIDBUSINOP_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocInvImpl::get_DocAllNAME_SPROJECT(void)
{
return Object->DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_DocAllNAME_SPROJECT(TFIBWideStringField * DocAllNAME_SPROJECT)
{
Object->DocAllNAME_SPROJECT=DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocInvImpl::get_DocAllNAME_SBUSINESS_OPER(void)
{
return Object->DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_DocAllNAME_SBUSINESS_OPER(TFIBWideStringField * DocAllNAME_SBUSINESS_OPER)
{
Object->DocAllNAME_SBUSINESS_OPER=DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocInvImpl::get_DocAllPREFIKS_NUM_GALLDOC(void)
{
return Object->DocAllPREFIKS_NUM_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_DocAllPREFIKS_NUM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_GALLDOC)
{
Object->DocAllPREFIKS_NUM_GALLDOC=DocAllPREFIKS_NUM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocInvImpl::get_DocTARTNOM(void)
{
return Object->DocTARTNOM;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_DocTARTNOM(TFIBWideStringField * DocTARTNOM)
{
Object->DocTARTNOM=DocTARTNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocInvImpl::get_DocTSHED(void)
{
return Object->DocTSHED;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_DocTSHED(TFIBWideStringField * DocTSHED)
{
Object->DocTSHED=DocTSHED;
}
//---------------------------------------------------------------
bool TDMDocInvImpl::get_NewElement(void)
{
return Object->NewElement;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_NewElement(bool NewElement)
{
Object->NewElement=NewElement;
}
//---------------------------------------------------------------
bool TDMDocInvImpl::get_Prosmotr(void)
{
return Object->Prosmotr;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_Prosmotr(bool Prosmotr)
{
Object->Prosmotr=Prosmotr;
}
//---------------------------------------------------------------
bool TDMDocInvImpl::get_NoEdit(void)
{
return Object->NoEdit;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_NoEdit(bool NoEdit)
{
Object->NoEdit=NoEdit;
}
//---------------------------------------------------------------
__int64 TDMDocInvImpl::get_IdDoc(void)
{
return Object->IdDoc;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_IdDoc(__int64 IdDoc)
{
Object->IdDoc=IdDoc;
}
//---------------------------------------------------------------
__int64 TDMDocInvImpl::get_IdGrp(void)
{
return Object->IdGrp;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_IdGrp(__int64 IdGrp)
{
Object->IdGrp=IdGrp;
}
//---------------------------------------------------------------
__int64 TDMDocInvImpl::get_IdElementaMaster(void)
{
return Object->IdElementaMaster;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_IdElementaMaster(__int64 IdElementaMaster)
{
Object->IdElementaMaster=IdElementaMaster;
}
//---------------------------------------------------------------
__int64 TDMDocInvImpl::get_IdGrpNom(void)
{
return Object->IdGrpNom;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_IdGrpNom(__int64 IdGrpNom)
{
Object->IdGrpNom=IdGrpNom;
}
//---------------------------------------------------------------
bool TDMDocInvImpl::get_ChangeTable(void)
{
return Object->ChangeTable;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_ChangeTable(bool ChangeTable)
{
Object->ChangeTable=ChangeTable;
}
//---------------------------------------------------------------
bool TDMDocInvImpl::get_ErrorRaschet(void)
{
return Object->ErrorRaschet;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_ErrorRaschet(bool ErrorRaschet)
{
Object->ErrorRaschet=ErrorRaschet;
}
//---------------------------------------------------------------
bool TDMDocInvImpl::get_EnableDvReg(void)
{
return Object->EnableDvReg;
}
//---------------------------------------------------------------
void TDMDocInvImpl::set_EnableDvReg(bool EnableDvReg)
{
Object->EnableDvReg=EnableDvReg;
}
//---------------------------------------------------------------
void TDMDocInvImpl::NewDoc(void)
{
return Object->NewDoc();
}
//---------------------------------------------------------------
void TDMDocInvImpl::OpenDoc(__int64 id_doc)
{
return Object->OpenDoc(id_doc);
}
//---------------------------------------------------------------
bool TDMDocInvImpl::SaveDoc(void)
{
return Object->SaveDoc();
}
//---------------------------------------------------------------
bool TDMDocInvImpl::DvRegDoc(void)
{
return Object->DvRegDoc();
}
//---------------------------------------------------------------
bool TDMDocInvImpl::CancelDvRegDoc(void)
{
return Object->CancelDvRegDoc();
}
//---------------------------------------------------------------
void TDMDocInvImpl::AddDocNewString(void)
{
return Object->AddDocNewString();
}
//---------------------------------------------------------------
void TDMDocInvImpl::DeleteStringDoc(void)
{
return Object->DeleteStringDoc();
}
//---------------------------------------------------------------
bool TDMDocInvImpl::DeleteDoc(__int64 id)
{
return Object->DeleteDoc(id);
}
//---------------------------------------------------------------
__int64 TDMDocInvImpl::GetIDDocPoNomeruDoc(int number_doc, TDate date_doc)
{
return Object->GetIDDocPoNomeruDoc(number_doc,date_doc);
}
//---------------------------------------------------------------
void TDMDocInvImpl::AddDataRev(void)
{
return Object->AddDataRev();
}
//---------------------------------------------------------------
bool TDMDocInvImpl::SearchStringPoNom(__int64 id_nom)
{
return Object->SearchStringPoNom(id_nom);
}
//---------------------------------------------------------------
int TDMDocInvImpl::GetNumberNewDoc(void)
{
return Object->GetNumberNewDoc();
}
//---------------------------------------------------------------
