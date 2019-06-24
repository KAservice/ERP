#include "vcl.h"
#pragma hdrstop


#include "UDMDocRealImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMDocRealImpl::TDMDocRealImpl()           
{                                            
Object=new TDMDocReal(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMDocRealImpl::~TDMDocRealImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMDocRealImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMDocRealImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMDocReal)                        
   {                                                                     
   *ppv=static_cast<IDMDocReal*> (this);                                
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
int TDMDocRealImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMDocRealImpl::kanRelease(void)                                  
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
int  TDMDocRealImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMDocRealImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMDocRealImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMDocRealImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMDocRealImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMDocRealImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMDocRealImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMDocReal
TDataSource * TDMDocRealImpl::get_DataSourceDoc(void)
{
return Object->DataSourceDoc;
}
//---------------------------------------------------------------
void TDMDocRealImpl::set_DataSourceDoc(TDataSource * DataSourceDoc)
{
Object->DataSourceDoc=DataSourceDoc;
}
//---------------------------------------------------------------
TDataSource * TDMDocRealImpl::get_DataSourceDocT(void)
{
return Object->DataSourceDocT;
}
//---------------------------------------------------------------
void TDMDocRealImpl::set_DataSourceDocT(TDataSource * DataSourceDocT)
{
Object->DataSourceDocT=DataSourceDocT;
}
//---------------------------------------------------------------
TDataSource * TDMDocRealImpl::get_DataSourceDocAll(void)
{
return Object->DataSourceDocAll;
}
//---------------------------------------------------------------
void TDMDocRealImpl::set_DataSourceDocAll(TDataSource * DataSourceDocAll)
{
Object->DataSourceDocAll=DataSourceDocAll;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocRealImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMDocRealImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocRealImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMDocRealImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocRealImpl::get_DocAll(void)
{
return Object->DocAll;
}
//---------------------------------------------------------------
void TDMDocRealImpl::set_DocAll(TpFIBDataSet * DocAll)
{
Object->DocAll=DocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocRealImpl::get_Doc(void)
{
return Object->Doc;
}
//---------------------------------------------------------------
void TDMDocRealImpl::set_Doc(TpFIBDataSet * Doc)
{
Object->Doc=Doc;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocRealImpl::get_DocT(void)
{
return Object->DocT;
}
//---------------------------------------------------------------
void TDMDocRealImpl::set_DocT(TpFIBDataSet * DocT)
{
Object->DocT=DocT;
}
//---------------------------------------------------------------
TFIBDateTimeField * TDMDocRealImpl::get_DocAllPOSDOC(void)
{
return Object->DocAllPOSDOC;
}
//---------------------------------------------------------------
void TDMDocRealImpl::set_DocAllPOSDOC(TFIBDateTimeField * DocAllPOSDOC)
{
Object->DocAllPOSDOC=DocAllPOSDOC;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMDocRealImpl::get_DocAllPRDOC(void)
{
return Object->DocAllPRDOC;
}
//---------------------------------------------------------------
void TDMDocRealImpl::set_DocAllPRDOC(TFIBSmallIntField * DocAllPRDOC)
{
Object->DocAllPRDOC=DocAllPRDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocRealImpl::get_DocAllNUMDOC(void)
{
return Object->DocAllNUMDOC;
}
//---------------------------------------------------------------
void TDMDocRealImpl::set_DocAllNUMDOC(TFIBIntegerField * DocAllNUMDOC)
{
Object->DocAllNUMDOC=DocAllNUMDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRealImpl::get_DocAllSUMDOC(void)
{
return Object->DocAllSUMDOC;
}
//---------------------------------------------------------------
void TDMDocRealImpl::set_DocAllSUMDOC(TFIBBCDField * DocAllSUMDOC)
{
Object->DocAllSUMDOC=DocAllSUMDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRealImpl::get_DocTKOLREAT(void)
{
return Object->DocTKOLREAT;
}
//---------------------------------------------------------------
void TDMDocRealImpl::set_DocTKOLREAT(TFIBBCDField * DocTKOLREAT)
{
Object->DocTKOLREAT=DocTKOLREAT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRealImpl::get_DocTKFREAT(void)
{
return Object->DocTKFREAT;
}
//---------------------------------------------------------------
void TDMDocRealImpl::set_DocTKFREAT(TFIBBCDField * DocTKFREAT)
{
Object->DocTKFREAT=DocTKFREAT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRealImpl::get_DocTPRICEREAT(void)
{
return Object->DocTPRICEREAT;
}
//---------------------------------------------------------------
void TDMDocRealImpl::set_DocTPRICEREAT(TFIBBCDField * DocTPRICEREAT)
{
Object->DocTPRICEREAT=DocTPRICEREAT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRealImpl::get_DocTSUMREAT(void)
{
return Object->DocTSUMREAT;
}
//---------------------------------------------------------------
void TDMDocRealImpl::set_DocTSUMREAT(TFIBBCDField * DocTSUMREAT)
{
Object->DocTSUMREAT=DocTSUMREAT;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocRealImpl::get_IBTrDvReg(void)
{
return Object->IBTrDvReg;
}
//---------------------------------------------------------------
void TDMDocRealImpl::set_IBTrDvReg(TpFIBTransaction * IBTrDvReg)
{
Object->IBTrDvReg=IBTrDvReg;
}
//---------------------------------------------------------------
TpFIBQuery * TDMDocRealImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TDMDocRealImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TIntegerField * TDMDocRealImpl::get_DocTRECNO(void)
{
return Object->DocTRECNO;
}
//---------------------------------------------------------------
void TDMDocRealImpl::set_DocTRECNO(TIntegerField * DocTRECNO)
{
Object->DocTRECNO=DocTRECNO;
}
//---------------------------------------------------------------
TpFIBQuery * TDMDocRealImpl::get_QueryCancelDvReg(void)
{
return Object->QueryCancelDvReg;
}
//---------------------------------------------------------------
void TDMDocRealImpl::set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg)
{
Object->QueryCancelDvReg=QueryCancelDvReg;
}
//---------------------------------------------------------------
TpFIBQuery * TDMDocRealImpl::get_QueryDvReg(void)
{
return Object->QueryDvReg;
}
//---------------------------------------------------------------
void TDMDocRealImpl::set_QueryDvReg(TpFIBQuery * QueryDvReg)
{
Object->QueryDvReg=QueryDvReg;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocRealImpl::get_NumDoc(void)
{
return Object->NumDoc;
}
//---------------------------------------------------------------
void TDMDocRealImpl::set_NumDoc(TpFIBDataSet * NumDoc)
{
Object->NumDoc=NumDoc;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRealImpl::get_DocAllIDDOC(void)
{
return Object->DocAllIDDOC;
}
//---------------------------------------------------------------
void TDMDocRealImpl::set_DocAllIDDOC(TFIBLargeIntField * DocAllIDDOC)
{
Object->DocAllIDDOC=DocAllIDDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRealImpl::get_DocAllIDFIRMDOC(void)
{
return Object->DocAllIDFIRMDOC;
}
//---------------------------------------------------------------
void TDMDocRealImpl::set_DocAllIDFIRMDOC(TFIBLargeIntField * DocAllIDFIRMDOC)
{
Object->DocAllIDFIRMDOC=DocAllIDFIRMDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRealImpl::get_DocAllIDSKLDOC(void)
{
return Object->DocAllIDSKLDOC;
}
//---------------------------------------------------------------
void TDMDocRealImpl::set_DocAllIDSKLDOC(TFIBLargeIntField * DocAllIDSKLDOC)
{
Object->DocAllIDSKLDOC=DocAllIDSKLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRealImpl::get_DocAllIDKLDOC(void)
{
return Object->DocAllIDKLDOC;
}
//---------------------------------------------------------------
void TDMDocRealImpl::set_DocAllIDKLDOC(TFIBLargeIntField * DocAllIDKLDOC)
{
Object->DocAllIDKLDOC=DocAllIDKLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRealImpl::get_DocAllIDDOGDOC(void)
{
return Object->DocAllIDDOGDOC;
}
//---------------------------------------------------------------
void TDMDocRealImpl::set_DocAllIDDOGDOC(TFIBLargeIntField * DocAllIDDOGDOC)
{
Object->DocAllIDDOGDOC=DocAllIDDOGDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRealImpl::get_DocAllIDUSERDOC(void)
{
return Object->DocAllIDUSERDOC;
}
//---------------------------------------------------------------
void TDMDocRealImpl::set_DocAllIDUSERDOC(TFIBLargeIntField * DocAllIDUSERDOC)
{
Object->DocAllIDUSERDOC=DocAllIDUSERDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRealImpl::get_DocAllGID_DOC(void)
{
return Object->DocAllGID_DOC;
}
//---------------------------------------------------------------
void TDMDocRealImpl::set_DocAllGID_DOC(TFIBWideStringField * DocAllGID_DOC)
{
Object->DocAllGID_DOC=DocAllGID_DOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRealImpl::get_DocAllPREFIKSDOC(void)
{
return Object->DocAllPREFIKSDOC;
}
//---------------------------------------------------------------
void TDMDocRealImpl::set_DocAllPREFIKSDOC(TFIBWideStringField * DocAllPREFIKSDOC)
{
Object->DocAllPREFIKSDOC=DocAllPREFIKSDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRealImpl::get_DocAllIDDOCOSNDOC(void)
{
return Object->DocAllIDDOCOSNDOC;
}
//---------------------------------------------------------------
void TDMDocRealImpl::set_DocAllIDDOCOSNDOC(TFIBLargeIntField * DocAllIDDOCOSNDOC)
{
Object->DocAllIDDOCOSNDOC=DocAllIDDOCOSNDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRealImpl::get_DocAllIDEXTDOC(void)
{
return Object->DocAllIDEXTDOC;
}
//---------------------------------------------------------------
void TDMDocRealImpl::set_DocAllIDEXTDOC(TFIBLargeIntField * DocAllIDEXTDOC)
{
Object->DocAllIDEXTDOC=DocAllIDEXTDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocRealImpl::get_DocAllTYPEEXTDOC(void)
{
return Object->DocAllTYPEEXTDOC;
}
//---------------------------------------------------------------
void TDMDocRealImpl::set_DocAllTYPEEXTDOC(TFIBIntegerField * DocAllTYPEEXTDOC)
{
Object->DocAllTYPEEXTDOC=DocAllTYPEEXTDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRealImpl::get_DocAllIDBASE_GALLDOC(void)
{
return Object->DocAllIDBASE_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocRealImpl::set_DocAllIDBASE_GALLDOC(TFIBLargeIntField * DocAllIDBASE_GALLDOC)
{
Object->DocAllIDBASE_GALLDOC=DocAllIDBASE_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRealImpl::get_DocAllIDPROJECT_GALLDOC(void)
{
return Object->DocAllIDPROJECT_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocRealImpl::set_DocAllIDPROJECT_GALLDOC(TFIBLargeIntField * DocAllIDPROJECT_GALLDOC)
{
Object->DocAllIDPROJECT_GALLDOC=DocAllIDPROJECT_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRealImpl::get_DocAllNAME_SINFBASE_OBMEN(void)
{
return Object->DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void TDMDocRealImpl::set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN)
{
Object->DocAllNAME_SINFBASE_OBMEN=DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRealImpl::get_DocAllNAMEFIRM(void)
{
return Object->DocAllNAMEFIRM;
}
//---------------------------------------------------------------
void TDMDocRealImpl::set_DocAllNAMEFIRM(TFIBWideStringField * DocAllNAMEFIRM)
{
Object->DocAllNAMEFIRM=DocAllNAMEFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRealImpl::get_DocAllNAMESKLAD(void)
{
return Object->DocAllNAMESKLAD;
}
//---------------------------------------------------------------
void TDMDocRealImpl::set_DocAllNAMESKLAD(TFIBWideStringField * DocAllNAMESKLAD)
{
Object->DocAllNAMESKLAD=DocAllNAMESKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRealImpl::get_DocAllNAMEKLIENT(void)
{
return Object->DocAllNAMEKLIENT;
}
//---------------------------------------------------------------
void TDMDocRealImpl::set_DocAllNAMEKLIENT(TFIBWideStringField * DocAllNAMEKLIENT)
{
Object->DocAllNAMEKLIENT=DocAllNAMEKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRealImpl::get_DocAllFNAME_USER(void)
{
return Object->DocAllFNAME_USER;
}
//---------------------------------------------------------------
void TDMDocRealImpl::set_DocAllFNAME_USER(TFIBWideStringField * DocAllFNAME_USER)
{
Object->DocAllFNAME_USER=DocAllFNAME_USER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRealImpl::get_DocIDREA(void)
{
return Object->DocIDREA;
}
//---------------------------------------------------------------
void TDMDocRealImpl::set_DocIDREA(TFIBLargeIntField * DocIDREA)
{
Object->DocIDREA=DocIDREA;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRealImpl::get_DocIDDOCREA(void)
{
return Object->DocIDDOCREA;
}
//---------------------------------------------------------------
void TDMDocRealImpl::set_DocIDDOCREA(TFIBLargeIntField * DocIDDOCREA)
{
Object->DocIDDOCREA=DocIDDOCREA;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRealImpl::get_DocPRIMREA(void)
{
return Object->DocPRIMREA;
}
//---------------------------------------------------------------
void TDMDocRealImpl::set_DocPRIMREA(TFIBWideStringField * DocPRIMREA)
{
Object->DocPRIMREA=DocPRIMREA;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRealImpl::get_DocGID_DREA(void)
{
return Object->DocGID_DREA;
}
//---------------------------------------------------------------
void TDMDocRealImpl::set_DocGID_DREA(TFIBWideStringField * DocGID_DREA)
{
Object->DocGID_DREA=DocGID_DREA;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRealImpl::get_DocIDTPRICEREA(void)
{
return Object->DocIDTPRICEREA;
}
//---------------------------------------------------------------
void TDMDocRealImpl::set_DocIDTPRICEREA(TFIBLargeIntField * DocIDTPRICEREA)
{
Object->DocIDTPRICEREA=DocIDTPRICEREA;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRealImpl::get_DocIDGRPOLREA(void)
{
return Object->DocIDGRPOLREA;
}
//---------------------------------------------------------------
void TDMDocRealImpl::set_DocIDGRPOLREA(TFIBLargeIntField * DocIDGRPOLREA)
{
Object->DocIDGRPOLREA=DocIDGRPOLREA;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRealImpl::get_DocIDBSCHETREA(void)
{
return Object->DocIDBSCHETREA;
}
//---------------------------------------------------------------
void TDMDocRealImpl::set_DocIDBSCHETREA(TFIBLargeIntField * DocIDBSCHETREA)
{
Object->DocIDBSCHETREA=DocIDBSCHETREA;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRealImpl::get_DocIDBASE_DREA(void)
{
return Object->DocIDBASE_DREA;
}
//---------------------------------------------------------------
void TDMDocRealImpl::set_DocIDBASE_DREA(TFIBLargeIntField * DocIDBASE_DREA)
{
Object->DocIDBASE_DREA=DocIDBASE_DREA;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRealImpl::get_DocNAME_TPRICE(void)
{
return Object->DocNAME_TPRICE;
}
//---------------------------------------------------------------
void TDMDocRealImpl::set_DocNAME_TPRICE(TFIBWideStringField * DocNAME_TPRICE)
{
Object->DocNAME_TPRICE=DocNAME_TPRICE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRealImpl::get_DocNAMEKLIENT(void)
{
return Object->DocNAMEKLIENT;
}
//---------------------------------------------------------------
void TDMDocRealImpl::set_DocNAMEKLIENT(TFIBWideStringField * DocNAMEKLIENT)
{
Object->DocNAMEKLIENT=DocNAMEKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRealImpl::get_DocNAMEBSCHET(void)
{
return Object->DocNAMEBSCHET;
}
//---------------------------------------------------------------
void TDMDocRealImpl::set_DocNAMEBSCHET(TFIBWideStringField * DocNAMEBSCHET)
{
Object->DocNAMEBSCHET=DocNAMEBSCHET;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRealImpl::get_DocTIDREAT(void)
{
return Object->DocTIDREAT;
}
//---------------------------------------------------------------
void TDMDocRealImpl::set_DocTIDREAT(TFIBLargeIntField * DocTIDREAT)
{
Object->DocTIDREAT=DocTIDREAT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRealImpl::get_DocTIDDOCREAT(void)
{
return Object->DocTIDDOCREAT;
}
//---------------------------------------------------------------
void TDMDocRealImpl::set_DocTIDDOCREAT(TFIBLargeIntField * DocTIDDOCREAT)
{
Object->DocTIDDOCREAT=DocTIDDOCREAT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRealImpl::get_DocTIDNOMREAT(void)
{
return Object->DocTIDNOMREAT;
}
//---------------------------------------------------------------
void TDMDocRealImpl::set_DocTIDNOMREAT(TFIBLargeIntField * DocTIDNOMREAT)
{
Object->DocTIDNOMREAT=DocTIDNOMREAT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRealImpl::get_DocTIDEDREAT(void)
{
return Object->DocTIDEDREAT;
}
//---------------------------------------------------------------
void TDMDocRealImpl::set_DocTIDEDREAT(TFIBLargeIntField * DocTIDEDREAT)
{
Object->DocTIDEDREAT=DocTIDEDREAT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRealImpl::get_DocTGID_DREAT(void)
{
return Object->DocTGID_DREAT;
}
//---------------------------------------------------------------
void TDMDocRealImpl::set_DocTGID_DREAT(TFIBWideStringField * DocTGID_DREAT)
{
Object->DocTGID_DREAT=DocTGID_DREAT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRealImpl::get_DocTIDBASE_DREAT(void)
{
return Object->DocTIDBASE_DREAT;
}
//---------------------------------------------------------------
void TDMDocRealImpl::set_DocTIDBASE_DREAT(TFIBLargeIntField * DocTIDBASE_DREAT)
{
Object->DocTIDBASE_DREAT=DocTIDBASE_DREAT;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocRealImpl::get_DocTNDS_DREAT(void)
{
return Object->DocTNDS_DREAT;
}
//---------------------------------------------------------------
void TDMDocRealImpl::set_DocTNDS_DREAT(TFIBIntegerField * DocTNDS_DREAT)
{
Object->DocTNDS_DREAT=DocTNDS_DREAT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRealImpl::get_DocTSUMNDS_DREAT(void)
{
return Object->DocTSUMNDS_DREAT;
}
//---------------------------------------------------------------
void TDMDocRealImpl::set_DocTSUMNDS_DREAT(TFIBBCDField * DocTSUMNDS_DREAT)
{
Object->DocTSUMNDS_DREAT=DocTSUMNDS_DREAT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRealImpl::get_DocTNAMENOM(void)
{
return Object->DocTNAMENOM;
}
//---------------------------------------------------------------
void TDMDocRealImpl::set_DocTNAMENOM(TFIBWideStringField * DocTNAMENOM)
{
Object->DocTNAMENOM=DocTNAMENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRealImpl::get_DocTNAMEED(void)
{
return Object->DocTNAMEED;
}
//---------------------------------------------------------------
void TDMDocRealImpl::set_DocTNAMEED(TFIBWideStringField * DocTNAMEED)
{
Object->DocTNAMEED=DocTNAMEED;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMDocRealImpl::get_DocTTNOM(void)
{
return Object->DocTTNOM;
}
//---------------------------------------------------------------
void TDMDocRealImpl::set_DocTTNOM(TFIBSmallIntField * DocTTNOM)
{
Object->DocTTNOM=DocTTNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRealImpl::get_DocAllTDOC(void)
{
return Object->DocAllTDOC;
}
//---------------------------------------------------------------
void TDMDocRealImpl::set_DocAllTDOC(TFIBWideStringField * DocAllTDOC)
{
Object->DocAllTDOC=DocAllTDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRealImpl::get_DocAllIDBUSINOP_GALLDOC(void)
{
return Object->DocAllIDBUSINOP_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocRealImpl::set_DocAllIDBUSINOP_GALLDOC(TFIBLargeIntField * DocAllIDBUSINOP_GALLDOC)
{
Object->DocAllIDBUSINOP_GALLDOC=DocAllIDBUSINOP_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRealImpl::get_DocAllNAME_SPROJECT(void)
{
return Object->DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
void TDMDocRealImpl::set_DocAllNAME_SPROJECT(TFIBWideStringField * DocAllNAME_SPROJECT)
{
Object->DocAllNAME_SPROJECT=DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRealImpl::get_DocAllNAME_SBUSINESS_OPER(void)
{
return Object->DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
void TDMDocRealImpl::set_DocAllNAME_SBUSINESS_OPER(TFIBWideStringField * DocAllNAME_SBUSINESS_OPER)
{
Object->DocAllNAME_SBUSINESS_OPER=DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRealImpl::get_DocIDRSCHETKLIENT_DREA(void)
{
return Object->DocIDRSCHETKLIENT_DREA;
}
//---------------------------------------------------------------
void TDMDocRealImpl::set_DocIDRSCHETKLIENT_DREA(TFIBLargeIntField * DocIDRSCHETKLIENT_DREA)
{
Object->DocIDRSCHETKLIENT_DREA=DocIDRSCHETKLIENT_DREA;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRealImpl::get_DocIDRSCHETGRPOL_DREA(void)
{
return Object->DocIDRSCHETGRPOL_DREA;
}
//---------------------------------------------------------------
void TDMDocRealImpl::set_DocIDRSCHETGRPOL_DREA(TFIBLargeIntField * DocIDRSCHETGRPOL_DREA)
{
Object->DocIDRSCHETGRPOL_DREA=DocIDRSCHETGRPOL_DREA;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRealImpl::get_DocNAME_RSCHET_KLIENT(void)
{
return Object->DocNAME_RSCHET_KLIENT;
}
//---------------------------------------------------------------
void TDMDocRealImpl::set_DocNAME_RSCHET_KLIENT(TFIBWideStringField * DocNAME_RSCHET_KLIENT)
{
Object->DocNAME_RSCHET_KLIENT=DocNAME_RSCHET_KLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRealImpl::get_DocNAME_RSCHET_GRPOL(void)
{
return Object->DocNAME_RSCHET_GRPOL;
}
//---------------------------------------------------------------
void TDMDocRealImpl::set_DocNAME_RSCHET_GRPOL(TFIBWideStringField * DocNAME_RSCHET_GRPOL)
{
Object->DocNAME_RSCHET_GRPOL=DocNAME_RSCHET_GRPOL;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRealImpl::get_DocAllPREFIKS_NUM_GALLDOC(void)
{
return Object->DocAllPREFIKS_NUM_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocRealImpl::set_DocAllPREFIKS_NUM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_GALLDOC)
{
Object->DocAllPREFIKS_NUM_GALLDOC=DocAllPREFIKS_NUM_GALLDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRealImpl::get_DocTSUMSK_DREAT(void)
{
return Object->DocTSUMSK_DREAT;
}
//---------------------------------------------------------------
void TDMDocRealImpl::set_DocTSUMSK_DREAT(TFIBBCDField * DocTSUMSK_DREAT)
{
Object->DocTSUMSK_DREAT=DocTSUMSK_DREAT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRealImpl::get_DocTPRSK_CARD_DREAT(void)
{
return Object->DocTPRSK_CARD_DREAT;
}
//---------------------------------------------------------------
void TDMDocRealImpl::set_DocTPRSK_CARD_DREAT(TFIBBCDField * DocTPRSK_CARD_DREAT)
{
Object->DocTPRSK_CARD_DREAT=DocTPRSK_CARD_DREAT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRealImpl::get_DocTPRSK_AUTO_DREAT(void)
{
return Object->DocTPRSK_AUTO_DREAT;
}
//---------------------------------------------------------------
void TDMDocRealImpl::set_DocTPRSK_AUTO_DREAT(TFIBBCDField * DocTPRSK_AUTO_DREAT)
{
Object->DocTPRSK_AUTO_DREAT=DocTPRSK_AUTO_DREAT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRealImpl::get_DocTPRSK_HAND_DREAT(void)
{
return Object->DocTPRSK_HAND_DREAT;
}
//---------------------------------------------------------------
void TDMDocRealImpl::set_DocTPRSK_HAND_DREAT(TFIBBCDField * DocTPRSK_HAND_DREAT)
{
Object->DocTPRSK_HAND_DREAT=DocTPRSK_HAND_DREAT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRealImpl::get_DocTPRSK_DREAT(void)
{
return Object->DocTPRSK_DREAT;
}
//---------------------------------------------------------------
void TDMDocRealImpl::set_DocTPRSK_DREAT(TFIBBCDField * DocTPRSK_DREAT)
{
Object->DocTPRSK_DREAT=DocTPRSK_DREAT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRealImpl::get_DocTNO_SK_DREAT(void)
{
return Object->DocTNO_SK_DREAT;
}
//---------------------------------------------------------------
void TDMDocRealImpl::set_DocTNO_SK_DREAT(TFIBBCDField * DocTNO_SK_DREAT)
{
Object->DocTNO_SK_DREAT=DocTNO_SK_DREAT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRealImpl::get_DocTARTNOM(void)
{
return Object->DocTARTNOM;
}
//---------------------------------------------------------------
void TDMDocRealImpl::set_DocTARTNOM(TFIBWideStringField * DocTARTNOM)
{
Object->DocTARTNOM=DocTARTNOM;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocRealImpl::get_DocTCODENOM(void)
{
return Object->DocTCODENOM;
}
//---------------------------------------------------------------
void TDMDocRealImpl::set_DocTCODENOM(TFIBIntegerField * DocTCODENOM)
{
Object->DocTCODENOM=DocTCODENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRealImpl::get_DocTSHED(void)
{
return Object->DocTSHED;
}
//---------------------------------------------------------------
void TDMDocRealImpl::set_DocTSHED(TFIBWideStringField * DocTSHED)
{
Object->DocTSHED=DocTSHED;
}
//---------------------------------------------------------------
bool TDMDocRealImpl::get_NewElement(void)
{
return Object->NewElement;
}
//---------------------------------------------------------------
void TDMDocRealImpl::set_NewElement(bool NewElement)
{
Object->NewElement=NewElement;
}
//---------------------------------------------------------------
bool TDMDocRealImpl::get_Prosmotr(void)
{
return Object->Prosmotr;
}
//---------------------------------------------------------------
void TDMDocRealImpl::set_Prosmotr(bool Prosmotr)
{
Object->Prosmotr=Prosmotr;
}
//---------------------------------------------------------------
bool TDMDocRealImpl::get_NoEdit(void)
{
return Object->NoEdit;
}
//---------------------------------------------------------------
void TDMDocRealImpl::set_NoEdit(bool NoEdit)
{
Object->NoEdit=NoEdit;
}
//---------------------------------------------------------------
__int64 TDMDocRealImpl::get_IdDoc(void)
{
return Object->IdDoc;
}
//---------------------------------------------------------------
void TDMDocRealImpl::set_IdDoc(__int64 IdDoc)
{
Object->IdDoc=IdDoc;
}
//---------------------------------------------------------------
double TDMDocRealImpl::get_SummaDoc(void)
{
return Object->SummaDoc;
}
//---------------------------------------------------------------
void TDMDocRealImpl::set_SummaDoc(double SummaDoc)
{
Object->SummaDoc=SummaDoc;
}
//---------------------------------------------------------------
double TDMDocRealImpl::get_OldSummaStr(void)
{
return Object->OldSummaStr;
}
//---------------------------------------------------------------
void TDMDocRealImpl::set_OldSummaStr(double OldSummaStr)
{
Object->OldSummaStr=OldSummaStr;
}
//---------------------------------------------------------------
double TDMDocRealImpl::get_NewSummaStr(void)
{
return Object->NewSummaStr;
}
//---------------------------------------------------------------
void TDMDocRealImpl::set_NewSummaStr(double NewSummaStr)
{
Object->NewSummaStr=NewSummaStr;
}
//---------------------------------------------------------------
int TDMDocRealImpl::get_IdSklad(void)
{
return Object->IdSklad;
}
//---------------------------------------------------------------
void TDMDocRealImpl::set_IdSklad(int IdSklad)
{
Object->IdSklad=IdSklad;
}
//---------------------------------------------------------------
bool TDMDocRealImpl::get_AutoRaschet(void)
{
return Object->AutoRaschet;
}
//---------------------------------------------------------------
void TDMDocRealImpl::set_AutoRaschet(bool AutoRaschet)
{
Object->AutoRaschet=AutoRaschet;
}
//---------------------------------------------------------------
bool TDMDocRealImpl::get_EnableDvReg(void)
{
return Object->EnableDvReg;
}
//---------------------------------------------------------------
void TDMDocRealImpl::set_EnableDvReg(bool EnableDvReg)
{
Object->EnableDvReg=EnableDvReg;
}
//---------------------------------------------------------------
bool TDMDocRealImpl::get_SkladRozn(void)
{
return Object->SkladRozn;
}
//---------------------------------------------------------------
void TDMDocRealImpl::set_SkladRozn(bool SkladRozn)
{
Object->SkladRozn=SkladRozn;
}
//---------------------------------------------------------------
bool TDMDocRealImpl::get_NoOtrOstatok(void)
{
return Object->NoOtrOstatok;
}
//---------------------------------------------------------------
void TDMDocRealImpl::set_NoOtrOstatok(bool NoOtrOstatok)
{
Object->NoOtrOstatok=NoOtrOstatok;
}
//---------------------------------------------------------------
void TDMDocRealImpl::NewDoc(void)
{
return Object->NewDoc();
}
//---------------------------------------------------------------
void TDMDocRealImpl::OpenDoc(__int64 IdDoc)
{
return Object->OpenDoc(IdDoc);
}
//---------------------------------------------------------------
bool TDMDocRealImpl::SaveDoc(void)
{
return Object->SaveDoc();
}
//---------------------------------------------------------------
bool TDMDocRealImpl::DvRegDoc(void)
{
return Object->DvRegDoc();
}
//---------------------------------------------------------------
bool TDMDocRealImpl::CancelDvRegDoc(void)
{
return Object->CancelDvRegDoc();
}
//---------------------------------------------------------------
void TDMDocRealImpl::AddDocNewString(void)
{
return Object->AddDocNewString();
}
//---------------------------------------------------------------
void TDMDocRealImpl::DeleteStringDoc(void)
{
return Object->DeleteStringDoc();
}
//---------------------------------------------------------------
void TDMDocRealImpl::CloseDoc(void)
{
return Object->CloseDoc();
}
//---------------------------------------------------------------
bool TDMDocRealImpl::DeleteDoc(__int64 id)
{
return Object->DeleteDoc( id);
}
//---------------------------------------------------------------
__int64 TDMDocRealImpl::GetIDDocPoNomeruDoc(int number_doc, TDate date_doc)
{
return Object->GetIDDocPoNomeruDoc(number_doc, date_doc);
}
//---------------------------------------------------------------
__int64 TDMDocRealImpl::GetIDDocSchetFact(void)
{
return Object->GetIDDocSchetFact();
}
//---------------------------------------------------------------
int TDMDocRealImpl::GetNumberNewDoc(void)
{
return Object->GetNumberNewDoc();
}
//---------------------------------------------------------------
