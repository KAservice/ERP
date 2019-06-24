#include "vcl.h"
#pragma hdrstop


#include "UDMDocVosvratPokImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMDocVosvratPokImpl::TDMDocVosvratPokImpl()           
{                                            
Object=new TDMDocVosvratPok(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMDocVosvratPokImpl::~TDMDocVosvratPokImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMDocVosvratPokImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMDocVosvratPokImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMDocVosvratPok)                        
   {                                                                     
   *ppv=static_cast<IDMDocVosvratPok*> (this);                                
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
int TDMDocVosvratPokImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMDocVosvratPokImpl::kanRelease(void)                                  
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
int  TDMDocVosvratPokImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMDocVosvratPokImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMDocVosvratPokImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMDocVosvratPokImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMDocVosvratPokImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMDocVosvratPokImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMDocVosvratPokImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMDocVosvratPok
TDataSource * TDMDocVosvratPokImpl::get_DataSourceDoc(void)
{
return Object->DataSourceDoc;
}
//---------------------------------------------------------------
void TDMDocVosvratPokImpl::set_DataSourceDoc(TDataSource * DataSourceDoc)
{
Object->DataSourceDoc=DataSourceDoc;
}
//---------------------------------------------------------------
TDataSource * TDMDocVosvratPokImpl::get_DataSourceDocT(void)
{
return Object->DataSourceDocT;
}
//---------------------------------------------------------------
void TDMDocVosvratPokImpl::set_DataSourceDocT(TDataSource * DataSourceDocT)
{
Object->DataSourceDocT=DataSourceDocT;
}
//---------------------------------------------------------------
TDataSource * TDMDocVosvratPokImpl::get_DataSourceDocAll(void)
{
return Object->DataSourceDocAll;
}
//---------------------------------------------------------------
void TDMDocVosvratPokImpl::set_DataSourceDocAll(TDataSource * DataSourceDocAll)
{
Object->DataSourceDocAll=DataSourceDocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocVosvratPokImpl::get_DocAll(void)
{
return Object->DocAll;
}
//---------------------------------------------------------------
void TDMDocVosvratPokImpl::set_DocAll(TpFIBDataSet * DocAll)
{
Object->DocAll=DocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocVosvratPokImpl::get_Doc(void)
{
return Object->Doc;
}
//---------------------------------------------------------------
void TDMDocVosvratPokImpl::set_Doc(TpFIBDataSet * Doc)
{
Object->Doc=Doc;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocVosvratPokImpl::get_DocT(void)
{
return Object->DocT;
}
//---------------------------------------------------------------
void TDMDocVosvratPokImpl::set_DocT(TpFIBDataSet * DocT)
{
Object->DocT=DocT;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocVosvratPokImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMDocVosvratPokImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocVosvratPokImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMDocVosvratPokImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocVosvratPokImpl::get_IBTrDvReg(void)
{
return Object->IBTrDvReg;
}
//---------------------------------------------------------------
void TDMDocVosvratPokImpl::set_IBTrDvReg(TpFIBTransaction * IBTrDvReg)
{
Object->IBTrDvReg=IBTrDvReg;
}
//---------------------------------------------------------------
TIntegerField * TDMDocVosvratPokImpl::get_DocTRECNO(void)
{
return Object->DocTRECNO;
}
//---------------------------------------------------------------
void TDMDocVosvratPokImpl::set_DocTRECNO(TIntegerField * DocTRECNO)
{
Object->DocTRECNO=DocTRECNO;
}
//---------------------------------------------------------------
TpFIBQuery * TDMDocVosvratPokImpl::get_QueryCancelDvReg(void)
{
return Object->QueryCancelDvReg;
}
//---------------------------------------------------------------
void TDMDocVosvratPokImpl::set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg)
{
Object->QueryCancelDvReg=QueryCancelDvReg;
}
//---------------------------------------------------------------
TpFIBQuery * TDMDocVosvratPokImpl::get_QueryDvReg(void)
{
return Object->QueryDvReg;
}
//---------------------------------------------------------------
void TDMDocVosvratPokImpl::set_QueryDvReg(TpFIBQuery * QueryDvReg)
{
Object->QueryDvReg=QueryDvReg;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocVosvratPokImpl::get_NumDoc(void)
{
return Object->NumDoc;
}
//---------------------------------------------------------------
void TDMDocVosvratPokImpl::set_NumDoc(TpFIBDataSet * NumDoc)
{
Object->NumDoc=NumDoc;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocVosvratPokImpl::get_DocAllIDDOC(void)
{
return Object->DocAllIDDOC;
}
//---------------------------------------------------------------
void TDMDocVosvratPokImpl::set_DocAllIDDOC(TFIBLargeIntField * DocAllIDDOC)
{
Object->DocAllIDDOC=DocAllIDDOC;
}
//---------------------------------------------------------------
TFIBDateTimeField * TDMDocVosvratPokImpl::get_DocAllPOSDOC(void)
{
return Object->DocAllPOSDOC;
}
//---------------------------------------------------------------
void TDMDocVosvratPokImpl::set_DocAllPOSDOC(TFIBDateTimeField * DocAllPOSDOC)
{
Object->DocAllPOSDOC=DocAllPOSDOC;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMDocVosvratPokImpl::get_DocAllPRDOC(void)
{
return Object->DocAllPRDOC;
}
//---------------------------------------------------------------
void TDMDocVosvratPokImpl::set_DocAllPRDOC(TFIBSmallIntField * DocAllPRDOC)
{
Object->DocAllPRDOC=DocAllPRDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocVosvratPokImpl::get_DocAllTDOC(void)
{
return Object->DocAllTDOC;
}
//---------------------------------------------------------------
void TDMDocVosvratPokImpl::set_DocAllTDOC(TFIBWideStringField * DocAllTDOC)
{
Object->DocAllTDOC=DocAllTDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocVosvratPokImpl::get_DocAllNUMDOC(void)
{
return Object->DocAllNUMDOC;
}
//---------------------------------------------------------------
void TDMDocVosvratPokImpl::set_DocAllNUMDOC(TFIBIntegerField * DocAllNUMDOC)
{
Object->DocAllNUMDOC=DocAllNUMDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocVosvratPokImpl::get_DocAllIDFIRMDOC(void)
{
return Object->DocAllIDFIRMDOC;
}
//---------------------------------------------------------------
void TDMDocVosvratPokImpl::set_DocAllIDFIRMDOC(TFIBLargeIntField * DocAllIDFIRMDOC)
{
Object->DocAllIDFIRMDOC=DocAllIDFIRMDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocVosvratPokImpl::get_DocAllIDSKLDOC(void)
{
return Object->DocAllIDSKLDOC;
}
//---------------------------------------------------------------
void TDMDocVosvratPokImpl::set_DocAllIDSKLDOC(TFIBLargeIntField * DocAllIDSKLDOC)
{
Object->DocAllIDSKLDOC=DocAllIDSKLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocVosvratPokImpl::get_DocAllIDKLDOC(void)
{
return Object->DocAllIDKLDOC;
}
//---------------------------------------------------------------
void TDMDocVosvratPokImpl::set_DocAllIDKLDOC(TFIBLargeIntField * DocAllIDKLDOC)
{
Object->DocAllIDKLDOC=DocAllIDKLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocVosvratPokImpl::get_DocAllIDDOGDOC(void)
{
return Object->DocAllIDDOGDOC;
}
//---------------------------------------------------------------
void TDMDocVosvratPokImpl::set_DocAllIDDOGDOC(TFIBLargeIntField * DocAllIDDOGDOC)
{
Object->DocAllIDDOGDOC=DocAllIDDOGDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocVosvratPokImpl::get_DocAllSUMDOC(void)
{
return Object->DocAllSUMDOC;
}
//---------------------------------------------------------------
void TDMDocVosvratPokImpl::set_DocAllSUMDOC(TFIBBCDField * DocAllSUMDOC)
{
Object->DocAllSUMDOC=DocAllSUMDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocVosvratPokImpl::get_DocAllIDUSERDOC(void)
{
return Object->DocAllIDUSERDOC;
}
//---------------------------------------------------------------
void TDMDocVosvratPokImpl::set_DocAllIDUSERDOC(TFIBLargeIntField * DocAllIDUSERDOC)
{
Object->DocAllIDUSERDOC=DocAllIDUSERDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocVosvratPokImpl::get_DocAllGID_DOC(void)
{
return Object->DocAllGID_DOC;
}
//---------------------------------------------------------------
void TDMDocVosvratPokImpl::set_DocAllGID_DOC(TFIBWideStringField * DocAllGID_DOC)
{
Object->DocAllGID_DOC=DocAllGID_DOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocVosvratPokImpl::get_DocAllPREFIKSDOC(void)
{
return Object->DocAllPREFIKSDOC;
}
//---------------------------------------------------------------
void TDMDocVosvratPokImpl::set_DocAllPREFIKSDOC(TFIBWideStringField * DocAllPREFIKSDOC)
{
Object->DocAllPREFIKSDOC=DocAllPREFIKSDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocVosvratPokImpl::get_DocAllIDDOCOSNDOC(void)
{
return Object->DocAllIDDOCOSNDOC;
}
//---------------------------------------------------------------
void TDMDocVosvratPokImpl::set_DocAllIDDOCOSNDOC(TFIBLargeIntField * DocAllIDDOCOSNDOC)
{
Object->DocAllIDDOCOSNDOC=DocAllIDDOCOSNDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocVosvratPokImpl::get_DocAllIDEXTDOC(void)
{
return Object->DocAllIDEXTDOC;
}
//---------------------------------------------------------------
void TDMDocVosvratPokImpl::set_DocAllIDEXTDOC(TFIBLargeIntField * DocAllIDEXTDOC)
{
Object->DocAllIDEXTDOC=DocAllIDEXTDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocVosvratPokImpl::get_DocAllTYPEEXTDOC(void)
{
return Object->DocAllTYPEEXTDOC;
}
//---------------------------------------------------------------
void TDMDocVosvratPokImpl::set_DocAllTYPEEXTDOC(TFIBIntegerField * DocAllTYPEEXTDOC)
{
Object->DocAllTYPEEXTDOC=DocAllTYPEEXTDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocVosvratPokImpl::get_DocAllIDBASE_GALLDOC(void)
{
return Object->DocAllIDBASE_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocVosvratPokImpl::set_DocAllIDBASE_GALLDOC(TFIBLargeIntField * DocAllIDBASE_GALLDOC)
{
Object->DocAllIDBASE_GALLDOC=DocAllIDBASE_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocVosvratPokImpl::get_DocAllIDPROJECT_GALLDOC(void)
{
return Object->DocAllIDPROJECT_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocVosvratPokImpl::set_DocAllIDPROJECT_GALLDOC(TFIBLargeIntField * DocAllIDPROJECT_GALLDOC)
{
Object->DocAllIDPROJECT_GALLDOC=DocAllIDPROJECT_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocVosvratPokImpl::get_DocAllIDBUSINOP_GALLDOC(void)
{
return Object->DocAllIDBUSINOP_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocVosvratPokImpl::set_DocAllIDBUSINOP_GALLDOC(TFIBLargeIntField * DocAllIDBUSINOP_GALLDOC)
{
Object->DocAllIDBUSINOP_GALLDOC=DocAllIDBUSINOP_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocVosvratPokImpl::get_DocAllFNAME_USER(void)
{
return Object->DocAllFNAME_USER;
}
//---------------------------------------------------------------
void TDMDocVosvratPokImpl::set_DocAllFNAME_USER(TFIBWideStringField * DocAllFNAME_USER)
{
Object->DocAllFNAME_USER=DocAllFNAME_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocVosvratPokImpl::get_DocAllNAME_SINFBASE_OBMEN(void)
{
return Object->DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void TDMDocVosvratPokImpl::set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN)
{
Object->DocAllNAME_SINFBASE_OBMEN=DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocVosvratPokImpl::get_DocAllNAMEFIRM(void)
{
return Object->DocAllNAMEFIRM;
}
//---------------------------------------------------------------
void TDMDocVosvratPokImpl::set_DocAllNAMEFIRM(TFIBWideStringField * DocAllNAMEFIRM)
{
Object->DocAllNAMEFIRM=DocAllNAMEFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocVosvratPokImpl::get_DocAllNAMESKLAD(void)
{
return Object->DocAllNAMESKLAD;
}
//---------------------------------------------------------------
void TDMDocVosvratPokImpl::set_DocAllNAMESKLAD(TFIBWideStringField * DocAllNAMESKLAD)
{
Object->DocAllNAMESKLAD=DocAllNAMESKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocVosvratPokImpl::get_DocAllNAMEKLIENT(void)
{
return Object->DocAllNAMEKLIENT;
}
//---------------------------------------------------------------
void TDMDocVosvratPokImpl::set_DocAllNAMEKLIENT(TFIBWideStringField * DocAllNAMEKLIENT)
{
Object->DocAllNAMEKLIENT=DocAllNAMEKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocVosvratPokImpl::get_DocAllNAME_SDOG(void)
{
return Object->DocAllNAME_SDOG;
}
//---------------------------------------------------------------
void TDMDocVosvratPokImpl::set_DocAllNAME_SDOG(TFIBWideStringField * DocAllNAME_SDOG)
{
Object->DocAllNAME_SDOG=DocAllNAME_SDOG;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocVosvratPokImpl::get_DocAllNAME_SPROJECT(void)
{
return Object->DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
void TDMDocVosvratPokImpl::set_DocAllNAME_SPROJECT(TFIBWideStringField * DocAllNAME_SPROJECT)
{
Object->DocAllNAME_SPROJECT=DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocVosvratPokImpl::get_DocAllNAME_SBUSINESS_OPER(void)
{
return Object->DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
void TDMDocVosvratPokImpl::set_DocAllNAME_SBUSINESS_OPER(TFIBWideStringField * DocAllNAME_SBUSINESS_OPER)
{
Object->DocAllNAME_SBUSINESS_OPER=DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocVosvratPokImpl::get_DocID_DVPOK(void)
{
return Object->DocID_DVPOK;
}
//---------------------------------------------------------------
void TDMDocVosvratPokImpl::set_DocID_DVPOK(TFIBLargeIntField * DocID_DVPOK)
{
Object->DocID_DVPOK=DocID_DVPOK;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocVosvratPokImpl::get_DocGID_DVPOK(void)
{
return Object->DocGID_DVPOK;
}
//---------------------------------------------------------------
void TDMDocVosvratPokImpl::set_DocGID_DVPOK(TFIBWideStringField * DocGID_DVPOK)
{
Object->DocGID_DVPOK=DocGID_DVPOK;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocVosvratPokImpl::get_DocIDDOC_DVPOK(void)
{
return Object->DocIDDOC_DVPOK;
}
//---------------------------------------------------------------
void TDMDocVosvratPokImpl::set_DocIDDOC_DVPOK(TFIBLargeIntField * DocIDDOC_DVPOK)
{
Object->DocIDDOC_DVPOK=DocIDDOC_DVPOK;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocVosvratPokImpl::get_DocIDTPRICE_DVPOK(void)
{
return Object->DocIDTPRICE_DVPOK;
}
//---------------------------------------------------------------
void TDMDocVosvratPokImpl::set_DocIDTPRICE_DVPOK(TFIBLargeIntField * DocIDTPRICE_DVPOK)
{
Object->DocIDTPRICE_DVPOK=DocIDTPRICE_DVPOK;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocVosvratPokImpl::get_DocIDRTPRICE_DVPOK(void)
{
return Object->DocIDRTPRICE_DVPOK;
}
//---------------------------------------------------------------
void TDMDocVosvratPokImpl::set_DocIDRTPRICE_DVPOK(TFIBLargeIntField * DocIDRTPRICE_DVPOK)
{
Object->DocIDRTPRICE_DVPOK=DocIDRTPRICE_DVPOK;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocVosvratPokImpl::get_DocDESCR_DVPOK(void)
{
return Object->DocDESCR_DVPOK;
}
//---------------------------------------------------------------
void TDMDocVosvratPokImpl::set_DocDESCR_DVPOK(TFIBWideStringField * DocDESCR_DVPOK)
{
Object->DocDESCR_DVPOK=DocDESCR_DVPOK;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocVosvratPokImpl::get_DocOPER_DVPOK(void)
{
return Object->DocOPER_DVPOK;
}
//---------------------------------------------------------------
void TDMDocVosvratPokImpl::set_DocOPER_DVPOK(TFIBIntegerField * DocOPER_DVPOK)
{
Object->DocOPER_DVPOK=DocOPER_DVPOK;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocVosvratPokImpl::get_DocSUM_DVPOK(void)
{
return Object->DocSUM_DVPOK;
}
//---------------------------------------------------------------
void TDMDocVosvratPokImpl::set_DocSUM_DVPOK(TFIBBCDField * DocSUM_DVPOK)
{
Object->DocSUM_DVPOK=DocSUM_DVPOK;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocVosvratPokImpl::get_DocIDBASE_DVPOK(void)
{
return Object->DocIDBASE_DVPOK;
}
//---------------------------------------------------------------
void TDMDocVosvratPokImpl::set_DocIDBASE_DVPOK(TFIBLargeIntField * DocIDBASE_DVPOK)
{
Object->DocIDBASE_DVPOK=DocIDBASE_DVPOK;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocVosvratPokImpl::get_DocTID_DVPOKT(void)
{
return Object->DocTID_DVPOKT;
}
//---------------------------------------------------------------
void TDMDocVosvratPokImpl::set_DocTID_DVPOKT(TFIBLargeIntField * DocTID_DVPOKT)
{
Object->DocTID_DVPOKT=DocTID_DVPOKT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocVosvratPokImpl::get_DocTGID_DVPOKT(void)
{
return Object->DocTGID_DVPOKT;
}
//---------------------------------------------------------------
void TDMDocVosvratPokImpl::set_DocTGID_DVPOKT(TFIBWideStringField * DocTGID_DVPOKT)
{
Object->DocTGID_DVPOKT=DocTGID_DVPOKT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocVosvratPokImpl::get_DocTIDDOC_DVPOKT(void)
{
return Object->DocTIDDOC_DVPOKT;
}
//---------------------------------------------------------------
void TDMDocVosvratPokImpl::set_DocTIDDOC_DVPOKT(TFIBLargeIntField * DocTIDDOC_DVPOKT)
{
Object->DocTIDDOC_DVPOKT=DocTIDDOC_DVPOKT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocVosvratPokImpl::get_DocTIDNOM_DVPOKT(void)
{
return Object->DocTIDNOM_DVPOKT;
}
//---------------------------------------------------------------
void TDMDocVosvratPokImpl::set_DocTIDNOM_DVPOKT(TFIBLargeIntField * DocTIDNOM_DVPOKT)
{
Object->DocTIDNOM_DVPOKT=DocTIDNOM_DVPOKT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocVosvratPokImpl::get_DocTIDED_DVPOKT(void)
{
return Object->DocTIDED_DVPOKT;
}
//---------------------------------------------------------------
void TDMDocVosvratPokImpl::set_DocTIDED_DVPOKT(TFIBLargeIntField * DocTIDED_DVPOKT)
{
Object->DocTIDED_DVPOKT=DocTIDED_DVPOKT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocVosvratPokImpl::get_DocTIDPART_DVPOKT(void)
{
return Object->DocTIDPART_DVPOKT;
}
//---------------------------------------------------------------
void TDMDocVosvratPokImpl::set_DocTIDPART_DVPOKT(TFIBLargeIntField * DocTIDPART_DVPOKT)
{
Object->DocTIDPART_DVPOKT=DocTIDPART_DVPOKT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocVosvratPokImpl::get_DocTKOL_DVPOKT(void)
{
return Object->DocTKOL_DVPOKT;
}
//---------------------------------------------------------------
void TDMDocVosvratPokImpl::set_DocTKOL_DVPOKT(TFIBBCDField * DocTKOL_DVPOKT)
{
Object->DocTKOL_DVPOKT=DocTKOL_DVPOKT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocVosvratPokImpl::get_DocTKF_DVPOKT(void)
{
return Object->DocTKF_DVPOKT;
}
//---------------------------------------------------------------
void TDMDocVosvratPokImpl::set_DocTKF_DVPOKT(TFIBBCDField * DocTKF_DVPOKT)
{
Object->DocTKF_DVPOKT=DocTKF_DVPOKT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocVosvratPokImpl::get_DocTPRICE_DVPOKT(void)
{
return Object->DocTPRICE_DVPOKT;
}
//---------------------------------------------------------------
void TDMDocVosvratPokImpl::set_DocTPRICE_DVPOKT(TFIBBCDField * DocTPRICE_DVPOKT)
{
Object->DocTPRICE_DVPOKT=DocTPRICE_DVPOKT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocVosvratPokImpl::get_DocTSUM_DVPOKT(void)
{
return Object->DocTSUM_DVPOKT;
}
//---------------------------------------------------------------
void TDMDocVosvratPokImpl::set_DocTSUM_DVPOKT(TFIBBCDField * DocTSUM_DVPOKT)
{
Object->DocTSUM_DVPOKT=DocTSUM_DVPOKT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocVosvratPokImpl::get_DocTRPRICE_DVPOKT(void)
{
return Object->DocTRPRICE_DVPOKT;
}
//---------------------------------------------------------------
void TDMDocVosvratPokImpl::set_DocTRPRICE_DVPOKT(TFIBBCDField * DocTRPRICE_DVPOKT)
{
Object->DocTRPRICE_DVPOKT=DocTRPRICE_DVPOKT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocVosvratPokImpl::get_DocTRSUM_DVPOKT(void)
{
return Object->DocTRSUM_DVPOKT;
}
//---------------------------------------------------------------
void TDMDocVosvratPokImpl::set_DocTRSUM_DVPOKT(TFIBBCDField * DocTRSUM_DVPOKT)
{
Object->DocTRSUM_DVPOKT=DocTRSUM_DVPOKT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocVosvratPokImpl::get_DocTIDBASE_DVPOKT(void)
{
return Object->DocTIDBASE_DVPOKT;
}
//---------------------------------------------------------------
void TDMDocVosvratPokImpl::set_DocTIDBASE_DVPOKT(TFIBLargeIntField * DocTIDBASE_DVPOKT)
{
Object->DocTIDBASE_DVPOKT=DocTIDBASE_DVPOKT;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocVosvratPokImpl::get_DocTNDS_DVPOKT(void)
{
return Object->DocTNDS_DVPOKT;
}
//---------------------------------------------------------------
void TDMDocVosvratPokImpl::set_DocTNDS_DVPOKT(TFIBIntegerField * DocTNDS_DVPOKT)
{
Object->DocTNDS_DVPOKT=DocTNDS_DVPOKT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocVosvratPokImpl::get_DocTSUMNDS_DVPOKT(void)
{
return Object->DocTSUMNDS_DVPOKT;
}
//---------------------------------------------------------------
void TDMDocVosvratPokImpl::set_DocTSUMNDS_DVPOKT(TFIBBCDField * DocTSUMNDS_DVPOKT)
{
Object->DocTSUMNDS_DVPOKT=DocTSUMNDS_DVPOKT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocVosvratPokImpl::get_DocTNAMENOM(void)
{
return Object->DocTNAMENOM;
}
//---------------------------------------------------------------
void TDMDocVosvratPokImpl::set_DocTNAMENOM(TFIBWideStringField * DocTNAMENOM)
{
Object->DocTNAMENOM=DocTNAMENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocVosvratPokImpl::get_DocTNAMEED(void)
{
return Object->DocTNAMEED;
}
//---------------------------------------------------------------
void TDMDocVosvratPokImpl::set_DocTNAMEED(TFIBWideStringField * DocTNAMEED)
{
Object->DocTNAMEED=DocTNAMEED;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocVosvratPokImpl::get_DocKLIENT_NAME_DVPOK(void)
{
return Object->DocKLIENT_NAME_DVPOK;
}
//---------------------------------------------------------------
void TDMDocVosvratPokImpl::set_DocKLIENT_NAME_DVPOK(TFIBWideStringField * DocKLIENT_NAME_DVPOK)
{
Object->DocKLIENT_NAME_DVPOK=DocKLIENT_NAME_DVPOK;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocVosvratPokImpl::get_DocKLIENT_ADR_DVPOK(void)
{
return Object->DocKLIENT_ADR_DVPOK;
}
//---------------------------------------------------------------
void TDMDocVosvratPokImpl::set_DocKLIENT_ADR_DVPOK(TFIBWideStringField * DocKLIENT_ADR_DVPOK)
{
Object->DocKLIENT_ADR_DVPOK=DocKLIENT_ADR_DVPOK;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocVosvratPokImpl::get_DocKLIENT_PHONE_DVPOK(void)
{
return Object->DocKLIENT_PHONE_DVPOK;
}
//---------------------------------------------------------------
void TDMDocVosvratPokImpl::set_DocKLIENT_PHONE_DVPOK(TFIBWideStringField * DocKLIENT_PHONE_DVPOK)
{
Object->DocKLIENT_PHONE_DVPOK=DocKLIENT_PHONE_DVPOK;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocVosvratPokImpl::get_DocKLIENT_PASSPORT_DVPOK(void)
{
return Object->DocKLIENT_PASSPORT_DVPOK;
}
//---------------------------------------------------------------
void TDMDocVosvratPokImpl::set_DocKLIENT_PASSPORT_DVPOK(TFIBWideStringField * DocKLIENT_PASSPORT_DVPOK)
{
Object->DocKLIENT_PASSPORT_DVPOK=DocKLIENT_PASSPORT_DVPOK;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocVosvratPokImpl::get_DocPRICHINA_DVPOK(void)
{
return Object->DocPRICHINA_DVPOK;
}
//---------------------------------------------------------------
void TDMDocVosvratPokImpl::set_DocPRICHINA_DVPOK(TFIBWideStringField * DocPRICHINA_DVPOK)
{
Object->DocPRICHINA_DVPOK=DocPRICHINA_DVPOK;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocVosvratPokImpl::get_DocNUMDOCSALE_DVPOK(void)
{
return Object->DocNUMDOCSALE_DVPOK;
}
//---------------------------------------------------------------
void TDMDocVosvratPokImpl::set_DocNUMDOCSALE_DVPOK(TFIBWideStringField * DocNUMDOCSALE_DVPOK)
{
Object->DocNUMDOCSALE_DVPOK=DocNUMDOCSALE_DVPOK;
}
//---------------------------------------------------------------
TFIBDateTimeField * TDMDocVosvratPokImpl::get_DocPOSDOCSALE_DVPOK(void)
{
return Object->DocPOSDOCSALE_DVPOK;
}
//---------------------------------------------------------------
void TDMDocVosvratPokImpl::set_DocPOSDOCSALE_DVPOK(TFIBDateTimeField * DocPOSDOCSALE_DVPOK)
{
Object->DocPOSDOCSALE_DVPOK=DocPOSDOCSALE_DVPOK;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocVosvratPokImpl::get_DocNUMDOCKL_DVPOK(void)
{
return Object->DocNUMDOCKL_DVPOK;
}
//---------------------------------------------------------------
void TDMDocVosvratPokImpl::set_DocNUMDOCKL_DVPOK(TFIBWideStringField * DocNUMDOCKL_DVPOK)
{
Object->DocNUMDOCKL_DVPOK=DocNUMDOCKL_DVPOK;
}
//---------------------------------------------------------------
TFIBDateTimeField * TDMDocVosvratPokImpl::get_DocPOSDOCKL_DVPOK(void)
{
return Object->DocPOSDOCKL_DVPOK;
}
//---------------------------------------------------------------
void TDMDocVosvratPokImpl::set_DocPOSDOCKL_DVPOK(TFIBDateTimeField * DocPOSDOCKL_DVPOK)
{
Object->DocPOSDOCKL_DVPOK=DocPOSDOCKL_DVPOK;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocVosvratPokImpl::get_DocOsn(void)
{
return Object->DocOsn;
}
//---------------------------------------------------------------
void TDMDocVosvratPokImpl::set_DocOsn(TpFIBDataSet * DocOsn)
{
Object->DocOsn=DocOsn;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocVosvratPokImpl::get_DocOsnTDOC(void)
{
return Object->DocOsnTDOC;
}
//---------------------------------------------------------------
void TDMDocVosvratPokImpl::set_DocOsnTDOC(TFIBWideStringField * DocOsnTDOC)
{
Object->DocOsnTDOC=DocOsnTDOC;
}
//---------------------------------------------------------------
TFIBDateTimeField * TDMDocVosvratPokImpl::get_DocOsnPOSDOC(void)
{
return Object->DocOsnPOSDOC;
}
//---------------------------------------------------------------
void TDMDocVosvratPokImpl::set_DocOsnPOSDOC(TFIBDateTimeField * DocOsnPOSDOC)
{
Object->DocOsnPOSDOC=DocOsnPOSDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocVosvratPokImpl::get_DocOsnNUMDOC(void)
{
return Object->DocOsnNUMDOC;
}
//---------------------------------------------------------------
void TDMDocVosvratPokImpl::set_DocOsnNUMDOC(TFIBIntegerField * DocOsnNUMDOC)
{
Object->DocOsnNUMDOC=DocOsnNUMDOC;
}
//---------------------------------------------------------------
TDataSource * TDMDocVosvratPokImpl::get_DataSourceDocOsn(void)
{
return Object->DataSourceDocOsn;
}
//---------------------------------------------------------------
void TDMDocVosvratPokImpl::set_DataSourceDocOsn(TDataSource * DataSourceDocOsn)
{
Object->DataSourceDocOsn=DataSourceDocOsn;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocVosvratPokImpl::get_DocAllPREFIKS_NUM_GALLDOC(void)
{
return Object->DocAllPREFIKS_NUM_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocVosvratPokImpl::set_DocAllPREFIKS_NUM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_GALLDOC)
{
Object->DocAllPREFIKS_NUM_GALLDOC=DocAllPREFIKS_NUM_GALLDOC;
}
//---------------------------------------------------------------
bool TDMDocVosvratPokImpl::get_NewElement(void)
{
return Object->NewElement;
}
//---------------------------------------------------------------
void TDMDocVosvratPokImpl::set_NewElement(bool NewElement)
{
Object->NewElement=NewElement;
}
//---------------------------------------------------------------
bool TDMDocVosvratPokImpl::get_Prosmotr(void)
{
return Object->Prosmotr;
}
//---------------------------------------------------------------
void TDMDocVosvratPokImpl::set_Prosmotr(bool Prosmotr)
{
Object->Prosmotr=Prosmotr;
}
//---------------------------------------------------------------
__int64 TDMDocVosvratPokImpl::get_IdDoc(void)
{
return Object->IdDoc;
}
//---------------------------------------------------------------
void TDMDocVosvratPokImpl::set_IdDoc(__int64 IdDoc)
{
Object->IdDoc=IdDoc;
}
//---------------------------------------------------------------
__int64 TDMDocVosvratPokImpl::get_IdTypePrice(void)
{
return Object->IdTypePrice;
}
//---------------------------------------------------------------
void TDMDocVosvratPokImpl::set_IdTypePrice(__int64 IdTypePrice)
{
Object->IdTypePrice=IdTypePrice;
}
//---------------------------------------------------------------
bool TDMDocVosvratPokImpl::get_IsmPrice(void)
{
return Object->IsmPrice;
}
//---------------------------------------------------------------
void TDMDocVosvratPokImpl::set_IsmPrice(bool IsmPrice)
{
Object->IsmPrice=IsmPrice;
}
//---------------------------------------------------------------
bool TDMDocVosvratPokImpl::get_IsmSum(void)
{
return Object->IsmSum;
}
//---------------------------------------------------------------
void TDMDocVosvratPokImpl::set_IsmSum(bool IsmSum)
{
Object->IsmSum=IsmSum;
}
//---------------------------------------------------------------
bool TDMDocVosvratPokImpl::get_EnableDvReg(void)
{
return Object->EnableDvReg;
}
//---------------------------------------------------------------
void TDMDocVosvratPokImpl::set_EnableDvReg(bool EnableDvReg)
{
Object->EnableDvReg=EnableDvReg;
}
//---------------------------------------------------------------
void TDMDocVosvratPokImpl::NewDoc(void)
{
return Object->NewDoc();
}
//---------------------------------------------------------------
void TDMDocVosvratPokImpl::OpenDoc(__int64 IdDoc)
{
return Object->OpenDoc(IdDoc);
}
//---------------------------------------------------------------
void TDMDocVosvratPokImpl::OpenDocOsn(void)
{
return Object->OpenDocOsn();
}
//---------------------------------------------------------------
bool TDMDocVosvratPokImpl::SaveDoc(void)
{
return Object->SaveDoc();
}
//---------------------------------------------------------------
bool TDMDocVosvratPokImpl::DvRegDoc(void)
{
return Object->DvRegDoc();
}
//---------------------------------------------------------------
bool TDMDocVosvratPokImpl::CancelDvRegDoc(void)
{
return Object->CancelDvRegDoc();
}
//---------------------------------------------------------------
void TDMDocVosvratPokImpl::AddDocNewString(void)
{
return Object->AddDocNewString();
}
//---------------------------------------------------------------
void TDMDocVosvratPokImpl::DeleteStringDoc(void)
{
return Object->DeleteStringDoc();
}
//---------------------------------------------------------------
bool TDMDocVosvratPokImpl::DeleteDoc(__int64 id)
{
return Object->DeleteDoc(id);
}
//---------------------------------------------------------------
__int64 TDMDocVosvratPokImpl::GetIDDocPoNomeruDoc(int number_doc, TDate date_doc)
{
return Object->GetIDDocPoNomeruDoc(number_doc, date_doc);
}
//---------------------------------------------------------------
void TDMDocVosvratPokImpl::AddZakPrice(void)
{
return Object->AddZakPrice();
}
//---------------------------------------------------------------
