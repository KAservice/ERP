#include "vcl.h"
#pragma hdrstop


#include "UDMDocRegCardBalanceImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMDocRegCardBalanceImpl::TDMDocRegCardBalanceImpl()           
{                                            
Object=new TDMDocRegCardBalance(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMDocRegCardBalanceImpl::~TDMDocRegCardBalanceImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMDocRegCardBalanceImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMDocRegCardBalanceImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMDocRegCardBalance)                        
   {                                                                     
   *ppv=static_cast<IDMDocRegCardBalance*> (this);                                
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
int TDMDocRegCardBalanceImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMDocRegCardBalanceImpl::kanRelease(void)                                  
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
int  TDMDocRegCardBalanceImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMDocRegCardBalanceImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMDocRegCardBalanceImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMDocRegCardBalanceImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMDocRegCardBalanceImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMDocRegCardBalanceImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMDocRegCardBalanceImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMDocRegCardBalance
TDataSource * TDMDocRegCardBalanceImpl::get_DataSourceDoc(void)
{
return Object->DataSourceDoc;
}
//---------------------------------------------------------------
void TDMDocRegCardBalanceImpl::set_DataSourceDoc(TDataSource * DataSourceDoc)
{
Object->DataSourceDoc=DataSourceDoc;
}
//---------------------------------------------------------------
TDataSource * TDMDocRegCardBalanceImpl::get_DataSourceDocT(void)
{
return Object->DataSourceDocT;
}
//---------------------------------------------------------------
void TDMDocRegCardBalanceImpl::set_DataSourceDocT(TDataSource * DataSourceDocT)
{
Object->DataSourceDocT=DataSourceDocT;
}
//---------------------------------------------------------------
TDataSource * TDMDocRegCardBalanceImpl::get_DataSourceDocAll(void)
{
return Object->DataSourceDocAll;
}
//---------------------------------------------------------------
void TDMDocRegCardBalanceImpl::set_DataSourceDocAll(TDataSource * DataSourceDocAll)
{
Object->DataSourceDocAll=DataSourceDocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocRegCardBalanceImpl::get_DocAll(void)
{
return Object->DocAll;
}
//---------------------------------------------------------------
void TDMDocRegCardBalanceImpl::set_DocAll(TpFIBDataSet * DocAll)
{
Object->DocAll=DocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocRegCardBalanceImpl::get_Doc(void)
{
return Object->Doc;
}
//---------------------------------------------------------------
void TDMDocRegCardBalanceImpl::set_Doc(TpFIBDataSet * Doc)
{
Object->Doc=Doc;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocRegCardBalanceImpl::get_DocT(void)
{
return Object->DocT;
}
//---------------------------------------------------------------
void TDMDocRegCardBalanceImpl::set_DocT(TpFIBDataSet * DocT)
{
Object->DocT=DocT;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocRegCardBalanceImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMDocRegCardBalanceImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocRegCardBalanceImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMDocRegCardBalanceImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocRegCardBalanceImpl::get_IBTrDvReg(void)
{
return Object->IBTrDvReg;
}
//---------------------------------------------------------------
void TDMDocRegCardBalanceImpl::set_IBTrDvReg(TpFIBTransaction * IBTrDvReg)
{
Object->IBTrDvReg=IBTrDvReg;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocRegCardBalanceImpl::get_NumDoc(void)
{
return Object->NumDoc;
}
//---------------------------------------------------------------
void TDMDocRegCardBalanceImpl::set_NumDoc(TpFIBDataSet * NumDoc)
{
Object->NumDoc=NumDoc;
}
//---------------------------------------------------------------
TpFIBQuery * TDMDocRegCardBalanceImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TDMDocRegCardBalanceImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TpFIBQuery * TDMDocRegCardBalanceImpl::get_QueryCancelDvReg(void)
{
return Object->QueryCancelDvReg;
}
//---------------------------------------------------------------
void TDMDocRegCardBalanceImpl::set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg)
{
Object->QueryCancelDvReg=QueryCancelDvReg;
}
//---------------------------------------------------------------
TpFIBQuery * TDMDocRegCardBalanceImpl::get_QueryDvReg(void)
{
return Object->QueryDvReg;
}
//---------------------------------------------------------------
void TDMDocRegCardBalanceImpl::set_QueryDvReg(TpFIBQuery * QueryDvReg)
{
Object->QueryDvReg=QueryDvReg;
}
//---------------------------------------------------------------
TFIBDateTimeField * TDMDocRegCardBalanceImpl::get_DocAllPOSDOC(void)
{
return Object->DocAllPOSDOC;
}
//---------------------------------------------------------------
void TDMDocRegCardBalanceImpl::set_DocAllPOSDOC(TFIBDateTimeField * DocAllPOSDOC)
{
Object->DocAllPOSDOC=DocAllPOSDOC;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMDocRegCardBalanceImpl::get_DocAllPRDOC(void)
{
return Object->DocAllPRDOC;
}
//---------------------------------------------------------------
void TDMDocRegCardBalanceImpl::set_DocAllPRDOC(TFIBSmallIntField * DocAllPRDOC)
{
Object->DocAllPRDOC=DocAllPRDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocRegCardBalanceImpl::get_DocAllNUMDOC(void)
{
return Object->DocAllNUMDOC;
}
//---------------------------------------------------------------
void TDMDocRegCardBalanceImpl::set_DocAllNUMDOC(TFIBIntegerField * DocAllNUMDOC)
{
Object->DocAllNUMDOC=DocAllNUMDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRegCardBalanceImpl::get_DocAllSUMDOC(void)
{
return Object->DocAllSUMDOC;
}
//---------------------------------------------------------------
void TDMDocRegCardBalanceImpl::set_DocAllSUMDOC(TFIBBCDField * DocAllSUMDOC)
{
Object->DocAllSUMDOC=DocAllSUMDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRegCardBalanceImpl::get_DocAllIDUSERDOC(void)
{
return Object->DocAllIDUSERDOC;
}
//---------------------------------------------------------------
void TDMDocRegCardBalanceImpl::set_DocAllIDUSERDOC(TFIBBCDField * DocAllIDUSERDOC)
{
Object->DocAllIDUSERDOC=DocAllIDUSERDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegCardBalanceImpl::get_DocAllIDDOC(void)
{
return Object->DocAllIDDOC;
}
//---------------------------------------------------------------
void TDMDocRegCardBalanceImpl::set_DocAllIDDOC(TFIBLargeIntField * DocAllIDDOC)
{
Object->DocAllIDDOC=DocAllIDDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegCardBalanceImpl::get_DocAllIDFIRMDOC(void)
{
return Object->DocAllIDFIRMDOC;
}
//---------------------------------------------------------------
void TDMDocRegCardBalanceImpl::set_DocAllIDFIRMDOC(TFIBLargeIntField * DocAllIDFIRMDOC)
{
Object->DocAllIDFIRMDOC=DocAllIDFIRMDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegCardBalanceImpl::get_DocAllIDSKLDOC(void)
{
return Object->DocAllIDSKLDOC;
}
//---------------------------------------------------------------
void TDMDocRegCardBalanceImpl::set_DocAllIDSKLDOC(TFIBLargeIntField * DocAllIDSKLDOC)
{
Object->DocAllIDSKLDOC=DocAllIDSKLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegCardBalanceImpl::get_DocAllIDKLDOC(void)
{
return Object->DocAllIDKLDOC;
}
//---------------------------------------------------------------
void TDMDocRegCardBalanceImpl::set_DocAllIDKLDOC(TFIBLargeIntField * DocAllIDKLDOC)
{
Object->DocAllIDKLDOC=DocAllIDKLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegCardBalanceImpl::get_DocAllIDDOGDOC(void)
{
return Object->DocAllIDDOGDOC;
}
//---------------------------------------------------------------
void TDMDocRegCardBalanceImpl::set_DocAllIDDOGDOC(TFIBLargeIntField * DocAllIDDOGDOC)
{
Object->DocAllIDDOGDOC=DocAllIDDOGDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegCardBalanceImpl::get_DocAllIDDOCOSNDOC(void)
{
return Object->DocAllIDDOCOSNDOC;
}
//---------------------------------------------------------------
void TDMDocRegCardBalanceImpl::set_DocAllIDDOCOSNDOC(TFIBLargeIntField * DocAllIDDOCOSNDOC)
{
Object->DocAllIDDOCOSNDOC=DocAllIDDOCOSNDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegCardBalanceImpl::get_DocAllIDEXTDOC(void)
{
return Object->DocAllIDEXTDOC;
}
//---------------------------------------------------------------
void TDMDocRegCardBalanceImpl::set_DocAllIDEXTDOC(TFIBLargeIntField * DocAllIDEXTDOC)
{
Object->DocAllIDEXTDOC=DocAllIDEXTDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegCardBalanceImpl::get_DocAllIDBASE_GALLDOC(void)
{
return Object->DocAllIDBASE_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocRegCardBalanceImpl::set_DocAllIDBASE_GALLDOC(TFIBLargeIntField * DocAllIDBASE_GALLDOC)
{
Object->DocAllIDBASE_GALLDOC=DocAllIDBASE_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegCardBalanceImpl::get_DocAllIDPROJECT_GALLDOC(void)
{
return Object->DocAllIDPROJECT_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocRegCardBalanceImpl::set_DocAllIDPROJECT_GALLDOC(TFIBLargeIntField * DocAllIDPROJECT_GALLDOC)
{
Object->DocAllIDPROJECT_GALLDOC=DocAllIDPROJECT_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegCardBalanceImpl::get_DocID_DRG_CARD_BALANCE(void)
{
return Object->DocID_DRG_CARD_BALANCE;
}
//---------------------------------------------------------------
void TDMDocRegCardBalanceImpl::set_DocID_DRG_CARD_BALANCE(TFIBLargeIntField * DocID_DRG_CARD_BALANCE)
{
Object->DocID_DRG_CARD_BALANCE=DocID_DRG_CARD_BALANCE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegCardBalanceImpl::get_DocIDBASE_DRG_CARD_BALANCE(void)
{
return Object->DocIDBASE_DRG_CARD_BALANCE;
}
//---------------------------------------------------------------
void TDMDocRegCardBalanceImpl::set_DocIDBASE_DRG_CARD_BALANCE(TFIBLargeIntField * DocIDBASE_DRG_CARD_BALANCE)
{
Object->DocIDBASE_DRG_CARD_BALANCE=DocIDBASE_DRG_CARD_BALANCE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegCardBalanceImpl::get_DocIDDOC_DRG_CARD_BALANCE(void)
{
return Object->DocIDDOC_DRG_CARD_BALANCE;
}
//---------------------------------------------------------------
void TDMDocRegCardBalanceImpl::set_DocIDDOC_DRG_CARD_BALANCE(TFIBLargeIntField * DocIDDOC_DRG_CARD_BALANCE)
{
Object->DocIDDOC_DRG_CARD_BALANCE=DocIDDOC_DRG_CARD_BALANCE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegCardBalanceImpl::get_DocTID_DRG_CARD_BALANCET(void)
{
return Object->DocTID_DRG_CARD_BALANCET;
}
//---------------------------------------------------------------
void TDMDocRegCardBalanceImpl::set_DocTID_DRG_CARD_BALANCET(TFIBLargeIntField * DocTID_DRG_CARD_BALANCET)
{
Object->DocTID_DRG_CARD_BALANCET=DocTID_DRG_CARD_BALANCET;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegCardBalanceImpl::get_DocTIDBASE_DRG_CARD_BALANCET(void)
{
return Object->DocTIDBASE_DRG_CARD_BALANCET;
}
//---------------------------------------------------------------
void TDMDocRegCardBalanceImpl::set_DocTIDBASE_DRG_CARD_BALANCET(TFIBLargeIntField * DocTIDBASE_DRG_CARD_BALANCET)
{
Object->DocTIDBASE_DRG_CARD_BALANCET=DocTIDBASE_DRG_CARD_BALANCET;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegCardBalanceImpl::get_DocTIDDOC_DRG_CARD_BALANCET(void)
{
return Object->DocTIDDOC_DRG_CARD_BALANCET;
}
//---------------------------------------------------------------
void TDMDocRegCardBalanceImpl::set_DocTIDDOC_DRG_CARD_BALANCET(TFIBLargeIntField * DocTIDDOC_DRG_CARD_BALANCET)
{
Object->DocTIDDOC_DRG_CARD_BALANCET=DocTIDDOC_DRG_CARD_BALANCET;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMDocRegCardBalanceImpl::get_DocTTDV_DRG_CARD_BALANCET(void)
{
return Object->DocTTDV_DRG_CARD_BALANCET;
}
//---------------------------------------------------------------
void TDMDocRegCardBalanceImpl::set_DocTTDV_DRG_CARD_BALANCET(TFIBSmallIntField * DocTTDV_DRG_CARD_BALANCET)
{
Object->DocTTDV_DRG_CARD_BALANCET=DocTTDV_DRG_CARD_BALANCET;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegCardBalanceImpl::get_DocTIDFIRM_DRG_CARD_BALANCET(void)
{
return Object->DocTIDFIRM_DRG_CARD_BALANCET;
}
//---------------------------------------------------------------
void TDMDocRegCardBalanceImpl::set_DocTIDFIRM_DRG_CARD_BALANCET(TFIBLargeIntField * DocTIDFIRM_DRG_CARD_BALANCET)
{
Object->DocTIDFIRM_DRG_CARD_BALANCET=DocTIDFIRM_DRG_CARD_BALANCET;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegCardBalanceImpl::get_DocTIDCARD_DRG_CARD_BALANCET(void)
{
return Object->DocTIDCARD_DRG_CARD_BALANCET;
}
//---------------------------------------------------------------
void TDMDocRegCardBalanceImpl::set_DocTIDCARD_DRG_CARD_BALANCET(TFIBLargeIntField * DocTIDCARD_DRG_CARD_BALANCET)
{
Object->DocTIDCARD_DRG_CARD_BALANCET=DocTIDCARD_DRG_CARD_BALANCET;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRegCardBalanceImpl::get_DocTSUM_DRG_CARD_BALANCET(void)
{
return Object->DocTSUM_DRG_CARD_BALANCET;
}
//---------------------------------------------------------------
void TDMDocRegCardBalanceImpl::set_DocTSUM_DRG_CARD_BALANCET(TFIBBCDField * DocTSUM_DRG_CARD_BALANCET)
{
Object->DocTSUM_DRG_CARD_BALANCET=DocTSUM_DRG_CARD_BALANCET;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocRegCardBalanceImpl::get_DocTOPER_DRG_CARD_BALANCET(void)
{
return Object->DocTOPER_DRG_CARD_BALANCET;
}
//---------------------------------------------------------------
void TDMDocRegCardBalanceImpl::set_DocTOPER_DRG_CARD_BALANCET(TFIBIntegerField * DocTOPER_DRG_CARD_BALANCET)
{
Object->DocTOPER_DRG_CARD_BALANCET=DocTOPER_DRG_CARD_BALANCET;
}
//---------------------------------------------------------------
TIntegerField * TDMDocRegCardBalanceImpl::get_DocTRECNO(void)
{
return Object->DocTRECNO;
}
//---------------------------------------------------------------
void TDMDocRegCardBalanceImpl::set_DocTRECNO(TIntegerField * DocTRECNO)
{
Object->DocTRECNO=DocTRECNO;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRegCardBalanceImpl::get_DocAllTDOC(void)
{
return Object->DocAllTDOC;
}
//---------------------------------------------------------------
void TDMDocRegCardBalanceImpl::set_DocAllTDOC(TFIBWideStringField * DocAllTDOC)
{
Object->DocAllTDOC=DocAllTDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRegCardBalanceImpl::get_DocAllGID_DOC(void)
{
return Object->DocAllGID_DOC;
}
//---------------------------------------------------------------
void TDMDocRegCardBalanceImpl::set_DocAllGID_DOC(TFIBWideStringField * DocAllGID_DOC)
{
Object->DocAllGID_DOC=DocAllGID_DOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRegCardBalanceImpl::get_DocAllPREFIKSDOC(void)
{
return Object->DocAllPREFIKSDOC;
}
//---------------------------------------------------------------
void TDMDocRegCardBalanceImpl::set_DocAllPREFIKSDOC(TFIBWideStringField * DocAllPREFIKSDOC)
{
Object->DocAllPREFIKSDOC=DocAllPREFIKSDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocRegCardBalanceImpl::get_DocAllTYPEEXTDOC(void)
{
return Object->DocAllTYPEEXTDOC;
}
//---------------------------------------------------------------
void TDMDocRegCardBalanceImpl::set_DocAllTYPEEXTDOC(TFIBIntegerField * DocAllTYPEEXTDOC)
{
Object->DocAllTYPEEXTDOC=DocAllTYPEEXTDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRegCardBalanceImpl::get_DocAllFNAME_USER(void)
{
return Object->DocAllFNAME_USER;
}
//---------------------------------------------------------------
void TDMDocRegCardBalanceImpl::set_DocAllFNAME_USER(TFIBWideStringField * DocAllFNAME_USER)
{
Object->DocAllFNAME_USER=DocAllFNAME_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRegCardBalanceImpl::get_DocAllNAME_SINFBASE_OBMEN(void)
{
return Object->DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void TDMDocRegCardBalanceImpl::set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN)
{
Object->DocAllNAME_SINFBASE_OBMEN=DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRegCardBalanceImpl::get_DocDESCR_DRG_CARD_BALANCE(void)
{
return Object->DocDESCR_DRG_CARD_BALANCE;
}
//---------------------------------------------------------------
void TDMDocRegCardBalanceImpl::set_DocDESCR_DRG_CARD_BALANCE(TFIBWideStringField * DocDESCR_DRG_CARD_BALANCE)
{
Object->DocDESCR_DRG_CARD_BALANCE=DocDESCR_DRG_CARD_BALANCE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRegCardBalanceImpl::get_DocTNAMEFIRM(void)
{
return Object->DocTNAMEFIRM;
}
//---------------------------------------------------------------
void TDMDocRegCardBalanceImpl::set_DocTNAMEFIRM(TFIBWideStringField * DocTNAMEFIRM)
{
Object->DocTNAMEFIRM=DocTNAMEFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRegCardBalanceImpl::get_DocTNAME_SDISCOUNT_CARD(void)
{
return Object->DocTNAME_SDISCOUNT_CARD;
}
//---------------------------------------------------------------
void TDMDocRegCardBalanceImpl::set_DocTNAME_SDISCOUNT_CARD(TFIBWideStringField * DocTNAME_SDISCOUNT_CARD)
{
Object->DocTNAME_SDISCOUNT_CARD=DocTNAME_SDISCOUNT_CARD;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegCardBalanceImpl::get_DocAllIDBUSINOP_GALLDOC(void)
{
return Object->DocAllIDBUSINOP_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocRegCardBalanceImpl::set_DocAllIDBUSINOP_GALLDOC(TFIBLargeIntField * DocAllIDBUSINOP_GALLDOC)
{
Object->DocAllIDBUSINOP_GALLDOC=DocAllIDBUSINOP_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRegCardBalanceImpl::get_DocAllNAME_SPROJECT(void)
{
return Object->DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
void TDMDocRegCardBalanceImpl::set_DocAllNAME_SPROJECT(TFIBWideStringField * DocAllNAME_SPROJECT)
{
Object->DocAllNAME_SPROJECT=DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRegCardBalanceImpl::get_DocAllNAME_SBUSINESS_OPER(void)
{
return Object->DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
void TDMDocRegCardBalanceImpl::set_DocAllNAME_SBUSINESS_OPER(TFIBWideStringField * DocAllNAME_SBUSINESS_OPER)
{
Object->DocAllNAME_SBUSINESS_OPER=DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRegCardBalanceImpl::get_DocAllPREFIKS_NUM_GALLDOC(void)
{
return Object->DocAllPREFIKS_NUM_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocRegCardBalanceImpl::set_DocAllPREFIKS_NUM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_GALLDOC)
{
Object->DocAllPREFIKS_NUM_GALLDOC=DocAllPREFIKS_NUM_GALLDOC;
}
//---------------------------------------------------------------
__int64 TDMDocRegCardBalanceImpl::get_IdDoc(void)
{
return Object->IdDoc;
}
//---------------------------------------------------------------
void TDMDocRegCardBalanceImpl::set_IdDoc(__int64 IdDoc)
{
Object->IdDoc=IdDoc;
}
//---------------------------------------------------------------
bool TDMDocRegCardBalanceImpl::get_Prosmotr(void)
{
return Object->Prosmotr;
}
//---------------------------------------------------------------
void TDMDocRegCardBalanceImpl::set_Prosmotr(bool Prosmotr)
{
Object->Prosmotr=Prosmotr;
}
//---------------------------------------------------------------
bool TDMDocRegCardBalanceImpl::get_EnableDvReg(void)
{
return Object->EnableDvReg;
}
//---------------------------------------------------------------
void TDMDocRegCardBalanceImpl::set_EnableDvReg(bool EnableDvReg)
{
Object->EnableDvReg=EnableDvReg;
}
//---------------------------------------------------------------
bool TDMDocRegCardBalanceImpl::NewDoc(void)
{
return Object->NewDoc();
}
//---------------------------------------------------------------
bool TDMDocRegCardBalanceImpl::OpenDoc(__int64 IdDoc)
{
return Object->OpenDoc(IdDoc);
}
//---------------------------------------------------------------
bool TDMDocRegCardBalanceImpl::SaveDoc(void)
{
return Object->SaveDoc();
}
//---------------------------------------------------------------
bool TDMDocRegCardBalanceImpl::DeleteDoc(__int64 id)
{
return Object->DeleteDoc(id);
}
//---------------------------------------------------------------
bool TDMDocRegCardBalanceImpl::DvRegDoc(void)
{
return Object->DvRegDoc();
}
//---------------------------------------------------------------
bool TDMDocRegCardBalanceImpl::CancelDvRegDoc(void)
{
return Object->CancelDvRegDoc();
}
//---------------------------------------------------------------
void TDMDocRegCardBalanceImpl::TableAppend(void)
{
return Object->TableAppend();
}
//---------------------------------------------------------------
void TDMDocRegCardBalanceImpl::TableDelete(void)
{
return Object->TableDelete();
}
//---------------------------------------------------------------
int TDMDocRegCardBalanceImpl::GetNumberNewDoc(void)
{
return Object->GetNumberNewDoc();
}
//---------------------------------------------------------------
