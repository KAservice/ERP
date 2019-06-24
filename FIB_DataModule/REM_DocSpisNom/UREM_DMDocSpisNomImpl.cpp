#include "vcl.h"
#pragma hdrstop


#include "UREM_DMDocSpisNomImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_DMDocSpisNomImpl::TREM_DMDocSpisNomImpl()           
{                                            
Object=new TREM_DMDocSpisNom(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_DMDocSpisNomImpl::~TREM_DMDocSpisNomImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_DMDocSpisNomImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_DMDocSpisNomImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_DMDocSpisNom)                        
   {                                                                     
   *ppv=static_cast<IREM_DMDocSpisNom*> (this);                                
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
int TREM_DMDocSpisNomImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_DMDocSpisNomImpl::kanRelease(void)                                  
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
int  TREM_DMDocSpisNomImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMDocSpisNomImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_DMDocSpisNomImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMDocSpisNomImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_DMDocSpisNomImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_DMDocSpisNomImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_DMDocSpisNomImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IREM_DMDocSpisNom
TDataSource * TREM_DMDocSpisNomImpl::get_DataSourceDoc(void)
{
return Object->DataSourceDoc;
}
//---------------------------------------------------------------
void TREM_DMDocSpisNomImpl::set_DataSourceDoc(TDataSource * DataSourceDoc)
{
Object->DataSourceDoc=DataSourceDoc;
}
//---------------------------------------------------------------
TDataSource * TREM_DMDocSpisNomImpl::get_DataSourceDocT(void)
{
return Object->DataSourceDocT;
}
//---------------------------------------------------------------
void TREM_DMDocSpisNomImpl::set_DataSourceDocT(TDataSource * DataSourceDocT)
{
Object->DataSourceDocT=DataSourceDocT;
}
//---------------------------------------------------------------
TDataSource * TREM_DMDocSpisNomImpl::get_DataSourceDocAll(void)
{
return Object->DataSourceDocAll;
}
//---------------------------------------------------------------
void TREM_DMDocSpisNomImpl::set_DataSourceDocAll(TDataSource * DataSourceDocAll)
{
Object->DataSourceDocAll=DataSourceDocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocSpisNomImpl::get_DocAll(void)
{
return Object->DocAll;
}
//---------------------------------------------------------------
void TREM_DMDocSpisNomImpl::set_DocAll(TpFIBDataSet * DocAll)
{
Object->DocAll=DocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocSpisNomImpl::get_Doc(void)
{
return Object->Doc;
}
//---------------------------------------------------------------
void TREM_DMDocSpisNomImpl::set_Doc(TpFIBDataSet * Doc)
{
Object->Doc=Doc;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocSpisNomImpl::get_DocT(void)
{
return Object->DocT;
}
//---------------------------------------------------------------
void TREM_DMDocSpisNomImpl::set_DocT(TpFIBDataSet * DocT)
{
Object->DocT=DocT;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMDocSpisNomImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TREM_DMDocSpisNomImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMDocSpisNomImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TREM_DMDocSpisNomImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMDocSpisNomImpl::get_IBTrDvReg(void)
{
return Object->IBTrDvReg;
}
//---------------------------------------------------------------
void TREM_DMDocSpisNomImpl::set_IBTrDvReg(TpFIBTransaction * IBTrDvReg)
{
Object->IBTrDvReg=IBTrDvReg;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocSpisNomImpl::get_NumDoc(void)
{
return Object->NumDoc;
}
//---------------------------------------------------------------
void TREM_DMDocSpisNomImpl::set_NumDoc(TpFIBDataSet * NumDoc)
{
Object->NumDoc=NumDoc;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMDocSpisNomImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TREM_DMDocSpisNomImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMDocSpisNomImpl::get_QueryCancelDvReg(void)
{
return Object->QueryCancelDvReg;
}
//---------------------------------------------------------------
void TREM_DMDocSpisNomImpl::set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg)
{
Object->QueryCancelDvReg=QueryCancelDvReg;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMDocSpisNomImpl::get_QueryDvReg(void)
{
return Object->QueryDvReg;
}
//---------------------------------------------------------------
void TREM_DMDocSpisNomImpl::set_QueryDvReg(TpFIBQuery * QueryDvReg)
{
Object->QueryDvReg=QueryDvReg;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocSpisNomImpl::get_NumDocMAXNUMBER(void)
{
return Object->NumDocMAXNUMBER;
}
//---------------------------------------------------------------
void TREM_DMDocSpisNomImpl::set_NumDocMAXNUMBER(TFIBIntegerField * NumDocMAXNUMBER)
{
Object->NumDocMAXNUMBER=NumDocMAXNUMBER;
}
//---------------------------------------------------------------
TIntegerField * TREM_DMDocSpisNomImpl::get_DocTRECNO(void)
{
return Object->DocTRECNO;
}
//---------------------------------------------------------------
void TREM_DMDocSpisNomImpl::set_DocTRECNO(TIntegerField * DocTRECNO)
{
Object->DocTRECNO=DocTRECNO;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocSpisNomImpl::get_DocAllID_REM_GALLDOC(void)
{
return Object->DocAllID_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocSpisNomImpl::set_DocAllID_REM_GALLDOC(TFIBLargeIntField * DocAllID_REM_GALLDOC)
{
Object->DocAllID_REM_GALLDOC=DocAllID_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocSpisNomImpl::get_DocAllIDBASE_REM_GALLDOC(void)
{
return Object->DocAllIDBASE_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocSpisNomImpl::set_DocAllIDBASE_REM_GALLDOC(TFIBLargeIntField * DocAllIDBASE_REM_GALLDOC)
{
Object->DocAllIDBASE_REM_GALLDOC=DocAllIDBASE_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocSpisNomImpl::get_DocAllIDFIRM_REM_GALLDOC(void)
{
return Object->DocAllIDFIRM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocSpisNomImpl::set_DocAllIDFIRM_REM_GALLDOC(TFIBLargeIntField * DocAllIDFIRM_REM_GALLDOC)
{
Object->DocAllIDFIRM_REM_GALLDOC=DocAllIDFIRM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocSpisNomImpl::get_DocAllIDSKLAD_REM_GALLDOC(void)
{
return Object->DocAllIDSKLAD_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocSpisNomImpl::set_DocAllIDSKLAD_REM_GALLDOC(TFIBLargeIntField * DocAllIDSKLAD_REM_GALLDOC)
{
Object->DocAllIDSKLAD_REM_GALLDOC=DocAllIDSKLAD_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocSpisNomImpl::get_DocAllIDKLIENT_REM_GALLDOC(void)
{
return Object->DocAllIDKLIENT_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocSpisNomImpl::set_DocAllIDKLIENT_REM_GALLDOC(TFIBLargeIntField * DocAllIDKLIENT_REM_GALLDOC)
{
Object->DocAllIDKLIENT_REM_GALLDOC=DocAllIDKLIENT_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocSpisNomImpl::get_DocAllIDUSER_REM_GALLDOC(void)
{
return Object->DocAllIDUSER_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocSpisNomImpl::set_DocAllIDUSER_REM_GALLDOC(TFIBLargeIntField * DocAllIDUSER_REM_GALLDOC)
{
Object->DocAllIDUSER_REM_GALLDOC=DocAllIDUSER_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMDocSpisNomImpl::get_DocAllPOS_REM_GALLDOC(void)
{
return Object->DocAllPOS_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocSpisNomImpl::set_DocAllPOS_REM_GALLDOC(TFIBDateTimeField * DocAllPOS_REM_GALLDOC)
{
Object->DocAllPOS_REM_GALLDOC=DocAllPOS_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocSpisNomImpl::get_DocAllNUM_REM_GALLDOC(void)
{
return Object->DocAllNUM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocSpisNomImpl::set_DocAllNUM_REM_GALLDOC(TFIBIntegerField * DocAllNUM_REM_GALLDOC)
{
Object->DocAllNUM_REM_GALLDOC=DocAllNUM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMDocSpisNomImpl::get_DocAllPR_REM_GALLDOC(void)
{
return Object->DocAllPR_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocSpisNomImpl::set_DocAllPR_REM_GALLDOC(TFIBSmallIntField * DocAllPR_REM_GALLDOC)
{
Object->DocAllPR_REM_GALLDOC=DocAllPR_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocSpisNomImpl::get_DocAllTDOC_REM_GALLDOC(void)
{
return Object->DocAllTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocSpisNomImpl::set_DocAllTDOC_REM_GALLDOC(TFIBWideStringField * DocAllTDOC_REM_GALLDOC)
{
Object->DocAllTDOC_REM_GALLDOC=DocAllTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocSpisNomImpl::get_DocAllIDDOCOSN_REM_GALLDOC(void)
{
return Object->DocAllIDDOCOSN_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocSpisNomImpl::set_DocAllIDDOCOSN_REM_GALLDOC(TFIBLargeIntField * DocAllIDDOCOSN_REM_GALLDOC)
{
Object->DocAllIDDOCOSN_REM_GALLDOC=DocAllIDDOCOSN_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocSpisNomImpl::get_DocAllTYPEEXTDOC_REM_GALLDOC(void)
{
return Object->DocAllTYPEEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocSpisNomImpl::set_DocAllTYPEEXTDOC_REM_GALLDOC(TFIBIntegerField * DocAllTYPEEXTDOC_REM_GALLDOC)
{
Object->DocAllTYPEEXTDOC_REM_GALLDOC=DocAllTYPEEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocSpisNomImpl::get_DocAllIDEXTDOC_REM_GALLDOC(void)
{
return Object->DocAllIDEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocSpisNomImpl::set_DocAllIDEXTDOC_REM_GALLDOC(TFIBLargeIntField * DocAllIDEXTDOC_REM_GALLDOC)
{
Object->DocAllIDEXTDOC_REM_GALLDOC=DocAllIDEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocSpisNomImpl::get_DocAllSUM_REM_GALLDOC(void)
{
return Object->DocAllSUM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocSpisNomImpl::set_DocAllSUM_REM_GALLDOC(TFIBBCDField * DocAllSUM_REM_GALLDOC)
{
Object->DocAllSUM_REM_GALLDOC=DocAllSUM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocSpisNomImpl::get_DocAllFNAME_USER(void)
{
return Object->DocAllFNAME_USER;
}
//---------------------------------------------------------------
void TREM_DMDocSpisNomImpl::set_DocAllFNAME_USER(TFIBWideStringField * DocAllFNAME_USER)
{
Object->DocAllFNAME_USER=DocAllFNAME_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocSpisNomImpl::get_DocAllNAME_SINFBASE_OBMEN(void)
{
return Object->DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void TREM_DMDocSpisNomImpl::set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN)
{
Object->DocAllNAME_SINFBASE_OBMEN=DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocSpisNomImpl::get_DocAllNAMEFIRM(void)
{
return Object->DocAllNAMEFIRM;
}
//---------------------------------------------------------------
void TREM_DMDocSpisNomImpl::set_DocAllNAMEFIRM(TFIBWideStringField * DocAllNAMEFIRM)
{
Object->DocAllNAMEFIRM=DocAllNAMEFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocSpisNomImpl::get_DocAllNAMESKLAD(void)
{
return Object->DocAllNAMESKLAD;
}
//---------------------------------------------------------------
void TREM_DMDocSpisNomImpl::set_DocAllNAMESKLAD(TFIBWideStringField * DocAllNAMESKLAD)
{
Object->DocAllNAMESKLAD=DocAllNAMESKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocSpisNomImpl::get_DocAllNAMEKLIENT(void)
{
return Object->DocAllNAMEKLIENT;
}
//---------------------------------------------------------------
void TREM_DMDocSpisNomImpl::set_DocAllNAMEKLIENT(TFIBWideStringField * DocAllNAMEKLIENT)
{
Object->DocAllNAMEKLIENT=DocAllNAMEKLIENT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocSpisNomImpl::get_DocID_REM_DSPN(void)
{
return Object->DocID_REM_DSPN;
}
//---------------------------------------------------------------
void TREM_DMDocSpisNomImpl::set_DocID_REM_DSPN(TFIBLargeIntField * DocID_REM_DSPN)
{
Object->DocID_REM_DSPN=DocID_REM_DSPN;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocSpisNomImpl::get_DocIDBASE_REM_DSPN(void)
{
return Object->DocIDBASE_REM_DSPN;
}
//---------------------------------------------------------------
void TREM_DMDocSpisNomImpl::set_DocIDBASE_REM_DSPN(TFIBLargeIntField * DocIDBASE_REM_DSPN)
{
Object->DocIDBASE_REM_DSPN=DocIDBASE_REM_DSPN;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocSpisNomImpl::get_DocIDDOC_REM_DSPN(void)
{
return Object->DocIDDOC_REM_DSPN;
}
//---------------------------------------------------------------
void TREM_DMDocSpisNomImpl::set_DocIDDOC_REM_DSPN(TFIBLargeIntField * DocIDDOC_REM_DSPN)
{
Object->DocIDDOC_REM_DSPN=DocIDDOC_REM_DSPN;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocSpisNomImpl::get_DocGID_REM_DSPN(void)
{
return Object->DocGID_REM_DSPN;
}
//---------------------------------------------------------------
void TREM_DMDocSpisNomImpl::set_DocGID_REM_DSPN(TFIBWideStringField * DocGID_REM_DSPN)
{
Object->DocGID_REM_DSPN=DocGID_REM_DSPN;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocSpisNomImpl::get_DocIDRTPRICE_REM_DSPN(void)
{
return Object->DocIDRTPRICE_REM_DSPN;
}
//---------------------------------------------------------------
void TREM_DMDocSpisNomImpl::set_DocIDRTPRICE_REM_DSPN(TFIBLargeIntField * DocIDRTPRICE_REM_DSPN)
{
Object->DocIDRTPRICE_REM_DSPN=DocIDRTPRICE_REM_DSPN;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocSpisNomImpl::get_DocRSUM_REM_DSPN(void)
{
return Object->DocRSUM_REM_DSPN;
}
//---------------------------------------------------------------
void TREM_DMDocSpisNomImpl::set_DocRSUM_REM_DSPN(TFIBBCDField * DocRSUM_REM_DSPN)
{
Object->DocRSUM_REM_DSPN=DocRSUM_REM_DSPN;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocSpisNomImpl::get_DocPRIM_REM_DSPN(void)
{
return Object->DocPRIM_REM_DSPN;
}
//---------------------------------------------------------------
void TREM_DMDocSpisNomImpl::set_DocPRIM_REM_DSPN(TFIBWideStringField * DocPRIM_REM_DSPN)
{
Object->DocPRIM_REM_DSPN=DocPRIM_REM_DSPN;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocSpisNomImpl::get_DocNAME_TPRICE(void)
{
return Object->DocNAME_TPRICE;
}
//---------------------------------------------------------------
void TREM_DMDocSpisNomImpl::set_DocNAME_TPRICE(TFIBWideStringField * DocNAME_TPRICE)
{
Object->DocNAME_TPRICE=DocNAME_TPRICE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocSpisNomImpl::get_DocTID_REM_DSPNT(void)
{
return Object->DocTID_REM_DSPNT;
}
//---------------------------------------------------------------
void TREM_DMDocSpisNomImpl::set_DocTID_REM_DSPNT(TFIBLargeIntField * DocTID_REM_DSPNT)
{
Object->DocTID_REM_DSPNT=DocTID_REM_DSPNT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocSpisNomImpl::get_DocTIDBASE_REM_DSPNT(void)
{
return Object->DocTIDBASE_REM_DSPNT;
}
//---------------------------------------------------------------
void TREM_DMDocSpisNomImpl::set_DocTIDBASE_REM_DSPNT(TFIBLargeIntField * DocTIDBASE_REM_DSPNT)
{
Object->DocTIDBASE_REM_DSPNT=DocTIDBASE_REM_DSPNT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocSpisNomImpl::get_DocTIDDOC_REM_DSPNT(void)
{
return Object->DocTIDDOC_REM_DSPNT;
}
//---------------------------------------------------------------
void TREM_DMDocSpisNomImpl::set_DocTIDDOC_REM_DSPNT(TFIBLargeIntField * DocTIDDOC_REM_DSPNT)
{
Object->DocTIDDOC_REM_DSPNT=DocTIDDOC_REM_DSPNT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocSpisNomImpl::get_DocTGID_REM_DSPNT(void)
{
return Object->DocTGID_REM_DSPNT;
}
//---------------------------------------------------------------
void TREM_DMDocSpisNomImpl::set_DocTGID_REM_DSPNT(TFIBWideStringField * DocTGID_REM_DSPNT)
{
Object->DocTGID_REM_DSPNT=DocTGID_REM_DSPNT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocSpisNomImpl::get_DocTIDNOM_REM_DSPNT(void)
{
return Object->DocTIDNOM_REM_DSPNT;
}
//---------------------------------------------------------------
void TREM_DMDocSpisNomImpl::set_DocTIDNOM_REM_DSPNT(TFIBLargeIntField * DocTIDNOM_REM_DSPNT)
{
Object->DocTIDNOM_REM_DSPNT=DocTIDNOM_REM_DSPNT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocSpisNomImpl::get_DocTIDED_REM_DSPNT(void)
{
return Object->DocTIDED_REM_DSPNT;
}
//---------------------------------------------------------------
void TREM_DMDocSpisNomImpl::set_DocTIDED_REM_DSPNT(TFIBLargeIntField * DocTIDED_REM_DSPNT)
{
Object->DocTIDED_REM_DSPNT=DocTIDED_REM_DSPNT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocSpisNomImpl::get_DocTIDHW_REM_DSPNT(void)
{
return Object->DocTIDHW_REM_DSPNT;
}
//---------------------------------------------------------------
void TREM_DMDocSpisNomImpl::set_DocTIDHW_REM_DSPNT(TFIBLargeIntField * DocTIDHW_REM_DSPNT)
{
Object->DocTIDHW_REM_DSPNT=DocTIDHW_REM_DSPNT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocSpisNomImpl::get_DocTKOL_REM_DSPNT(void)
{
return Object->DocTKOL_REM_DSPNT;
}
//---------------------------------------------------------------
void TREM_DMDocSpisNomImpl::set_DocTKOL_REM_DSPNT(TFIBBCDField * DocTKOL_REM_DSPNT)
{
Object->DocTKOL_REM_DSPNT=DocTKOL_REM_DSPNT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocSpisNomImpl::get_DocTKF_REM_DSPNT(void)
{
return Object->DocTKF_REM_DSPNT;
}
//---------------------------------------------------------------
void TREM_DMDocSpisNomImpl::set_DocTKF_REM_DSPNT(TFIBBCDField * DocTKF_REM_DSPNT)
{
Object->DocTKF_REM_DSPNT=DocTKF_REM_DSPNT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocSpisNomImpl::get_DocTPRICE_REM_DSPNT(void)
{
return Object->DocTPRICE_REM_DSPNT;
}
//---------------------------------------------------------------
void TREM_DMDocSpisNomImpl::set_DocTPRICE_REM_DSPNT(TFIBBCDField * DocTPRICE_REM_DSPNT)
{
Object->DocTPRICE_REM_DSPNT=DocTPRICE_REM_DSPNT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocSpisNomImpl::get_DocTSUM_REM_DSPNT(void)
{
return Object->DocTSUM_REM_DSPNT;
}
//---------------------------------------------------------------
void TREM_DMDocSpisNomImpl::set_DocTSUM_REM_DSPNT(TFIBBCDField * DocTSUM_REM_DSPNT)
{
Object->DocTSUM_REM_DSPNT=DocTSUM_REM_DSPNT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocSpisNomImpl::get_DocTRPRICE_REM_DSPNT(void)
{
return Object->DocTRPRICE_REM_DSPNT;
}
//---------------------------------------------------------------
void TREM_DMDocSpisNomImpl::set_DocTRPRICE_REM_DSPNT(TFIBBCDField * DocTRPRICE_REM_DSPNT)
{
Object->DocTRPRICE_REM_DSPNT=DocTRPRICE_REM_DSPNT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocSpisNomImpl::get_DocTRSUM_REM_DSPNT(void)
{
return Object->DocTRSUM_REM_DSPNT;
}
//---------------------------------------------------------------
void TREM_DMDocSpisNomImpl::set_DocTRSUM_REM_DSPNT(TFIBBCDField * DocTRSUM_REM_DSPNT)
{
Object->DocTRSUM_REM_DSPNT=DocTRSUM_REM_DSPNT;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMDocSpisNomImpl::get_DocTDVREG_REM_DSPNT(void)
{
return Object->DocTDVREG_REM_DSPNT;
}
//---------------------------------------------------------------
void TREM_DMDocSpisNomImpl::set_DocTDVREG_REM_DSPNT(TFIBSmallIntField * DocTDVREG_REM_DSPNT)
{
Object->DocTDVREG_REM_DSPNT=DocTDVREG_REM_DSPNT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocSpisNomImpl::get_DocTNAMENOM(void)
{
return Object->DocTNAMENOM;
}
//---------------------------------------------------------------
void TREM_DMDocSpisNomImpl::set_DocTNAMENOM(TFIBWideStringField * DocTNAMENOM)
{
Object->DocTNAMENOM=DocTNAMENOM;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocSpisNomImpl::get_DocTCODENOM(void)
{
return Object->DocTCODENOM;
}
//---------------------------------------------------------------
void TREM_DMDocSpisNomImpl::set_DocTCODENOM(TFIBIntegerField * DocTCODENOM)
{
Object->DocTCODENOM=DocTCODENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocSpisNomImpl::get_DocTARTNOM(void)
{
return Object->DocTARTNOM;
}
//---------------------------------------------------------------
void TREM_DMDocSpisNomImpl::set_DocTARTNOM(TFIBWideStringField * DocTARTNOM)
{
Object->DocTARTNOM=DocTARTNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocSpisNomImpl::get_DocTNAMEED(void)
{
return Object->DocTNAMEED;
}
//---------------------------------------------------------------
void TREM_DMDocSpisNomImpl::set_DocTNAMEED(TFIBWideStringField * DocTNAMEED)
{
Object->DocTNAMEED=DocTNAMEED;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocSpisNomImpl::get_DocTSHED(void)
{
return Object->DocTSHED;
}
//---------------------------------------------------------------
void TREM_DMDocSpisNomImpl::set_DocTSHED(TFIBWideStringField * DocTSHED)
{
Object->DocTSHED=DocTSHED;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocSpisNomImpl::get_DocTNAME_REM_SHARDWARE(void)
{
return Object->DocTNAME_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMDocSpisNomImpl::set_DocTNAME_REM_SHARDWARE(TFIBWideStringField * DocTNAME_REM_SHARDWARE)
{
Object->DocTNAME_REM_SHARDWARE=DocTNAME_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocSpisNomImpl::get_DocTCODE_REM_SHARDWARE(void)
{
return Object->DocTCODE_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMDocSpisNomImpl::set_DocTCODE_REM_SHARDWARE(TFIBIntegerField * DocTCODE_REM_SHARDWARE)
{
Object->DocTCODE_REM_SHARDWARE=DocTCODE_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocSpisNomImpl::get_DocTSERNUM_REM_SHARDWARE(void)
{
return Object->DocTSERNUM_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMDocSpisNomImpl::set_DocTSERNUM_REM_SHARDWARE(TFIBWideStringField * DocTSERNUM_REM_SHARDWARE)
{
Object->DocTSERNUM_REM_SHARDWARE=DocTSERNUM_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocSpisNomImpl::get_DocAllIDPROJECT_REM_GALLDOC(void)
{
return Object->DocAllIDPROJECT_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocSpisNomImpl::set_DocAllIDPROJECT_REM_GALLDOC(TFIBLargeIntField * DocAllIDPROJECT_REM_GALLDOC)
{
Object->DocAllIDPROJECT_REM_GALLDOC=DocAllIDPROJECT_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocSpisNomImpl::get_DocAllIDBUSINOP_REM_GALLDOC(void)
{
return Object->DocAllIDBUSINOP_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocSpisNomImpl::set_DocAllIDBUSINOP_REM_GALLDOC(TFIBLargeIntField * DocAllIDBUSINOP_REM_GALLDOC)
{
Object->DocAllIDBUSINOP_REM_GALLDOC=DocAllIDBUSINOP_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocSpisNomImpl::get_DocAllPREFIKS_NUM_REM_GALLDOC(void)
{
return Object->DocAllPREFIKS_NUM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocSpisNomImpl::set_DocAllPREFIKS_NUM_REM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_REM_GALLDOC)
{
Object->DocAllPREFIKS_NUM_REM_GALLDOC=DocAllPREFIKS_NUM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocSpisNomImpl::get_DocAllNAME_SPROJECT(void)
{
return Object->DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
void TREM_DMDocSpisNomImpl::set_DocAllNAME_SPROJECT(TFIBWideStringField * DocAllNAME_SPROJECT)
{
Object->DocAllNAME_SPROJECT=DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocSpisNomImpl::get_DocAllNAME_SBUSINESS_OPER(void)
{
return Object->DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
void TREM_DMDocSpisNomImpl::set_DocAllNAME_SBUSINESS_OPER(TFIBWideStringField * DocAllNAME_SBUSINESS_OPER)
{
Object->DocAllNAME_SBUSINESS_OPER=DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocSpisNomImpl::get_DocTIDTNOM_REM_DSPNT(void)
{
return Object->DocTIDTNOM_REM_DSPNT;
}
//---------------------------------------------------------------
void TREM_DMDocSpisNomImpl::set_DocTIDTNOM_REM_DSPNT(TFIBLargeIntField * DocTIDTNOM_REM_DSPNT)
{
Object->DocTIDTNOM_REM_DSPNT=DocTIDTNOM_REM_DSPNT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocSpisNomImpl::get_DocTIDMHRAN_REM_DSPNT(void)
{
return Object->DocTIDMHRAN_REM_DSPNT;
}
//---------------------------------------------------------------
void TREM_DMDocSpisNomImpl::set_DocTIDMHRAN_REM_DSPNT(TFIBLargeIntField * DocTIDMHRAN_REM_DSPNT)
{
Object->DocTIDMHRAN_REM_DSPNT=DocTIDMHRAN_REM_DSPNT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocSpisNomImpl::get_DocTNAME_SMHRAN(void)
{
return Object->DocTNAME_SMHRAN;
}
//---------------------------------------------------------------
void TREM_DMDocSpisNomImpl::set_DocTNAME_SMHRAN(TFIBWideStringField * DocTNAME_SMHRAN)
{
Object->DocTNAME_SMHRAN=DocTNAME_SMHRAN;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocSpisNomImpl::get_DocTNAME_STNOM(void)
{
return Object->DocTNAME_STNOM;
}
//---------------------------------------------------------------
void TREM_DMDocSpisNomImpl::set_DocTNAME_STNOM(TFIBWideStringField * DocTNAME_STNOM)
{
Object->DocTNAME_STNOM=DocTNAME_STNOM;
}
//---------------------------------------------------------------
__int64 TREM_DMDocSpisNomImpl::get_IdDoc(void)
{
return Object->IdDoc;
}
//---------------------------------------------------------------
void TREM_DMDocSpisNomImpl::set_IdDoc(__int64 IdDoc)
{
Object->IdDoc=IdDoc;
}
//---------------------------------------------------------------
bool TREM_DMDocSpisNomImpl::get_Prosmotr(void)
{
return Object->Prosmotr;
}
//---------------------------------------------------------------
void TREM_DMDocSpisNomImpl::set_Prosmotr(bool Prosmotr)
{
Object->Prosmotr=Prosmotr;
}
//---------------------------------------------------------------
bool TREM_DMDocSpisNomImpl::NewDoc(void)
{
return Object->NewDoc();
}
//---------------------------------------------------------------
bool TREM_DMDocSpisNomImpl::OpenDoc(__int64 id)
{
return Object->OpenDoc(id);
}
//---------------------------------------------------------------
bool TREM_DMDocSpisNomImpl::SaveDoc(void)
{
return Object->SaveDoc();
}
//---------------------------------------------------------------
bool TREM_DMDocSpisNomImpl::DeleteDoc(__int64 id)
{
return Object->DeleteDoc(id);
}
//---------------------------------------------------------------
bool TREM_DMDocSpisNomImpl::DvRegDoc(void)
{
return Object->DvRegDoc();
}
//---------------------------------------------------------------
bool TREM_DMDocSpisNomImpl::CancelDvRegDoc(void)
{
return Object->CancelDvRegDoc();
}
//---------------------------------------------------------------
void TREM_DMDocSpisNomImpl::TableAppend(void)
{
return Object->TableAppend();
}
//---------------------------------------------------------------
void TREM_DMDocSpisNomImpl::TableDelete(void)
{
return Object->TableDelete();
}
//---------------------------------------------------------------
