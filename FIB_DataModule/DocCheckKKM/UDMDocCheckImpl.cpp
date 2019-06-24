#include "vcl.h"
#pragma hdrstop


#include "UDMDocCheckImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMDocCheckImpl::TDMDocCheckImpl()           
{                                            
Object=new TDMDocCheck(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMDocCheckImpl::~TDMDocCheckImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMDocCheckImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMDocCheckImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMDocCheck)                        
   {                                                                     
   *ppv=static_cast<IDMDocCheck*> (this);                                
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
int TDMDocCheckImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMDocCheckImpl::kanRelease(void)                                  
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
int  TDMDocCheckImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMDocCheckImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMDocCheckImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMDocCheckImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMDocCheckImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMDocCheckImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMDocCheckImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMDocCheck
TDataSource * TDMDocCheckImpl::get_DataSourceDoc(void)
{
return Object->DataSourceDoc;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DataSourceDoc(TDataSource * DataSourceDoc)
{
Object->DataSourceDoc=DataSourceDoc;
}
//---------------------------------------------------------------
TDataSource * TDMDocCheckImpl::get_DataSourceDocT(void)
{
return Object->DataSourceDocT;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DataSourceDocT(TDataSource * DataSourceDocT)
{
Object->DataSourceDocT=DataSourceDocT;
}
//---------------------------------------------------------------
TDataSource * TDMDocCheckImpl::get_DataSourceDocAll(void)
{
return Object->DataSourceDocAll;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DataSourceDocAll(TDataSource * DataSourceDocAll)
{
Object->DataSourceDocAll=DataSourceDocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocCheckImpl::get_DocAll(void)
{
return Object->DocAll;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocAll(TpFIBDataSet * DocAll)
{
Object->DocAll=DocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocCheckImpl::get_Doc(void)
{
return Object->Doc;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_Doc(TpFIBDataSet * Doc)
{
Object->Doc=Doc;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocCheckImpl::get_DocT(void)
{
return Object->DocT;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocT(TpFIBDataSet * DocT)
{
Object->DocT=DocT;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocCheckImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocCheckImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TFIBDateTimeField * TDMDocCheckImpl::get_DocAllPOSDOC(void)
{
return Object->DocAllPOSDOC;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocAllPOSDOC(TFIBDateTimeField * DocAllPOSDOC)
{
Object->DocAllPOSDOC=DocAllPOSDOC;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMDocCheckImpl::get_DocAllPRDOC(void)
{
return Object->DocAllPRDOC;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocAllPRDOC(TFIBSmallIntField * DocAllPRDOC)
{
Object->DocAllPRDOC=DocAllPRDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocCheckImpl::get_DocAllNUMDOC(void)
{
return Object->DocAllNUMDOC;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocAllNUMDOC(TFIBIntegerField * DocAllNUMDOC)
{
Object->DocAllNUMDOC=DocAllNUMDOC;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocCheckImpl::get_IBTrDvReg(void)
{
return Object->IBTrDvReg;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_IBTrDvReg(TpFIBTransaction * IBTrDvReg)
{
Object->IBTrDvReg=IBTrDvReg;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocCheckImpl::get_NumDoc(void)
{
return Object->NumDoc;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_NumDoc(TpFIBDataSet * NumDoc)
{
Object->NumDoc=NumDoc;
}
//---------------------------------------------------------------

TpFIBDataSet * TDMDocCheckImpl::get_SpisokTypePrice(void)
{
return Object->SpisokTypePrice;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_SpisokTypePrice(TpFIBDataSet * SpisokTypePrice)
{
Object->SpisokTypePrice=SpisokTypePrice;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocCheckImpl::get_SpisokTypePriceID_TPRICE(void)
{
return Object->SpisokTypePriceID_TPRICE;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_SpisokTypePriceID_TPRICE(TFIBIntegerField * SpisokTypePriceID_TPRICE)
{
Object->SpisokTypePriceID_TPRICE=SpisokTypePriceID_TPRICE;
}
//---------------------------------------------------------------
TpFIBQuery * TDMDocCheckImpl::get_QueryCancelDvReg(void)
{
return Object->QueryCancelDvReg;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg)
{
Object->QueryCancelDvReg=QueryCancelDvReg;
}
//---------------------------------------------------------------
TpFIBQuery * TDMDocCheckImpl::get_QueryDvReg(void)
{
return Object->QueryDvReg;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_QueryDvReg(TpFIBQuery * QueryDvReg)
{
Object->QueryDvReg=QueryDvReg;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocCheckImpl::get_DocOsn(void)
{
return Object->DocOsn;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocOsn(TpFIBDataSet * DocOsn)
{
Object->DocOsn=DocOsn;
}
//---------------------------------------------------------------
TDataSource * TDMDocCheckImpl::get_DataSourceDocOsn(void)
{
return Object->DataSourceDocOsn;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DataSourceDocOsn(TDataSource * DataSourceDocOsn)
{
Object->DataSourceDocOsn=DataSourceDocOsn;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocCheckImpl::get_DocOpl(void)
{
return Object->DocOpl;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocOpl(TpFIBDataSet * DocOpl)
{
Object->DocOpl=DocOpl;
}
//---------------------------------------------------------------
TDataSource * TDMDocCheckImpl::get_DataSourceDocOpl(void)
{
return Object->DataSourceDocOpl;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DataSourceDocOpl(TDataSource * DataSourceDocOpl)
{
Object->DataSourceDocOpl=DataSourceDocOpl;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocCheckImpl::get_DocAllIDDOC(void)
{
return Object->DocAllIDDOC;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocAllIDDOC(TFIBLargeIntField * DocAllIDDOC)
{
Object->DocAllIDDOC=DocAllIDDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocCheckImpl::get_DocAllTDOC(void)
{
return Object->DocAllTDOC;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocAllTDOC(TFIBWideStringField * DocAllTDOC)
{
Object->DocAllTDOC=DocAllTDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocCheckImpl::get_DocAllIDFIRMDOC(void)
{
return Object->DocAllIDFIRMDOC;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocAllIDFIRMDOC(TFIBLargeIntField * DocAllIDFIRMDOC)
{
Object->DocAllIDFIRMDOC=DocAllIDFIRMDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocCheckImpl::get_DocAllIDSKLDOC(void)
{
return Object->DocAllIDSKLDOC;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocAllIDSKLDOC(TFIBLargeIntField * DocAllIDSKLDOC)
{
Object->DocAllIDSKLDOC=DocAllIDSKLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocCheckImpl::get_DocAllIDKLDOC(void)
{
return Object->DocAllIDKLDOC;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocAllIDKLDOC(TFIBLargeIntField * DocAllIDKLDOC)
{
Object->DocAllIDKLDOC=DocAllIDKLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocCheckImpl::get_DocAllIDDOGDOC(void)
{
return Object->DocAllIDDOGDOC;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocAllIDDOGDOC(TFIBLargeIntField * DocAllIDDOGDOC)
{
Object->DocAllIDDOGDOC=DocAllIDDOGDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocCheckImpl::get_DocAllSUMDOC(void)
{
return Object->DocAllSUMDOC;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocAllSUMDOC(TFIBBCDField * DocAllSUMDOC)
{
Object->DocAllSUMDOC=DocAllSUMDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocCheckImpl::get_DocAllIDUSERDOC(void)
{
return Object->DocAllIDUSERDOC;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocAllIDUSERDOC(TFIBLargeIntField * DocAllIDUSERDOC)
{
Object->DocAllIDUSERDOC=DocAllIDUSERDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocCheckImpl::get_DocAllGID_DOC(void)
{
return Object->DocAllGID_DOC;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocAllGID_DOC(TFIBWideStringField * DocAllGID_DOC)
{
Object->DocAllGID_DOC=DocAllGID_DOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocCheckImpl::get_DocAllPREFIKSDOC(void)
{
return Object->DocAllPREFIKSDOC;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocAllPREFIKSDOC(TFIBWideStringField * DocAllPREFIKSDOC)
{
Object->DocAllPREFIKSDOC=DocAllPREFIKSDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocCheckImpl::get_DocAllIDDOCOSNDOC(void)
{
return Object->DocAllIDDOCOSNDOC;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocAllIDDOCOSNDOC(TFIBLargeIntField * DocAllIDDOCOSNDOC)
{
Object->DocAllIDDOCOSNDOC=DocAllIDDOCOSNDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocCheckImpl::get_DocAllIDEXTDOC(void)
{
return Object->DocAllIDEXTDOC;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocAllIDEXTDOC(TFIBLargeIntField * DocAllIDEXTDOC)
{
Object->DocAllIDEXTDOC=DocAllIDEXTDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocCheckImpl::get_DocAllTYPEEXTDOC(void)
{
return Object->DocAllTYPEEXTDOC;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocAllTYPEEXTDOC(TFIBIntegerField * DocAllTYPEEXTDOC)
{
Object->DocAllTYPEEXTDOC=DocAllTYPEEXTDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocCheckImpl::get_DocAllIDBASE_GALLDOC(void)
{
return Object->DocAllIDBASE_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocAllIDBASE_GALLDOC(TFIBLargeIntField * DocAllIDBASE_GALLDOC)
{
Object->DocAllIDBASE_GALLDOC=DocAllIDBASE_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocCheckImpl::get_DocAllIDPROJECT_GALLDOC(void)
{
return Object->DocAllIDPROJECT_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocAllIDPROJECT_GALLDOC(TFIBLargeIntField * DocAllIDPROJECT_GALLDOC)
{
Object->DocAllIDPROJECT_GALLDOC=DocAllIDPROJECT_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocCheckImpl::get_DocAllFNAME_USER(void)
{
return Object->DocAllFNAME_USER;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocAllFNAME_USER(TFIBWideStringField * DocAllFNAME_USER)
{
Object->DocAllFNAME_USER=DocAllFNAME_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocCheckImpl::get_DocAllNAME_SDOG(void)
{
return Object->DocAllNAME_SDOG;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocAllNAME_SDOG(TFIBWideStringField * DocAllNAME_SDOG)
{
Object->DocAllNAME_SDOG=DocAllNAME_SDOG;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocCheckImpl::get_DocAllNAMEKLIENT(void)
{
return Object->DocAllNAMEKLIENT;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocAllNAMEKLIENT(TFIBWideStringField * DocAllNAMEKLIENT)
{
Object->DocAllNAMEKLIENT=DocAllNAMEKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocCheckImpl::get_DocAllNAME_SINFBASE_OBMEN(void)
{
return Object->DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN)
{
Object->DocAllNAME_SINFBASE_OBMEN=DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocCheckImpl::get_DocAllNAMEFIRM(void)
{
return Object->DocAllNAMEFIRM;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocAllNAMEFIRM(TFIBWideStringField * DocAllNAMEFIRM)
{
Object->DocAllNAMEFIRM=DocAllNAMEFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocCheckImpl::get_DocAllNAMESKLAD(void)
{
return Object->DocAllNAMESKLAD;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocAllNAMESKLAD(TFIBWideStringField * DocAllNAMESKLAD)
{
Object->DocAllNAMESKLAD=DocAllNAMESKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocCheckImpl::get_DocAllNAME_SPROJECT(void)
{
return Object->DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocAllNAME_SPROJECT(TFIBWideStringField * DocAllNAME_SPROJECT)
{
Object->DocAllNAME_SPROJECT=DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocCheckImpl::get_DocOsnTDOC(void)
{
return Object->DocOsnTDOC;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocOsnTDOC(TFIBWideStringField * DocOsnTDOC)
{
Object->DocOsnTDOC=DocOsnTDOC;
}
//---------------------------------------------------------------
TFIBDateTimeField * TDMDocCheckImpl::get_DocOsnPOSDOC(void)
{
return Object->DocOsnPOSDOC;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocOsnPOSDOC(TFIBDateTimeField * DocOsnPOSDOC)
{
Object->DocOsnPOSDOC=DocOsnPOSDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocCheckImpl::get_DocOsnNUMDOC(void)
{
return Object->DocOsnNUMDOC;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocOsnNUMDOC(TFIBIntegerField * DocOsnNUMDOC)
{
Object->DocOsnNUMDOC=DocOsnNUMDOC;
}
//---------------------------------------------------------------
TIntegerField * TDMDocCheckImpl::get_DocOplRECNO(void)
{
return Object->DocOplRECNO;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocOplRECNO(TIntegerField * DocOplRECNO)
{
Object->DocOplRECNO=DocOplRECNO;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocCheckImpl::get_DocIDCHK(void)
{
return Object->DocIDCHK;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocIDCHK(TFIBLargeIntField * DocIDCHK)
{
Object->DocIDCHK=DocIDCHK;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocCheckImpl::get_DocIDDOCCHK(void)
{
return Object->DocIDDOCCHK;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocIDDOCCHK(TFIBLargeIntField * DocIDDOCCHK)
{
Object->DocIDDOCCHK=DocIDDOCCHK;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocCheckImpl::get_DocIDKKMCHK(void)
{
return Object->DocIDKKMCHK;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocIDKKMCHK(TFIBLargeIntField * DocIDKKMCHK)
{
Object->DocIDKKMCHK=DocIDKKMCHK;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocCheckImpl::get_DocIDTPRICE(void)
{
return Object->DocIDTPRICE;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocIDTPRICE(TFIBLargeIntField * DocIDTPRICE)
{
Object->DocIDTPRICE=DocIDTPRICE;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocCheckImpl::get_DocNCHECKCHK(void)
{
return Object->DocNCHECKCHK;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocNCHECKCHK(TFIBIntegerField * DocNCHECKCHK)
{
Object->DocNCHECKCHK=DocNCHECKCHK;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocCheckImpl::get_DocNKLCHK(void)
{
return Object->DocNKLCHK;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocNKLCHK(TFIBIntegerField * DocNKLCHK)
{
Object->DocNKLCHK=DocNKLCHK;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocCheckImpl::get_DocOPERCHK(void)
{
return Object->DocOPERCHK;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocOPERCHK(TFIBIntegerField * DocOPERCHK)
{
Object->DocOPERCHK=DocOPERCHK;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocCheckImpl::get_DocOPLNALCHK(void)
{
return Object->DocOPLNALCHK;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocOPLNALCHK(TFIBBCDField * DocOPLNALCHK)
{
Object->DocOPLNALCHK=DocOPLNALCHK;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocCheckImpl::get_DocOPLPCCHK(void)
{
return Object->DocOPLPCCHK;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocOPLPCCHK(TFIBBCDField * DocOPLPCCHK)
{
Object->DocOPLPCCHK=DocOPLPCCHK;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocCheckImpl::get_DocNALCHK(void)
{
return Object->DocNALCHK;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocNALCHK(TFIBBCDField * DocNALCHK)
{
Object->DocNALCHK=DocNALCHK;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocCheckImpl::get_DocPRIMCHK(void)
{
return Object->DocPRIMCHK;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocPRIMCHK(TFIBWideStringField * DocPRIMCHK)
{
Object->DocPRIMCHK=DocPRIMCHK;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocCheckImpl::get_DocGID_DCHK(void)
{
return Object->DocGID_DCHK;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocGID_DCHK(TFIBWideStringField * DocGID_DCHK)
{
Object->DocGID_DCHK=DocGID_DCHK;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMDocCheckImpl::get_DocDVREGCHK(void)
{
return Object->DocDVREGCHK;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocDVREGCHK(TFIBSmallIntField * DocDVREGCHK)
{
Object->DocDVREGCHK=DocDVREGCHK;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocCheckImpl::get_DocSAVNUMCHK(void)
{
return Object->DocSAVNUMCHK;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocSAVNUMCHK(TFIBWideStringField * DocSAVNUMCHK)
{
Object->DocSAVNUMCHK=DocSAVNUMCHK;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocCheckImpl::get_DocMODELCHK(void)
{
return Object->DocMODELCHK;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocMODELCHK(TFIBWideStringField * DocMODELCHK)
{
Object->DocMODELCHK=DocMODELCHK;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocCheckImpl::get_DocREGNUMCHK(void)
{
return Object->DocREGNUMCHK;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocREGNUMCHK(TFIBWideStringField * DocREGNUMCHK)
{
Object->DocREGNUMCHK=DocREGNUMCHK;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocCheckImpl::get_DocIDDCARDCHK(void)
{
return Object->DocIDDCARDCHK;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocIDDCARDCHK(TFIBLargeIntField * DocIDDCARDCHK)
{
Object->DocIDDCARDCHK=DocIDDCARDCHK;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocCheckImpl::get_DocIDBASE_DCHK(void)
{
return Object->DocIDBASE_DCHK;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocIDBASE_DCHK(TFIBLargeIntField * DocIDBASE_DCHK)
{
Object->DocIDBASE_DCHK=DocIDBASE_DCHK;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocCheckImpl::get_DocSDACHA_DCHK(void)
{
return Object->DocSDACHA_DCHK;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocSDACHA_DCHK(TFIBBCDField * DocSDACHA_DCHK)
{
Object->DocSDACHA_DCHK=DocSDACHA_DCHK;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocCheckImpl::get_DocIDBSCHET_DCHK(void)
{
return Object->DocIDBSCHET_DCHK;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocIDBSCHET_DCHK(TFIBLargeIntField * DocIDBSCHET_DCHK)
{
Object->DocIDBSCHET_DCHK=DocIDBSCHET_DCHK;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocCheckImpl::get_DocOPLPLATCARD_DCHK(void)
{
return Object->DocOPLPLATCARD_DCHK;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocOPLPLATCARD_DCHK(TFIBBCDField * DocOPLPLATCARD_DCHK)
{
Object->DocOPLPLATCARD_DCHK=DocOPLPLATCARD_DCHK;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocCheckImpl::get_DocOPLCREDITCARD_DCHK(void)
{
return Object->DocOPLCREDITCARD_DCHK;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocOPLCREDITCARD_DCHK(TFIBBCDField * DocOPLCREDITCARD_DCHK)
{
Object->DocOPLCREDITCARD_DCHK=DocOPLCREDITCARD_DCHK;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocCheckImpl::get_DocOPLPLATCARD_ALL_DCHK(void)
{
return Object->DocOPLPLATCARD_ALL_DCHK;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocOPLPLATCARD_ALL_DCHK(TFIBBCDField * DocOPLPLATCARD_ALL_DCHK)
{
Object->DocOPLPLATCARD_ALL_DCHK=DocOPLPLATCARD_ALL_DCHK;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocCheckImpl::get_DocOPLCREDITCARD_ALL_DCHK(void)
{
return Object->DocOPLCREDITCARD_ALL_DCHK;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocOPLCREDITCARD_ALL_DCHK(TFIBBCDField * DocOPLCREDITCARD_ALL_DCHK)
{
Object->DocOPLCREDITCARD_ALL_DCHK=DocOPLCREDITCARD_ALL_DCHK;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocCheckImpl::get_DocNAMEKKM(void)
{
return Object->DocNAMEKKM;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocNAMEKKM(TFIBWideStringField * DocNAMEKKM)
{
Object->DocNAMEKKM=DocNAMEKKM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocCheckImpl::get_DocNAME_SDISCOUNT_CARD(void)
{
return Object->DocNAME_SDISCOUNT_CARD;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocNAME_SDISCOUNT_CARD(TFIBWideStringField * DocNAME_SDISCOUNT_CARD)
{
Object->DocNAME_SDISCOUNT_CARD=DocNAME_SDISCOUNT_CARD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocCheckImpl::get_DocNAMEBSCHET(void)
{
return Object->DocNAMEBSCHET;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocNAMEBSCHET(TFIBWideStringField * DocNAMEBSCHET)
{
Object->DocNAMEBSCHET=DocNAMEBSCHET;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocCheckImpl::get_DocTIDCHKT(void)
{
return Object->DocTIDCHKT;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocTIDCHKT(TFIBLargeIntField * DocTIDCHKT)
{
Object->DocTIDCHKT=DocTIDCHKT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocCheckImpl::get_DocTIDDOCCHKT(void)
{
return Object->DocTIDDOCCHKT;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocTIDDOCCHKT(TFIBLargeIntField * DocTIDDOCCHKT)
{
Object->DocTIDDOCCHKT=DocTIDDOCCHKT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocCheckImpl::get_DocTIDNOMCHKT(void)
{
return Object->DocTIDNOMCHKT;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocTIDNOMCHKT(TFIBLargeIntField * DocTIDNOMCHKT)
{
Object->DocTIDNOMCHKT=DocTIDNOMCHKT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocCheckImpl::get_DocTIDEDCHKT(void)
{
return Object->DocTIDEDCHKT;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocTIDEDCHKT(TFIBLargeIntField * DocTIDEDCHKT)
{
Object->DocTIDEDCHKT=DocTIDEDCHKT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocCheckImpl::get_DocTKOLCHKT(void)
{
return Object->DocTKOLCHKT;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocTKOLCHKT(TFIBBCDField * DocTKOLCHKT)
{
Object->DocTKOLCHKT=DocTKOLCHKT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocCheckImpl::get_DocTKFCHKT(void)
{
return Object->DocTKFCHKT;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocTKFCHKT(TFIBBCDField * DocTKFCHKT)
{
Object->DocTKFCHKT=DocTKFCHKT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocCheckImpl::get_DocTPRICECHKT(void)
{
return Object->DocTPRICECHKT;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocTPRICECHKT(TFIBBCDField * DocTPRICECHKT)
{
Object->DocTPRICECHKT=DocTPRICECHKT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocCheckImpl::get_DocTSUMCHKT(void)
{
return Object->DocTSUMCHKT;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocTSUMCHKT(TFIBBCDField * DocTSUMCHKT)
{
Object->DocTSUMCHKT=DocTSUMCHKT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocCheckImpl::get_DocTSKCHKT(void)
{
return Object->DocTSKCHKT;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocTSKCHKT(TFIBBCDField * DocTSKCHKT)
{
Object->DocTSKCHKT=DocTSKCHKT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocCheckImpl::get_DocTNADCHKT(void)
{
return Object->DocTNADCHKT;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocTNADCHKT(TFIBBCDField * DocTNADCHKT)
{
Object->DocTNADCHKT=DocTNADCHKT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocCheckImpl::get_DocTPRSKCHKT(void)
{
return Object->DocTPRSKCHKT;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocTPRSKCHKT(TFIBBCDField * DocTPRSKCHKT)
{
Object->DocTPRSKCHKT=DocTPRSKCHKT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocCheckImpl::get_DocTPRNADCHKT(void)
{
return Object->DocTPRNADCHKT;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocTPRNADCHKT(TFIBBCDField * DocTPRNADCHKT)
{
Object->DocTPRNADCHKT=DocTPRNADCHKT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocCheckImpl::get_DocTGID_DCHKT(void)
{
return Object->DocTGID_DCHKT;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocTGID_DCHKT(TFIBWideStringField * DocTGID_DCHKT)
{
Object->DocTGID_DCHKT=DocTGID_DCHKT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocCheckImpl::get_DocTIDBASE_DCHKT(void)
{
return Object->DocTIDBASE_DCHKT;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocTIDBASE_DCHKT(TFIBLargeIntField * DocTIDBASE_DCHKT)
{
Object->DocTIDBASE_DCHKT=DocTIDBASE_DCHKT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocCheckImpl::get_DocTPRSK_CARD_DCHKT(void)
{
return Object->DocTPRSK_CARD_DCHKT;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocTPRSK_CARD_DCHKT(TFIBBCDField * DocTPRSK_CARD_DCHKT)
{
Object->DocTPRSK_CARD_DCHKT=DocTPRSK_CARD_DCHKT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocCheckImpl::get_DocTPRSK_AUTO_DCHKT(void)
{
return Object->DocTPRSK_AUTO_DCHKT;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocTPRSK_AUTO_DCHKT(TFIBBCDField * DocTPRSK_AUTO_DCHKT)
{
Object->DocTPRSK_AUTO_DCHKT=DocTPRSK_AUTO_DCHKT;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocCheckImpl::get_DocTNDS_DCHKT(void)
{
return Object->DocTNDS_DCHKT;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocTNDS_DCHKT(TFIBIntegerField * DocTNDS_DCHKT)
{
Object->DocTNDS_DCHKT=DocTNDS_DCHKT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocCheckImpl::get_DocTSUMNDS_DCHKT(void)
{
return Object->DocTSUMNDS_DCHKT;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocTSUMNDS_DCHKT(TFIBBCDField * DocTSUMNDS_DCHKT)
{
Object->DocTSUMNDS_DCHKT=DocTSUMNDS_DCHKT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocCheckImpl::get_DocTKRNAMENOM(void)
{
return Object->DocTKRNAMENOM;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocTKRNAMENOM(TFIBWideStringField * DocTKRNAMENOM)
{
Object->DocTKRNAMENOM=DocTKRNAMENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocCheckImpl::get_DocTNAMENOM(void)
{
return Object->DocTNAMENOM;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocTNAMENOM(TFIBWideStringField * DocTNAMENOM)
{
Object->DocTNAMENOM=DocTNAMENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocCheckImpl::get_DocTNAMEED(void)
{
return Object->DocTNAMEED;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocTNAMEED(TFIBWideStringField * DocTNAMEED)
{
Object->DocTNAMEED=DocTNAMEED;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMDocCheckImpl::get_DocTTNOM(void)
{
return Object->DocTTNOM;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocTTNOM(TFIBSmallIntField * DocTTNOM)
{
Object->DocTTNOM=DocTTNOM;
}
//---------------------------------------------------------------
TIntegerField * TDMDocCheckImpl::get_DocTRECNO(void)
{
return Object->DocTRECNO;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocTRECNO(TIntegerField * DocTRECNO)
{
Object->DocTRECNO=DocTRECNO;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocCheckImpl::get_DocOplID_DCHK_OPL(void)
{
return Object->DocOplID_DCHK_OPL;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocOplID_DCHK_OPL(TFIBLargeIntField * DocOplID_DCHK_OPL)
{
Object->DocOplID_DCHK_OPL=DocOplID_DCHK_OPL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocCheckImpl::get_DocOplIDBASE_DCHK_OPL(void)
{
return Object->DocOplIDBASE_DCHK_OPL;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocOplIDBASE_DCHK_OPL(TFIBLargeIntField * DocOplIDBASE_DCHK_OPL)
{
Object->DocOplIDBASE_DCHK_OPL=DocOplIDBASE_DCHK_OPL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocCheckImpl::get_DocOplIDCARD_DCHK_OPL(void)
{
return Object->DocOplIDCARD_DCHK_OPL;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocOplIDCARD_DCHK_OPL(TFIBLargeIntField * DocOplIDCARD_DCHK_OPL)
{
Object->DocOplIDCARD_DCHK_OPL=DocOplIDCARD_DCHK_OPL;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocCheckImpl::get_DocOplSUMPLAT_DCHK_OPL(void)
{
return Object->DocOplSUMPLAT_DCHK_OPL;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocOplSUMPLAT_DCHK_OPL(TFIBBCDField * DocOplSUMPLAT_DCHK_OPL)
{
Object->DocOplSUMPLAT_DCHK_OPL=DocOplSUMPLAT_DCHK_OPL;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocCheckImpl::get_DocOplSUMCREDIT_DCHK_OPL(void)
{
return Object->DocOplSUMCREDIT_DCHK_OPL;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocOplSUMCREDIT_DCHK_OPL(TFIBBCDField * DocOplSUMCREDIT_DCHK_OPL)
{
Object->DocOplSUMCREDIT_DCHK_OPL=DocOplSUMCREDIT_DCHK_OPL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocCheckImpl::get_DocOplIDDOC_DCHK_OPL(void)
{
return Object->DocOplIDDOC_DCHK_OPL;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocOplIDDOC_DCHK_OPL(TFIBLargeIntField * DocOplIDDOC_DCHK_OPL)
{
Object->DocOplIDDOC_DCHK_OPL=DocOplIDDOC_DCHK_OPL;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocCheckImpl::get_DocOplNAME_SDISCOUNT_CARD(void)
{
return Object->DocOplNAME_SDISCOUNT_CARD;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocOplNAME_SDISCOUNT_CARD(TFIBWideStringField * DocOplNAME_SDISCOUNT_CARD)
{
Object->DocOplNAME_SDISCOUNT_CARD=DocOplNAME_SDISCOUNT_CARD;
}
//---------------------------------------------------------------
TFloatField * TDMDocCheckImpl::get_DocALLOPL(void)
{
return Object->DocALLOPL;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocALLOPL(TFloatField * DocALLOPL)
{
Object->DocALLOPL=DocALLOPL;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocCheckImpl::get_SpisokTypePriceNAME_TPRICE(void)
{
return Object->SpisokTypePriceNAME_TPRICE;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_SpisokTypePriceNAME_TPRICE(TFIBWideStringField * SpisokTypePriceNAME_TPRICE)
{
Object->SpisokTypePriceNAME_TPRICE=SpisokTypePriceNAME_TPRICE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocCheckImpl::get_SpisokTypePriceGID_STPRICE(void)
{
return Object->SpisokTypePriceGID_STPRICE;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_SpisokTypePriceGID_STPRICE(TFIBWideStringField * SpisokTypePriceGID_STPRICE)
{
Object->SpisokTypePriceGID_STPRICE=SpisokTypePriceGID_STPRICE;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocCheckImpl::get_DocTCODENOM(void)
{
return Object->DocTCODENOM;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocTCODENOM(TFIBIntegerField * DocTCODENOM)
{
Object->DocTCODENOM=DocTCODENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocCheckImpl::get_DocTARTNOM(void)
{
return Object->DocTARTNOM;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocTARTNOM(TFIBWideStringField * DocTARTNOM)
{
Object->DocTARTNOM=DocTARTNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocCheckImpl::get_DocTSHED(void)
{
return Object->DocTSHED;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocTSHED(TFIBWideStringField * DocTSHED)
{
Object->DocTSHED=DocTSHED;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocCheckImpl::get_DocAllIDBUSINOP_GALLDOC(void)
{
return Object->DocAllIDBUSINOP_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocAllIDBUSINOP_GALLDOC(TFIBLargeIntField * DocAllIDBUSINOP_GALLDOC)
{
Object->DocAllIDBUSINOP_GALLDOC=DocAllIDBUSINOP_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocCheckImpl::get_DocAllNAME_SBUSINESS_OPER(void)
{
return Object->DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocAllNAME_SBUSINESS_OPER(TFIBWideStringField * DocAllNAME_SBUSINESS_OPER)
{
Object->DocAllNAME_SBUSINESS_OPER=DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocCheckImpl::get_DocOPL_OTHER_DCHK(void)
{
return Object->DocOPL_OTHER_DCHK;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocOPL_OTHER_DCHK(TFIBBCDField * DocOPL_OTHER_DCHK)
{
Object->DocOPL_OTHER_DCHK=DocOPL_OTHER_DCHK;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocCheckImpl::get_DocTPRSK_HAND_DCHKT(void)
{
return Object->DocTPRSK_HAND_DCHKT;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocTPRSK_HAND_DCHKT(TFIBBCDField * DocTPRSK_HAND_DCHKT)
{
Object->DocTPRSK_HAND_DCHKT=DocTPRSK_HAND_DCHKT;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMDocCheckImpl::get_DocTNO_SK_DCHKT(void)
{
return Object->DocTNO_SK_DCHKT;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocTNO_SK_DCHKT(TFIBSmallIntField * DocTNO_SK_DCHKT)
{
Object->DocTNO_SK_DCHKT=DocTNO_SK_DCHKT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocCheckImpl::get_DocTIDGRPNOM(void)
{
return Object->DocTIDGRPNOM;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocTIDGRPNOM(TFIBLargeIntField * DocTIDGRPNOM)
{
Object->DocTIDGRPNOM=DocTIDGRPNOM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocCheckImpl::get_DocTIDVID_SNOM(void)
{
return Object->DocTIDVID_SNOM;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocTIDVID_SNOM(TFIBLargeIntField * DocTIDVID_SNOM)
{
Object->DocTIDVID_SNOM=DocTIDVID_SNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocCheckImpl::get_DocTNAMEGN(void)
{
return Object->DocTNAMEGN;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocTNAMEGN(TFIBWideStringField * DocTNAMEGN)
{
Object->DocTNAMEGN=DocTNAMEGN;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocCheckImpl::get_DocTNAME_SVIDNOM(void)
{
return Object->DocTNAME_SVIDNOM;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocTNAME_SVIDNOM(TFIBWideStringField * DocTNAME_SVIDNOM)
{
Object->DocTNAME_SVIDNOM=DocTNAME_SVIDNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocCheckImpl::get_DocAllPREFIKS_NUM_GALLDOC(void)
{
return Object->DocAllPREFIKS_NUM_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocAllPREFIKS_NUM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_GALLDOC)
{
Object->DocAllPREFIKS_NUM_GALLDOC=DocAllPREFIKS_NUM_GALLDOC;
}
//---------------------------------------------------------------






TFIBLargeIntField * TDMDocCheckImpl::get_DocTIDTNOM_DCHKT(void)
{
return Object->DocTIDTNOM_DCHKT;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocTIDTNOM_DCHKT(TFIBLargeIntField * DocTIDTNOM_DCHKT)
{
Object->DocTIDTNOM_DCHKT=DocTIDTNOM_DCHKT;
}
//---------------------------------------------------------------


TFIBLargeIntField * TDMDocCheckImpl::get_DocTIDDEPARTMENT_DCHKT(void)
{
return Object->DocTIDDEPARTMENT_DCHKT;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocTIDDEPARTMENT_DCHKT(TFIBLargeIntField * DocTIDDEPARTMENT_DCHKT)
{
Object->DocTIDDEPARTMENT_DCHKT=DocTIDDEPARTMENT_DCHKT;
}
//---------------------------------------------------------------


TFIBIntegerField * TDMDocCheckImpl::get_DocTNUMOTDKKT_SDEPARTMENT(void)
{
return Object->DocTNUMOTDKKT_SDEPARTMENT;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocTNUMOTDKKT_SDEPARTMENT(TFIBIntegerField * DocTNUMOTDKKT_SDEPARTMENT)
{
Object->DocTNUMOTDKKT_SDEPARTMENT=DocTNUMOTDKKT_SDEPARTMENT;
}
//---------------------------------------------------------------


TFIBWideStringField * TDMDocCheckImpl::get_DocTNAME_SDEPARTMENT(void)
{
return Object->DocTNAME_SDEPARTMENT;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocTNAME_SDEPARTMENT(TFIBWideStringField * DocTNAME_SDEPARTMENT)
{
Object->DocTNAME_SDEPARTMENT=DocTNAME_SDEPARTMENT;
}
//---------------------------------------------------------------


TFIBWideStringField * TDMDocCheckImpl::get_DocTNAME_STNOM(void)
{
return Object->DocTNAME_STNOM;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocTNAME_STNOM(TFIBWideStringField * DocTNAME_STNOM)
{
Object->DocTNAME_STNOM=DocTNAME_STNOM;
}
//---------------------------------------------------------------


TFIBWideStringField * TDMDocCheckImpl::get_DocFISCALSIGN_DCHK(void)
{
return Object->DocAllPREFIKS_NUM_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocFISCALSIGN_DCHK(TFIBWideStringField * DocFISCALSIGN_DCHK)
{
Object->DocFISCALSIGN_DCHK=DocFISCALSIGN_DCHK;
}
//---------------------------------------------------------------


TFIBWideStringField * TDMDocCheckImpl::get_DocPHONE_DCHK(void)
{
return Object->DocPHONE_DCHK;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocPHONE_DCHK(TFIBWideStringField * DocPHONE_DCHK)
{
Object->DocPHONE_DCHK=DocPHONE_DCHK;
}
//---------------------------------------------------------------


TFIBWideStringField * TDMDocCheckImpl::get_DocEMAIL_DCHK(void)
{
return Object->DocEMAIL_DCHK;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_DocEMAIL_DCHK(TFIBWideStringField * DocEMAIL_DCHK)
{
Object->DocEMAIL_DCHK=DocEMAIL_DCHK;
}
//---------------------------------------------------------------










bool TDMDocCheckImpl::get_NewElement(void)
{
return Object->NewElement;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_NewElement(bool NewElement)
{
Object->NewElement=NewElement;
}
//---------------------------------------------------------------
bool TDMDocCheckImpl::get_Prosmotr(void)
{
return Object->Prosmotr;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_Prosmotr(bool Prosmotr)
{
Object->Prosmotr=Prosmotr;
}
//---------------------------------------------------------------
UnicodeString TDMDocCheckImpl::get_ProsmotrText(void)
{
return Object->ProsmotrText;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_ProsmotrText(UnicodeString ProsmotrText)
{
Object->ProsmotrText=ProsmotrText;
}
//---------------------------------------------------------------
__int64 TDMDocCheckImpl::get_IdDoc(void)
{
return Object->IdDoc;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_IdDoc(__int64 IdDoc)
{
Object->IdDoc=IdDoc;
}
//---------------------------------------------------------------
__int64 TDMDocCheckImpl::get_IdGrp(void)
{
return Object->IdGrp;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_IdGrp(__int64 IdGrp)
{
Object->IdGrp=IdGrp;
}
//---------------------------------------------------------------
__int64 TDMDocCheckImpl::get_IdElementaMaster(void)
{
return Object->IdElementaMaster;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_IdElementaMaster(__int64 IdElementaMaster)
{
Object->IdElementaMaster=IdElementaMaster;
}
//---------------------------------------------------------------
__int64 TDMDocCheckImpl::get_IdTypePrice(void)
{
return Object->IdTypePrice;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_IdTypePrice(__int64 IdTypePrice)
{
Object->IdTypePrice=IdTypePrice;
}
//---------------------------------------------------------------
int TDMDocCheckImpl::get_Operation(void)
{
return Object->Operation;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_Operation(int Operation)
{
Object->Operation=Operation;
}
//---------------------------------------------------------------
__int64 TDMDocCheckImpl::get_IdSklad(void)
{
return Object->IdSklad;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_IdSklad(__int64 IdSklad)
{
Object->IdSklad=IdSklad;
}
//---------------------------------------------------------------
bool TDMDocCheckImpl::get_AutoRaschet(void)
{
return Object->AutoRaschet;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_AutoRaschet(bool AutoRaschet)
{
Object->AutoRaschet=AutoRaschet;
}
//---------------------------------------------------------------
bool TDMDocCheckImpl::get_EnableDvReg(void)
{
return Object->EnableDvReg;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_EnableDvReg(bool EnableDvReg)
{
Object->EnableDvReg=EnableDvReg;
}
//---------------------------------------------------------------
bool TDMDocCheckImpl::get_SkladRozn(void)
{
return Object->SkladRozn;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_SkladRozn(bool SkladRozn)
{
Object->SkladRozn=SkladRozn;
}
//---------------------------------------------------------------
bool TDMDocCheckImpl::get_NoOtrOstatok(void)
{
return Object->NoOtrOstatok;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::set_NoOtrOstatok(bool NoOtrOstatok)
{
Object->NoOtrOstatok=NoOtrOstatok;
}
//---------------------------------------------------------------
void TDMDocCheckImpl::NewDoc(void)
{
return Object->NewDoc();
}
//---------------------------------------------------------------
bool TDMDocCheckImpl::OpenDoc(__int64 IdDoc)
{
return Object->OpenDoc(IdDoc);
}
//---------------------------------------------------------------
void TDMDocCheckImpl::OpenDocOsn(void)
{
return Object->OpenDocOsn();
}
//---------------------------------------------------------------
bool TDMDocCheckImpl::SaveDoc(void)
{
return Object->SaveDoc();
}
//---------------------------------------------------------------
bool TDMDocCheckImpl::BeforeSaveDoc(void)
{
return Object->BeforeSaveDoc();
}
//---------------------------------------------------------------
bool TDMDocCheckImpl::AfterSaveDoc(void)
{
return Object->AfterSaveDoc();
}
//---------------------------------------------------------------
bool TDMDocCheckImpl::DvRegDoc(void)
{
return Object->DvRegDoc();
}
//---------------------------------------------------------------
bool TDMDocCheckImpl::CancelDvRegDoc(void)
{
return Object->CancelDvRegDoc();
}
//---------------------------------------------------------------
bool TDMDocCheckImpl::DeleteDoc(__int64 id)
{
return Object->DeleteDoc(id);
}
//---------------------------------------------------------------
void TDMDocCheckImpl::AddDocNewString(void)
{
return Object->AddDocNewString();
}
//---------------------------------------------------------------
void TDMDocCheckImpl::DeleteStringDoc(void)
{
return Object->DeleteStringDoc();
}
//---------------------------------------------------------------
void TDMDocCheckImpl::CloseDoc(void)
{
return Object->CloseDoc();
}
//---------------------------------------------------------------
void TDMDocCheckImpl::ValidateProsmotr(void)
{
return Object->ValidateProsmotr();
}
//---------------------------------------------------------------
void TDMDocCheckImpl::AdddRecordInGurOperDiscountCard(void)
{
return Object->AdddRecordInGurOperDiscountCard();
}
//---------------------------------------------------------------
int TDMDocCheckImpl::GetNumberNewDoc(void)
{
return Object->GetNumberNewDoc();
}
//---------------------------------------------------------------
