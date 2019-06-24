#include "vcl.h"
#pragma hdrstop


#include "UREM_DMDocPerServCentrImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_DMDocPerServCentrImpl::TREM_DMDocPerServCentrImpl()           
{                                            
Object=new TREM_DMDocPerServCentr(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_DMDocPerServCentrImpl::~TREM_DMDocPerServCentrImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_DMDocPerServCentrImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_DMDocPerServCentrImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_DMDocPerServCentr)                        
   {                                                                     
   *ppv=static_cast<IREM_DMDocPerServCentr*> (this);                                
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
int TREM_DMDocPerServCentrImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_DMDocPerServCentrImpl::kanRelease(void)                                  
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
int  TREM_DMDocPerServCentrImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMDocPerServCentrImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_DMDocPerServCentrImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMDocPerServCentrImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_DMDocPerServCentrImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_DMDocPerServCentrImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_DMDocPerServCentrImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IREM_DMDocPerServCentr
TDataSource * TREM_DMDocPerServCentrImpl::get_DataSourceDoc(void)
{
return Object->DataSourceDoc;
}
//---------------------------------------------------------------
void TREM_DMDocPerServCentrImpl::set_DataSourceDoc(TDataSource * DataSourceDoc)
{
Object->DataSourceDoc=DataSourceDoc;
}
//---------------------------------------------------------------
TDataSource * TREM_DMDocPerServCentrImpl::get_DataSourceDocT(void)
{
return Object->DataSourceDocT;
}
//---------------------------------------------------------------
void TREM_DMDocPerServCentrImpl::set_DataSourceDocT(TDataSource * DataSourceDocT)
{
Object->DataSourceDocT=DataSourceDocT;
}
//---------------------------------------------------------------
TDataSource * TREM_DMDocPerServCentrImpl::get_DataSourceDocAll(void)
{
return Object->DataSourceDocAll;
}
//---------------------------------------------------------------
void TREM_DMDocPerServCentrImpl::set_DataSourceDocAll(TDataSource * DataSourceDocAll)
{
Object->DataSourceDocAll=DataSourceDocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocPerServCentrImpl::get_DocAll(void)
{
return Object->DocAll;
}
//---------------------------------------------------------------
void TREM_DMDocPerServCentrImpl::set_DocAll(TpFIBDataSet * DocAll)
{
Object->DocAll=DocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocPerServCentrImpl::get_Doc(void)
{
return Object->Doc;
}
//---------------------------------------------------------------
void TREM_DMDocPerServCentrImpl::set_Doc(TpFIBDataSet * Doc)
{
Object->Doc=Doc;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocPerServCentrImpl::get_DocT(void)
{
return Object->DocT;
}
//---------------------------------------------------------------
void TREM_DMDocPerServCentrImpl::set_DocT(TpFIBDataSet * DocT)
{
Object->DocT=DocT;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMDocPerServCentrImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TREM_DMDocPerServCentrImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMDocPerServCentrImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TREM_DMDocPerServCentrImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMDocPerServCentrImpl::get_IBTrDvReg(void)
{
return Object->IBTrDvReg;
}
//---------------------------------------------------------------
void TREM_DMDocPerServCentrImpl::set_IBTrDvReg(TpFIBTransaction * IBTrDvReg)
{
Object->IBTrDvReg=IBTrDvReg;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMDocPerServCentrImpl::get_NumDoc(void)
{
return Object->NumDoc;
}
//---------------------------------------------------------------
void TREM_DMDocPerServCentrImpl::set_NumDoc(TpFIBDataSet * NumDoc)
{
Object->NumDoc=NumDoc;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMDocPerServCentrImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TREM_DMDocPerServCentrImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMDocPerServCentrImpl::get_QueryCancelDvReg(void)
{
return Object->QueryCancelDvReg;
}
//---------------------------------------------------------------
void TREM_DMDocPerServCentrImpl::set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg)
{
Object->QueryCancelDvReg=QueryCancelDvReg;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMDocPerServCentrImpl::get_QueryDvReg(void)
{
return Object->QueryDvReg;
}
//---------------------------------------------------------------
void TREM_DMDocPerServCentrImpl::set_QueryDvReg(TpFIBQuery * QueryDvReg)
{
Object->QueryDvReg=QueryDvReg;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocPerServCentrImpl::get_NumDocMAXNUMBER(void)
{
return Object->NumDocMAXNUMBER;
}
//---------------------------------------------------------------
void TREM_DMDocPerServCentrImpl::set_NumDocMAXNUMBER(TFIBIntegerField * NumDocMAXNUMBER)
{
Object->NumDocMAXNUMBER=NumDocMAXNUMBER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocPerServCentrImpl::get_DocAllID_REM_GALLDOC(void)
{
return Object->DocAllID_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocPerServCentrImpl::set_DocAllID_REM_GALLDOC(TFIBLargeIntField * DocAllID_REM_GALLDOC)
{
Object->DocAllID_REM_GALLDOC=DocAllID_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocPerServCentrImpl::get_DocAllIDBASE_REM_GALLDOC(void)
{
return Object->DocAllIDBASE_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocPerServCentrImpl::set_DocAllIDBASE_REM_GALLDOC(TFIBLargeIntField * DocAllIDBASE_REM_GALLDOC)
{
Object->DocAllIDBASE_REM_GALLDOC=DocAllIDBASE_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocPerServCentrImpl::get_DocAllIDFIRM_REM_GALLDOC(void)
{
return Object->DocAllIDFIRM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocPerServCentrImpl::set_DocAllIDFIRM_REM_GALLDOC(TFIBLargeIntField * DocAllIDFIRM_REM_GALLDOC)
{
Object->DocAllIDFIRM_REM_GALLDOC=DocAllIDFIRM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocPerServCentrImpl::get_DocAllIDSKLAD_REM_GALLDOC(void)
{
return Object->DocAllIDSKLAD_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocPerServCentrImpl::set_DocAllIDSKLAD_REM_GALLDOC(TFIBLargeIntField * DocAllIDSKLAD_REM_GALLDOC)
{
Object->DocAllIDSKLAD_REM_GALLDOC=DocAllIDSKLAD_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocPerServCentrImpl::get_DocAllIDKLIENT_REM_GALLDOC(void)
{
return Object->DocAllIDKLIENT_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocPerServCentrImpl::set_DocAllIDKLIENT_REM_GALLDOC(TFIBLargeIntField * DocAllIDKLIENT_REM_GALLDOC)
{
Object->DocAllIDKLIENT_REM_GALLDOC=DocAllIDKLIENT_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocPerServCentrImpl::get_DocAllIDUSER_REM_GALLDOC(void)
{
return Object->DocAllIDUSER_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocPerServCentrImpl::set_DocAllIDUSER_REM_GALLDOC(TFIBLargeIntField * DocAllIDUSER_REM_GALLDOC)
{
Object->DocAllIDUSER_REM_GALLDOC=DocAllIDUSER_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMDocPerServCentrImpl::get_DocAllPOS_REM_GALLDOC(void)
{
return Object->DocAllPOS_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocPerServCentrImpl::set_DocAllPOS_REM_GALLDOC(TFIBDateTimeField * DocAllPOS_REM_GALLDOC)
{
Object->DocAllPOS_REM_GALLDOC=DocAllPOS_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocPerServCentrImpl::get_DocAllNUM_REM_GALLDOC(void)
{
return Object->DocAllNUM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocPerServCentrImpl::set_DocAllNUM_REM_GALLDOC(TFIBIntegerField * DocAllNUM_REM_GALLDOC)
{
Object->DocAllNUM_REM_GALLDOC=DocAllNUM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMDocPerServCentrImpl::get_DocAllPR_REM_GALLDOC(void)
{
return Object->DocAllPR_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocPerServCentrImpl::set_DocAllPR_REM_GALLDOC(TFIBSmallIntField * DocAllPR_REM_GALLDOC)
{
Object->DocAllPR_REM_GALLDOC=DocAllPR_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocPerServCentrImpl::get_DocAllTDOC_REM_GALLDOC(void)
{
return Object->DocAllTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocPerServCentrImpl::set_DocAllTDOC_REM_GALLDOC(TFIBWideStringField * DocAllTDOC_REM_GALLDOC)
{
Object->DocAllTDOC_REM_GALLDOC=DocAllTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocPerServCentrImpl::get_DocAllIDDOCOSN_REM_GALLDOC(void)
{
return Object->DocAllIDDOCOSN_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocPerServCentrImpl::set_DocAllIDDOCOSN_REM_GALLDOC(TFIBLargeIntField * DocAllIDDOCOSN_REM_GALLDOC)
{
Object->DocAllIDDOCOSN_REM_GALLDOC=DocAllIDDOCOSN_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocPerServCentrImpl::get_DocAllTYPEEXTDOC_REM_GALLDOC(void)
{
return Object->DocAllTYPEEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocPerServCentrImpl::set_DocAllTYPEEXTDOC_REM_GALLDOC(TFIBIntegerField * DocAllTYPEEXTDOC_REM_GALLDOC)
{
Object->DocAllTYPEEXTDOC_REM_GALLDOC=DocAllTYPEEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocPerServCentrImpl::get_DocAllIDEXTDOC_REM_GALLDOC(void)
{
return Object->DocAllIDEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocPerServCentrImpl::set_DocAllIDEXTDOC_REM_GALLDOC(TFIBLargeIntField * DocAllIDEXTDOC_REM_GALLDOC)
{
Object->DocAllIDEXTDOC_REM_GALLDOC=DocAllIDEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocPerServCentrImpl::get_DocAllSUM_REM_GALLDOC(void)
{
return Object->DocAllSUM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocPerServCentrImpl::set_DocAllSUM_REM_GALLDOC(TFIBBCDField * DocAllSUM_REM_GALLDOC)
{
Object->DocAllSUM_REM_GALLDOC=DocAllSUM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocPerServCentrImpl::get_DocAllFNAME_USER(void)
{
return Object->DocAllFNAME_USER;
}
//---------------------------------------------------------------
void TREM_DMDocPerServCentrImpl::set_DocAllFNAME_USER(TFIBWideStringField * DocAllFNAME_USER)
{
Object->DocAllFNAME_USER=DocAllFNAME_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocPerServCentrImpl::get_DocAllNAME_SINFBASE_OBMEN(void)
{
return Object->DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void TREM_DMDocPerServCentrImpl::set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN)
{
Object->DocAllNAME_SINFBASE_OBMEN=DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocPerServCentrImpl::get_DocAllNAMEFIRM(void)
{
return Object->DocAllNAMEFIRM;
}
//---------------------------------------------------------------
void TREM_DMDocPerServCentrImpl::set_DocAllNAMEFIRM(TFIBWideStringField * DocAllNAMEFIRM)
{
Object->DocAllNAMEFIRM=DocAllNAMEFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocPerServCentrImpl::get_DocAllNAMESKLAD(void)
{
return Object->DocAllNAMESKLAD;
}
//---------------------------------------------------------------
void TREM_DMDocPerServCentrImpl::set_DocAllNAMESKLAD(TFIBWideStringField * DocAllNAMESKLAD)
{
Object->DocAllNAMESKLAD=DocAllNAMESKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocPerServCentrImpl::get_DocAllNAMEKLIENT(void)
{
return Object->DocAllNAMEKLIENT;
}
//---------------------------------------------------------------
void TREM_DMDocPerServCentrImpl::set_DocAllNAMEKLIENT(TFIBWideStringField * DocAllNAMEKLIENT)
{
Object->DocAllNAMEKLIENT=DocAllNAMEKLIENT;
}
//---------------------------------------------------------------
TIntegerField * TREM_DMDocPerServCentrImpl::get_DocTRECNO(void)
{
return Object->DocTRECNO;
}
//---------------------------------------------------------------
void TREM_DMDocPerServCentrImpl::set_DocTRECNO(TIntegerField * DocTRECNO)
{
Object->DocTRECNO=DocTRECNO;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocPerServCentrImpl::get_DocID_REM_DSCPER(void)
{
return Object->DocID_REM_DSCPER;
}
//---------------------------------------------------------------
void TREM_DMDocPerServCentrImpl::set_DocID_REM_DSCPER(TFIBLargeIntField * DocID_REM_DSCPER)
{
Object->DocID_REM_DSCPER=DocID_REM_DSCPER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocPerServCentrImpl::get_DocIDBASE_REM_DSCPER(void)
{
return Object->DocIDBASE_REM_DSCPER;
}
//---------------------------------------------------------------
void TREM_DMDocPerServCentrImpl::set_DocIDBASE_REM_DSCPER(TFIBLargeIntField * DocIDBASE_REM_DSCPER)
{
Object->DocIDBASE_REM_DSCPER=DocIDBASE_REM_DSCPER;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocPerServCentrImpl::get_DocGID_REM_DSCPER(void)
{
return Object->DocGID_REM_DSCPER;
}
//---------------------------------------------------------------
void TREM_DMDocPerServCentrImpl::set_DocGID_REM_DSCPER(TFIBWideStringField * DocGID_REM_DSCPER)
{
Object->DocGID_REM_DSCPER=DocGID_REM_DSCPER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocPerServCentrImpl::get_DocIDDOC_REM_DSCPER(void)
{
return Object->DocIDDOC_REM_DSCPER;
}
//---------------------------------------------------------------
void TREM_DMDocPerServCentrImpl::set_DocIDDOC_REM_DSCPER(TFIBLargeIntField * DocIDDOC_REM_DSCPER)
{
Object->DocIDDOC_REM_DSCPER=DocIDDOC_REM_DSCPER;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocPerServCentrImpl::get_DocNUMDOCSC_REM_DSCPER(void)
{
return Object->DocNUMDOCSC_REM_DSCPER;
}
//---------------------------------------------------------------
void TREM_DMDocPerServCentrImpl::set_DocNUMDOCSC_REM_DSCPER(TFIBWideStringField * DocNUMDOCSC_REM_DSCPER)
{
Object->DocNUMDOCSC_REM_DSCPER=DocNUMDOCSC_REM_DSCPER;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMDocPerServCentrImpl::get_DocPOSDOCSC_REM_DSCPER(void)
{
return Object->DocPOSDOCSC_REM_DSCPER;
}
//---------------------------------------------------------------
void TREM_DMDocPerServCentrImpl::set_DocPOSDOCSC_REM_DSCPER(TFIBDateTimeField * DocPOSDOCSC_REM_DSCPER)
{
Object->DocPOSDOCSC_REM_DSCPER=DocPOSDOCSC_REM_DSCPER;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocPerServCentrImpl::get_DocPRIM_REM_DSCPER(void)
{
return Object->DocPRIM_REM_DSCPER;
}
//---------------------------------------------------------------
void TREM_DMDocPerServCentrImpl::set_DocPRIM_REM_DSCPER(TFIBWideStringField * DocPRIM_REM_DSCPER)
{
Object->DocPRIM_REM_DSCPER=DocPRIM_REM_DSCPER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocPerServCentrImpl::get_DocTID_REM_DSCPERT(void)
{
return Object->DocTID_REM_DSCPERT;
}
//---------------------------------------------------------------
void TREM_DMDocPerServCentrImpl::set_DocTID_REM_DSCPERT(TFIBLargeIntField * DocTID_REM_DSCPERT)
{
Object->DocTID_REM_DSCPERT=DocTID_REM_DSCPERT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocPerServCentrImpl::get_DocTIDBASE_REM_DSCPERT(void)
{
return Object->DocTIDBASE_REM_DSCPERT;
}
//---------------------------------------------------------------
void TREM_DMDocPerServCentrImpl::set_DocTIDBASE_REM_DSCPERT(TFIBLargeIntField * DocTIDBASE_REM_DSCPERT)
{
Object->DocTIDBASE_REM_DSCPERT=DocTIDBASE_REM_DSCPERT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocPerServCentrImpl::get_DocTGID_REM_DSCPERT(void)
{
return Object->DocTGID_REM_DSCPERT;
}
//---------------------------------------------------------------
void TREM_DMDocPerServCentrImpl::set_DocTGID_REM_DSCPERT(TFIBWideStringField * DocTGID_REM_DSCPERT)
{
Object->DocTGID_REM_DSCPERT=DocTGID_REM_DSCPERT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocPerServCentrImpl::get_DocTIDDOC_REM_DSCPERT(void)
{
return Object->DocTIDDOC_REM_DSCPERT;
}
//---------------------------------------------------------------
void TREM_DMDocPerServCentrImpl::set_DocTIDDOC_REM_DSCPERT(TFIBLargeIntField * DocTIDDOC_REM_DSCPERT)
{
Object->DocTIDDOC_REM_DSCPERT=DocTIDDOC_REM_DSCPERT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocPerServCentrImpl::get_DocTIDZ_REM_DSCPERT(void)
{
return Object->DocTIDZ_REM_DSCPERT;
}
//---------------------------------------------------------------
void TREM_DMDocPerServCentrImpl::set_DocTIDZ_REM_DSCPERT(TFIBLargeIntField * DocTIDZ_REM_DSCPERT)
{
Object->DocTIDZ_REM_DSCPERT=DocTIDZ_REM_DSCPERT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMDocPerServCentrImpl::get_DocTKOL_REM_DSCPERT(void)
{
return Object->DocTKOL_REM_DSCPERT;
}
//---------------------------------------------------------------
void TREM_DMDocPerServCentrImpl::set_DocTKOL_REM_DSCPERT(TFIBBCDField * DocTKOL_REM_DSCPERT)
{
Object->DocTKOL_REM_DSCPERT=DocTKOL_REM_DSCPERT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocPerServCentrImpl::get_DocTNAME_REM_Z(void)
{
return Object->DocTNAME_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocPerServCentrImpl::set_DocTNAME_REM_Z(TFIBWideStringField * DocTNAME_REM_Z)
{
Object->DocTNAME_REM_Z=DocTNAME_REM_Z;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMDocPerServCentrImpl::get_DocTNUM_REM_Z(void)
{
return Object->DocTNUM_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocPerServCentrImpl::set_DocTNUM_REM_Z(TFIBIntegerField * DocTNUM_REM_Z)
{
Object->DocTNUM_REM_Z=DocTNUM_REM_Z;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMDocPerServCentrImpl::get_DocTPOS_REM_Z(void)
{
return Object->DocTPOS_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocPerServCentrImpl::set_DocTPOS_REM_Z(TFIBDateTimeField * DocTPOS_REM_Z)
{
Object->DocTPOS_REM_Z=DocTPOS_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocPerServCentrImpl::get_DocTSERNUM_REM_Z(void)
{
return Object->DocTSERNUM_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocPerServCentrImpl::set_DocTSERNUM_REM_Z(TFIBWideStringField * DocTSERNUM_REM_Z)
{
Object->DocTSERNUM_REM_Z=DocTSERNUM_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocPerServCentrImpl::get_DocTSERNUM2_REM_Z(void)
{
return Object->DocTSERNUM2_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocPerServCentrImpl::set_DocTSERNUM2_REM_Z(TFIBWideStringField * DocTSERNUM2_REM_Z)
{
Object->DocTSERNUM2_REM_Z=DocTSERNUM2_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocPerServCentrImpl::get_DocTKLIENT_NAME_REM_Z(void)
{
return Object->DocTKLIENT_NAME_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocPerServCentrImpl::set_DocTKLIENT_NAME_REM_Z(TFIBWideStringField * DocTKLIENT_NAME_REM_Z)
{
Object->DocTKLIENT_NAME_REM_Z=DocTKLIENT_NAME_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocPerServCentrImpl::get_DocTMODEL_REM_Z(void)
{
return Object->DocTMODEL_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMDocPerServCentrImpl::set_DocTMODEL_REM_Z(TFIBWideStringField * DocTMODEL_REM_Z)
{
Object->DocTMODEL_REM_Z=DocTMODEL_REM_Z;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocPerServCentrImpl::get_DocAllIDPROJECT_REM_GALLDOC(void)
{
return Object->DocAllIDPROJECT_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocPerServCentrImpl::set_DocAllIDPROJECT_REM_GALLDOC(TFIBLargeIntField * DocAllIDPROJECT_REM_GALLDOC)
{
Object->DocAllIDPROJECT_REM_GALLDOC=DocAllIDPROJECT_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMDocPerServCentrImpl::get_DocAllIDBUSINOP_REM_GALLDOC(void)
{
return Object->DocAllIDBUSINOP_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocPerServCentrImpl::set_DocAllIDBUSINOP_REM_GALLDOC(TFIBLargeIntField * DocAllIDBUSINOP_REM_GALLDOC)
{
Object->DocAllIDBUSINOP_REM_GALLDOC=DocAllIDBUSINOP_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocPerServCentrImpl::get_DocAllPREFIKS_NUM_REM_GALLDOC(void)
{
return Object->DocAllPREFIKS_NUM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMDocPerServCentrImpl::set_DocAllPREFIKS_NUM_REM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_REM_GALLDOC)
{
Object->DocAllPREFIKS_NUM_REM_GALLDOC=DocAllPREFIKS_NUM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocPerServCentrImpl::get_DocAllNAME_SPROJECT(void)
{
return Object->DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
void TREM_DMDocPerServCentrImpl::set_DocAllNAME_SPROJECT(TFIBWideStringField * DocAllNAME_SPROJECT)
{
Object->DocAllNAME_SPROJECT=DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMDocPerServCentrImpl::get_DocAllNAME_SBUSINESS_OPER(void)
{
return Object->DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
void TREM_DMDocPerServCentrImpl::set_DocAllNAME_SBUSINESS_OPER(TFIBWideStringField * DocAllNAME_SBUSINESS_OPER)
{
Object->DocAllNAME_SBUSINESS_OPER=DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
__int64 TREM_DMDocPerServCentrImpl::get_IdDoc(void)
{
return Object->IdDoc;
}
//---------------------------------------------------------------
void TREM_DMDocPerServCentrImpl::set_IdDoc(__int64 IdDoc)
{
Object->IdDoc=IdDoc;
}
//---------------------------------------------------------------
bool TREM_DMDocPerServCentrImpl::get_Prosmotr(void)
{
return Object->Prosmotr;
}
//---------------------------------------------------------------
void TREM_DMDocPerServCentrImpl::set_Prosmotr(bool Prosmotr)
{
Object->Prosmotr=Prosmotr;
}
//---------------------------------------------------------------
bool TREM_DMDocPerServCentrImpl::NewDoc(void)
{
return Object->NewDoc();
}
//---------------------------------------------------------------
bool TREM_DMDocPerServCentrImpl::OpenDoc(__int64 id)
{
return Object->OpenDoc(id);
}
//---------------------------------------------------------------
bool TREM_DMDocPerServCentrImpl::SaveDoc(void)
{
return Object->SaveDoc();
}
//---------------------------------------------------------------
bool TREM_DMDocPerServCentrImpl::DeleteDoc(__int64 id)
{
return Object->DeleteDoc(id);
}
//---------------------------------------------------------------
bool TREM_DMDocPerServCentrImpl::DvRegDoc(void)
{
return Object->DvRegDoc();
}
//---------------------------------------------------------------
bool TREM_DMDocPerServCentrImpl::CancelDvRegDoc(void)
{
return Object->CancelDvRegDoc();
}
//---------------------------------------------------------------
void TREM_DMDocPerServCentrImpl::TableAppend(void)
{
return Object->TableAppend();
}
//---------------------------------------------------------------
void TREM_DMDocPerServCentrImpl::TableDelete(void)
{
return Object->TableDelete();
}
//---------------------------------------------------------------
