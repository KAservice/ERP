#include "vcl.h"
#pragma hdrstop


#include "UDMDocRepKKMImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMDocRepKKMImpl::TDMDocRepKKMImpl()           
{                                            
Object=new TDMDocRepKKM(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMDocRepKKMImpl::~TDMDocRepKKMImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMDocRepKKMImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMDocRepKKMImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMDocRepKKM)                        
   {                                                                     
   *ppv=static_cast<IDMDocRepKKM*> (this);                                
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
int TDMDocRepKKMImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMDocRepKKMImpl::kanRelease(void)                                  
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
int  TDMDocRepKKMImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMDocRepKKMImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMDocRepKKMImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMDocRepKKMImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMDocRepKKMImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMDocRepKKM
TDataSource * TDMDocRepKKMImpl::get_DataSourceDoc(void)
{
return Object->DataSourceDoc;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_DataSourceDoc(TDataSource * DataSourceDoc)
{
Object->DataSourceDoc=DataSourceDoc;
}
//---------------------------------------------------------------
TDataSource * TDMDocRepKKMImpl::get_DataSourceDocT(void)
{
return Object->DataSourceDocT;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_DataSourceDocT(TDataSource * DataSourceDocT)
{
Object->DataSourceDocT=DataSourceDocT;
}
//---------------------------------------------------------------
TDataSource * TDMDocRepKKMImpl::get_DataSourceDocAll(void)
{
return Object->DataSourceDocAll;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_DataSourceDocAll(TDataSource * DataSourceDocAll)
{
Object->DataSourceDocAll=DataSourceDocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocRepKKMImpl::get_DocAll(void)
{
return Object->DocAll;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_DocAll(TpFIBDataSet * DocAll)
{
Object->DocAll=DocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocRepKKMImpl::get_Doc(void)
{
return Object->Doc;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_Doc(TpFIBDataSet * Doc)
{
Object->Doc=Doc;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocRepKKMImpl::get_DocT(void)
{
return Object->DocT;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_DocT(TpFIBDataSet * DocT)
{
Object->DocT=DocT;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocRepKKMImpl::get_IBTrDvReg(void)
{
return Object->IBTrDvReg;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_IBTrDvReg(TpFIBTransaction * IBTrDvReg)
{
Object->IBTrDvReg=IBTrDvReg;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocRepKKMImpl::get_NumDoc(void)
{
return Object->NumDoc;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_NumDoc(TpFIBDataSet * NumDoc)
{
Object->NumDoc=NumDoc;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocRepKKMImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocRepKKMImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TFIBDateTimeField * TDMDocRepKKMImpl::get_DocAllPOSDOC(void)
{
return Object->DocAllPOSDOC;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_DocAllPOSDOC(TFIBDateTimeField * DocAllPOSDOC)
{
Object->DocAllPOSDOC=DocAllPOSDOC;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMDocRepKKMImpl::get_DocAllPRDOC(void)
{
return Object->DocAllPRDOC;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_DocAllPRDOC(TFIBSmallIntField * DocAllPRDOC)
{
Object->DocAllPRDOC=DocAllPRDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocRepKKMImpl::get_DocAllNUMDOC(void)
{
return Object->DocAllNUMDOC;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_DocAllNUMDOC(TFIBIntegerField * DocAllNUMDOC)
{
Object->DocAllNUMDOC=DocAllNUMDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRepKKMImpl::get_DocAllSUMDOC(void)
{
return Object->DocAllSUMDOC;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_DocAllSUMDOC(TFIBBCDField * DocAllSUMDOC)
{
Object->DocAllSUMDOC=DocAllSUMDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRepKKMImpl::get_DocOPLNAL_DREPKKM(void)
{
return Object->DocOPLNAL_DREPKKM;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_DocOPLNAL_DREPKKM(TFIBBCDField * DocOPLNAL_DREPKKM)
{
Object->DocOPLNAL_DREPKKM=DocOPLNAL_DREPKKM;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRepKKMImpl::get_DocOPLPC_DREPKKM(void)
{
return Object->DocOPLPC_DREPKKM;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_DocOPLPC_DREPKKM(TFIBBCDField * DocOPLPC_DREPKKM)
{
Object->DocOPLPC_DREPKKM=DocOPLPC_DREPKKM;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocRepKKMImpl::get_DocNKL_DREPKKM(void)
{
return Object->DocNKL_DREPKKM;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_DocNKL_DREPKKM(TFIBIntegerField * DocNKL_DREPKKM)
{
Object->DocNKL_DREPKKM=DocNKL_DREPKKM;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRepKKMImpl::get_DocSK_DREPKKM(void)
{
return Object->DocSK_DREPKKM;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_DocSK_DREPKKM(TFIBBCDField * DocSK_DREPKKM)
{
Object->DocSK_DREPKKM=DocSK_DREPKKM;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRepKKMImpl::get_DocNAD_DREPKKM(void)
{
return Object->DocNAD_DREPKKM;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_DocNAD_DREPKKM(TFIBBCDField * DocNAD_DREPKKM)
{
Object->DocNAD_DREPKKM=DocNAD_DREPKKM;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMDocRepKKMImpl::get_DocDVREG_DREPKKM(void)
{
return Object->DocDVREG_DREPKKM;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_DocDVREG_DREPKKM(TFIBSmallIntField * DocDVREG_DREPKKM)
{
Object->DocDVREG_DREPKKM=DocDVREG_DREPKKM;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRepKKMImpl::get_DocTPRICE_DREPKKMT(void)
{
return Object->DocTPRICE_DREPKKMT;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_DocTPRICE_DREPKKMT(TFIBBCDField * DocTPRICE_DREPKKMT)
{
Object->DocTPRICE_DREPKKMT=DocTPRICE_DREPKKMT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRepKKMImpl::get_DocTKOL_DREPKKMT(void)
{
return Object->DocTKOL_DREPKKMT;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_DocTKOL_DREPKKMT(TFIBBCDField * DocTKOL_DREPKKMT)
{
Object->DocTKOL_DREPKKMT=DocTKOL_DREPKKMT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRepKKMImpl::get_DocTKF_DREPKKMT(void)
{
return Object->DocTKF_DREPKKMT;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_DocTKF_DREPKKMT(TFIBBCDField * DocTKF_DREPKKMT)
{
Object->DocTKF_DREPKKMT=DocTKF_DREPKKMT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRepKKMImpl::get_DocTSUM_DREPKKMT(void)
{
return Object->DocTSUM_DREPKKMT;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_DocTSUM_DREPKKMT(TFIBBCDField * DocTSUM_DREPKKMT)
{
Object->DocTSUM_DREPKKMT=DocTSUM_DREPKKMT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRepKKMImpl::get_DocTSK_DREPKKMT(void)
{
return Object->DocTSK_DREPKKMT;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_DocTSK_DREPKKMT(TFIBBCDField * DocTSK_DREPKKMT)
{
Object->DocTSK_DREPKKMT=DocTSK_DREPKKMT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRepKKMImpl::get_DocTNAD_DREPKKMT(void)
{
return Object->DocTNAD_DREPKKMT;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_DocTNAD_DREPKKMT(TFIBBCDField * DocTNAD_DREPKKMT)
{
Object->DocTNAD_DREPKKMT=DocTNAD_DREPKKMT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRepKKMImpl::get_DocTPRICEFULL_DREPKKMT(void)
{
return Object->DocTPRICEFULL_DREPKKMT;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_DocTPRICEFULL_DREPKKMT(TFIBBCDField * DocTPRICEFULL_DREPKKMT)
{
Object->DocTPRICEFULL_DREPKKMT=DocTPRICEFULL_DREPKKMT;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocRepKKMImpl::get_DocTTNOM(void)
{
return Object->DocTTNOM;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_DocTTNOM(TFIBIntegerField * DocTTNOM)
{
Object->DocTTNOM=DocTTNOM;
}
//---------------------------------------------------------------
TIntegerField * TDMDocRepKKMImpl::get_DocTRECNO(void)
{
return Object->DocTRECNO;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_DocTRECNO(TIntegerField * DocTRECNO)
{
Object->DocTRECNO=DocTRECNO;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocRepKKMImpl::get_IBQ(void)
{
return Object->IBQ;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_IBQ(TpFIBDataSet * IBQ)
{
Object->IBQ=IBQ;
}
//---------------------------------------------------------------
TpFIBQuery * TDMDocRepKKMImpl::get_QueryCancelDvReg(void)
{
return Object->QueryCancelDvReg;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg)
{
Object->QueryCancelDvReg=QueryCancelDvReg;
}
//---------------------------------------------------------------
TpFIBQuery * TDMDocRepKKMImpl::get_QueryDvReg(void)
{
return Object->QueryDvReg;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_QueryDvReg(TpFIBQuery * QueryDvReg)
{
Object->QueryDvReg=QueryDvReg;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocRepKKMImpl::get_TableDoc(void)
{
return Object->TableDoc;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_TableDoc(TpFIBDataSet * TableDoc)
{
Object->TableDoc=TableDoc;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocRepKKMImpl::get_PayDoc(void)
{
return Object->PayDoc;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_PayDoc(TpFIBDataSet * PayDoc)
{
Object->PayDoc=PayDoc;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRepKKMImpl::get_TableDocSUMMA(void)
{
return Object->TableDocSUMMA;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_TableDocSUMMA(TFIBBCDField * TableDocSUMMA)
{
Object->TableDocSUMMA=TableDocSUMMA;
}
//---------------------------------------------------------------
TFIBFloatField * TDMDocRepKKMImpl::get_TableDocSUMKOL(void)
{
return Object->TableDocSUMKOL;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_TableDocSUMKOL(TFIBFloatField * TableDocSUMKOL)
{
Object->TableDocSUMKOL=TableDocSUMKOL;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRepKKMImpl::get_TableDocSUMSK(void)
{
return Object->TableDocSUMSK;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_TableDocSUMSK(TFIBBCDField * TableDocSUMSK)
{
Object->TableDocSUMSK=TableDocSUMSK;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRepKKMImpl::get_TableDocSUMNAD(void)
{
return Object->TableDocSUMNAD;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_TableDocSUMNAD(TFIBBCDField * TableDocSUMNAD)
{
Object->TableDocSUMNAD=TableDocSUMNAD;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRepKKMImpl::get_PayDocOPLATANAL(void)
{
return Object->PayDocOPLATANAL;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_PayDocOPLATANAL(TFIBBCDField * PayDocOPLATANAL)
{
Object->PayDocOPLATANAL=PayDocOPLATANAL;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRepKKMImpl::get_PayDocOPLATAPC(void)
{
return Object->PayDocOPLATAPC;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_PayDocOPLATAPC(TFIBBCDField * PayDocOPLATAPC)
{
Object->PayDocOPLATAPC=PayDocOPLATAPC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRepKKMImpl::get_TableDocIDNOM(void)
{
return Object->TableDocIDNOM;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_TableDocIDNOM(TFIBLargeIntField * TableDocIDNOM)
{
Object->TableDocIDNOM=TableDocIDNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRepKKMImpl::get_TableDocNAMENOM(void)
{
return Object->TableDocNAMENOM;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_TableDocNAMENOM(TFIBWideStringField * TableDocNAMENOM)
{
Object->TableDocNAMENOM=TableDocNAMENOM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRepKKMImpl::get_TableDocIDED(void)
{
return Object->TableDocIDED;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_TableDocIDED(TFIBLargeIntField * TableDocIDED)
{
Object->TableDocIDED=TableDocIDED;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRepKKMImpl::get_TableDocNAMEED(void)
{
return Object->TableDocNAMEED;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_TableDocNAMEED(TFIBWideStringField * TableDocNAMEED)
{
Object->TableDocNAMEED=TableDocNAMEED;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRepKKMImpl::get_DocAllIDDOC(void)
{
return Object->DocAllIDDOC;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_DocAllIDDOC(TFIBLargeIntField * DocAllIDDOC)
{
Object->DocAllIDDOC=DocAllIDDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRepKKMImpl::get_DocAllIDFIRMDOC(void)
{
return Object->DocAllIDFIRMDOC;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_DocAllIDFIRMDOC(TFIBLargeIntField * DocAllIDFIRMDOC)
{
Object->DocAllIDFIRMDOC=DocAllIDFIRMDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRepKKMImpl::get_DocAllIDSKLDOC(void)
{
return Object->DocAllIDSKLDOC;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_DocAllIDSKLDOC(TFIBLargeIntField * DocAllIDSKLDOC)
{
Object->DocAllIDSKLDOC=DocAllIDSKLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRepKKMImpl::get_DocAllIDKLDOC(void)
{
return Object->DocAllIDKLDOC;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_DocAllIDKLDOC(TFIBLargeIntField * DocAllIDKLDOC)
{
Object->DocAllIDKLDOC=DocAllIDKLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRepKKMImpl::get_DocAllIDDOGDOC(void)
{
return Object->DocAllIDDOGDOC;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_DocAllIDDOGDOC(TFIBLargeIntField * DocAllIDDOGDOC)
{
Object->DocAllIDDOGDOC=DocAllIDDOGDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRepKKMImpl::get_DocAllIDUSERDOC(void)
{
return Object->DocAllIDUSERDOC;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_DocAllIDUSERDOC(TFIBLargeIntField * DocAllIDUSERDOC)
{
Object->DocAllIDUSERDOC=DocAllIDUSERDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRepKKMImpl::get_DocAllGID_DOC(void)
{
return Object->DocAllGID_DOC;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_DocAllGID_DOC(TFIBWideStringField * DocAllGID_DOC)
{
Object->DocAllGID_DOC=DocAllGID_DOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRepKKMImpl::get_DocAllPREFIKSDOC(void)
{
return Object->DocAllPREFIKSDOC;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_DocAllPREFIKSDOC(TFIBWideStringField * DocAllPREFIKSDOC)
{
Object->DocAllPREFIKSDOC=DocAllPREFIKSDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRepKKMImpl::get_DocAllIDDOCOSNDOC(void)
{
return Object->DocAllIDDOCOSNDOC;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_DocAllIDDOCOSNDOC(TFIBLargeIntField * DocAllIDDOCOSNDOC)
{
Object->DocAllIDDOCOSNDOC=DocAllIDDOCOSNDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRepKKMImpl::get_DocAllIDEXTDOC(void)
{
return Object->DocAllIDEXTDOC;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_DocAllIDEXTDOC(TFIBLargeIntField * DocAllIDEXTDOC)
{
Object->DocAllIDEXTDOC=DocAllIDEXTDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocRepKKMImpl::get_DocAllTYPEEXTDOC(void)
{
return Object->DocAllTYPEEXTDOC;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_DocAllTYPEEXTDOC(TFIBIntegerField * DocAllTYPEEXTDOC)
{
Object->DocAllTYPEEXTDOC=DocAllTYPEEXTDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRepKKMImpl::get_DocAllIDBASE_GALLDOC(void)
{
return Object->DocAllIDBASE_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_DocAllIDBASE_GALLDOC(TFIBLargeIntField * DocAllIDBASE_GALLDOC)
{
Object->DocAllIDBASE_GALLDOC=DocAllIDBASE_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRepKKMImpl::get_DocAllIDPROJECT_GALLDOC(void)
{
return Object->DocAllIDPROJECT_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_DocAllIDPROJECT_GALLDOC(TFIBLargeIntField * DocAllIDPROJECT_GALLDOC)
{
Object->DocAllIDPROJECT_GALLDOC=DocAllIDPROJECT_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRepKKMImpl::get_DocAllFNAME_USER(void)
{
return Object->DocAllFNAME_USER;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_DocAllFNAME_USER(TFIBWideStringField * DocAllFNAME_USER)
{
Object->DocAllFNAME_USER=DocAllFNAME_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRepKKMImpl::get_DocAllNAME_SDOG(void)
{
return Object->DocAllNAME_SDOG;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_DocAllNAME_SDOG(TFIBWideStringField * DocAllNAME_SDOG)
{
Object->DocAllNAME_SDOG=DocAllNAME_SDOG;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRepKKMImpl::get_DocAllNAMEKLIENT(void)
{
return Object->DocAllNAMEKLIENT;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_DocAllNAMEKLIENT(TFIBWideStringField * DocAllNAMEKLIENT)
{
Object->DocAllNAMEKLIENT=DocAllNAMEKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRepKKMImpl::get_DocAllNAMEFIRM(void)
{
return Object->DocAllNAMEFIRM;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_DocAllNAMEFIRM(TFIBWideStringField * DocAllNAMEFIRM)
{
Object->DocAllNAMEFIRM=DocAllNAMEFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRepKKMImpl::get_DocAllNAMESKLAD(void)
{
return Object->DocAllNAMESKLAD;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_DocAllNAMESKLAD(TFIBWideStringField * DocAllNAMESKLAD)
{
Object->DocAllNAMESKLAD=DocAllNAMESKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRepKKMImpl::get_DocAllNAME_SINFBASE_OBMEN(void)
{
return Object->DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN)
{
Object->DocAllNAME_SINFBASE_OBMEN=DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRepKKMImpl::get_DocID_DREPKKM(void)
{
return Object->DocID_DREPKKM;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_DocID_DREPKKM(TFIBLargeIntField * DocID_DREPKKM)
{
Object->DocID_DREPKKM=DocID_DREPKKM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRepKKMImpl::get_DocGID_DREPKKM(void)
{
return Object->DocGID_DREPKKM;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_DocGID_DREPKKM(TFIBWideStringField * DocGID_DREPKKM)
{
Object->DocGID_DREPKKM=DocGID_DREPKKM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRepKKMImpl::get_DocIDDOC_DREPKKM(void)
{
return Object->DocIDDOC_DREPKKM;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_DocIDDOC_DREPKKM(TFIBLargeIntField * DocIDDOC_DREPKKM)
{
Object->DocIDDOC_DREPKKM=DocIDDOC_DREPKKM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRepKKMImpl::get_DocIDKKM_DREPKKM(void)
{
return Object->DocIDKKM_DREPKKM;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_DocIDKKM_DREPKKM(TFIBLargeIntField * DocIDKKM_DREPKKM)
{
Object->DocIDKKM_DREPKKM=DocIDKKM_DREPKKM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRepKKMImpl::get_DocPRIM_DREPKKM(void)
{
return Object->DocPRIM_DREPKKM;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_DocPRIM_DREPKKM(TFIBWideStringField * DocPRIM_DREPKKM)
{
Object->DocPRIM_DREPKKM=DocPRIM_DREPKKM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRepKKMImpl::get_DocIDTPRICE_DREPKKM(void)
{
return Object->DocIDTPRICE_DREPKKM;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_DocIDTPRICE_DREPKKM(TFIBLargeIntField * DocIDTPRICE_DREPKKM)
{
Object->DocIDTPRICE_DREPKKM=DocIDTPRICE_DREPKKM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRepKKMImpl::get_DocIDBASE_DREPKKM(void)
{
return Object->DocIDBASE_DREPKKM;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_DocIDBASE_DREPKKM(TFIBLargeIntField * DocIDBASE_DREPKKM)
{
Object->DocIDBASE_DREPKKM=DocIDBASE_DREPKKM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRepKKMImpl::get_DocIDBSCHET_DREPKKM(void)
{
return Object->DocIDBSCHET_DREPKKM;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_DocIDBSCHET_DREPKKM(TFIBLargeIntField * DocIDBSCHET_DREPKKM)
{
Object->DocIDBSCHET_DREPKKM=DocIDBSCHET_DREPKKM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRepKKMImpl::get_DocNAMEKKM(void)
{
return Object->DocNAMEKKM;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_DocNAMEKKM(TFIBWideStringField * DocNAMEKKM)
{
Object->DocNAMEKKM=DocNAMEKKM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRepKKMImpl::get_DocNAME_TPRICE(void)
{
return Object->DocNAME_TPRICE;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_DocNAME_TPRICE(TFIBWideStringField * DocNAME_TPRICE)
{
Object->DocNAME_TPRICE=DocNAME_TPRICE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRepKKMImpl::get_DocNAMEBSCHET(void)
{
return Object->DocNAMEBSCHET;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_DocNAMEBSCHET(TFIBWideStringField * DocNAMEBSCHET)
{
Object->DocNAMEBSCHET=DocNAMEBSCHET;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRepKKMImpl::get_DocTID_DREPKKMT(void)
{
return Object->DocTID_DREPKKMT;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_DocTID_DREPKKMT(TFIBLargeIntField * DocTID_DREPKKMT)
{
Object->DocTID_DREPKKMT=DocTID_DREPKKMT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRepKKMImpl::get_DocTGID_DREPKKMT(void)
{
return Object->DocTGID_DREPKKMT;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_DocTGID_DREPKKMT(TFIBWideStringField * DocTGID_DREPKKMT)
{
Object->DocTGID_DREPKKMT=DocTGID_DREPKKMT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRepKKMImpl::get_DocTIDDOC_DREPKKMT(void)
{
return Object->DocTIDDOC_DREPKKMT;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_DocTIDDOC_DREPKKMT(TFIBLargeIntField * DocTIDDOC_DREPKKMT)
{
Object->DocTIDDOC_DREPKKMT=DocTIDDOC_DREPKKMT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRepKKMImpl::get_DocTIDNOM_DREPKKMT(void)
{
return Object->DocTIDNOM_DREPKKMT;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_DocTIDNOM_DREPKKMT(TFIBLargeIntField * DocTIDNOM_DREPKKMT)
{
Object->DocTIDNOM_DREPKKMT=DocTIDNOM_DREPKKMT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRepKKMImpl::get_DocTIDED_DREPKKMT(void)
{
return Object->DocTIDED_DREPKKMT;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_DocTIDED_DREPKKMT(TFIBLargeIntField * DocTIDED_DREPKKMT)
{
Object->DocTIDED_DREPKKMT=DocTIDED_DREPKKMT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRepKKMImpl::get_DocTIDBASE_DREPKKMT(void)
{
return Object->DocTIDBASE_DREPKKMT;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_DocTIDBASE_DREPKKMT(TFIBLargeIntField * DocTIDBASE_DREPKKMT)
{
Object->DocTIDBASE_DREPKKMT=DocTIDBASE_DREPKKMT;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocRepKKMImpl::get_DocTNDS_DREPKKMT(void)
{
return Object->DocTNDS_DREPKKMT;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_DocTNDS_DREPKKMT(TFIBIntegerField * DocTNDS_DREPKKMT)
{
Object->DocTNDS_DREPKKMT=DocTNDS_DREPKKMT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRepKKMImpl::get_DocTSUMNDS_DREPKKMT(void)
{
return Object->DocTSUMNDS_DREPKKMT;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_DocTSUMNDS_DREPKKMT(TFIBBCDField * DocTSUMNDS_DREPKKMT)
{
Object->DocTSUMNDS_DREPKKMT=DocTSUMNDS_DREPKKMT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRepKKMImpl::get_DocTKRNAMENOM(void)
{
return Object->DocTKRNAMENOM;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_DocTKRNAMENOM(TFIBWideStringField * DocTKRNAMENOM)
{
Object->DocTKRNAMENOM=DocTKRNAMENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRepKKMImpl::get_DocTNAMENOM(void)
{
return Object->DocTNAMENOM;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_DocTNAMENOM(TFIBWideStringField * DocTNAMENOM)
{
Object->DocTNAMENOM=DocTNAMENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRepKKMImpl::get_DocTNAMEED(void)
{
return Object->DocTNAMEED;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_DocTNAMEED(TFIBWideStringField * DocTNAMEED)
{
Object->DocTNAMEED=DocTNAMEED;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRepKKMImpl::get_DocAllTDOC(void)
{
return Object->DocAllTDOC;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_DocAllTDOC(TFIBWideStringField * DocAllTDOC)
{
Object->DocAllTDOC=DocAllTDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRepKKMImpl::get_DocAllIDBUSINOP_GALLDOC(void)
{
return Object->DocAllIDBUSINOP_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_DocAllIDBUSINOP_GALLDOC(TFIBLargeIntField * DocAllIDBUSINOP_GALLDOC)
{
Object->DocAllIDBUSINOP_GALLDOC=DocAllIDBUSINOP_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRepKKMImpl::get_DocAllNAME_SPROJECT(void)
{
return Object->DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_DocAllNAME_SPROJECT(TFIBWideStringField * DocAllNAME_SPROJECT)
{
Object->DocAllNAME_SPROJECT=DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRepKKMImpl::get_DocAllNAME_SBUSINESS_OPER(void)
{
return Object->DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_DocAllNAME_SBUSINESS_OPER(TFIBWideStringField * DocAllNAME_SBUSINESS_OPER)
{
Object->DocAllNAME_SBUSINESS_OPER=DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRepKKMImpl::get_DocAllPREFIKS_NUM_GALLDOC(void)
{
return Object->DocAllPREFIKS_NUM_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_DocAllPREFIKS_NUM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_GALLDOC)
{
Object->DocAllPREFIKS_NUM_GALLDOC=DocAllPREFIKS_NUM_GALLDOC;
}
//---------------------------------------------------------------
bool TDMDocRepKKMImpl::get_NewElement(void)
{
return Object->NewElement;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_NewElement(bool NewElement)
{
Object->NewElement=NewElement;
}
//---------------------------------------------------------------
bool TDMDocRepKKMImpl::get_Prosmotr(void)
{
return Object->Prosmotr;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_Prosmotr(bool Prosmotr)
{
Object->Prosmotr=Prosmotr;
}
//---------------------------------------------------------------
bool TDMDocRepKKMImpl::get_Vibor(void)
{
return Object->Vibor;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_Vibor(bool Vibor)
{
Object->Vibor=Vibor;
}
//---------------------------------------------------------------
__int64 TDMDocRepKKMImpl::get_IdDoc(void)
{
return Object->IdDoc;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_IdDoc(__int64 IdDoc)
{
Object->IdDoc=IdDoc;
}
//---------------------------------------------------------------
__int64 TDMDocRepKKMImpl::get_IdTypePrice(void)
{
return Object->IdTypePrice;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_IdTypePrice(__int64 IdTypePrice)
{
Object->IdTypePrice=IdTypePrice;
}
//---------------------------------------------------------------
__int64 TDMDocRepKKMImpl::get_IdSklad(void)
{
return Object->IdSklad;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_IdSklad(__int64 IdSklad)
{
Object->IdSklad=IdSklad;
}
//---------------------------------------------------------------
bool TDMDocRepKKMImpl::get_NoEdit(void)
{
return Object->NoEdit;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_NoEdit(bool NoEdit)
{
Object->NoEdit=NoEdit;
}
//---------------------------------------------------------------
bool TDMDocRepKKMImpl::get_AutoRaschet(void)
{
return Object->AutoRaschet;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_AutoRaschet(bool AutoRaschet)
{
Object->AutoRaschet=AutoRaschet;
}
//---------------------------------------------------------------
bool TDMDocRepKKMImpl::get_EnableDvReg(void)
{
return Object->EnableDvReg;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_EnableDvReg(bool EnableDvReg)
{
Object->EnableDvReg=EnableDvReg;
}
//---------------------------------------------------------------
bool TDMDocRepKKMImpl::get_SkladRozn(void)
{
return Object->SkladRozn;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_SkladRozn(bool SkladRozn)
{
Object->SkladRozn=SkladRozn;
}
//---------------------------------------------------------------
bool TDMDocRepKKMImpl::get_NoOtrOstatok(void)
{
return Object->NoOtrOstatok;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::set_NoOtrOstatok(bool NoOtrOstatok)
{
Object->NoOtrOstatok=NoOtrOstatok;
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::NewDoc(void)
{
return Object->NewDoc();
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::OpenDoc(__int64 IdDoc)
{
return Object->OpenDoc(IdDoc);
}
//---------------------------------------------------------------
bool TDMDocRepKKMImpl::SaveDoc(void)
{
return Object->SaveDoc();
}
//---------------------------------------------------------------
bool TDMDocRepKKMImpl::DvRegDoc(void)
{
return Object->DvRegDoc();
}
//---------------------------------------------------------------
bool TDMDocRepKKMImpl::CancelDvRegDoc(void)
{
return Object->CancelDvRegDoc();
}
//---------------------------------------------------------------
bool TDMDocRepKKMImpl::DeleteDoc(__int64 id)
{
return Object->DeleteDoc(id);
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::AddDocNewString(void)
{
return Object->AddDocNewString();
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::DeleteStringDoc(void)
{
return Object->DeleteStringDoc();
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::CloseDoc(void)
{
return Object->CloseDoc();
}
//---------------------------------------------------------------
double TDMDocRepKKMImpl::Summa(void)
{
return Object->Summa();
}
//---------------------------------------------------------------
bool TDMDocRepKKMImpl::CreateReportKKM(   __int64 id_sklad,__int64 id_kkm,__int64 id_firm,int number_kl ,TDateTime NachInterval,TDateTime ConInterval)
{
return Object->CreateReportKKM(id_sklad,id_kkm,id_firm,number_kl ,NachInterval,ConInterval);
}
//---------------------------------------------------------------
void TDMDocRepKKMImpl::GetSumOplata(      __int64 id_sklad,__int64 id_kkm,__int64 id_firm,int number_kl ,TDateTime NachInterval,TDateTime ConInterval )
{
return Object->GetSumOplata(id_sklad,id_kkm,id_firm,number_kl ,NachInterval,ConInterval );
}
//---------------------------------------------------------------
int TDMDocRepKKMImpl::GetNumberNewDoc(void)
{
return Object->GetNumberNewDoc();
}
//---------------------------------------------------------------
