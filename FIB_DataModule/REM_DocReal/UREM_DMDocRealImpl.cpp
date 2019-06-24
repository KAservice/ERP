#include "vcl.h"
#pragma hdrstop


#include "UREM_DMDocRealImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_DMDocRealImpl::TREM_DMDocRealImpl()           
{                                            
Object=new TREM_DMDocReal(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_DMDocRealImpl::~TREM_DMDocRealImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_DMDocRealImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_DMDocRealImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_DMDocReal)                        
   {                                                                     
   *ppv=static_cast<IREM_DMDocReal*> (this);                                
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
int TREM_DMDocRealImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_DMDocRealImpl::kanRelease(void)                                  
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
int  TREM_DMDocRealImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_DMDocRealImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_DMDocRealImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_DMDocRealImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_DMDocRealImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IREM_DMDocReal
TDataSource * TREM_DMDocRealImpl::get_DataSourceDoc(void)
{
return Object->DataSourceDoc;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_DataSourceDoc(TDataSource * DataSourceDoc)
{
Object->DataSourceDoc=DataSourceDoc;
}
//---------------------------------------------------------------
TDataSource * TREM_DMDocRealImpl::get_DataSourceDocT(void)
{
return Object->DataSourceDocT;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_DataSourceDocT(TDataSource * DataSourceDocT)
{
Object->DataSourceDocT=DataSourceDocT;
}
//---------------------------------------------------------------
TDataSource * TREM_DMDocRealImpl::get_DataSourceDocAll(void)
{
return Object->DataSourceDocAll;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_DataSourceDocAll(TDataSource * DataSourceDocAll)
{
Object->DataSourceDocAll=DataSourceDocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocRealImpl::get_DocAll(void)
{
return Object->DocAll;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_DocAll(TpFIBDataSet * DocAll)
{
Object->DocAll=DocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocRealImpl::get_Doc(void)
{
return Object->Doc;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_Doc(TpFIBDataSet * Doc)
{
Object->Doc=Doc;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocRealImpl::get_DocT(void)
{
return Object->DocT;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_DocT(TpFIBDataSet * DocT)
{
Object->DocT=DocT;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMDocRealImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMDocRealImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMDocRealImpl::get_IBTrDvReg(void)
{
return Object->IBTrDvReg;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_IBTrDvReg(TpFIBTransaction * IBTrDvReg)
{
Object->IBTrDvReg=IBTrDvReg;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocRealImpl::get_NumDoc(void)
{
return Object->NumDoc;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_NumDoc(TpFIBDataSet * NumDoc)
{
Object->NumDoc=NumDoc;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocRealImpl::get_NumDocMAXNUMBER(void)
{
return Object->NumDocMAXNUMBER;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_NumDocMAXNUMBER(TFIBIntegerField * NumDocMAXNUMBER)
{
Object->NumDocMAXNUMBER=NumDocMAXNUMBER;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocRealImpl::get_SpisokTypePrice(void)
{
return Object->SpisokTypePrice;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_SpisokTypePrice(TpFIBDataSet * SpisokTypePrice)
{
Object->SpisokTypePrice=SpisokTypePrice;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocRealImpl::get_SpisokTypePriceID_TPRICE(void)
{
return Object->SpisokTypePriceID_TPRICE;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_SpisokTypePriceID_TPRICE(TFIBIntegerField * SpisokTypePriceID_TPRICE)
{
Object->SpisokTypePriceID_TPRICE=SpisokTypePriceID_TPRICE;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMDocRealImpl::get_QueryCancelDvReg(void)
{
return Object->QueryCancelDvReg;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg)
{
Object->QueryCancelDvReg=QueryCancelDvReg;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMDocRealImpl::get_QueryDvReg(void)
{
return Object->QueryDvReg;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_QueryDvReg(TpFIBQuery * QueryDvReg)
{
Object->QueryDvReg=QueryDvReg;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocRealImpl::get_DocOsn(void)
{
return Object->DocOsn;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_DocOsn(TpFIBDataSet * DocOsn)
{
Object->DocOsn=DocOsn;
}
//---------------------------------------------------------------
TDataSource * TREM_DMDocRealImpl::get_DataSourceDocOsn(void)
{
return Object->DataSourceDocOsn;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_DataSourceDocOsn(TDataSource * DataSourceDocOsn)
{
Object->DataSourceDocOsn=DataSourceDocOsn;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRealImpl::get_SpisokTypePriceNAME_TPRICE(void)
{
return Object->SpisokTypePriceNAME_TPRICE;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_SpisokTypePriceNAME_TPRICE(TFIBWideStringField * SpisokTypePriceNAME_TPRICE)
{
Object->SpisokTypePriceNAME_TPRICE=SpisokTypePriceNAME_TPRICE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRealImpl::get_SpisokTypePriceGID_STPRICE(void)
{
return Object->SpisokTypePriceGID_STPRICE;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_SpisokTypePriceGID_STPRICE(TFIBWideStringField * SpisokTypePriceGID_STPRICE)
{
Object->SpisokTypePriceGID_STPRICE=SpisokTypePriceGID_STPRICE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRealImpl::get_DocAllID_REM_GALLDOC(void)
{
return Object->DocAllID_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_DocAllID_REM_GALLDOC(TFIBLargeIntField * DocAllID_REM_GALLDOC)
{
Object->DocAllID_REM_GALLDOC=DocAllID_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRealImpl::get_DocAllIDBASE_REM_GALLDOC(void)
{
return Object->DocAllIDBASE_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_DocAllIDBASE_REM_GALLDOC(TFIBLargeIntField * DocAllIDBASE_REM_GALLDOC)
{
Object->DocAllIDBASE_REM_GALLDOC=DocAllIDBASE_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRealImpl::get_DocAllIDFIRM_REM_GALLDOC(void)
{
return Object->DocAllIDFIRM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_DocAllIDFIRM_REM_GALLDOC(TFIBLargeIntField * DocAllIDFIRM_REM_GALLDOC)
{
Object->DocAllIDFIRM_REM_GALLDOC=DocAllIDFIRM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRealImpl::get_DocAllIDSKLAD_REM_GALLDOC(void)
{
return Object->DocAllIDSKLAD_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_DocAllIDSKLAD_REM_GALLDOC(TFIBLargeIntField * DocAllIDSKLAD_REM_GALLDOC)
{
Object->DocAllIDSKLAD_REM_GALLDOC=DocAllIDSKLAD_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRealImpl::get_DocAllIDKLIENT_REM_GALLDOC(void)
{
return Object->DocAllIDKLIENT_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_DocAllIDKLIENT_REM_GALLDOC(TFIBLargeIntField * DocAllIDKLIENT_REM_GALLDOC)
{
Object->DocAllIDKLIENT_REM_GALLDOC=DocAllIDKLIENT_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRealImpl::get_DocAllIDUSER_REM_GALLDOC(void)
{
return Object->DocAllIDUSER_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_DocAllIDUSER_REM_GALLDOC(TFIBLargeIntField * DocAllIDUSER_REM_GALLDOC)
{
Object->DocAllIDUSER_REM_GALLDOC=DocAllIDUSER_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMDocRealImpl::get_DocAllPOS_REM_GALLDOC(void)
{
return Object->DocAllPOS_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_DocAllPOS_REM_GALLDOC(TFIBDateTimeField * DocAllPOS_REM_GALLDOC)
{
Object->DocAllPOS_REM_GALLDOC=DocAllPOS_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocRealImpl::get_DocAllNUM_REM_GALLDOC(void)
{
return Object->DocAllNUM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_DocAllNUM_REM_GALLDOC(TFIBIntegerField * DocAllNUM_REM_GALLDOC)
{
Object->DocAllNUM_REM_GALLDOC=DocAllNUM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMDocRealImpl::get_DocAllPR_REM_GALLDOC(void)
{
return Object->DocAllPR_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_DocAllPR_REM_GALLDOC(TFIBSmallIntField * DocAllPR_REM_GALLDOC)
{
Object->DocAllPR_REM_GALLDOC=DocAllPR_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRealImpl::get_DocAllTDOC_REM_GALLDOC(void)
{
return Object->DocAllTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_DocAllTDOC_REM_GALLDOC(TFIBWideStringField * DocAllTDOC_REM_GALLDOC)
{
Object->DocAllTDOC_REM_GALLDOC=DocAllTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRealImpl::get_DocAllIDDOCOSN_REM_GALLDOC(void)
{
return Object->DocAllIDDOCOSN_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_DocAllIDDOCOSN_REM_GALLDOC(TFIBLargeIntField * DocAllIDDOCOSN_REM_GALLDOC)
{
Object->DocAllIDDOCOSN_REM_GALLDOC=DocAllIDDOCOSN_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocRealImpl::get_DocAllTYPEEXTDOC_REM_GALLDOC(void)
{
return Object->DocAllTYPEEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_DocAllTYPEEXTDOC_REM_GALLDOC(TFIBIntegerField * DocAllTYPEEXTDOC_REM_GALLDOC)
{
Object->DocAllTYPEEXTDOC_REM_GALLDOC=DocAllTYPEEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRealImpl::get_DocAllIDEXTDOC_REM_GALLDOC(void)
{
return Object->DocAllIDEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_DocAllIDEXTDOC_REM_GALLDOC(TFIBLargeIntField * DocAllIDEXTDOC_REM_GALLDOC)
{
Object->DocAllIDEXTDOC_REM_GALLDOC=DocAllIDEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocRealImpl::get_DocAllSUM_REM_GALLDOC(void)
{
return Object->DocAllSUM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_DocAllSUM_REM_GALLDOC(TFIBBCDField * DocAllSUM_REM_GALLDOC)
{
Object->DocAllSUM_REM_GALLDOC=DocAllSUM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRealImpl::get_DocAllIDPROJECT_REM_GALLDOC(void)
{
return Object->DocAllIDPROJECT_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_DocAllIDPROJECT_REM_GALLDOC(TFIBLargeIntField * DocAllIDPROJECT_REM_GALLDOC)
{
Object->DocAllIDPROJECT_REM_GALLDOC=DocAllIDPROJECT_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRealImpl::get_DocAllIDBUSINOP_REM_GALLDOC(void)
{
return Object->DocAllIDBUSINOP_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_DocAllIDBUSINOP_REM_GALLDOC(TFIBLargeIntField * DocAllIDBUSINOP_REM_GALLDOC)
{
Object->DocAllIDBUSINOP_REM_GALLDOC=DocAllIDBUSINOP_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRealImpl::get_DocAllFNAME_USER(void)
{
return Object->DocAllFNAME_USER;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_DocAllFNAME_USER(TFIBWideStringField * DocAllFNAME_USER)
{
Object->DocAllFNAME_USER=DocAllFNAME_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRealImpl::get_DocAllNAME_SINFBASE_OBMEN(void)
{
return Object->DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN)
{
Object->DocAllNAME_SINFBASE_OBMEN=DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRealImpl::get_DocAllNAMEFIRM(void)
{
return Object->DocAllNAMEFIRM;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_DocAllNAMEFIRM(TFIBWideStringField * DocAllNAMEFIRM)
{
Object->DocAllNAMEFIRM=DocAllNAMEFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRealImpl::get_DocAllNAMESKLAD(void)
{
return Object->DocAllNAMESKLAD;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_DocAllNAMESKLAD(TFIBWideStringField * DocAllNAMESKLAD)
{
Object->DocAllNAMESKLAD=DocAllNAMESKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRealImpl::get_DocAllNAMEKLIENT(void)
{
return Object->DocAllNAMEKLIENT;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_DocAllNAMEKLIENT(TFIBWideStringField * DocAllNAMEKLIENT)
{
Object->DocAllNAMEKLIENT=DocAllNAMEKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRealImpl::get_DocAllNAME_SPROJECT(void)
{
return Object->DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_DocAllNAME_SPROJECT(TFIBWideStringField * DocAllNAME_SPROJECT)
{
Object->DocAllNAME_SPROJECT=DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRealImpl::get_DocAllNAME_SBUSINESS_OPER(void)
{
return Object->DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_DocAllNAME_SBUSINESS_OPER(TFIBWideStringField * DocAllNAME_SBUSINESS_OPER)
{
Object->DocAllNAME_SBUSINESS_OPER=DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRealImpl::get_DocID_REM_DREAL(void)
{
return Object->DocID_REM_DREAL;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_DocID_REM_DREAL(TFIBLargeIntField * DocID_REM_DREAL)
{
Object->DocID_REM_DREAL=DocID_REM_DREAL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRealImpl::get_DocIDBASE_REM_DREAL(void)
{
return Object->DocIDBASE_REM_DREAL;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_DocIDBASE_REM_DREAL(TFIBLargeIntField * DocIDBASE_REM_DREAL)
{
Object->DocIDBASE_REM_DREAL=DocIDBASE_REM_DREAL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRealImpl::get_DocIDDOC_REM_DREAL(void)
{
return Object->DocIDDOC_REM_DREAL;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_DocIDDOC_REM_DREAL(TFIBLargeIntField * DocIDDOC_REM_DREAL)
{
Object->DocIDDOC_REM_DREAL=DocIDDOC_REM_DREAL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRealImpl::get_DocGID_REM_DREAL(void)
{
return Object->DocGID_REM_DREAL;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_DocGID_REM_DREAL(TFIBWideStringField * DocGID_REM_DREAL)
{
Object->DocGID_REM_DREAL=DocGID_REM_DREAL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRealImpl::get_DocIDTPRICE_REM_DREAL(void)
{
return Object->DocIDTPRICE_REM_DREAL;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_DocIDTPRICE_REM_DREAL(TFIBLargeIntField * DocIDTPRICE_REM_DREAL)
{
Object->DocIDTPRICE_REM_DREAL=DocIDTPRICE_REM_DREAL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRealImpl::get_DocPRIM_REM_DREAL(void)
{
return Object->DocPRIM_REM_DREAL;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_DocPRIM_REM_DREAL(TFIBWideStringField * DocPRIM_REM_DREAL)
{
Object->DocPRIM_REM_DREAL=DocPRIM_REM_DREAL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRealImpl::get_DocIDCARD_REM_DREAL(void)
{
return Object->DocIDCARD_REM_DREAL;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_DocIDCARD_REM_DREAL(TFIBLargeIntField * DocIDCARD_REM_DREAL)
{
Object->DocIDCARD_REM_DREAL=DocIDCARD_REM_DREAL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRealImpl::get_DocNAME_SDISCOUNT_CARD(void)
{
return Object->DocNAME_SDISCOUNT_CARD;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_DocNAME_SDISCOUNT_CARD(TFIBWideStringField * DocNAME_SDISCOUNT_CARD)
{
Object->DocNAME_SDISCOUNT_CARD=DocNAME_SDISCOUNT_CARD;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRealImpl::get_DocTID_REM_DREALT(void)
{
return Object->DocTID_REM_DREALT;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_DocTID_REM_DREALT(TFIBLargeIntField * DocTID_REM_DREALT)
{
Object->DocTID_REM_DREALT=DocTID_REM_DREALT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRealImpl::get_DocTIDBASE_REM_DREALT(void)
{
return Object->DocTIDBASE_REM_DREALT;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_DocTIDBASE_REM_DREALT(TFIBLargeIntField * DocTIDBASE_REM_DREALT)
{
Object->DocTIDBASE_REM_DREALT=DocTIDBASE_REM_DREALT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRealImpl::get_DocTIDDOC_REM_DREALT(void)
{
return Object->DocTIDDOC_REM_DREALT;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_DocTIDDOC_REM_DREALT(TFIBLargeIntField * DocTIDDOC_REM_DREALT)
{
Object->DocTIDDOC_REM_DREALT=DocTIDDOC_REM_DREALT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRealImpl::get_DocTGID_REM_DREALT(void)
{
return Object->DocTGID_REM_DREALT;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_DocTGID_REM_DREALT(TFIBWideStringField * DocTGID_REM_DREALT)
{
Object->DocTGID_REM_DREALT=DocTGID_REM_DREALT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRealImpl::get_DocTIDNOM_REM_DREALT(void)
{
return Object->DocTIDNOM_REM_DREALT;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_DocTIDNOM_REM_DREALT(TFIBLargeIntField * DocTIDNOM_REM_DREALT)
{
Object->DocTIDNOM_REM_DREALT=DocTIDNOM_REM_DREALT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRealImpl::get_DocTIDED_REM_DREALT(void)
{
return Object->DocTIDED_REM_DREALT;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_DocTIDED_REM_DREALT(TFIBLargeIntField * DocTIDED_REM_DREALT)
{
Object->DocTIDED_REM_DREALT=DocTIDED_REM_DREALT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRealImpl::get_DocTIDHW_REM_DREALT(void)
{
return Object->DocTIDHW_REM_DREALT;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_DocTIDHW_REM_DREALT(TFIBLargeIntField * DocTIDHW_REM_DREALT)
{
Object->DocTIDHW_REM_DREALT=DocTIDHW_REM_DREALT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocRealImpl::get_DocTKOL_REM_DREALT(void)
{
return Object->DocTKOL_REM_DREALT;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_DocTKOL_REM_DREALT(TFIBBCDField * DocTKOL_REM_DREALT)
{
Object->DocTKOL_REM_DREALT=DocTKOL_REM_DREALT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocRealImpl::get_DocTKF_REM_DREALT(void)
{
return Object->DocTKF_REM_DREALT;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_DocTKF_REM_DREALT(TFIBBCDField * DocTKF_REM_DREALT)
{
Object->DocTKF_REM_DREALT=DocTKF_REM_DREALT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocRealImpl::get_DocTPRICE_REM_DREALT(void)
{
return Object->DocTPRICE_REM_DREALT;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_DocTPRICE_REM_DREALT(TFIBBCDField * DocTPRICE_REM_DREALT)
{
Object->DocTPRICE_REM_DREALT=DocTPRICE_REM_DREALT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocRealImpl::get_DocTSUM_REM_DREALT(void)
{
return Object->DocTSUM_REM_DREALT;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_DocTSUM_REM_DREALT(TFIBBCDField * DocTSUM_REM_DREALT)
{
Object->DocTSUM_REM_DREALT=DocTSUM_REM_DREALT;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocRealImpl::get_DocTNDS_REM_DREALT(void)
{
return Object->DocTNDS_REM_DREALT;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_DocTNDS_REM_DREALT(TFIBIntegerField * DocTNDS_REM_DREALT)
{
Object->DocTNDS_REM_DREALT=DocTNDS_REM_DREALT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocRealImpl::get_DocTSUMNDS_REM_DREALT(void)
{
return Object->DocTSUMNDS_REM_DREALT;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_DocTSUMNDS_REM_DREALT(TFIBBCDField * DocTSUMNDS_REM_DREALT)
{
Object->DocTSUMNDS_REM_DREALT=DocTSUMNDS_REM_DREALT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocRealImpl::get_DocTPRSK_REM_DREALT(void)
{
return Object->DocTPRSK_REM_DREALT;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_DocTPRSK_REM_DREALT(TFIBBCDField * DocTPRSK_REM_DREALT)
{
Object->DocTPRSK_REM_DREALT=DocTPRSK_REM_DREALT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocRealImpl::get_DocTSUMSK_REM_DREALT(void)
{
return Object->DocTSUMSK_REM_DREALT;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_DocTSUMSK_REM_DREALT(TFIBBCDField * DocTSUMSK_REM_DREALT)
{
Object->DocTSUMSK_REM_DREALT=DocTSUMSK_REM_DREALT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocRealImpl::get_DocTPRSK_CARD_REM_DREALT(void)
{
return Object->DocTPRSK_CARD_REM_DREALT;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_DocTPRSK_CARD_REM_DREALT(TFIBBCDField * DocTPRSK_CARD_REM_DREALT)
{
Object->DocTPRSK_CARD_REM_DREALT=DocTPRSK_CARD_REM_DREALT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocRealImpl::get_DocTPRSK_AUTO_REM_DREALT(void)
{
return Object->DocTPRSK_AUTO_REM_DREALT;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_DocTPRSK_AUTO_REM_DREALT(TFIBBCDField * DocTPRSK_AUTO_REM_DREALT)
{
Object->DocTPRSK_AUTO_REM_DREALT=DocTPRSK_AUTO_REM_DREALT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocRealImpl::get_DocTPRSK_HAND_REM_DREALT(void)
{
return Object->DocTPRSK_HAND_REM_DREALT;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_DocTPRSK_HAND_REM_DREALT(TFIBBCDField * DocTPRSK_HAND_REM_DREALT)
{
Object->DocTPRSK_HAND_REM_DREALT=DocTPRSK_HAND_REM_DREALT;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMDocRealImpl::get_DocTNO_SK_REM_DREALT(void)
{
return Object->DocTNO_SK_REM_DREALT;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_DocTNO_SK_REM_DREALT(TFIBSmallIntField * DocTNO_SK_REM_DREALT)
{
Object->DocTNO_SK_REM_DREALT=DocTNO_SK_REM_DREALT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRealImpl::get_DocTKRNAMENOM(void)
{
return Object->DocTKRNAMENOM;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_DocTKRNAMENOM(TFIBWideStringField * DocTKRNAMENOM)
{
Object->DocTKRNAMENOM=DocTKRNAMENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRealImpl::get_DocTNAMENOM(void)
{
return Object->DocTNAMENOM;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_DocTNAMENOM(TFIBWideStringField * DocTNAMENOM)
{
Object->DocTNAMENOM=DocTNAMENOM;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMDocRealImpl::get_DocTTNOM(void)
{
return Object->DocTTNOM;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_DocTTNOM(TFIBSmallIntField * DocTTNOM)
{
Object->DocTTNOM=DocTTNOM;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocRealImpl::get_DocTCODENOM(void)
{
return Object->DocTCODENOM;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_DocTCODENOM(TFIBIntegerField * DocTCODENOM)
{
Object->DocTCODENOM=DocTCODENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRealImpl::get_DocTARTNOM(void)
{
return Object->DocTARTNOM;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_DocTARTNOM(TFIBWideStringField * DocTARTNOM)
{
Object->DocTARTNOM=DocTARTNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRealImpl::get_DocTNAMEED(void)
{
return Object->DocTNAMEED;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_DocTNAMEED(TFIBWideStringField * DocTNAMEED)
{
Object->DocTNAMEED=DocTNAMEED;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRealImpl::get_DocTSHED(void)
{
return Object->DocTSHED;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_DocTSHED(TFIBWideStringField * DocTSHED)
{
Object->DocTSHED=DocTSHED;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRealImpl::get_DocTIDGRPNOM(void)
{
return Object->DocTIDGRPNOM;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_DocTIDGRPNOM(TFIBLargeIntField * DocTIDGRPNOM)
{
Object->DocTIDGRPNOM=DocTIDGRPNOM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRealImpl::get_DocTIDVID_SNOM(void)
{
return Object->DocTIDVID_SNOM;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_DocTIDVID_SNOM(TFIBLargeIntField * DocTIDVID_SNOM)
{
Object->DocTIDVID_SNOM=DocTIDVID_SNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRealImpl::get_DocTNAMEGN(void)
{
return Object->DocTNAMEGN;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_DocTNAMEGN(TFIBWideStringField * DocTNAMEGN)
{
Object->DocTNAMEGN=DocTNAMEGN;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRealImpl::get_DocTNAME_SVIDNOM(void)
{
return Object->DocTNAME_SVIDNOM;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_DocTNAME_SVIDNOM(TFIBWideStringField * DocTNAME_SVIDNOM)
{
Object->DocTNAME_SVIDNOM=DocTNAME_SVIDNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRealImpl::get_DocTNAME_REM_SHARDWARE(void)
{
return Object->DocTNAME_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_DocTNAME_REM_SHARDWARE(TFIBWideStringField * DocTNAME_REM_SHARDWARE)
{
Object->DocTNAME_REM_SHARDWARE=DocTNAME_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocRealImpl::get_DocTCODE_REM_SHARDWARE(void)
{
return Object->DocTCODE_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_DocTCODE_REM_SHARDWARE(TFIBIntegerField * DocTCODE_REM_SHARDWARE)
{
Object->DocTCODE_REM_SHARDWARE=DocTCODE_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRealImpl::get_DocTSERNUM_REM_SHARDWARE(void)
{
return Object->DocTSERNUM_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_DocTSERNUM_REM_SHARDWARE(TFIBWideStringField * DocTSERNUM_REM_SHARDWARE)
{
Object->DocTSERNUM_REM_SHARDWARE=DocTSERNUM_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRealImpl::get_DocOsnTDOC_REM_GALLDOC(void)
{
return Object->DocOsnTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_DocOsnTDOC_REM_GALLDOC(TFIBWideStringField * DocOsnTDOC_REM_GALLDOC)
{
Object->DocOsnTDOC_REM_GALLDOC=DocOsnTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMDocRealImpl::get_DocOsnPOS_REM_GALLDOC(void)
{
return Object->DocOsnPOS_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_DocOsnPOS_REM_GALLDOC(TFIBDateTimeField * DocOsnPOS_REM_GALLDOC)
{
Object->DocOsnPOS_REM_GALLDOC=DocOsnPOS_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocRealImpl::get_DocOsnNUM_REM_GALLDOC(void)
{
return Object->DocOsnNUM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_DocOsnNUM_REM_GALLDOC(TFIBIntegerField * DocOsnNUM_REM_GALLDOC)
{
Object->DocOsnNUM_REM_GALLDOC=DocOsnNUM_REM_GALLDOC;
}
//---------------------------------------------------------------
TIntegerField * TREM_DMDocRealImpl::get_DocTRECNO(void)
{
return Object->DocTRECNO;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_DocTRECNO(TIntegerField * DocTRECNO)
{
Object->DocTRECNO=DocTRECNO;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMDocRealImpl::get_DocTDVREG_REM_DREALT(void)
{
return Object->DocTDVREG_REM_DREALT;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_DocTDVREG_REM_DREALT(TFIBSmallIntField * DocTDVREG_REM_DREALT)
{
Object->DocTDVREG_REM_DREALT=DocTDVREG_REM_DREALT;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocRealImpl::get_DocTWARRANTY_REM_DREALT(void)
{
return Object->DocTWARRANTY_REM_DREALT;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_DocTWARRANTY_REM_DREALT(TFIBIntegerField * DocTWARRANTY_REM_DREALT)
{
Object->DocTWARRANTY_REM_DREALT=DocTWARRANTY_REM_DREALT;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMDocRealImpl::get_DocTFL_NECOND_REM_SHARDWARE(void)
{
return Object->DocTFL_NECOND_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_DocTFL_NECOND_REM_SHARDWARE(TFIBSmallIntField * DocTFL_NECOND_REM_SHARDWARE)
{
Object->DocTFL_NECOND_REM_SHARDWARE=DocTFL_NECOND_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRealImpl::get_DocTPRICHINA_REM_SHARDWARE(void)
{
return Object->DocTPRICHINA_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_DocTPRICHINA_REM_SHARDWARE(TFIBWideStringField * DocTPRICHINA_REM_SHARDWARE)
{
Object->DocTPRICHINA_REM_SHARDWARE=DocTPRICHINA_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRealImpl::get_DocAllPREFIKS_NUM_REM_GALLDOC(void)
{
return Object->DocAllPREFIKS_NUM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_DocAllPREFIKS_NUM_REM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_REM_GALLDOC)
{
Object->DocAllPREFIKS_NUM_REM_GALLDOC=DocAllPREFIKS_NUM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRealImpl::get_DocTIDTNOM_REM_DREALT(void)
{
return Object->DocTIDTNOM_REM_DREALT;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_DocTIDTNOM_REM_DREALT(TFIBLargeIntField * DocTIDTNOM_REM_DREALT)
{
Object->DocTIDTNOM_REM_DREALT=DocTIDTNOM_REM_DREALT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocRealImpl::get_DocTIDMHRAN_DREALT(void)
{
return Object->DocTIDMHRAN_DREALT;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_DocTIDMHRAN_DREALT(TFIBLargeIntField * DocTIDMHRAN_DREALT)
{
Object->DocTIDMHRAN_DREALT=DocTIDMHRAN_DREALT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRealImpl::get_DocTNAME_STNOM(void)
{
return Object->DocTNAME_STNOM;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_DocTNAME_STNOM(TFIBWideStringField * DocTNAME_STNOM)
{
Object->DocTNAME_STNOM=DocTNAME_STNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocRealImpl::get_DocTNAME_SMHRAN(void)
{
return Object->DocTNAME_SMHRAN;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_DocTNAME_SMHRAN(TFIBWideStringField * DocTNAME_SMHRAN)
{
Object->DocTNAME_SMHRAN=DocTNAME_SMHRAN;
}
//---------------------------------------------------------------
bool TREM_DMDocRealImpl::get_NewElement(void)
{
return Object->NewElement;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_NewElement(bool NewElement)
{
Object->NewElement=NewElement;
}
//---------------------------------------------------------------
bool TREM_DMDocRealImpl::get_Prosmotr(void)
{
return Object->Prosmotr;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_Prosmotr(bool Prosmotr)
{
Object->Prosmotr=Prosmotr;
}
//---------------------------------------------------------------
UnicodeString TREM_DMDocRealImpl::get_ProsmotrText(void)
{
return Object->ProsmotrText;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_ProsmotrText(UnicodeString ProsmotrText)
{
Object->ProsmotrText=ProsmotrText;
}
//---------------------------------------------------------------
__int64 TREM_DMDocRealImpl::get_IdDoc(void)
{
return Object->IdDoc;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_IdDoc(__int64 IdDoc)
{
Object->IdDoc=IdDoc;
}
//---------------------------------------------------------------
__int64 TREM_DMDocRealImpl::get_IdGrp(void)
{
return Object->IdGrp;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_IdGrp(__int64 IdGrp)
{
Object->IdGrp=IdGrp;
}
//---------------------------------------------------------------
__int64 TREM_DMDocRealImpl::get_IdElementaMaster(void)
{
return Object->IdElementaMaster;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_IdElementaMaster(__int64 IdElementaMaster)
{
Object->IdElementaMaster=IdElementaMaster;
}
//---------------------------------------------------------------
__int64 TREM_DMDocRealImpl::get_IdTypePrice(void)
{
return Object->IdTypePrice;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_IdTypePrice(__int64 IdTypePrice)
{
Object->IdTypePrice=IdTypePrice;
}
//---------------------------------------------------------------
int TREM_DMDocRealImpl::get_Operation(void)
{
return Object->Operation;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_Operation(int Operation)
{
Object->Operation=Operation;
}
//---------------------------------------------------------------
__int64 TREM_DMDocRealImpl::get_IdSklad(void)
{
return Object->IdSklad;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_IdSklad(__int64 IdSklad)
{
Object->IdSklad=IdSklad;
}
//---------------------------------------------------------------
bool TREM_DMDocRealImpl::get_AutoRaschet(void)
{
return Object->AutoRaschet;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_AutoRaschet(bool AutoRaschet)
{
Object->AutoRaschet=AutoRaschet;
}
//---------------------------------------------------------------
bool TREM_DMDocRealImpl::get_EnableDvReg(void)
{
return Object->EnableDvReg;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_EnableDvReg(bool EnableDvReg)
{
Object->EnableDvReg=EnableDvReg;
}
//---------------------------------------------------------------
bool TREM_DMDocRealImpl::get_SkladRozn(void)
{
return Object->SkladRozn;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_SkladRozn(bool SkladRozn)
{
Object->SkladRozn=SkladRozn;
}
//---------------------------------------------------------------
bool TREM_DMDocRealImpl::get_NoOtrOstatok(void)
{
return Object->NoOtrOstatok;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::set_NoOtrOstatok(bool NoOtrOstatok)
{
Object->NoOtrOstatok=NoOtrOstatok;
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::NewDoc(void)
{
return Object->NewDoc();
}
//---------------------------------------------------------------
bool TREM_DMDocRealImpl::OpenDoc(__int64 IdDoc)
{
return Object->OpenDoc(IdDoc);
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::OpenDocOsn(void)
{
return Object->OpenDocOsn();
}
//---------------------------------------------------------------
bool TREM_DMDocRealImpl::SaveDoc(void)
{
return Object->SaveDoc();
}
//---------------------------------------------------------------
bool TREM_DMDocRealImpl::BeforeSaveDoc(void)
{
return Object->BeforeSaveDoc();
}
//---------------------------------------------------------------
bool TREM_DMDocRealImpl::AfterSaveDoc(void)
{
return Object->AfterSaveDoc();
}
//---------------------------------------------------------------
bool TREM_DMDocRealImpl::DvRegDoc(void)
{
return Object->DvRegDoc();
}
//---------------------------------------------------------------
bool TREM_DMDocRealImpl::CancelDvRegDoc(void)
{
return Object->CancelDvRegDoc();
}
//---------------------------------------------------------------
bool TREM_DMDocRealImpl::DeleteDoc(__int64 id)
{
return Object->DeleteDoc( id);
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::AddDocNewString(void)
{
return Object->AddDocNewString();
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::DeleteStringDoc(void)
{
return Object->DeleteStringDoc();
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::CloseDoc(void)
{
return Object->CloseDoc();
}
//---------------------------------------------------------------
void TREM_DMDocRealImpl::ValidateProsmotr(void)
{
return Object->ValidateProsmotr();
}
//---------------------------------------------------------------
int TREM_DMDocRealImpl::GetNumberNewDoc(void)
{
return Object->GetNumberNewDoc();
}
//---------------------------------------------------------------
