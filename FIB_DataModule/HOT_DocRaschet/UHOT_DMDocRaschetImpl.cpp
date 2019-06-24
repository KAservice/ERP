#include "vcl.h"
#pragma hdrstop


#include "UHOT_DMDocRaschetImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
THOT_DMDocRaschetImpl::THOT_DMDocRaschetImpl()           
{                                            
Object=new THOT_DMDocRaschet(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
THOT_DMDocRaschetImpl::~THOT_DMDocRaschetImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void THOT_DMDocRaschetImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int THOT_DMDocRaschetImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IHOT_DMDocRaschet)                        
   {                                                                     
   *ppv=static_cast<IHOT_DMDocRaschet*> (this);                                
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
int THOT_DMDocRaschetImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int THOT_DMDocRaschetImpl::kanRelease(void)                                  
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
int  THOT_DMDocRaschetImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void THOT_DMDocRaschetImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  THOT_DMDocRaschetImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void THOT_DMDocRaschetImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int THOT_DMDocRaschetImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl);
kanRelease();
Object->ClsIdImpl=CLSID_THOT_DMDocRaschetImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int THOT_DMDocRaschetImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IHOT_DMDocRaschet
TDataSource * THOT_DMDocRaschetImpl::get_DataSourceDoc(void)
{
return Object->DataSourceDoc;
}
//---------------------------------------------------------------
void THOT_DMDocRaschetImpl::set_DataSourceDoc(TDataSource * DataSourceDoc)
{
Object->DataSourceDoc=DataSourceDoc;
}
//---------------------------------------------------------------
TDataSource * THOT_DMDocRaschetImpl::get_DataSourceDocT(void)
{
return Object->DataSourceDocT;
}
//---------------------------------------------------------------
void THOT_DMDocRaschetImpl::set_DataSourceDocT(TDataSource * DataSourceDocT)
{
Object->DataSourceDocT=DataSourceDocT;
}
//---------------------------------------------------------------
TDataSource * THOT_DMDocRaschetImpl::get_DataSourceDocAll(void)
{
return Object->DataSourceDocAll;
}
//---------------------------------------------------------------
void THOT_DMDocRaschetImpl::set_DataSourceDocAll(TDataSource * DataSourceDocAll)
{
Object->DataSourceDocAll=DataSourceDocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * THOT_DMDocRaschetImpl::get_DocAll(void)
{
return Object->DocAll;
}
//---------------------------------------------------------------
void THOT_DMDocRaschetImpl::set_DocAll(TpFIBDataSet * DocAll)
{
Object->DocAll=DocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * THOT_DMDocRaschetImpl::get_Doc(void)
{
return Object->Doc;
}
//---------------------------------------------------------------
void THOT_DMDocRaschetImpl::set_Doc(TpFIBDataSet * Doc)
{
Object->Doc=Doc;
}
//---------------------------------------------------------------
TpFIBDataSet * THOT_DMDocRaschetImpl::get_DocT(void)
{
return Object->DocT;
}
//---------------------------------------------------------------
void THOT_DMDocRaschetImpl::set_DocT(TpFIBDataSet * DocT)
{
Object->DocT=DocT;
}
//---------------------------------------------------------------
TpFIBQuery * THOT_DMDocRaschetImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void THOT_DMDocRaschetImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TFIBDateTimeField * THOT_DMDocRaschetImpl::get_DocAllPOS_HOT_GALLDOC(void)
{
return Object->DocAllPOS_HOT_GALLDOC;
}
//---------------------------------------------------------------
void THOT_DMDocRaschetImpl::set_DocAllPOS_HOT_GALLDOC(TFIBDateTimeField * DocAllPOS_HOT_GALLDOC)
{
Object->DocAllPOS_HOT_GALLDOC=DocAllPOS_HOT_GALLDOC;
}
//---------------------------------------------------------------
TFIBSmallIntField * THOT_DMDocRaschetImpl::get_DocAllPR_HOT_GALLDOC(void)
{
return Object->DocAllPR_HOT_GALLDOC;
}
//---------------------------------------------------------------
void THOT_DMDocRaschetImpl::set_DocAllPR_HOT_GALLDOC(TFIBSmallIntField * DocAllPR_HOT_GALLDOC)
{
Object->DocAllPR_HOT_GALLDOC=DocAllPR_HOT_GALLDOC;
}
//---------------------------------------------------------------
TFIBBCDField * THOT_DMDocRaschetImpl::get_DocAllSUM_HOT_GALLDOC(void)
{
return Object->DocAllSUM_HOT_GALLDOC;
}
//---------------------------------------------------------------
void THOT_DMDocRaschetImpl::set_DocAllSUM_HOT_GALLDOC(TFIBBCDField * DocAllSUM_HOT_GALLDOC)
{
Object->DocAllSUM_HOT_GALLDOC=DocAllSUM_HOT_GALLDOC;
}
//---------------------------------------------------------------
TpFIBQuery * THOT_DMDocRaschetImpl::get_QueryDvReg(void)
{
return Object->QueryDvReg;
}
//---------------------------------------------------------------
void THOT_DMDocRaschetImpl::set_QueryDvReg(TpFIBQuery * QueryDvReg)
{
Object->QueryDvReg=QueryDvReg;
}
//---------------------------------------------------------------
TpFIBQuery * THOT_DMDocRaschetImpl::get_QueryCancelDvReg(void)
{
return Object->QueryCancelDvReg;
}
//---------------------------------------------------------------
void THOT_DMDocRaschetImpl::set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg)
{
Object->QueryCancelDvReg=QueryCancelDvReg;
}
//---------------------------------------------------------------
TpFIBDataSet * THOT_DMDocRaschetImpl::get_TypePriceDataSet(void)
{
return Object->TypePriceDataSet;
}
//---------------------------------------------------------------
void THOT_DMDocRaschetImpl::set_TypePriceDataSet(TpFIBDataSet * TypePriceDataSet)
{
Object->TypePriceDataSet=TypePriceDataSet;
}
//---------------------------------------------------------------
TFIBSmallIntField * THOT_DMDocRaschetImpl::get_DocTTUSL_HOT_DRASCHETT(void)
{
return Object->DocTTUSL_HOT_DRASCHETT;
}
//---------------------------------------------------------------
void THOT_DMDocRaschetImpl::set_DocTTUSL_HOT_DRASCHETT(TFIBSmallIntField * DocTTUSL_HOT_DRASCHETT)
{
Object->DocTTUSL_HOT_DRASCHETT=DocTTUSL_HOT_DRASCHETT;
}
//---------------------------------------------------------------
TFIBBCDField * THOT_DMDocRaschetImpl::get_DocTKOL_HOT_DRASCHETT(void)
{
return Object->DocTKOL_HOT_DRASCHETT;
}
//---------------------------------------------------------------
void THOT_DMDocRaschetImpl::set_DocTKOL_HOT_DRASCHETT(TFIBBCDField * DocTKOL_HOT_DRASCHETT)
{
Object->DocTKOL_HOT_DRASCHETT=DocTKOL_HOT_DRASCHETT;
}
//---------------------------------------------------------------
TFIBBCDField * THOT_DMDocRaschetImpl::get_DocTKF_HOT_DRASCHETT(void)
{
return Object->DocTKF_HOT_DRASCHETT;
}
//---------------------------------------------------------------
void THOT_DMDocRaschetImpl::set_DocTKF_HOT_DRASCHETT(TFIBBCDField * DocTKF_HOT_DRASCHETT)
{
Object->DocTKF_HOT_DRASCHETT=DocTKF_HOT_DRASCHETT;
}
//---------------------------------------------------------------
TFIBBCDField * THOT_DMDocRaschetImpl::get_DocTPRICE_HOT_DRASCHETT(void)
{
return Object->DocTPRICE_HOT_DRASCHETT;
}
//---------------------------------------------------------------
void THOT_DMDocRaschetImpl::set_DocTPRICE_HOT_DRASCHETT(TFIBBCDField * DocTPRICE_HOT_DRASCHETT)
{
Object->DocTPRICE_HOT_DRASCHETT=DocTPRICE_HOT_DRASCHETT;
}
//---------------------------------------------------------------
TIntegerField * THOT_DMDocRaschetImpl::get_DocTRECNO(void)
{
return Object->DocTRECNO;
}
//---------------------------------------------------------------
void THOT_DMDocRaschetImpl::set_DocTRECNO(TIntegerField * DocTRECNO)
{
Object->DocTRECNO=DocTRECNO;
}
//---------------------------------------------------------------
TFIBBCDField * THOT_DMDocRaschetImpl::get_DocTSUM_HOT_DRASCHETT(void)
{
return Object->DocTSUM_HOT_DRASCHETT;
}
//---------------------------------------------------------------
void THOT_DMDocRaschetImpl::set_DocTSUM_HOT_DRASCHETT(TFIBBCDField * DocTSUM_HOT_DRASCHETT)
{
Object->DocTSUM_HOT_DRASCHETT=DocTSUM_HOT_DRASCHETT;
}
//---------------------------------------------------------------
TFIBDateTimeField * THOT_DMDocRaschetImpl::get_DocTPOSNACH_HOT_DRASCHETT(void)
{
return Object->DocTPOSNACH_HOT_DRASCHETT;
}
//---------------------------------------------------------------
void THOT_DMDocRaschetImpl::set_DocTPOSNACH_HOT_DRASCHETT(TFIBDateTimeField * DocTPOSNACH_HOT_DRASCHETT)
{
Object->DocTPOSNACH_HOT_DRASCHETT=DocTPOSNACH_HOT_DRASCHETT;
}
//---------------------------------------------------------------
TFIBDateTimeField * THOT_DMDocRaschetImpl::get_DocTPOSCON_HOT_DRASCHETT(void)
{
return Object->DocTPOSCON_HOT_DRASCHETT;
}
//---------------------------------------------------------------
void THOT_DMDocRaschetImpl::set_DocTPOSCON_HOT_DRASCHETT(TFIBDateTimeField * DocTPOSCON_HOT_DRASCHETT)
{
Object->DocTPOSCON_HOT_DRASCHETT=DocTPOSCON_HOT_DRASCHETT;
}
//---------------------------------------------------------------
TStringField * THOT_DMDocRaschetImpl::get_DocTVIBOR_TYPE_PRICE(void)
{
return Object->DocTVIBOR_TYPE_PRICE;
}
//---------------------------------------------------------------
void THOT_DMDocRaschetImpl::set_DocTVIBOR_TYPE_PRICE(TStringField * DocTVIBOR_TYPE_PRICE)
{
Object->DocTVIBOR_TYPE_PRICE=DocTVIBOR_TYPE_PRICE;
}
//---------------------------------------------------------------
TpFIBDataSet * THOT_DMDocRaschetImpl::get_SpisokGuestOsnUslug(void)
{
return Object->SpisokGuestOsnUslug;
}
//---------------------------------------------------------------
void THOT_DMDocRaschetImpl::set_SpisokGuestOsnUslug(TpFIBDataSet * SpisokGuestOsnUslug)
{
Object->SpisokGuestOsnUslug=SpisokGuestOsnUslug;
}
//---------------------------------------------------------------
TpFIBDataSet * THOT_DMDocRaschetImpl::get_SpisokGuestDopUslug(void)
{
return Object->SpisokGuestDopUslug;
}
//---------------------------------------------------------------
void THOT_DMDocRaschetImpl::set_SpisokGuestDopUslug(TpFIBDataSet * SpisokGuestDopUslug)
{
Object->SpisokGuestDopUslug=SpisokGuestDopUslug;
}
//---------------------------------------------------------------
TFIBFloatField * THOT_DMDocRaschetImpl::get_SpisokGuestOsnUslugSUMKOL(void)
{
return Object->SpisokGuestOsnUslugSUMKOL;
}
//---------------------------------------------------------------
void THOT_DMDocRaschetImpl::set_SpisokGuestOsnUslugSUMKOL(TFIBFloatField * SpisokGuestOsnUslugSUMKOL)
{
Object->SpisokGuestOsnUslugSUMKOL=SpisokGuestOsnUslugSUMKOL;
}
//---------------------------------------------------------------
TFIBBCDField * THOT_DMDocRaschetImpl::get_SpisokGuestDopUslugSUM(void)
{
return Object->SpisokGuestDopUslugSUM;
}
//---------------------------------------------------------------
void THOT_DMDocRaschetImpl::set_SpisokGuestDopUslugSUM(TFIBBCDField * SpisokGuestDopUslugSUM)
{
Object->SpisokGuestDopUslugSUM=SpisokGuestDopUslugSUM;
}
//---------------------------------------------------------------
TFIBBCDField * THOT_DMDocRaschetImpl::get_SpisokGuestOsnUslugIDKLIENT(void)
{
return Object->SpisokGuestOsnUslugIDKLIENT;
}
//---------------------------------------------------------------
void THOT_DMDocRaschetImpl::set_SpisokGuestOsnUslugIDKLIENT(TFIBBCDField * SpisokGuestOsnUslugIDKLIENT)
{
Object->SpisokGuestOsnUslugIDKLIENT=SpisokGuestOsnUslugIDKLIENT;
}
//---------------------------------------------------------------
TFIBBCDField * THOT_DMDocRaschetImpl::get_SpisokGuestDopUslugIDKLIENT(void)
{
return Object->SpisokGuestDopUslugIDKLIENT;
}
//---------------------------------------------------------------
void THOT_DMDocRaschetImpl::set_SpisokGuestDopUslugIDKLIENT(TFIBBCDField * SpisokGuestDopUslugIDKLIENT)
{
Object->SpisokGuestDopUslugIDKLIENT=SpisokGuestDopUslugIDKLIENT;
}
//---------------------------------------------------------------
TpFIBDataSet * THOT_DMDocRaschetImpl::get_NumDoc(void)
{
return Object->NumDoc;
}
//---------------------------------------------------------------
void THOT_DMDocRaschetImpl::set_NumDoc(TpFIBDataSet * NumDoc)
{
Object->NumDoc=NumDoc;
}
//---------------------------------------------------------------
TFIBIntegerField * THOT_DMDocRaschetImpl::get_NumDocMAXNUMBER(void)
{
return Object->NumDocMAXNUMBER;
}
//---------------------------------------------------------------
void THOT_DMDocRaschetImpl::set_NumDocMAXNUMBER(TFIBIntegerField * NumDocMAXNUMBER)
{
Object->NumDocMAXNUMBER=NumDocMAXNUMBER;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMDocRaschetImpl::get_SpisokGuestOsnUslugNAMEKLIENT(void)
{
return Object->SpisokGuestOsnUslugNAMEKLIENT;
}
//---------------------------------------------------------------
void THOT_DMDocRaschetImpl::set_SpisokGuestOsnUslugNAMEKLIENT(TFIBWideStringField * SpisokGuestOsnUslugNAMEKLIENT)
{
Object->SpisokGuestOsnUslugNAMEKLIENT=SpisokGuestOsnUslugNAMEKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMDocRaschetImpl::get_SpisokGuestDopUslugNAMEKLIENT(void)
{
return Object->SpisokGuestDopUslugNAMEKLIENT;
}
//---------------------------------------------------------------
void THOT_DMDocRaschetImpl::set_SpisokGuestDopUslugNAMEKLIENT(TFIBWideStringField * SpisokGuestDopUslugNAMEKLIENT)
{
Object->SpisokGuestDopUslugNAMEKLIENT=SpisokGuestDopUslugNAMEKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMDocRaschetImpl::get_DocAllTDOC_HOT_GALLDOC(void)
{
return Object->DocAllTDOC_HOT_GALLDOC;
}
//---------------------------------------------------------------
void THOT_DMDocRaschetImpl::set_DocAllTDOC_HOT_GALLDOC(TFIBWideStringField * DocAllTDOC_HOT_GALLDOC)
{
Object->DocAllTDOC_HOT_GALLDOC=DocAllTDOC_HOT_GALLDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * THOT_DMDocRaschetImpl::get_DocAllNUMBER_HOT_GALLDOC(void)
{
return Object->DocAllNUMBER_HOT_GALLDOC;
}
//---------------------------------------------------------------
void THOT_DMDocRaschetImpl::set_DocAllNUMBER_HOT_GALLDOC(TFIBIntegerField * DocAllNUMBER_HOT_GALLDOC)
{
Object->DocAllNUMBER_HOT_GALLDOC=DocAllNUMBER_HOT_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMDocRaschetImpl::get_DocAllNAME_SINFBASE_OBMEN(void)
{
return Object->DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void THOT_DMDocRaschetImpl::set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN)
{
Object->DocAllNAME_SINFBASE_OBMEN=DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMDocRaschetImpl::get_DocAllNAMEFIRM(void)
{
return Object->DocAllNAMEFIRM;
}
//---------------------------------------------------------------
void THOT_DMDocRaschetImpl::set_DocAllNAMEFIRM(TFIBWideStringField * DocAllNAMEFIRM)
{
Object->DocAllNAMEFIRM=DocAllNAMEFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMDocRaschetImpl::get_DocAllNAMEKLIENT(void)
{
return Object->DocAllNAMEKLIENT;
}
//---------------------------------------------------------------
void THOT_DMDocRaschetImpl::set_DocAllNAMEKLIENT(TFIBWideStringField * DocAllNAMEKLIENT)
{
Object->DocAllNAMEKLIENT=DocAllNAMEKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMDocRaschetImpl::get_DocAllFNAME_USER(void)
{
return Object->DocAllFNAME_USER;
}
//---------------------------------------------------------------
void THOT_DMDocRaschetImpl::set_DocAllFNAME_USER(TFIBWideStringField * DocAllFNAME_USER)
{
Object->DocAllFNAME_USER=DocAllFNAME_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMDocRaschetImpl::get_DocAllNAMESKLAD(void)
{
return Object->DocAllNAMESKLAD;
}
//---------------------------------------------------------------
void THOT_DMDocRaschetImpl::set_DocAllNAMESKLAD(TFIBWideStringField * DocAllNAMESKLAD)
{
Object->DocAllNAMESKLAD=DocAllNAMESKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMDocRaschetImpl::get_DocPRIM_HOT_DRASCHET(void)
{
return Object->DocPRIM_HOT_DRASCHET;
}
//---------------------------------------------------------------
void THOT_DMDocRaschetImpl::set_DocPRIM_HOT_DRASCHET(TFIBWideStringField * DocPRIM_HOT_DRASCHET)
{
Object->DocPRIM_HOT_DRASCHET=DocPRIM_HOT_DRASCHET;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMDocRaschetImpl::get_DocNAMEBSCHET(void)
{
return Object->DocNAMEBSCHET;
}
//---------------------------------------------------------------
void THOT_DMDocRaschetImpl::set_DocNAMEBSCHET(TFIBWideStringField * DocNAMEBSCHET)
{
Object->DocNAMEBSCHET=DocNAMEBSCHET;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMDocRaschetImpl::get_DocTNAMENOM(void)
{
return Object->DocTNAMENOM;
}
//---------------------------------------------------------------
void THOT_DMDocRaschetImpl::set_DocTNAMENOM(TFIBWideStringField * DocTNAMENOM)
{
Object->DocTNAMENOM=DocTNAMENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMDocRaschetImpl::get_DocTNAMEED(void)
{
return Object->DocTNAMEED;
}
//---------------------------------------------------------------
void THOT_DMDocRaschetImpl::set_DocTNAMEED(TFIBWideStringField * DocTNAMEED)
{
Object->DocTNAMEED=DocTNAMEED;
}
//---------------------------------------------------------------
TFIBSmallIntField * THOT_DMDocRaschetImpl::get_DocTTNOM(void)
{
return Object->DocTTNOM;
}
//---------------------------------------------------------------
void THOT_DMDocRaschetImpl::set_DocTTNOM(TFIBSmallIntField * DocTTNOM)
{
Object->DocTTNOM=DocTTNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMDocRaschetImpl::get_DocTNAME_TPRICE(void)
{
return Object->DocTNAME_TPRICE;
}
//---------------------------------------------------------------
void THOT_DMDocRaschetImpl::set_DocTNAME_TPRICE(TFIBWideStringField * DocTNAME_TPRICE)
{
Object->DocTNAME_TPRICE=DocTNAME_TPRICE;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMDocRaschetImpl::get_DocTNAME_HOT_SNF(void)
{
return Object->DocTNAME_HOT_SNF;
}
//---------------------------------------------------------------
void THOT_DMDocRaschetImpl::set_DocTNAME_HOT_SNF(TFIBWideStringField * DocTNAME_HOT_SNF)
{
Object->DocTNAME_HOT_SNF=DocTNAME_HOT_SNF;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMDocRaschetImpl::get_DocTNAME_HOT_SCATNOM(void)
{
return Object->DocTNAME_HOT_SCATNOM;
}
//---------------------------------------------------------------
void THOT_DMDocRaschetImpl::set_DocTNAME_HOT_SCATNOM(TFIBWideStringField * DocTNAME_HOT_SCATNOM)
{
Object->DocTNAME_HOT_SCATNOM=DocTNAME_HOT_SCATNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMDocRaschetImpl::get_DocTNAME_HOT_STYPEPOS(void)
{
return Object->DocTNAME_HOT_STYPEPOS;
}
//---------------------------------------------------------------
void THOT_DMDocRaschetImpl::set_DocTNAME_HOT_STYPEPOS(TFIBWideStringField * DocTNAME_HOT_STYPEPOS)
{
Object->DocTNAME_HOT_STYPEPOS=DocTNAME_HOT_STYPEPOS;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMDocRaschetImpl::get_DocTNAMEKLIENT(void)
{
return Object->DocTNAMEKLIENT;
}
//---------------------------------------------------------------
void THOT_DMDocRaschetImpl::set_DocTNAMEKLIENT(TFIBWideStringField * DocTNAMEKLIENT)
{
Object->DocTNAMEKLIENT=DocTNAMEKLIENT;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocRaschetImpl::get_DocAllID_HOT_GALLDOC(void)
{
return Object->DocAllID_HOT_GALLDOC;
}
//---------------------------------------------------------------
void THOT_DMDocRaschetImpl::set_DocAllID_HOT_GALLDOC(TFIBLargeIntField * DocAllID_HOT_GALLDOC)
{
Object->DocAllID_HOT_GALLDOC=DocAllID_HOT_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocRaschetImpl::get_DocAllIDFIRM_HOT_GALLDOC(void)
{
return Object->DocAllIDFIRM_HOT_GALLDOC;
}
//---------------------------------------------------------------
void THOT_DMDocRaschetImpl::set_DocAllIDFIRM_HOT_GALLDOC(TFIBLargeIntField * DocAllIDFIRM_HOT_GALLDOC)
{
Object->DocAllIDFIRM_HOT_GALLDOC=DocAllIDFIRM_HOT_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocRaschetImpl::get_DocAllIDKL_HOT_GALLDOC(void)
{
return Object->DocAllIDKL_HOT_GALLDOC;
}
//---------------------------------------------------------------
void THOT_DMDocRaschetImpl::set_DocAllIDKL_HOT_GALLDOC(TFIBLargeIntField * DocAllIDKL_HOT_GALLDOC)
{
Object->DocAllIDKL_HOT_GALLDOC=DocAllIDKL_HOT_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocRaschetImpl::get_DocAllIDUSER_HOT_GALLDOC(void)
{
return Object->DocAllIDUSER_HOT_GALLDOC;
}
//---------------------------------------------------------------
void THOT_DMDocRaschetImpl::set_DocAllIDUSER_HOT_GALLDOC(TFIBLargeIntField * DocAllIDUSER_HOT_GALLDOC)
{
Object->DocAllIDUSER_HOT_GALLDOC=DocAllIDUSER_HOT_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocRaschetImpl::get_DocAllIDDOCOSN_HOT_GALLDOC(void)
{
return Object->DocAllIDDOCOSN_HOT_GALLDOC;
}
//---------------------------------------------------------------
void THOT_DMDocRaschetImpl::set_DocAllIDDOCOSN_HOT_GALLDOC(TFIBLargeIntField * DocAllIDDOCOSN_HOT_GALLDOC)
{
Object->DocAllIDDOCOSN_HOT_GALLDOC=DocAllIDDOCOSN_HOT_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocRaschetImpl::get_DocAllIDSKLAD_HOT_GALLDOC(void)
{
return Object->DocAllIDSKLAD_HOT_GALLDOC;
}
//---------------------------------------------------------------
void THOT_DMDocRaschetImpl::set_DocAllIDSKLAD_HOT_GALLDOC(TFIBLargeIntField * DocAllIDSKLAD_HOT_GALLDOC)
{
Object->DocAllIDSKLAD_HOT_GALLDOC=DocAllIDSKLAD_HOT_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocRaschetImpl::get_DocAllIDBASE_HOT_GALLDOC(void)
{
return Object->DocAllIDBASE_HOT_GALLDOC;
}
//---------------------------------------------------------------
void THOT_DMDocRaschetImpl::set_DocAllIDBASE_HOT_GALLDOC(TFIBLargeIntField * DocAllIDBASE_HOT_GALLDOC)
{
Object->DocAllIDBASE_HOT_GALLDOC=DocAllIDBASE_HOT_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocRaschetImpl::get_DocID_HOT_DRASCHET(void)
{
return Object->DocID_HOT_DRASCHET;
}
//---------------------------------------------------------------
void THOT_DMDocRaschetImpl::set_DocID_HOT_DRASCHET(TFIBLargeIntField * DocID_HOT_DRASCHET)
{
Object->DocID_HOT_DRASCHET=DocID_HOT_DRASCHET;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocRaschetImpl::get_DocIDDOCH_HOT_DRASCHET(void)
{
return Object->DocIDDOCH_HOT_DRASCHET;
}
//---------------------------------------------------------------
void THOT_DMDocRaschetImpl::set_DocIDDOCH_HOT_DRASCHET(TFIBLargeIntField * DocIDDOCH_HOT_DRASCHET)
{
Object->DocIDDOCH_HOT_DRASCHET=DocIDDOCH_HOT_DRASCHET;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocRaschetImpl::get_DocIDBSCHET_HOT_DRASCHET(void)
{
return Object->DocIDBSCHET_HOT_DRASCHET;
}
//---------------------------------------------------------------
void THOT_DMDocRaschetImpl::set_DocIDBSCHET_HOT_DRASCHET(TFIBLargeIntField * DocIDBSCHET_HOT_DRASCHET)
{
Object->DocIDBSCHET_HOT_DRASCHET=DocIDBSCHET_HOT_DRASCHET;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocRaschetImpl::get_DocIDBASE_HOT_DRASCHET(void)
{
return Object->DocIDBASE_HOT_DRASCHET;
}
//---------------------------------------------------------------
void THOT_DMDocRaschetImpl::set_DocIDBASE_HOT_DRASCHET(TFIBLargeIntField * DocIDBASE_HOT_DRASCHET)
{
Object->DocIDBASE_HOT_DRASCHET=DocIDBASE_HOT_DRASCHET;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocRaschetImpl::get_DocIDTPRICE_HOT_DRASCHET(void)
{
return Object->DocIDTPRICE_HOT_DRASCHET;
}
//---------------------------------------------------------------
void THOT_DMDocRaschetImpl::set_DocIDTPRICE_HOT_DRASCHET(TFIBLargeIntField * DocIDTPRICE_HOT_DRASCHET)
{
Object->DocIDTPRICE_HOT_DRASCHET=DocIDTPRICE_HOT_DRASCHET;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocRaschetImpl::get_DocTID_HOT_DRASCHETT(void)
{
return Object->DocTID_HOT_DRASCHETT;
}
//---------------------------------------------------------------
void THOT_DMDocRaschetImpl::set_DocTID_HOT_DRASCHETT(TFIBLargeIntField * DocTID_HOT_DRASCHETT)
{
Object->DocTID_HOT_DRASCHETT=DocTID_HOT_DRASCHETT;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocRaschetImpl::get_DocTIDDOCH_HOT_DRASCHETT(void)
{
return Object->DocTIDDOCH_HOT_DRASCHETT;
}
//---------------------------------------------------------------
void THOT_DMDocRaschetImpl::set_DocTIDDOCH_HOT_DRASCHETT(TFIBLargeIntField * DocTIDDOCH_HOT_DRASCHETT)
{
Object->DocTIDDOCH_HOT_DRASCHETT=DocTIDDOCH_HOT_DRASCHETT;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocRaschetImpl::get_DocTIDTPRICE_HOT_DRASCHETT(void)
{
return Object->DocTIDTPRICE_HOT_DRASCHETT;
}
//---------------------------------------------------------------
void THOT_DMDocRaschetImpl::set_DocTIDTPRICE_HOT_DRASCHETT(TFIBLargeIntField * DocTIDTPRICE_HOT_DRASCHETT)
{
Object->DocTIDTPRICE_HOT_DRASCHETT=DocTIDTPRICE_HOT_DRASCHETT;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocRaschetImpl::get_DocTIDNOM_HOT_DRASCHETT(void)
{
return Object->DocTIDNOM_HOT_DRASCHETT;
}
//---------------------------------------------------------------
void THOT_DMDocRaschetImpl::set_DocTIDNOM_HOT_DRASCHETT(TFIBLargeIntField * DocTIDNOM_HOT_DRASCHETT)
{
Object->DocTIDNOM_HOT_DRASCHETT=DocTIDNOM_HOT_DRASCHETT;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocRaschetImpl::get_DocTIDED_HOT_DRASCHETT(void)
{
return Object->DocTIDED_HOT_DRASCHETT;
}
//---------------------------------------------------------------
void THOT_DMDocRaschetImpl::set_DocTIDED_HOT_DRASCHETT(TFIBLargeIntField * DocTIDED_HOT_DRASCHETT)
{
Object->DocTIDED_HOT_DRASCHETT=DocTIDED_HOT_DRASCHETT;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocRaschetImpl::get_DocTIDNOMER_HOT_DRASCHETT(void)
{
return Object->DocTIDNOMER_HOT_DRASCHETT;
}
//---------------------------------------------------------------
void THOT_DMDocRaschetImpl::set_DocTIDNOMER_HOT_DRASCHETT(TFIBLargeIntField * DocTIDNOMER_HOT_DRASCHETT)
{
Object->DocTIDNOMER_HOT_DRASCHETT=DocTIDNOMER_HOT_DRASCHETT;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocRaschetImpl::get_DocTIDCAT_HOT_DRASCHETT(void)
{
return Object->DocTIDCAT_HOT_DRASCHETT;
}
//---------------------------------------------------------------
void THOT_DMDocRaschetImpl::set_DocTIDCAT_HOT_DRASCHETT(TFIBLargeIntField * DocTIDCAT_HOT_DRASCHETT)
{
Object->DocTIDCAT_HOT_DRASCHETT=DocTIDCAT_HOT_DRASCHETT;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocRaschetImpl::get_DocTIDGUEST_HOT_DRASCHETT(void)
{
return Object->DocTIDGUEST_HOT_DRASCHETT;
}
//---------------------------------------------------------------
void THOT_DMDocRaschetImpl::set_DocTIDGUEST_HOT_DRASCHETT(TFIBLargeIntField * DocTIDGUEST_HOT_DRASCHETT)
{
Object->DocTIDGUEST_HOT_DRASCHETT=DocTIDGUEST_HOT_DRASCHETT;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocRaschetImpl::get_DocTIDTPOS_HOT_DRASCHETT(void)
{
return Object->DocTIDTPOS_HOT_DRASCHETT;
}
//---------------------------------------------------------------
void THOT_DMDocRaschetImpl::set_DocTIDTPOS_HOT_DRASCHETT(TFIBLargeIntField * DocTIDTPOS_HOT_DRASCHETT)
{
Object->DocTIDTPOS_HOT_DRASCHETT=DocTIDTPOS_HOT_DRASCHETT;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocRaschetImpl::get_DocTIDBASE_HOT_DRASCHETT(void)
{
return Object->DocTIDBASE_HOT_DRASCHETT;
}
//---------------------------------------------------------------
void THOT_DMDocRaschetImpl::set_DocTIDBASE_HOT_DRASCHETT(TFIBLargeIntField * DocTIDBASE_HOT_DRASCHETT)
{
Object->DocTIDBASE_HOT_DRASCHETT=DocTIDBASE_HOT_DRASCHETT;
}
//---------------------------------------------------------------
bool THOT_DMDocRaschetImpl::get_Prosmotr(void)
{
return Object->Prosmotr;
}
//---------------------------------------------------------------
void THOT_DMDocRaschetImpl::set_Prosmotr(bool Prosmotr)
{
Object->Prosmotr=Prosmotr;
}
//---------------------------------------------------------------
bool THOT_DMDocRaschetImpl::get_NoEdit(void)
{
return Object->NoEdit;
}
//---------------------------------------------------------------
void THOT_DMDocRaschetImpl::set_NoEdit(bool NoEdit)
{
Object->NoEdit=NoEdit;
}
//---------------------------------------------------------------
bool THOT_DMDocRaschetImpl::get_Vibor(void)
{
return Object->Vibor;
}
//---------------------------------------------------------------
void THOT_DMDocRaschetImpl::set_Vibor(bool Vibor)
{
Object->Vibor=Vibor;
}
//---------------------------------------------------------------
void THOT_DMDocRaschetImpl::NewDoc(void)
{
return Object->NewDoc();
}
//---------------------------------------------------------------
void THOT_DMDocRaschetImpl::OpenDoc(__int64 IdDoc)
{
return Object->OpenDoc(IdDoc);
}
//---------------------------------------------------------------
bool THOT_DMDocRaschetImpl::SaveDoc(void)
{
return Object->SaveDoc();
}
//---------------------------------------------------------------
bool THOT_DMDocRaschetImpl::DvRegDoc(void)
{
return Object->DvRegDoc();
}
//---------------------------------------------------------------
bool THOT_DMDocRaschetImpl::CancelDvRegDoc(void)
{
return Object->CancelDvRegDoc();
}
//---------------------------------------------------------------
void THOT_DMDocRaschetImpl::AddString(void)
{
return Object->AddString();
}
//---------------------------------------------------------------
void THOT_DMDocRaschetImpl::DeleteString(void)
{
return Object->DeleteString();
}
//---------------------------------------------------------------
void THOT_DMDocRaschetImpl::CloseDoc(void)
{
return Object->CloseDoc();
}
//---------------------------------------------------------------
bool THOT_DMDocRaschetImpl::DeleteDoc(__int64 id)
{
return Object->DeleteDoc(id);
}
//---------------------------------------------------------------
void THOT_DMDocRaschetImpl::GetSpisokGuest(void)
{
return Object->GetSpisokGuest();
}
//---------------------------------------------------------------
double THOT_DMDocRaschetImpl::GetKolOsnUslugGuest(__int64 id_guest)
{
return Object->GetKolOsnUslugGuest(id_guest);
}
//---------------------------------------------------------------
double THOT_DMDocRaschetImpl::GetSumDopUslugGuest(__int64 id_guest)
{
return Object->GetSumDopUslugGuest(id_guest);
}
//---------------------------------------------------------------
