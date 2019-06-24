#include "vcl.h"
#pragma hdrstop


#include "UREM_DMDocPerImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_DMDocPerImpl::TREM_DMDocPerImpl()           
{                                            
Object=new TREM_DMDocPer(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_DMDocPerImpl::~TREM_DMDocPerImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_DMDocPerImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_DMDocPerImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_DMDocPer)                        
   {                                                                     
   *ppv=static_cast<IREM_DMDocPer*> (this);                                
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
int TREM_DMDocPerImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_DMDocPerImpl::kanRelease(void)                                  
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
int  TREM_DMDocPerImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_DMDocPerImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_DMDocPerImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_DMDocPerImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_DMDocPerImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IREM_DMDocPer
TDataSource * TREM_DMDocPerImpl::get_DataSourceDoc(void)
{
return Object->DataSourceDoc;
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_DataSourceDoc(TDataSource * DataSourceDoc)
{
Object->DataSourceDoc=DataSourceDoc;
}
//---------------------------------------------------------------
TDataSource * TREM_DMDocPerImpl::get_DataSourceDocT(void)
{
return Object->DataSourceDocT;
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_DataSourceDocT(TDataSource * DataSourceDocT)
{
Object->DataSourceDocT=DataSourceDocT;
}
//---------------------------------------------------------------
TDataSource * TREM_DMDocPerImpl::get_DataSourceDocAll(void)
{
return Object->DataSourceDocAll;
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_DataSourceDocAll(TDataSource * DataSourceDocAll)
{
Object->DataSourceDocAll=DataSourceDocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocPerImpl::get_DocAll(void)
{
return Object->DocAll;
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_DocAll(TpFIBDataSet * DocAll)
{
Object->DocAll=DocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocPerImpl::get_Doc(void)
{
return Object->Doc;
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_Doc(TpFIBDataSet * Doc)
{
Object->Doc=Doc;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocPerImpl::get_DocT(void)
{
return Object->DocT;
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_DocT(TpFIBDataSet * DocT)
{
Object->DocT=DocT;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMDocPerImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMDocPerImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMDocPerImpl::get_IBTrDvReg(void)
{
return Object->IBTrDvReg;
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_IBTrDvReg(TpFIBTransaction * IBTrDvReg)
{
Object->IBTrDvReg=IBTrDvReg;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocPerImpl::get_NumDoc(void)
{
return Object->NumDoc;
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_NumDoc(TpFIBDataSet * NumDoc)
{
Object->NumDoc=NumDoc;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocPerImpl::get_NumDocMAXNUMBER(void)
{
return Object->NumDocMAXNUMBER;
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_NumDocMAXNUMBER(TFIBIntegerField * NumDocMAXNUMBER)
{
Object->NumDocMAXNUMBER=NumDocMAXNUMBER;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocPerImpl::get_SpisokTypePrice(void)
{
return Object->SpisokTypePrice;
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_SpisokTypePrice(TpFIBDataSet * SpisokTypePrice)
{
Object->SpisokTypePrice=SpisokTypePrice;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocPerImpl::get_SpisokTypePriceID_TPRICE(void)
{
return Object->SpisokTypePriceID_TPRICE;
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_SpisokTypePriceID_TPRICE(TFIBIntegerField * SpisokTypePriceID_TPRICE)
{
Object->SpisokTypePriceID_TPRICE=SpisokTypePriceID_TPRICE;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMDocPerImpl::get_QueryCancelDvReg(void)
{
return Object->QueryCancelDvReg;
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg)
{
Object->QueryCancelDvReg=QueryCancelDvReg;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMDocPerImpl::get_QueryDvReg(void)
{
return Object->QueryDvReg;
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_QueryDvReg(TpFIBQuery * QueryDvReg)
{
Object->QueryDvReg=QueryDvReg;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocPerImpl::get_DocOsn(void)
{
return Object->DocOsn;
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_DocOsn(TpFIBDataSet * DocOsn)
{
Object->DocOsn=DocOsn;
}
//---------------------------------------------------------------
TDataSource * TREM_DMDocPerImpl::get_DataSourceDocOsn(void)
{
return Object->DataSourceDocOsn;
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_DataSourceDocOsn(TDataSource * DataSourceDocOsn)
{
Object->DataSourceDocOsn=DataSourceDocOsn;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocPerImpl::get_SpisokTypePriceNAME_TPRICE(void)
{
return Object->SpisokTypePriceNAME_TPRICE;
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_SpisokTypePriceNAME_TPRICE(TFIBWideStringField * SpisokTypePriceNAME_TPRICE)
{
Object->SpisokTypePriceNAME_TPRICE=SpisokTypePriceNAME_TPRICE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocPerImpl::get_SpisokTypePriceGID_STPRICE(void)
{
return Object->SpisokTypePriceGID_STPRICE;
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_SpisokTypePriceGID_STPRICE(TFIBWideStringField * SpisokTypePriceGID_STPRICE)
{
Object->SpisokTypePriceGID_STPRICE=SpisokTypePriceGID_STPRICE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocPerImpl::get_DocAllID_REM_GALLDOC(void)
{
return Object->DocAllID_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_DocAllID_REM_GALLDOC(TFIBLargeIntField * DocAllID_REM_GALLDOC)
{
Object->DocAllID_REM_GALLDOC=DocAllID_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocPerImpl::get_DocAllIDBASE_REM_GALLDOC(void)
{
return Object->DocAllIDBASE_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_DocAllIDBASE_REM_GALLDOC(TFIBLargeIntField * DocAllIDBASE_REM_GALLDOC)
{
Object->DocAllIDBASE_REM_GALLDOC=DocAllIDBASE_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocPerImpl::get_DocAllIDFIRM_REM_GALLDOC(void)
{
return Object->DocAllIDFIRM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_DocAllIDFIRM_REM_GALLDOC(TFIBLargeIntField * DocAllIDFIRM_REM_GALLDOC)
{
Object->DocAllIDFIRM_REM_GALLDOC=DocAllIDFIRM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocPerImpl::get_DocAllIDSKLAD_REM_GALLDOC(void)
{
return Object->DocAllIDSKLAD_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_DocAllIDSKLAD_REM_GALLDOC(TFIBLargeIntField * DocAllIDSKLAD_REM_GALLDOC)
{
Object->DocAllIDSKLAD_REM_GALLDOC=DocAllIDSKLAD_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocPerImpl::get_DocAllIDKLIENT_REM_GALLDOC(void)
{
return Object->DocAllIDKLIENT_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_DocAllIDKLIENT_REM_GALLDOC(TFIBLargeIntField * DocAllIDKLIENT_REM_GALLDOC)
{
Object->DocAllIDKLIENT_REM_GALLDOC=DocAllIDKLIENT_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocPerImpl::get_DocAllIDUSER_REM_GALLDOC(void)
{
return Object->DocAllIDUSER_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_DocAllIDUSER_REM_GALLDOC(TFIBLargeIntField * DocAllIDUSER_REM_GALLDOC)
{
Object->DocAllIDUSER_REM_GALLDOC=DocAllIDUSER_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMDocPerImpl::get_DocAllPOS_REM_GALLDOC(void)
{
return Object->DocAllPOS_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_DocAllPOS_REM_GALLDOC(TFIBDateTimeField * DocAllPOS_REM_GALLDOC)
{
Object->DocAllPOS_REM_GALLDOC=DocAllPOS_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocPerImpl::get_DocAllNUM_REM_GALLDOC(void)
{
return Object->DocAllNUM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_DocAllNUM_REM_GALLDOC(TFIBIntegerField * DocAllNUM_REM_GALLDOC)
{
Object->DocAllNUM_REM_GALLDOC=DocAllNUM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMDocPerImpl::get_DocAllPR_REM_GALLDOC(void)
{
return Object->DocAllPR_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_DocAllPR_REM_GALLDOC(TFIBSmallIntField * DocAllPR_REM_GALLDOC)
{
Object->DocAllPR_REM_GALLDOC=DocAllPR_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocPerImpl::get_DocAllTDOC_REM_GALLDOC(void)
{
return Object->DocAllTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_DocAllTDOC_REM_GALLDOC(TFIBWideStringField * DocAllTDOC_REM_GALLDOC)
{
Object->DocAllTDOC_REM_GALLDOC=DocAllTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocPerImpl::get_DocAllIDDOCOSN_REM_GALLDOC(void)
{
return Object->DocAllIDDOCOSN_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_DocAllIDDOCOSN_REM_GALLDOC(TFIBLargeIntField * DocAllIDDOCOSN_REM_GALLDOC)
{
Object->DocAllIDDOCOSN_REM_GALLDOC=DocAllIDDOCOSN_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocPerImpl::get_DocAllTYPEEXTDOC_REM_GALLDOC(void)
{
return Object->DocAllTYPEEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_DocAllTYPEEXTDOC_REM_GALLDOC(TFIBIntegerField * DocAllTYPEEXTDOC_REM_GALLDOC)
{
Object->DocAllTYPEEXTDOC_REM_GALLDOC=DocAllTYPEEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocPerImpl::get_DocAllIDEXTDOC_REM_GALLDOC(void)
{
return Object->DocAllIDEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_DocAllIDEXTDOC_REM_GALLDOC(TFIBLargeIntField * DocAllIDEXTDOC_REM_GALLDOC)
{
Object->DocAllIDEXTDOC_REM_GALLDOC=DocAllIDEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocPerImpl::get_DocAllSUM_REM_GALLDOC(void)
{
return Object->DocAllSUM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_DocAllSUM_REM_GALLDOC(TFIBBCDField * DocAllSUM_REM_GALLDOC)
{
Object->DocAllSUM_REM_GALLDOC=DocAllSUM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocPerImpl::get_DocAllIDPROJECT_REM_GALLDOC(void)
{
return Object->DocAllIDPROJECT_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_DocAllIDPROJECT_REM_GALLDOC(TFIBLargeIntField * DocAllIDPROJECT_REM_GALLDOC)
{
Object->DocAllIDPROJECT_REM_GALLDOC=DocAllIDPROJECT_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocPerImpl::get_DocAllIDBUSINOP_REM_GALLDOC(void)
{
return Object->DocAllIDBUSINOP_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_DocAllIDBUSINOP_REM_GALLDOC(TFIBLargeIntField * DocAllIDBUSINOP_REM_GALLDOC)
{
Object->DocAllIDBUSINOP_REM_GALLDOC=DocAllIDBUSINOP_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocPerImpl::get_DocAllFNAME_USER(void)
{
return Object->DocAllFNAME_USER;
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_DocAllFNAME_USER(TFIBWideStringField * DocAllFNAME_USER)
{
Object->DocAllFNAME_USER=DocAllFNAME_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocPerImpl::get_DocAllNAME_SINFBASE_OBMEN(void)
{
return Object->DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN)
{
Object->DocAllNAME_SINFBASE_OBMEN=DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocPerImpl::get_DocAllNAMEFIRM(void)
{
return Object->DocAllNAMEFIRM;
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_DocAllNAMEFIRM(TFIBWideStringField * DocAllNAMEFIRM)
{
Object->DocAllNAMEFIRM=DocAllNAMEFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocPerImpl::get_DocAllNAMESKLAD(void)
{
return Object->DocAllNAMESKLAD;
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_DocAllNAMESKLAD(TFIBWideStringField * DocAllNAMESKLAD)
{
Object->DocAllNAMESKLAD=DocAllNAMESKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocPerImpl::get_DocAllNAMEKLIENT(void)
{
return Object->DocAllNAMEKLIENT;
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_DocAllNAMEKLIENT(TFIBWideStringField * DocAllNAMEKLIENT)
{
Object->DocAllNAMEKLIENT=DocAllNAMEKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocPerImpl::get_DocAllNAME_SPROJECT(void)
{
return Object->DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_DocAllNAME_SPROJECT(TFIBWideStringField * DocAllNAME_SPROJECT)
{
Object->DocAllNAME_SPROJECT=DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocPerImpl::get_DocAllNAME_SBUSINESS_OPER(void)
{
return Object->DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_DocAllNAME_SBUSINESS_OPER(TFIBWideStringField * DocAllNAME_SBUSINESS_OPER)
{
Object->DocAllNAME_SBUSINESS_OPER=DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocPerImpl::get_DocOsnTDOC_REM_GALLDOC(void)
{
return Object->DocOsnTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_DocOsnTDOC_REM_GALLDOC(TFIBWideStringField * DocOsnTDOC_REM_GALLDOC)
{
Object->DocOsnTDOC_REM_GALLDOC=DocOsnTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMDocPerImpl::get_DocOsnPOS_REM_GALLDOC(void)
{
return Object->DocOsnPOS_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_DocOsnPOS_REM_GALLDOC(TFIBDateTimeField * DocOsnPOS_REM_GALLDOC)
{
Object->DocOsnPOS_REM_GALLDOC=DocOsnPOS_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocPerImpl::get_DocOsnNUM_REM_GALLDOC(void)
{
return Object->DocOsnNUM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_DocOsnNUM_REM_GALLDOC(TFIBIntegerField * DocOsnNUM_REM_GALLDOC)
{
Object->DocOsnNUM_REM_GALLDOC=DocOsnNUM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocPerImpl::get_DocID_REM_DPER(void)
{
return Object->DocID_REM_DPER;
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_DocID_REM_DPER(TFIBLargeIntField * DocID_REM_DPER)
{
Object->DocID_REM_DPER=DocID_REM_DPER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocPerImpl::get_DocIDBASE_REM_DPER(void)
{
return Object->DocIDBASE_REM_DPER;
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_DocIDBASE_REM_DPER(TFIBLargeIntField * DocIDBASE_REM_DPER)
{
Object->DocIDBASE_REM_DPER=DocIDBASE_REM_DPER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocPerImpl::get_DocIDDOC_REM_DPER(void)
{
return Object->DocIDDOC_REM_DPER;
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_DocIDDOC_REM_DPER(TFIBLargeIntField * DocIDDOC_REM_DPER)
{
Object->DocIDDOC_REM_DPER=DocIDDOC_REM_DPER;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocPerImpl::get_DocGID_REM_DPER(void)
{
return Object->DocGID_REM_DPER;
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_DocGID_REM_DPER(TFIBWideStringField * DocGID_REM_DPER)
{
Object->DocGID_REM_DPER=DocGID_REM_DPER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocPerImpl::get_DocIDRTPRICE_REM_DPER(void)
{
return Object->DocIDRTPRICE_REM_DPER;
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_DocIDRTPRICE_REM_DPER(TFIBLargeIntField * DocIDRTPRICE_REM_DPER)
{
Object->DocIDRTPRICE_REM_DPER=DocIDRTPRICE_REM_DPER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocPerImpl::get_DocIDSKLPOL_REM_DPER(void)
{
return Object->DocIDSKLPOL_REM_DPER;
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_DocIDSKLPOL_REM_DPER(TFIBLargeIntField * DocIDSKLPOL_REM_DPER)
{
Object->DocIDSKLPOL_REM_DPER=DocIDSKLPOL_REM_DPER;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocPerImpl::get_DocPRIM_REM_DPER(void)
{
return Object->DocPRIM_REM_DPER;
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_DocPRIM_REM_DPER(TFIBWideStringField * DocPRIM_REM_DPER)
{
Object->DocPRIM_REM_DPER=DocPRIM_REM_DPER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocPerImpl::get_DocTID_REM_DPERT(void)
{
return Object->DocTID_REM_DPERT;
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_DocTID_REM_DPERT(TFIBLargeIntField * DocTID_REM_DPERT)
{
Object->DocTID_REM_DPERT=DocTID_REM_DPERT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocPerImpl::get_DocTIDBASE_REM_DPERT(void)
{
return Object->DocTIDBASE_REM_DPERT;
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_DocTIDBASE_REM_DPERT(TFIBLargeIntField * DocTIDBASE_REM_DPERT)
{
Object->DocTIDBASE_REM_DPERT=DocTIDBASE_REM_DPERT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocPerImpl::get_DocTIDDOC_REM_DPERT(void)
{
return Object->DocTIDDOC_REM_DPERT;
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_DocTIDDOC_REM_DPERT(TFIBLargeIntField * DocTIDDOC_REM_DPERT)
{
Object->DocTIDDOC_REM_DPERT=DocTIDDOC_REM_DPERT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocPerImpl::get_DocTGID_REM_DPERT(void)
{
return Object->DocTGID_REM_DPERT;
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_DocTGID_REM_DPERT(TFIBWideStringField * DocTGID_REM_DPERT)
{
Object->DocTGID_REM_DPERT=DocTGID_REM_DPERT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocPerImpl::get_DocTIDNOM_REM_DPERT(void)
{
return Object->DocTIDNOM_REM_DPERT;
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_DocTIDNOM_REM_DPERT(TFIBLargeIntField * DocTIDNOM_REM_DPERT)
{
Object->DocTIDNOM_REM_DPERT=DocTIDNOM_REM_DPERT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocPerImpl::get_DocTIDED_REM_DPERT(void)
{
return Object->DocTIDED_REM_DPERT;
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_DocTIDED_REM_DPERT(TFIBLargeIntField * DocTIDED_REM_DPERT)
{
Object->DocTIDED_REM_DPERT=DocTIDED_REM_DPERT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocPerImpl::get_DocTIDHW_REM_DPERT(void)
{
return Object->DocTIDHW_REM_DPERT;
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_DocTIDHW_REM_DPERT(TFIBLargeIntField * DocTIDHW_REM_DPERT)
{
Object->DocTIDHW_REM_DPERT=DocTIDHW_REM_DPERT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocPerImpl::get_DocTKOL_REM_DPERT(void)
{
return Object->DocTKOL_REM_DPERT;
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_DocTKOL_REM_DPERT(TFIBBCDField * DocTKOL_REM_DPERT)
{
Object->DocTKOL_REM_DPERT=DocTKOL_REM_DPERT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocPerImpl::get_DocTKF_REM_DPERT(void)
{
return Object->DocTKF_REM_DPERT;
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_DocTKF_REM_DPERT(TFIBBCDField * DocTKF_REM_DPERT)
{
Object->DocTKF_REM_DPERT=DocTKF_REM_DPERT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocPerImpl::get_DocTRPRICE_REM_DPERT(void)
{
return Object->DocTRPRICE_REM_DPERT;
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_DocTRPRICE_REM_DPERT(TFIBBCDField * DocTRPRICE_REM_DPERT)
{
Object->DocTRPRICE_REM_DPERT=DocTRPRICE_REM_DPERT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocPerImpl::get_DocTRSUM_REM_DPERT(void)
{
return Object->DocTRSUM_REM_DPERT;
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_DocTRSUM_REM_DPERT(TFIBBCDField * DocTRSUM_REM_DPERT)
{
Object->DocTRSUM_REM_DPERT=DocTRSUM_REM_DPERT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocPerImpl::get_DocTNAC_REM_DPERT(void)
{
return Object->DocTNAC_REM_DPERT;
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_DocTNAC_REM_DPERT(TFIBBCDField * DocTNAC_REM_DPERT)
{
Object->DocTNAC_REM_DPERT=DocTNAC_REM_DPERT;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMDocPerImpl::get_DocTDVREG_REM_DPERT(void)
{
return Object->DocTDVREG_REM_DPERT;
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_DocTDVREG_REM_DPERT(TFIBSmallIntField * DocTDVREG_REM_DPERT)
{
Object->DocTDVREG_REM_DPERT=DocTDVREG_REM_DPERT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocPerImpl::get_DocTKRNAMENOM(void)
{
return Object->DocTKRNAMENOM;
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_DocTKRNAMENOM(TFIBWideStringField * DocTKRNAMENOM)
{
Object->DocTKRNAMENOM=DocTKRNAMENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocPerImpl::get_DocTNAMENOM(void)
{
return Object->DocTNAMENOM;
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_DocTNAMENOM(TFIBWideStringField * DocTNAMENOM)
{
Object->DocTNAMENOM=DocTNAMENOM;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMDocPerImpl::get_DocTTNOM(void)
{
return Object->DocTTNOM;
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_DocTTNOM(TFIBSmallIntField * DocTTNOM)
{
Object->DocTTNOM=DocTTNOM;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocPerImpl::get_DocTCODENOM(void)
{
return Object->DocTCODENOM;
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_DocTCODENOM(TFIBIntegerField * DocTCODENOM)
{
Object->DocTCODENOM=DocTCODENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocPerImpl::get_DocTARTNOM(void)
{
return Object->DocTARTNOM;
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_DocTARTNOM(TFIBWideStringField * DocTARTNOM)
{
Object->DocTARTNOM=DocTARTNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocPerImpl::get_DocTNAMEED(void)
{
return Object->DocTNAMEED;
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_DocTNAMEED(TFIBWideStringField * DocTNAMEED)
{
Object->DocTNAMEED=DocTNAMEED;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocPerImpl::get_DocTSHED(void)
{
return Object->DocTSHED;
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_DocTSHED(TFIBWideStringField * DocTSHED)
{
Object->DocTSHED=DocTSHED;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocPerImpl::get_DocTIDGRPNOM(void)
{
return Object->DocTIDGRPNOM;
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_DocTIDGRPNOM(TFIBLargeIntField * DocTIDGRPNOM)
{
Object->DocTIDGRPNOM=DocTIDGRPNOM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocPerImpl::get_DocTIDVID_SNOM(void)
{
return Object->DocTIDVID_SNOM;
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_DocTIDVID_SNOM(TFIBLargeIntField * DocTIDVID_SNOM)
{
Object->DocTIDVID_SNOM=DocTIDVID_SNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocPerImpl::get_DocTNAMEGN(void)
{
return Object->DocTNAMEGN;
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_DocTNAMEGN(TFIBWideStringField * DocTNAMEGN)
{
Object->DocTNAMEGN=DocTNAMEGN;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocPerImpl::get_DocTNAME_SVIDNOM(void)
{
return Object->DocTNAME_SVIDNOM;
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_DocTNAME_SVIDNOM(TFIBWideStringField * DocTNAME_SVIDNOM)
{
Object->DocTNAME_SVIDNOM=DocTNAME_SVIDNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocPerImpl::get_DocTNAME_REM_SHARDWARE(void)
{
return Object->DocTNAME_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_DocTNAME_REM_SHARDWARE(TFIBWideStringField * DocTNAME_REM_SHARDWARE)
{
Object->DocTNAME_REM_SHARDWARE=DocTNAME_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocPerImpl::get_DocTCODE_REM_SHARDWARE(void)
{
return Object->DocTCODE_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_DocTCODE_REM_SHARDWARE(TFIBIntegerField * DocTCODE_REM_SHARDWARE)
{
Object->DocTCODE_REM_SHARDWARE=DocTCODE_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocPerImpl::get_DocTSERNUM_REM_SHARDWARE(void)
{
return Object->DocTSERNUM_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_DocTSERNUM_REM_SHARDWARE(TFIBWideStringField * DocTSERNUM_REM_SHARDWARE)
{
Object->DocTSERNUM_REM_SHARDWARE=DocTSERNUM_REM_SHARDWARE;
}
//---------------------------------------------------------------
TIntegerField * TREM_DMDocPerImpl::get_DocTRECNO(void)
{
return Object->DocTRECNO;
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_DocTRECNO(TIntegerField * DocTRECNO)
{
Object->DocTRECNO=DocTRECNO;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocPerImpl::get_DocNAMESKLAD(void)
{
return Object->DocNAMESKLAD;
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_DocNAMESKLAD(TFIBWideStringField * DocNAMESKLAD)
{
Object->DocNAMESKLAD=DocNAMESKLAD;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMDocPerImpl::get_DocTDVREG_POL_REM_DPERT(void)
{
return Object->DocTDVREG_POL_REM_DPERT;
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_DocTDVREG_POL_REM_DPERT(TFIBSmallIntField * DocTDVREG_POL_REM_DPERT)
{
Object->DocTDVREG_POL_REM_DPERT=DocTDVREG_POL_REM_DPERT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocPerImpl::get_DocAllPREFIKS_NUM_REM_GALLDOC(void)
{
return Object->DocAllPREFIKS_NUM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_DocAllPREFIKS_NUM_REM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_REM_GALLDOC)
{
Object->DocAllPREFIKS_NUM_REM_GALLDOC=DocAllPREFIKS_NUM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocPerImpl::get_DocTIDTNOM_REM_DPERT(void)
{
return Object->DocTIDTNOM_REM_DPERT;
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_DocTIDTNOM_REM_DPERT(TFIBLargeIntField * DocTIDTNOM_REM_DPERT)
{
Object->DocTIDTNOM_REM_DPERT=DocTIDTNOM_REM_DPERT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocPerImpl::get_DocTIDMHRAN_OTPR_REM_DPERT(void)
{
return Object->DocTIDMHRAN_OTPR_REM_DPERT;
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_DocTIDMHRAN_OTPR_REM_DPERT(TFIBLargeIntField * DocTIDMHRAN_OTPR_REM_DPERT)
{
Object->DocTIDMHRAN_OTPR_REM_DPERT=DocTIDMHRAN_OTPR_REM_DPERT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocPerImpl::get_DocTIDMHRAN_POL_REM_DPERT(void)
{
return Object->DocTIDMHRAN_POL_REM_DPERT;
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_DocTIDMHRAN_POL_REM_DPERT(TFIBLargeIntField * DocTIDMHRAN_POL_REM_DPERT)
{
Object->DocTIDMHRAN_POL_REM_DPERT=DocTIDMHRAN_POL_REM_DPERT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocPerImpl::get_DocTNAME_SMHRAN_POL(void)
{
return Object->DocTNAME_SMHRAN_POL;
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_DocTNAME_SMHRAN_POL(TFIBWideStringField * DocTNAME_SMHRAN_POL)
{
Object->DocTNAME_SMHRAN_POL=DocTNAME_SMHRAN_POL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocPerImpl::get_DocTNAME_STNOM(void)
{
return Object->DocTNAME_STNOM;
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_DocTNAME_STNOM(TFIBWideStringField * DocTNAME_STNOM)
{
Object->DocTNAME_STNOM=DocTNAME_STNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocPerImpl::get_DocTNAME_SMHRAN_OTPR(void)
{
return Object->DocTNAME_SMHRAN_OTPR;
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_DocTNAME_SMHRAN_OTPR(TFIBWideStringField * DocTNAME_SMHRAN_OTPR)
{
Object->DocTNAME_SMHRAN_OTPR=DocTNAME_SMHRAN_OTPR;
}
//---------------------------------------------------------------
bool TREM_DMDocPerImpl::get_NewElement(void)
{
return Object->NewElement;
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_NewElement(bool NewElement)
{
Object->NewElement=NewElement;
}
//---------------------------------------------------------------
bool TREM_DMDocPerImpl::get_Prosmotr(void)
{
return Object->Prosmotr;
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_Prosmotr(bool Prosmotr)
{
Object->Prosmotr=Prosmotr;
}
//---------------------------------------------------------------
UnicodeString TREM_DMDocPerImpl::get_ProsmotrText(void)
{
return Object->ProsmotrText;
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_ProsmotrText(UnicodeString ProsmotrText)
{
Object->ProsmotrText=ProsmotrText;
}
//---------------------------------------------------------------
__int64 TREM_DMDocPerImpl::get_IdDoc(void)
{
return Object->IdDoc;
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_IdDoc(__int64 IdDoc)
{
Object->IdDoc=IdDoc;
}
//---------------------------------------------------------------
__int64 TREM_DMDocPerImpl::get_IdGrp(void)
{
return Object->IdGrp;
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_IdGrp(__int64 IdGrp)
{
Object->IdGrp=IdGrp;
}
//---------------------------------------------------------------
bool TREM_DMDocPerImpl::get_AutoRaschet(void)
{
return Object->AutoRaschet;
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_AutoRaschet(bool AutoRaschet)
{
Object->AutoRaschet=AutoRaschet;
}
//---------------------------------------------------------------
bool TREM_DMDocPerImpl::get_EnableDvReg(void)
{
return Object->EnableDvReg;
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_EnableDvReg(bool EnableDvReg)
{
Object->EnableDvReg=EnableDvReg;
}
//---------------------------------------------------------------
bool TREM_DMDocPerImpl::get_SkladRozn(void)
{
return Object->SkladRozn;
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_SkladRozn(bool SkladRozn)
{
Object->SkladRozn=SkladRozn;
}
//---------------------------------------------------------------
bool TREM_DMDocPerImpl::get_NoOtrOstatok(void)
{
return Object->NoOtrOstatok;
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::set_NoOtrOstatok(bool NoOtrOstatok)
{
Object->NoOtrOstatok=NoOtrOstatok;
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::NewDoc(void)
{
return Object->NewDoc();
}
//---------------------------------------------------------------
bool TREM_DMDocPerImpl::OpenDoc(__int64 IdDoc)
{
return Object->OpenDoc(IdDoc);
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::OpenDocOsn(void)
{
return Object->OpenDocOsn();
}
//---------------------------------------------------------------
bool TREM_DMDocPerImpl::SaveDoc(void)
{
return Object->SaveDoc();
}
//---------------------------------------------------------------
bool TREM_DMDocPerImpl::BeforeSaveDoc(void)
{
return Object->BeforeSaveDoc();
}
//---------------------------------------------------------------
bool TREM_DMDocPerImpl::AfterSaveDoc(void)
{
return Object->AfterSaveDoc();
}
//---------------------------------------------------------------
bool TREM_DMDocPerImpl::DvRegDoc(void)
{
return Object->DvRegDoc();
}
//---------------------------------------------------------------
bool TREM_DMDocPerImpl::CancelDvRegDoc(void)
{
return Object->CancelDvRegDoc();
}
//---------------------------------------------------------------
bool TREM_DMDocPerImpl::DeleteDoc(__int64 id)
{
return Object->DeleteDoc(id);
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::AddDocNewString(void)
{
return Object->AddDocNewString();
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::DeleteStringDoc(void)
{
return Object->DeleteStringDoc();
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::CloseDoc(void)
{
return Object->CloseDoc();
}
//---------------------------------------------------------------
void TREM_DMDocPerImpl::ValidateProsmotr(void)
{
return Object->ValidateProsmotr();
}
//---------------------------------------------------------------
int TREM_DMDocPerImpl::GetNumberNewDoc()
{
return Object->GetNumberNewDoc();
}
//---------------------------------------------------------------
