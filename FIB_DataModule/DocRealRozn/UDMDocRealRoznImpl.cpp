#include "vcl.h"
#pragma hdrstop


#include "UDMDocRealRoznImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMDocRealRoznImpl::TDMDocRealRoznImpl()           
{                                            
Object=new TDMDocRealRozn(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMDocRealRoznImpl::~TDMDocRealRoznImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMDocRealRoznImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMDocRealRoznImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMDocRealRozn)                        
   {                                                                     
   *ppv=static_cast<IDMDocRealRozn*> (this);                                
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
int TDMDocRealRoznImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMDocRealRoznImpl::kanRelease(void)                                  
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
int  TDMDocRealRoznImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMDocRealRoznImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMDocRealRoznImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMDocRealRoznImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMDocRealRoznImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMDocRealRoznImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMDocRealRoznImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMDocRealRozn
TDataSource * TDMDocRealRoznImpl::get_DataSourceDoc(void)
{
return Object->DataSourceDoc;
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::set_DataSourceDoc(TDataSource * DataSourceDoc)
{
Object->DataSourceDoc=DataSourceDoc;
}
//---------------------------------------------------------------
TDataSource * TDMDocRealRoznImpl::get_DataSourceDocT(void)
{
return Object->DataSourceDocT;
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::set_DataSourceDocT(TDataSource * DataSourceDocT)
{
Object->DataSourceDocT=DataSourceDocT;
}
//---------------------------------------------------------------
TDataSource * TDMDocRealRoznImpl::get_DataSourceDocAll(void)
{
return Object->DataSourceDocAll;
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::set_DataSourceDocAll(TDataSource * DataSourceDocAll)
{
Object->DataSourceDocAll=DataSourceDocAll;
}
//---------------------------------------------------------------
TDataSource * TDMDocRealRoznImpl::get_DataSourcePay(void)
{
return Object->DataSourcePay;
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::set_DataSourcePay(TDataSource * DataSourcePay)
{
Object->DataSourcePay=DataSourcePay;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocRealRoznImpl::get_DocAll(void)
{
return Object->DocAll;
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::set_DocAll(TpFIBDataSet * DocAll)
{
Object->DocAll=DocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocRealRoznImpl::get_Doc(void)
{
return Object->Doc;
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::set_Doc(TpFIBDataSet * Doc)
{
Object->Doc=Doc;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocRealRoznImpl::get_DocT(void)
{
return Object->DocT;
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::set_DocT(TpFIBDataSet * DocT)
{
Object->DocT=DocT;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocRealRoznImpl::get_Pay(void)
{
return Object->Pay;
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::set_Pay(TpFIBDataSet * Pay)
{
Object->Pay=Pay;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocRealRoznImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocRealRoznImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRealRoznImpl::get_DocFIRSTSUM_DREALROZN(void)
{
return Object->DocFIRSTSUM_DREALROZN;
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::set_DocFIRSTSUM_DREALROZN(TFIBBCDField * DocFIRSTSUM_DREALROZN)
{
Object->DocFIRSTSUM_DREALROZN=DocFIRSTSUM_DREALROZN;
}
//---------------------------------------------------------------
TFIBDateTimeField * TDMDocRealRoznImpl::get_DocAllPOSDOC(void)
{
return Object->DocAllPOSDOC;
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::set_DocAllPOSDOC(TFIBDateTimeField * DocAllPOSDOC)
{
Object->DocAllPOSDOC=DocAllPOSDOC;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMDocRealRoznImpl::get_DocAllPRDOC(void)
{
return Object->DocAllPRDOC;
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::set_DocAllPRDOC(TFIBSmallIntField * DocAllPRDOC)
{
Object->DocAllPRDOC=DocAllPRDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocRealRoznImpl::get_DocAllNUMDOC(void)
{
return Object->DocAllNUMDOC;
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::set_DocAllNUMDOC(TFIBIntegerField * DocAllNUMDOC)
{
Object->DocAllNUMDOC=DocAllNUMDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRealRoznImpl::get_DocAllSUMDOC(void)
{
return Object->DocAllSUMDOC;
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::set_DocAllSUMDOC(TFIBBCDField * DocAllSUMDOC)
{
Object->DocAllSUMDOC=DocAllSUMDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRealRoznImpl::get_DocTKOL_DREALROZNT(void)
{
return Object->DocTKOL_DREALROZNT;
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::set_DocTKOL_DREALROZNT(TFIBBCDField * DocTKOL_DREALROZNT)
{
Object->DocTKOL_DREALROZNT=DocTKOL_DREALROZNT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRealRoznImpl::get_DocTKF_DREALROZNT(void)
{
return Object->DocTKF_DREALROZNT;
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::set_DocTKF_DREALROZNT(TFIBBCDField * DocTKF_DREALROZNT)
{
Object->DocTKF_DREALROZNT=DocTKF_DREALROZNT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRealRoznImpl::get_DocTPRICE_DREALROZNT(void)
{
return Object->DocTPRICE_DREALROZNT;
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::set_DocTPRICE_DREALROZNT(TFIBBCDField * DocTPRICE_DREALROZNT)
{
Object->DocTPRICE_DREALROZNT=DocTPRICE_DREALROZNT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRealRoznImpl::get_DocTSUM_DREALROZNT(void)
{
return Object->DocTSUM_DREALROZNT;
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::set_DocTSUM_DREALROZNT(TFIBBCDField * DocTSUM_DREALROZNT)
{
Object->DocTSUM_DREALROZNT=DocTSUM_DREALROZNT;
}
//---------------------------------------------------------------
TIntegerField * TDMDocRealRoznImpl::get_DocTRECNO(void)
{
return Object->DocTRECNO;
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::set_DocTRECNO(TIntegerField * DocTRECNO)
{
Object->DocTRECNO=DocTRECNO;
}
//---------------------------------------------------------------
TFIBDateField * TDMDocRealRoznImpl::get_PayDO_DREALROZN_PAY(void)
{
return Object->PayDO_DREALROZN_PAY;
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::set_PayDO_DREALROZN_PAY(TFIBDateField * PayDO_DREALROZN_PAY)
{
Object->PayDO_DREALROZN_PAY=PayDO_DREALROZN_PAY;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRealRoznImpl::get_PaySUM_DREALROZN_PAY(void)
{
return Object->PaySUM_DREALROZN_PAY;
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::set_PaySUM_DREALROZN_PAY(TFIBBCDField * PaySUM_DREALROZN_PAY)
{
Object->PaySUM_DREALROZN_PAY=PaySUM_DREALROZN_PAY;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocRealRoznImpl::get_NumDoc(void)
{
return Object->NumDoc;
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::set_NumDoc(TpFIBDataSet * NumDoc)
{
Object->NumDoc=NumDoc;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocRealRoznImpl::get_IBTrDvReg(void)
{
return Object->IBTrDvReg;
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::set_IBTrDvReg(TpFIBTransaction * IBTrDvReg)
{
Object->IBTrDvReg=IBTrDvReg;
}
//---------------------------------------------------------------
TIntegerField * TDMDocRealRoznImpl::get_PayRECNO(void)
{
return Object->PayRECNO;
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::set_PayRECNO(TIntegerField * PayRECNO)
{
Object->PayRECNO=PayRECNO;
}
//---------------------------------------------------------------
TpFIBQuery * TDMDocRealRoznImpl::get_QueryCancelDvReg(void)
{
return Object->QueryCancelDvReg;
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg)
{
Object->QueryCancelDvReg=QueryCancelDvReg;
}
//---------------------------------------------------------------
TpFIBQuery * TDMDocRealRoznImpl::get_QueryDvReg(void)
{
return Object->QueryDvReg;
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::set_QueryDvReg(TpFIBQuery * QueryDvReg)
{
Object->QueryDvReg=QueryDvReg;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRealRoznImpl::get_DocTPRICEFULL_DREALROZNT(void)
{
return Object->DocTPRICEFULL_DREALROZNT;
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::set_DocTPRICEFULL_DREALROZNT(TFIBBCDField * DocTPRICEFULL_DREALROZNT)
{
Object->DocTPRICEFULL_DREALROZNT=DocTPRICEFULL_DREALROZNT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRealRoznImpl::get_DocTPRSK_DREALROZNT(void)
{
return Object->DocTPRSK_DREALROZNT;
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::set_DocTPRSK_DREALROZNT(TFIBBCDField * DocTPRSK_DREALROZNT)
{
Object->DocTPRSK_DREALROZNT=DocTPRSK_DREALROZNT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRealRoznImpl::get_DocTSUMSK_DREALROZNT(void)
{
return Object->DocTSUMSK_DREALROZNT;
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::set_DocTSUMSK_DREALROZNT(TFIBBCDField * DocTSUMSK_DREALROZNT)
{
Object->DocTSUMSK_DREALROZNT=DocTSUMSK_DREALROZNT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRealRoznImpl::get_DocTPRNAD_DREALROZNT(void)
{
return Object->DocTPRNAD_DREALROZNT;
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::set_DocTPRNAD_DREALROZNT(TFIBBCDField * DocTPRNAD_DREALROZNT)
{
Object->DocTPRNAD_DREALROZNT=DocTPRNAD_DREALROZNT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRealRoznImpl::get_DocTSUMNAD_DREALROZNT(void)
{
return Object->DocTSUMNAD_DREALROZNT;
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::set_DocTSUMNAD_DREALROZNT(TFIBBCDField * DocTSUMNAD_DREALROZNT)
{
Object->DocTSUMNAD_DREALROZNT=DocTSUMNAD_DREALROZNT;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocRealRoznImpl::get_DocTNDS_DREALROZNT(void)
{
return Object->DocTNDS_DREALROZNT;
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::set_DocTNDS_DREALROZNT(TFIBIntegerField * DocTNDS_DREALROZNT)
{
Object->DocTNDS_DREALROZNT=DocTNDS_DREALROZNT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRealRoznImpl::get_DocTSUMNDS_DREALROZNT(void)
{
return Object->DocTSUMNDS_DREALROZNT;
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::set_DocTSUMNDS_DREALROZNT(TFIBBCDField * DocTSUMNDS_DREALROZNT)
{
Object->DocTSUMNDS_DREALROZNT=DocTSUMNDS_DREALROZNT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRealRoznImpl::get_DocAllIDDOC(void)
{
return Object->DocAllIDDOC;
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::set_DocAllIDDOC(TFIBLargeIntField * DocAllIDDOC)
{
Object->DocAllIDDOC=DocAllIDDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRealRoznImpl::get_DocAllIDFIRMDOC(void)
{
return Object->DocAllIDFIRMDOC;
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::set_DocAllIDFIRMDOC(TFIBLargeIntField * DocAllIDFIRMDOC)
{
Object->DocAllIDFIRMDOC=DocAllIDFIRMDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRealRoznImpl::get_DocAllIDSKLDOC(void)
{
return Object->DocAllIDSKLDOC;
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::set_DocAllIDSKLDOC(TFIBLargeIntField * DocAllIDSKLDOC)
{
Object->DocAllIDSKLDOC=DocAllIDSKLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRealRoznImpl::get_DocAllIDKLDOC(void)
{
return Object->DocAllIDKLDOC;
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::set_DocAllIDKLDOC(TFIBLargeIntField * DocAllIDKLDOC)
{
Object->DocAllIDKLDOC=DocAllIDKLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRealRoznImpl::get_DocAllIDDOGDOC(void)
{
return Object->DocAllIDDOGDOC;
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::set_DocAllIDDOGDOC(TFIBLargeIntField * DocAllIDDOGDOC)
{
Object->DocAllIDDOGDOC=DocAllIDDOGDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRealRoznImpl::get_DocAllIDUSERDOC(void)
{
return Object->DocAllIDUSERDOC;
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::set_DocAllIDUSERDOC(TFIBLargeIntField * DocAllIDUSERDOC)
{
Object->DocAllIDUSERDOC=DocAllIDUSERDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRealRoznImpl::get_DocAllGID_DOC(void)
{
return Object->DocAllGID_DOC;
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::set_DocAllGID_DOC(TFIBWideStringField * DocAllGID_DOC)
{
Object->DocAllGID_DOC=DocAllGID_DOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRealRoznImpl::get_DocAllPREFIKSDOC(void)
{
return Object->DocAllPREFIKSDOC;
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::set_DocAllPREFIKSDOC(TFIBWideStringField * DocAllPREFIKSDOC)
{
Object->DocAllPREFIKSDOC=DocAllPREFIKSDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRealRoznImpl::get_DocAllIDDOCOSNDOC(void)
{
return Object->DocAllIDDOCOSNDOC;
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::set_DocAllIDDOCOSNDOC(TFIBLargeIntField * DocAllIDDOCOSNDOC)
{
Object->DocAllIDDOCOSNDOC=DocAllIDDOCOSNDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRealRoznImpl::get_DocAllIDEXTDOC(void)
{
return Object->DocAllIDEXTDOC;
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::set_DocAllIDEXTDOC(TFIBLargeIntField * DocAllIDEXTDOC)
{
Object->DocAllIDEXTDOC=DocAllIDEXTDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocRealRoznImpl::get_DocAllTYPEEXTDOC(void)
{
return Object->DocAllTYPEEXTDOC;
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::set_DocAllTYPEEXTDOC(TFIBIntegerField * DocAllTYPEEXTDOC)
{
Object->DocAllTYPEEXTDOC=DocAllTYPEEXTDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRealRoznImpl::get_DocAllIDBASE_GALLDOC(void)
{
return Object->DocAllIDBASE_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::set_DocAllIDBASE_GALLDOC(TFIBLargeIntField * DocAllIDBASE_GALLDOC)
{
Object->DocAllIDBASE_GALLDOC=DocAllIDBASE_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRealRoznImpl::get_DocAllIDPROJECT_GALLDOC(void)
{
return Object->DocAllIDPROJECT_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::set_DocAllIDPROJECT_GALLDOC(TFIBLargeIntField * DocAllIDPROJECT_GALLDOC)
{
Object->DocAllIDPROJECT_GALLDOC=DocAllIDPROJECT_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRealRoznImpl::get_DocAllNAME_SINFBASE_OBMEN(void)
{
return Object->DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN)
{
Object->DocAllNAME_SINFBASE_OBMEN=DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRealRoznImpl::get_DocAllNAMEFIRM(void)
{
return Object->DocAllNAMEFIRM;
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::set_DocAllNAMEFIRM(TFIBWideStringField * DocAllNAMEFIRM)
{
Object->DocAllNAMEFIRM=DocAllNAMEFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRealRoznImpl::get_DocAllNAMESKLAD(void)
{
return Object->DocAllNAMESKLAD;
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::set_DocAllNAMESKLAD(TFIBWideStringField * DocAllNAMESKLAD)
{
Object->DocAllNAMESKLAD=DocAllNAMESKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRealRoznImpl::get_DocAllNAMEKLIENT(void)
{
return Object->DocAllNAMEKLIENT;
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::set_DocAllNAMEKLIENT(TFIBWideStringField * DocAllNAMEKLIENT)
{
Object->DocAllNAMEKLIENT=DocAllNAMEKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRealRoznImpl::get_DocAllFNAME_USER(void)
{
return Object->DocAllFNAME_USER;
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::set_DocAllFNAME_USER(TFIBWideStringField * DocAllFNAME_USER)
{
Object->DocAllFNAME_USER=DocAllFNAME_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRealRoznImpl::get_DocAllNAME_SDOG(void)
{
return Object->DocAllNAME_SDOG;
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::set_DocAllNAME_SDOG(TFIBWideStringField * DocAllNAME_SDOG)
{
Object->DocAllNAME_SDOG=DocAllNAME_SDOG;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRealRoznImpl::get_DocAllNAME_SPROJECT(void)
{
return Object->DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::set_DocAllNAME_SPROJECT(TFIBWideStringField * DocAllNAME_SPROJECT)
{
Object->DocAllNAME_SPROJECT=DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRealRoznImpl::get_DocID_DREALROZN(void)
{
return Object->DocID_DREALROZN;
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::set_DocID_DREALROZN(TFIBLargeIntField * DocID_DREALROZN)
{
Object->DocID_DREALROZN=DocID_DREALROZN;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRealRoznImpl::get_DocIDDOC_DREALROZN(void)
{
return Object->DocIDDOC_DREALROZN;
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::set_DocIDDOC_DREALROZN(TFIBLargeIntField * DocIDDOC_DREALROZN)
{
Object->DocIDDOC_DREALROZN=DocIDDOC_DREALROZN;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRealRoznImpl::get_DocGID_DREALROZN(void)
{
return Object->DocGID_DREALROZN;
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::set_DocGID_DREALROZN(TFIBWideStringField * DocGID_DREALROZN)
{
Object->DocGID_DREALROZN=DocGID_DREALROZN;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRealRoznImpl::get_DocIDTPRICE_DREALROZN(void)
{
return Object->DocIDTPRICE_DREALROZN;
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::set_DocIDTPRICE_DREALROZN(TFIBLargeIntField * DocIDTPRICE_DREALROZN)
{
Object->DocIDTPRICE_DREALROZN=DocIDTPRICE_DREALROZN;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRealRoznImpl::get_DocPRIM_DREALROZN(void)
{
return Object->DocPRIM_DREALROZN;
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::set_DocPRIM_DREALROZN(TFIBWideStringField * DocPRIM_DREALROZN)
{
Object->DocPRIM_DREALROZN=DocPRIM_DREALROZN;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRealRoznImpl::get_DocIDKKM_DREALROZN(void)
{
return Object->DocIDKKM_DREALROZN;
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::set_DocIDKKM_DREALROZN(TFIBLargeIntField * DocIDKKM_DREALROZN)
{
Object->DocIDKKM_DREALROZN=DocIDKKM_DREALROZN;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRealRoznImpl::get_DocIDDCARD_DREALROZN(void)
{
return Object->DocIDDCARD_DREALROZN;
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::set_DocIDDCARD_DREALROZN(TFIBLargeIntField * DocIDDCARD_DREALROZN)
{
Object->DocIDDCARD_DREALROZN=DocIDDCARD_DREALROZN;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRealRoznImpl::get_DocIDBASE_DREALROZN(void)
{
return Object->DocIDBASE_DREALROZN;
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::set_DocIDBASE_DREALROZN(TFIBLargeIntField * DocIDBASE_DREALROZN)
{
Object->DocIDBASE_DREALROZN=DocIDBASE_DREALROZN;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRealRoznImpl::get_DocNAME_TPRICE(void)
{
return Object->DocNAME_TPRICE;
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::set_DocNAME_TPRICE(TFIBWideStringField * DocNAME_TPRICE)
{
Object->DocNAME_TPRICE=DocNAME_TPRICE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRealRoznImpl::get_DocNAMEKKM(void)
{
return Object->DocNAMEKKM;
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::set_DocNAMEKKM(TFIBWideStringField * DocNAMEKKM)
{
Object->DocNAMEKKM=DocNAMEKKM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRealRoznImpl::get_DocTID_DREALROZNT(void)
{
return Object->DocTID_DREALROZNT;
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::set_DocTID_DREALROZNT(TFIBLargeIntField * DocTID_DREALROZNT)
{
Object->DocTID_DREALROZNT=DocTID_DREALROZNT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRealRoznImpl::get_DocTIDDOC_DREALROZNT(void)
{
return Object->DocTIDDOC_DREALROZNT;
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::set_DocTIDDOC_DREALROZNT(TFIBLargeIntField * DocTIDDOC_DREALROZNT)
{
Object->DocTIDDOC_DREALROZNT=DocTIDDOC_DREALROZNT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRealRoznImpl::get_DocTGID_DREALROZNT(void)
{
return Object->DocTGID_DREALROZNT;
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::set_DocTGID_DREALROZNT(TFIBWideStringField * DocTGID_DREALROZNT)
{
Object->DocTGID_DREALROZNT=DocTGID_DREALROZNT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRealRoznImpl::get_DocTIDNOM_DREALROZNT(void)
{
return Object->DocTIDNOM_DREALROZNT;
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::set_DocTIDNOM_DREALROZNT(TFIBLargeIntField * DocTIDNOM_DREALROZNT)
{
Object->DocTIDNOM_DREALROZNT=DocTIDNOM_DREALROZNT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRealRoznImpl::get_DocTIDED_DREALROZNT(void)
{
return Object->DocTIDED_DREALROZNT;
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::set_DocTIDED_DREALROZNT(TFIBLargeIntField * DocTIDED_DREALROZNT)
{
Object->DocTIDED_DREALROZNT=DocTIDED_DREALROZNT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRealRoznImpl::get_DocTIDBASE_DREALROZNT(void)
{
return Object->DocTIDBASE_DREALROZNT;
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::set_DocTIDBASE_DREALROZNT(TFIBLargeIntField * DocTIDBASE_DREALROZNT)
{
Object->DocTIDBASE_DREALROZNT=DocTIDBASE_DREALROZNT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRealRoznImpl::get_DocTNAMENOM(void)
{
return Object->DocTNAMENOM;
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::set_DocTNAMENOM(TFIBWideStringField * DocTNAMENOM)
{
Object->DocTNAMENOM=DocTNAMENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRealRoznImpl::get_DocTNAMEED(void)
{
return Object->DocTNAMEED;
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::set_DocTNAMEED(TFIBWideStringField * DocTNAMEED)
{
Object->DocTNAMEED=DocTNAMEED;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMDocRealRoznImpl::get_DocTTNOM(void)
{
return Object->DocTTNOM;
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::set_DocTTNOM(TFIBSmallIntField * DocTTNOM)
{
Object->DocTTNOM=DocTTNOM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRealRoznImpl::get_PayID_DREALROZN_PAY(void)
{
return Object->PayID_DREALROZN_PAY;
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::set_PayID_DREALROZN_PAY(TFIBLargeIntField * PayID_DREALROZN_PAY)
{
Object->PayID_DREALROZN_PAY=PayID_DREALROZN_PAY;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRealRoznImpl::get_PayIDDOC_DREALROZN_PAY(void)
{
return Object->PayIDDOC_DREALROZN_PAY;
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::set_PayIDDOC_DREALROZN_PAY(TFIBLargeIntField * PayIDDOC_DREALROZN_PAY)
{
Object->PayIDDOC_DREALROZN_PAY=PayIDDOC_DREALROZN_PAY;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRealRoznImpl::get_PayGID_DREALROZN_PAY(void)
{
return Object->PayGID_DREALROZN_PAY;
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::set_PayGID_DREALROZN_PAY(TFIBWideStringField * PayGID_DREALROZN_PAY)
{
Object->PayGID_DREALROZN_PAY=PayGID_DREALROZN_PAY;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRealRoznImpl::get_PayIDBASE_DREALROZN_PAY(void)
{
return Object->PayIDBASE_DREALROZN_PAY;
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::set_PayIDBASE_DREALROZN_PAY(TFIBLargeIntField * PayIDBASE_DREALROZN_PAY)
{
Object->PayIDBASE_DREALROZN_PAY=PayIDBASE_DREALROZN_PAY;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRealRoznImpl::get_DocAllTDOC(void)
{
return Object->DocAllTDOC;
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::set_DocAllTDOC(TFIBWideStringField * DocAllTDOC)
{
Object->DocAllTDOC=DocAllTDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRealRoznImpl::get_DocAllIDBUSINOP_GALLDOC(void)
{
return Object->DocAllIDBUSINOP_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::set_DocAllIDBUSINOP_GALLDOC(TFIBLargeIntField * DocAllIDBUSINOP_GALLDOC)
{
Object->DocAllIDBUSINOP_GALLDOC=DocAllIDBUSINOP_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRealRoznImpl::get_DocAllNAME_SBUSINESS_OPER(void)
{
return Object->DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::set_DocAllNAME_SBUSINESS_OPER(TFIBWideStringField * DocAllNAME_SBUSINESS_OPER)
{
Object->DocAllNAME_SBUSINESS_OPER=DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRealRoznImpl::get_DocAllPREFIKS_NUM_GALLDOC(void)
{
return Object->DocAllPREFIKS_NUM_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::set_DocAllPREFIKS_NUM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_GALLDOC)
{
Object->DocAllPREFIKS_NUM_GALLDOC=DocAllPREFIKS_NUM_GALLDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRealRoznImpl::get_DocTPRSK_CARD_DREALROZNT(void)
{
return Object->DocTPRSK_CARD_DREALROZNT;
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::set_DocTPRSK_CARD_DREALROZNT(TFIBBCDField * DocTPRSK_CARD_DREALROZNT)
{
Object->DocTPRSK_CARD_DREALROZNT=DocTPRSK_CARD_DREALROZNT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRealRoznImpl::get_DocTPRSK_AUTO_DREALROZNT(void)
{
return Object->DocTPRSK_AUTO_DREALROZNT;
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::set_DocTPRSK_AUTO_DREALROZNT(TFIBBCDField * DocTPRSK_AUTO_DREALROZNT)
{
Object->DocTPRSK_AUTO_DREALROZNT=DocTPRSK_AUTO_DREALROZNT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRealRoznImpl::get_DocTPRSK_HAND_DREALROZNT(void)
{
return Object->DocTPRSK_HAND_DREALROZNT;
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::set_DocTPRSK_HAND_DREALROZNT(TFIBBCDField * DocTPRSK_HAND_DREALROZNT)
{
Object->DocTPRSK_HAND_DREALROZNT=DocTPRSK_HAND_DREALROZNT;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMDocRealRoznImpl::get_DocTNO_SK_DREALROZNT(void)
{
return Object->DocTNO_SK_DREALROZNT;
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::set_DocTNO_SK_DREALROZNT(TFIBSmallIntField * DocTNO_SK_DREALROZNT)
{
Object->DocTNO_SK_DREALROZNT=DocTNO_SK_DREALROZNT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRealRoznImpl::get_DocTARTNOM(void)
{
return Object->DocTARTNOM;
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::set_DocTARTNOM(TFIBWideStringField * DocTARTNOM)
{
Object->DocTARTNOM=DocTARTNOM;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocRealRoznImpl::get_DocTCODENOM(void)
{
return Object->DocTCODENOM;
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::set_DocTCODENOM(TFIBIntegerField * DocTCODENOM)
{
Object->DocTCODENOM=DocTCODENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRealRoznImpl::get_DocTSHED(void)
{
return Object->DocTSHED;
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::set_DocTSHED(TFIBWideStringField * DocTSHED)
{
Object->DocTSHED=DocTSHED;
}
//---------------------------------------------------------------
bool TDMDocRealRoznImpl::get_NewElement(void)
{
return Object->NewElement;
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::set_NewElement(bool NewElement)
{
Object->NewElement=NewElement;
}
//---------------------------------------------------------------
bool TDMDocRealRoznImpl::get_Prosmotr(void)
{
return Object->Prosmotr;
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::set_Prosmotr(bool Prosmotr)
{
Object->Prosmotr=Prosmotr;
}
//---------------------------------------------------------------
bool TDMDocRealRoznImpl::get_NoEdit(void)
{
return Object->NoEdit;
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::set_NoEdit(bool NoEdit)
{
Object->NoEdit=NoEdit;
}
//---------------------------------------------------------------
__int64 TDMDocRealRoznImpl::get_IdDoc(void)
{
return Object->IdDoc;
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::set_IdDoc(__int64 IdDoc)
{
Object->IdDoc=IdDoc;
}
//---------------------------------------------------------------
__int64 TDMDocRealRoznImpl::get_IdSklad(void)
{
return Object->IdSklad;
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::set_IdSklad(__int64 IdSklad)
{
Object->IdSklad=IdSklad;
}
//---------------------------------------------------------------
bool TDMDocRealRoznImpl::get_AutoRaschet(void)
{
return Object->AutoRaschet;
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::set_AutoRaschet(bool AutoRaschet)
{
Object->AutoRaschet=AutoRaschet;
}
//---------------------------------------------------------------
bool TDMDocRealRoznImpl::get_EnableDvReg(void)
{
return Object->EnableDvReg;
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::set_EnableDvReg(bool EnableDvReg)
{
Object->EnableDvReg=EnableDvReg;
}
//---------------------------------------------------------------
bool TDMDocRealRoznImpl::get_SkladRozn(void)
{
return Object->SkladRozn;
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::set_SkladRozn(bool SkladRozn)
{
Object->SkladRozn=SkladRozn;
}
//---------------------------------------------------------------
bool TDMDocRealRoznImpl::get_NoOtrOstatok(void)
{
return Object->NoOtrOstatok;
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::set_NoOtrOstatok(bool NoOtrOstatok)
{
Object->NoOtrOstatok=NoOtrOstatok;
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::NewDoc(void)
{
return Object->NewDoc();
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::OpenDoc(__int64 IdDoc)
{
return Object->OpenDoc(IdDoc);
}
//---------------------------------------------------------------
bool TDMDocRealRoznImpl::SaveDoc(void)
{
return Object->SaveDoc();
}
//---------------------------------------------------------------
bool TDMDocRealRoznImpl::DvRegDoc(void)
{
return Object->DvRegDoc();
}
//---------------------------------------------------------------
bool TDMDocRealRoznImpl::CancelDvRegDoc(void)
{
return Object->CancelDvRegDoc();
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::AddDocNewString(void)
{
return Object->AddDocNewString();
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::DeleteStringDoc(void)
{
return Object->DeleteStringDoc();
}
//---------------------------------------------------------------
void TDMDocRealRoznImpl::CloseDoc(void)
{
return Object->CloseDoc();
}
//---------------------------------------------------------------
bool TDMDocRealRoznImpl::DeleteDoc(__int64 id)
{
return Object->DeleteDoc(id);
}
//---------------------------------------------------------------
int TDMDocRealRoznImpl::GetNumberNewDoc(void)
{
return Object->GetNumberNewDoc();
}
//---------------------------------------------------------------
