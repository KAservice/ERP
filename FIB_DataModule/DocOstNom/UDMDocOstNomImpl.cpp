#include "vcl.h"
#pragma hdrstop


#include "UDMDocOstNomImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMDocOstNomImpl::TDMDocOstNomImpl()           
{                                            
Object=new TDMDocOstNom(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMDocOstNomImpl::~TDMDocOstNomImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMDocOstNomImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMDocOstNomImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMDocOstNom)                        
   {                                                                     
   *ppv=static_cast<IDMDocOstNom*> (this);                                
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
int TDMDocOstNomImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMDocOstNomImpl::kanRelease(void)                                  
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
int  TDMDocOstNomImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMDocOstNomImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMDocOstNomImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMDocOstNomImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMDocOstNomImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMDocOstNom
TDataSource * TDMDocOstNomImpl::get_DataSourceDoc(void)
{
return Object->DataSourceDoc;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_DataSourceDoc(TDataSource * DataSourceDoc)
{
Object->DataSourceDoc=DataSourceDoc;
}
//---------------------------------------------------------------
TDataSource * TDMDocOstNomImpl::get_DataSourceDocT(void)
{
return Object->DataSourceDocT;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_DataSourceDocT(TDataSource * DataSourceDocT)
{
Object->DataSourceDocT=DataSourceDocT;
}
//---------------------------------------------------------------
TDataSource * TDMDocOstNomImpl::get_DataSourceDocAll(void)
{
return Object->DataSourceDocAll;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_DataSourceDocAll(TDataSource * DataSourceDocAll)
{
Object->DataSourceDocAll=DataSourceDocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocOstNomImpl::get_DocAll(void)
{
return Object->DocAll;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_DocAll(TpFIBDataSet * DocAll)
{
Object->DocAll=DocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocOstNomImpl::get_Doc(void)
{
return Object->Doc;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_Doc(TpFIBDataSet * Doc)
{
Object->Doc=Doc;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocOstNomImpl::get_IBTrDvReg(void)
{
return Object->IBTrDvReg;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_IBTrDvReg(TpFIBTransaction * IBTrDvReg)
{
Object->IBTrDvReg=IBTrDvReg;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocOstNomImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocOstNomImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocOstNomImpl::get_DocT(void)
{
return Object->DocT;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_DocT(TpFIBDataSet * DocT)
{
Object->DocT=DocT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocOstNomImpl::get_DocTKOLOSNT(void)
{
return Object->DocTKOLOSNT;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_DocTKOLOSNT(TFIBBCDField * DocTKOLOSNT)
{
Object->DocTKOLOSNT=DocTKOLOSNT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocOstNomImpl::get_DocTKFOSNT(void)
{
return Object->DocTKFOSNT;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_DocTKFOSNT(TFIBBCDField * DocTKFOSNT)
{
Object->DocTKFOSNT=DocTKFOSNT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocOstNomImpl::get_DocTPRICEOSNT(void)
{
return Object->DocTPRICEOSNT;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_DocTPRICEOSNT(TFIBBCDField * DocTPRICEOSNT)
{
Object->DocTPRICEOSNT=DocTPRICEOSNT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocOstNomImpl::get_DocTSUMOSNT(void)
{
return Object->DocTSUMOSNT;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_DocTSUMOSNT(TFIBBCDField * DocTSUMOSNT)
{
Object->DocTSUMOSNT=DocTSUMOSNT;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocOstNomImpl::get_DocTTNOM(void)
{
return Object->DocTTNOM;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_DocTTNOM(TFIBIntegerField * DocTTNOM)
{
Object->DocTTNOM=DocTTNOM;
}
//---------------------------------------------------------------
TIntegerField * TDMDocOstNomImpl::get_DocTRECNO(void)
{
return Object->DocTRECNO;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_DocTRECNO(TIntegerField * DocTRECNO)
{
Object->DocTRECNO=DocTRECNO;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocOstNomImpl::get_NumDoc(void)
{
return Object->NumDoc;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_NumDoc(TpFIBDataSet * NumDoc)
{
Object->NumDoc=NumDoc;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocOstNomImpl::get_Grp(void)
{
return Object->Grp;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_Grp(TpFIBDataSet * Grp)
{
Object->Grp=Grp;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocOstNomImpl::get_El(void)
{
return Object->El;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_El(TpFIBDataSet * El)
{
Object->El=El;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocOstNomImpl::get_IBQ(void)
{
return Object->IBQ;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_IBQ(TpFIBDataSet * IBQ)
{
Object->IBQ=IBQ;
}
//---------------------------------------------------------------
TpFIBQuery * TDMDocOstNomImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocOstNomImpl::get_DocOsn(void)
{
return Object->DocOsn;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_DocOsn(TpFIBDataSet * DocOsn)
{
Object->DocOsn=DocOsn;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocOstNomImpl::get_DocOsnNUMDOC(void)
{
return Object->DocOsnNUMDOC;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_DocOsnNUMDOC(TFIBIntegerField * DocOsnNUMDOC)
{
Object->DocOsnNUMDOC=DocOsnNUMDOC;
}
//---------------------------------------------------------------
TFIBDateTimeField * TDMDocOstNomImpl::get_DocOsnPOSDOC(void)
{
return Object->DocOsnPOSDOC;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_DocOsnPOSDOC(TFIBDateTimeField * DocOsnPOSDOC)
{
Object->DocOsnPOSDOC=DocOsnPOSDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocOstNomImpl::get_DocRSUM_DOSN(void)
{
return Object->DocRSUM_DOSN;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_DocRSUM_DOSN(TFIBBCDField * DocRSUM_DOSN)
{
Object->DocRSUM_DOSN=DocRSUM_DOSN;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocOstNomImpl::get_DocTRPRICE_DOSNT(void)
{
return Object->DocTRPRICE_DOSNT;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_DocTRPRICE_DOSNT(TFIBBCDField * DocTRPRICE_DOSNT)
{
Object->DocTRPRICE_DOSNT=DocTRPRICE_DOSNT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocOstNomImpl::get_DocTRSUM_DOSNT(void)
{
return Object->DocTRSUM_DOSNT;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_DocTRSUM_DOSNT(TFIBBCDField * DocTRSUM_DOSNT)
{
Object->DocTRSUM_DOSNT=DocTRSUM_DOSNT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocOstNomImpl::get_DocTNAC_DOSNT(void)
{
return Object->DocTNAC_DOSNT;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_DocTNAC_DOSNT(TFIBBCDField * DocTNAC_DOSNT)
{
Object->DocTNAC_DOSNT=DocTNAC_DOSNT;
}
//---------------------------------------------------------------
TpFIBQuery * TDMDocOstNomImpl::get_QueryCancelDvReg(void)
{
return Object->QueryCancelDvReg;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg)
{
Object->QueryCancelDvReg=QueryCancelDvReg;
}
//---------------------------------------------------------------
TpFIBQuery * TDMDocOstNomImpl::get_QueryDvReg(void)
{
return Object->QueryDvReg;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_QueryDvReg(TpFIBQuery * QueryDvReg)
{
Object->QueryDvReg=QueryDvReg;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocOstNomImpl::get_DocTNDS_DOSNT(void)
{
return Object->DocTNDS_DOSNT;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_DocTNDS_DOSNT(TFIBIntegerField * DocTNDS_DOSNT)
{
Object->DocTNDS_DOSNT=DocTNDS_DOSNT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocOstNomImpl::get_DocTSUMNDS_DOSNT(void)
{
return Object->DocTSUMNDS_DOSNT;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_DocTSUMNDS_DOSNT(TFIBBCDField * DocTSUMNDS_DOSNT)
{
Object->DocTSUMNDS_DOSNT=DocTSUMNDS_DOSNT;
}
//---------------------------------------------------------------
TFIBDateTimeField * TDMDocOstNomImpl::get_DocTSRGODNPART(void)
{
return Object->DocTSRGODNPART;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_DocTSRGODNPART(TFIBDateTimeField * DocTSRGODNPART)
{
Object->DocTSRGODNPART=DocTSRGODNPART;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocOstNomImpl::get_DocOsnTDOC(void)
{
return Object->DocOsnTDOC;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_DocOsnTDOC(TFIBWideStringField * DocOsnTDOC)
{
Object->DocOsnTDOC=DocOsnTDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocOstNomImpl::get_GrpNAMEGN(void)
{
return Object->GrpNAMEGN;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_GrpNAMEGN(TFIBWideStringField * GrpNAMEGN)
{
Object->GrpNAMEGN=GrpNAMEGN;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocOstNomImpl::get_GrpIDGN(void)
{
return Object->GrpIDGN;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_GrpIDGN(TFIBLargeIntField * GrpIDGN)
{
Object->GrpIDGN=GrpIDGN;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocOstNomImpl::get_GrpSUMMA(void)
{
return Object->GrpSUMMA;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_GrpSUMMA(TFIBBCDField * GrpSUMMA)
{
Object->GrpSUMMA=GrpSUMMA;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocOstNomImpl::get_ElNAMENOM(void)
{
return Object->ElNAMENOM;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_ElNAMENOM(TFIBWideStringField * ElNAMENOM)
{
Object->ElNAMENOM=ElNAMENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocOstNomImpl::get_ElNAMEED(void)
{
return Object->ElNAMEED;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_ElNAMEED(TFIBWideStringField * ElNAMEED)
{
Object->ElNAMEED=ElNAMEED;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocOstNomImpl::get_ElSUMMA(void)
{
return Object->ElSUMMA;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_ElSUMMA(TFIBBCDField * ElSUMMA)
{
Object->ElSUMMA=ElSUMMA;
}
//---------------------------------------------------------------
TFIBFloatField * TDMDocOstNomImpl::get_ElSUMKOL(void)
{
return Object->ElSUMKOL;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_ElSUMKOL(TFIBFloatField * ElSUMKOL)
{
Object->ElSUMKOL=ElSUMKOL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocOstNomImpl::get_DocAllIDDOC(void)
{
return Object->DocAllIDDOC;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_DocAllIDDOC(TFIBLargeIntField * DocAllIDDOC)
{
Object->DocAllIDDOC=DocAllIDDOC;
}
//---------------------------------------------------------------
TFIBDateTimeField * TDMDocOstNomImpl::get_DocAllPOSDOC(void)
{
return Object->DocAllPOSDOC;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_DocAllPOSDOC(TFIBDateTimeField * DocAllPOSDOC)
{
Object->DocAllPOSDOC=DocAllPOSDOC;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMDocOstNomImpl::get_DocAllPRDOC(void)
{
return Object->DocAllPRDOC;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_DocAllPRDOC(TFIBSmallIntField * DocAllPRDOC)
{
Object->DocAllPRDOC=DocAllPRDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocOstNomImpl::get_DocAllTDOC(void)
{
return Object->DocAllTDOC;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_DocAllTDOC(TFIBWideStringField * DocAllTDOC)
{
Object->DocAllTDOC=DocAllTDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocOstNomImpl::get_DocAllNUMDOC(void)
{
return Object->DocAllNUMDOC;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_DocAllNUMDOC(TFIBIntegerField * DocAllNUMDOC)
{
Object->DocAllNUMDOC=DocAllNUMDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocOstNomImpl::get_DocAllIDFIRMDOC(void)
{
return Object->DocAllIDFIRMDOC;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_DocAllIDFIRMDOC(TFIBLargeIntField * DocAllIDFIRMDOC)
{
Object->DocAllIDFIRMDOC=DocAllIDFIRMDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocOstNomImpl::get_DocAllIDSKLDOC(void)
{
return Object->DocAllIDSKLDOC;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_DocAllIDSKLDOC(TFIBLargeIntField * DocAllIDSKLDOC)
{
Object->DocAllIDSKLDOC=DocAllIDSKLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocOstNomImpl::get_DocAllIDKLDOC(void)
{
return Object->DocAllIDKLDOC;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_DocAllIDKLDOC(TFIBLargeIntField * DocAllIDKLDOC)
{
Object->DocAllIDKLDOC=DocAllIDKLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocOstNomImpl::get_DocAllIDDOGDOC(void)
{
return Object->DocAllIDDOGDOC;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_DocAllIDDOGDOC(TFIBLargeIntField * DocAllIDDOGDOC)
{
Object->DocAllIDDOGDOC=DocAllIDDOGDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocOstNomImpl::get_DocAllSUMDOC(void)
{
return Object->DocAllSUMDOC;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_DocAllSUMDOC(TFIBBCDField * DocAllSUMDOC)
{
Object->DocAllSUMDOC=DocAllSUMDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocOstNomImpl::get_DocAllIDUSERDOC(void)
{
return Object->DocAllIDUSERDOC;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_DocAllIDUSERDOC(TFIBLargeIntField * DocAllIDUSERDOC)
{
Object->DocAllIDUSERDOC=DocAllIDUSERDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocOstNomImpl::get_DocAllGID_DOC(void)
{
return Object->DocAllGID_DOC;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_DocAllGID_DOC(TFIBWideStringField * DocAllGID_DOC)
{
Object->DocAllGID_DOC=DocAllGID_DOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocOstNomImpl::get_DocAllPREFIKSDOC(void)
{
return Object->DocAllPREFIKSDOC;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_DocAllPREFIKSDOC(TFIBWideStringField * DocAllPREFIKSDOC)
{
Object->DocAllPREFIKSDOC=DocAllPREFIKSDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocOstNomImpl::get_DocAllIDDOCOSNDOC(void)
{
return Object->DocAllIDDOCOSNDOC;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_DocAllIDDOCOSNDOC(TFIBLargeIntField * DocAllIDDOCOSNDOC)
{
Object->DocAllIDDOCOSNDOC=DocAllIDDOCOSNDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocOstNomImpl::get_DocAllIDEXTDOC(void)
{
return Object->DocAllIDEXTDOC;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_DocAllIDEXTDOC(TFIBLargeIntField * DocAllIDEXTDOC)
{
Object->DocAllIDEXTDOC=DocAllIDEXTDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocOstNomImpl::get_DocAllTYPEEXTDOC(void)
{
return Object->DocAllTYPEEXTDOC;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_DocAllTYPEEXTDOC(TFIBIntegerField * DocAllTYPEEXTDOC)
{
Object->DocAllTYPEEXTDOC=DocAllTYPEEXTDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocOstNomImpl::get_DocAllIDBASE_GALLDOC(void)
{
return Object->DocAllIDBASE_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_DocAllIDBASE_GALLDOC(TFIBLargeIntField * DocAllIDBASE_GALLDOC)
{
Object->DocAllIDBASE_GALLDOC=DocAllIDBASE_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocOstNomImpl::get_DocAllIDPROJECT_GALLDOC(void)
{
return Object->DocAllIDPROJECT_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_DocAllIDPROJECT_GALLDOC(TFIBLargeIntField * DocAllIDPROJECT_GALLDOC)
{
Object->DocAllIDPROJECT_GALLDOC=DocAllIDPROJECT_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocOstNomImpl::get_DocAllFNAME_USER(void)
{
return Object->DocAllFNAME_USER;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_DocAllFNAME_USER(TFIBWideStringField * DocAllFNAME_USER)
{
Object->DocAllFNAME_USER=DocAllFNAME_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocOstNomImpl::get_DocAllNAME_SINFBASE_OBMEN(void)
{
return Object->DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN)
{
Object->DocAllNAME_SINFBASE_OBMEN=DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocOstNomImpl::get_DocAllNAMEFIRM(void)
{
return Object->DocAllNAMEFIRM;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_DocAllNAMEFIRM(TFIBWideStringField * DocAllNAMEFIRM)
{
Object->DocAllNAMEFIRM=DocAllNAMEFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocOstNomImpl::get_DocAllNAMESKLAD(void)
{
return Object->DocAllNAMESKLAD;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_DocAllNAMESKLAD(TFIBWideStringField * DocAllNAMESKLAD)
{
Object->DocAllNAMESKLAD=DocAllNAMESKLAD;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocOstNomImpl::get_DocIDOSN(void)
{
return Object->DocIDOSN;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_DocIDOSN(TFIBLargeIntField * DocIDOSN)
{
Object->DocIDOSN=DocIDOSN;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocOstNomImpl::get_DocIDDOCOSN(void)
{
return Object->DocIDDOCOSN;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_DocIDDOCOSN(TFIBLargeIntField * DocIDDOCOSN)
{
Object->DocIDDOCOSN=DocIDDOCOSN;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocOstNomImpl::get_DocPRIMOSN(void)
{
return Object->DocPRIMOSN;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_DocPRIMOSN(TFIBWideStringField * DocPRIMOSN)
{
Object->DocPRIMOSN=DocPRIMOSN;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocOstNomImpl::get_DocIDTPRICEOSN(void)
{
return Object->DocIDTPRICEOSN;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_DocIDTPRICEOSN(TFIBLargeIntField * DocIDTPRICEOSN)
{
Object->DocIDTPRICEOSN=DocIDTPRICEOSN;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocOstNomImpl::get_DocGID_DOSN(void)
{
return Object->DocGID_DOSN;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_DocGID_DOSN(TFIBWideStringField * DocGID_DOSN)
{
Object->DocGID_DOSN=DocGID_DOSN;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocOstNomImpl::get_DocIDRTPRICE_DOSN(void)
{
return Object->DocIDRTPRICE_DOSN;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_DocIDRTPRICE_DOSN(TFIBLargeIntField * DocIDRTPRICE_DOSN)
{
Object->DocIDRTPRICE_DOSN=DocIDRTPRICE_DOSN;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocOstNomImpl::get_DocIDBASE_DOSN(void)
{
return Object->DocIDBASE_DOSN;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_DocIDBASE_DOSN(TFIBLargeIntField * DocIDBASE_DOSN)
{
Object->DocIDBASE_DOSN=DocIDBASE_DOSN;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocOstNomImpl::get_DocOPER_DOSN(void)
{
return Object->DocOPER_DOSN;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_DocOPER_DOSN(TFIBIntegerField * DocOPER_DOSN)
{
Object->DocOPER_DOSN=DocOPER_DOSN;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocOstNomImpl::get_DocNAME_TPRICE(void)
{
return Object->DocNAME_TPRICE;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_DocNAME_TPRICE(TFIBWideStringField * DocNAME_TPRICE)
{
Object->DocNAME_TPRICE=DocNAME_TPRICE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocOstNomImpl::get_DocTIDOSNT(void)
{
return Object->DocTIDOSNT;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_DocTIDOSNT(TFIBLargeIntField * DocTIDOSNT)
{
Object->DocTIDOSNT=DocTIDOSNT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocOstNomImpl::get_DocTIDDOCOSNT(void)
{
return Object->DocTIDDOCOSNT;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_DocTIDDOCOSNT(TFIBLargeIntField * DocTIDDOCOSNT)
{
Object->DocTIDDOCOSNT=DocTIDDOCOSNT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocOstNomImpl::get_DocTIDNOMOSNT(void)
{
return Object->DocTIDNOMOSNT;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_DocTIDNOMOSNT(TFIBLargeIntField * DocTIDNOMOSNT)
{
Object->DocTIDNOMOSNT=DocTIDNOMOSNT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocOstNomImpl::get_DocTIDEDOSNT(void)
{
return Object->DocTIDEDOSNT;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_DocTIDEDOSNT(TFIBLargeIntField * DocTIDEDOSNT)
{
Object->DocTIDEDOSNT=DocTIDEDOSNT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocOstNomImpl::get_DocTIDPARTOSNT(void)
{
return Object->DocTIDPARTOSNT;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_DocTIDPARTOSNT(TFIBLargeIntField * DocTIDPARTOSNT)
{
Object->DocTIDPARTOSNT=DocTIDPARTOSNT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocOstNomImpl::get_DocTGID_DOSNT(void)
{
return Object->DocTGID_DOSNT;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_DocTGID_DOSNT(TFIBWideStringField * DocTGID_DOSNT)
{
Object->DocTGID_DOSNT=DocTGID_DOSNT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocOstNomImpl::get_DocTIDBASE_DOSNT(void)
{
return Object->DocTIDBASE_DOSNT;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_DocTIDBASE_DOSNT(TFIBLargeIntField * DocTIDBASE_DOSNT)
{
Object->DocTIDBASE_DOSNT=DocTIDBASE_DOSNT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocOstNomImpl::get_DocTNAMENOM(void)
{
return Object->DocTNAMENOM;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_DocTNAMENOM(TFIBWideStringField * DocTNAMENOM)
{
Object->DocTNAMENOM=DocTNAMENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocOstNomImpl::get_DocTNAMEED(void)
{
return Object->DocTNAMEED;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_DocTNAMEED(TFIBWideStringField * DocTNAMEED)
{
Object->DocTNAMEED=DocTNAMEED;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocOstNomImpl::get_DocTGTDPART(void)
{
return Object->DocTGTDPART;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_DocTGTDPART(TFIBWideStringField * DocTGTDPART)
{
Object->DocTGTDPART=DocTGTDPART;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocOstNomImpl::get_DocTSERTPART(void)
{
return Object->DocTSERTPART;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_DocTSERTPART(TFIBWideStringField * DocTSERTPART)
{
Object->DocTSERTPART=DocTSERTPART;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocOstNomImpl::get_DocAllIDBUSINOP_GALLDOC(void)
{
return Object->DocAllIDBUSINOP_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_DocAllIDBUSINOP_GALLDOC(TFIBLargeIntField * DocAllIDBUSINOP_GALLDOC)
{
Object->DocAllIDBUSINOP_GALLDOC=DocAllIDBUSINOP_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocOstNomImpl::get_DocAllNAME_SPROJECT(void)
{
return Object->DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_DocAllNAME_SPROJECT(TFIBWideStringField * DocAllNAME_SPROJECT)
{
Object->DocAllNAME_SPROJECT=DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocOstNomImpl::get_DocAllNAME_SBUSINESS_OPER(void)
{
return Object->DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_DocAllNAME_SBUSINESS_OPER(TFIBWideStringField * DocAllNAME_SBUSINESS_OPER)
{
Object->DocAllNAME_SBUSINESS_OPER=DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocOstNomImpl::get_DocAllPREFIKS_NUM_GALLDOC(void)
{
return Object->DocAllPREFIKS_NUM_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_DocAllPREFIKS_NUM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_GALLDOC)
{
Object->DocAllPREFIKS_NUM_GALLDOC=DocAllPREFIKS_NUM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocOstNomImpl::get_DocTARTNOM(void)
{
return Object->DocTARTNOM;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_DocTARTNOM(TFIBWideStringField * DocTARTNOM)
{
Object->DocTARTNOM=DocTARTNOM;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocOstNomImpl::get_DocTCODENOM(void)
{
return Object->DocTCODENOM;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_DocTCODENOM(TFIBIntegerField * DocTCODENOM)
{
Object->DocTCODENOM=DocTCODENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocOstNomImpl::get_DocTSHED(void)
{
return Object->DocTSHED;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_DocTSHED(TFIBWideStringField * DocTSHED)
{
Object->DocTSHED=DocTSHED;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocOstNomImpl::get_TypeNom(void)
{
return Object->TypeNom;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_TypeNom(TpFIBDataSet * TypeNom)
{
Object->TypeNom=TypeNom;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocOstNomImpl::get_TypeNomID_STNOM(void)
{
return Object->TypeNomID_STNOM;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_TypeNomID_STNOM(TFIBLargeIntField * TypeNomID_STNOM)
{
Object->TypeNomID_STNOM=TypeNomID_STNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocOstNomImpl::get_TypeNomNAME_STNOM(void)
{
return Object->TypeNomNAME_STNOM;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_TypeNomNAME_STNOM(TFIBWideStringField * TypeNomNAME_STNOM)
{
Object->TypeNomNAME_STNOM=TypeNomNAME_STNOM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocOstNomImpl::get_DocTIDTNOM_DOSNT(void)
{
return Object->DocTIDTNOM_DOSNT;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_DocTIDTNOM_DOSNT(TFIBLargeIntField * DocTIDTNOM_DOSNT)
{
Object->DocTIDTNOM_DOSNT=DocTIDTNOM_DOSNT;
}
//---------------------------------------------------------------
TStringField * TDMDocOstNomImpl::get_DocTNAME_TYPE_NOM(void)
{
return Object->DocTNAME_TYPE_NOM;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_DocTNAME_TYPE_NOM(TStringField * DocTNAME_TYPE_NOM)
{
Object->DocTNAME_TYPE_NOM=DocTNAME_TYPE_NOM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocOstNomImpl::get_DocAllIDOBJECT_GALLDOC(void)
{
return Object->DocAllIDOBJECT_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_DocAllIDOBJECT_GALLDOC(TFIBLargeIntField * DocAllIDOBJECT_GALLDOC)
{
Object->DocAllIDOBJECT_GALLDOC=DocAllIDOBJECT_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocOstNomImpl::get_DocAllNAME_SOBJECT(void)
{
return Object->DocAllNAME_SOBJECT;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_DocAllNAME_SOBJECT(TFIBWideStringField * DocAllNAME_SOBJECT)
{
Object->DocAllNAME_SOBJECT=DocAllNAME_SOBJECT;
}
//---------------------------------------------------------------
bool TDMDocOstNomImpl::get_NewElement(void)
{
return Object->NewElement;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_NewElement(bool NewElement)
{
Object->NewElement=NewElement;
}
//---------------------------------------------------------------
bool TDMDocOstNomImpl::get_Prosmotr(void)
{
return Object->Prosmotr;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_Prosmotr(bool Prosmotr)
{
Object->Prosmotr=Prosmotr;
}
//---------------------------------------------------------------
__int64 TDMDocOstNomImpl::get_IdDoc(void)
{
return Object->IdDoc;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_IdDoc(__int64 IdDoc)
{
Object->IdDoc=IdDoc;
}
//---------------------------------------------------------------
__int64 TDMDocOstNomImpl::get_IdGrp(void)
{
return Object->IdGrp;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_IdGrp(__int64 IdGrp)
{
Object->IdGrp=IdGrp;
}
//---------------------------------------------------------------
__int64 TDMDocOstNomImpl::get_IdElementaMaster(void)
{
return Object->IdElementaMaster;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_IdElementaMaster(__int64 IdElementaMaster)
{
Object->IdElementaMaster=IdElementaMaster;
}
//---------------------------------------------------------------
bool TDMDocOstNomImpl::get_SkladRozn(void)
{
return Object->SkladRozn;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_SkladRozn(bool SkladRozn)
{
Object->SkladRozn=SkladRozn;
}
//---------------------------------------------------------------
bool TDMDocOstNomImpl::get_EnableDvReg(void)
{
return Object->EnableDvReg;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::set_EnableDvReg(bool EnableDvReg)
{
Object->EnableDvReg=EnableDvReg;
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::NewDoc(void)
{
return Object->NewDoc();
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::OpenDoc(__int64 id_doc)
{
return Object->OpenDoc(id_doc);
}
//---------------------------------------------------------------
bool TDMDocOstNomImpl::SaveDoc(void)
{
return Object->SaveDoc();
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::CloseDoc(void)
{
return Object->CloseDoc();
}
//---------------------------------------------------------------
bool TDMDocOstNomImpl::DvRegDoc(void)
{
return Object->DvRegDoc();
}
//---------------------------------------------------------------
bool TDMDocOstNomImpl::CancelDvRegDoc(void)
{
return Object->CancelDvRegDoc();
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::AddDocNewString(void)
{
return Object->AddDocNewString();
}
//---------------------------------------------------------------
void TDMDocOstNomImpl::DeleteStringDoc(void)
{
return Object->DeleteStringDoc();
}
//---------------------------------------------------------------
bool TDMDocOstNomImpl::DeleteDoc(__int64 id)
{
return Object->DeleteDoc(id);
}
//---------------------------------------------------------------
__int64 TDMDocOstNomImpl::GetIDDocPoNomeruDoc(int number_doc, TDate date_doc)
{
return Object->GetIDDocPoNomeruDoc(number_doc, date_doc);
}
//---------------------------------------------------------------
bool TDMDocOstNomImpl::AddDataInv(void)
{
return Object->AddDataInv();
}
//---------------------------------------------------------------
bool TDMDocOstNomImpl::SearchStringPoNom(__int64 id_nom)
{
return Object->SearchStringPoNom(id_nom);
}
//---------------------------------------------------------------
int TDMDocOstNomImpl::GetNumberNewDoc(void)
{
return Object->GetNumberNewDoc();
}
//---------------------------------------------------------------
