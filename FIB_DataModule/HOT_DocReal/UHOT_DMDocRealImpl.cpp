#include "vcl.h"
#pragma hdrstop


#include "UHOT_DMDocRealImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
THOT_DMDocRealImpl::THOT_DMDocRealImpl()           
{                                            
Object=new THOT_DMDocReal(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
THOT_DMDocRealImpl::~THOT_DMDocRealImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void THOT_DMDocRealImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int THOT_DMDocRealImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IHOT_DMDocReal)                        
   {                                                                     
   *ppv=static_cast<IHOT_DMDocReal*> (this);                                
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
int THOT_DMDocRealImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int THOT_DMDocRealImpl::kanRelease(void)                                  
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
int  THOT_DMDocRealImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void THOT_DMDocRealImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  THOT_DMDocRealImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void THOT_DMDocRealImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int THOT_DMDocRealImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl);
kanRelease();
Object->ClsIdImpl=CLSID_THOT_DMDocRealImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int THOT_DMDocRealImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IHOT_DMDocReal
TDataSource * THOT_DMDocRealImpl::get_DataSourceDoc(void)
{
return Object->DataSourceDoc;
}
//---------------------------------------------------------------
void THOT_DMDocRealImpl::set_DataSourceDoc(TDataSource * DataSourceDoc)
{
Object->DataSourceDoc=DataSourceDoc;
}
//---------------------------------------------------------------
TDataSource * THOT_DMDocRealImpl::get_DataSourceDocT(void)
{
return Object->DataSourceDocT;
}
//---------------------------------------------------------------
void THOT_DMDocRealImpl::set_DataSourceDocT(TDataSource * DataSourceDocT)
{
Object->DataSourceDocT=DataSourceDocT;
}
//---------------------------------------------------------------
TDataSource * THOT_DMDocRealImpl::get_DataSourceDocAll(void)
{
return Object->DataSourceDocAll;
}
//---------------------------------------------------------------
void THOT_DMDocRealImpl::set_DataSourceDocAll(TDataSource * DataSourceDocAll)
{
Object->DataSourceDocAll=DataSourceDocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * THOT_DMDocRealImpl::get_DocAll(void)
{
return Object->DocAll;
}
//---------------------------------------------------------------
void THOT_DMDocRealImpl::set_DocAll(TpFIBDataSet * DocAll)
{
Object->DocAll=DocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * THOT_DMDocRealImpl::get_Doc(void)
{
return Object->Doc;
}
//---------------------------------------------------------------
void THOT_DMDocRealImpl::set_Doc(TpFIBDataSet * Doc)
{
Object->Doc=Doc;
}
//---------------------------------------------------------------
TpFIBDataSet * THOT_DMDocRealImpl::get_DocT(void)
{
return Object->DocT;
}
//---------------------------------------------------------------
void THOT_DMDocRealImpl::set_DocT(TpFIBDataSet * DocT)
{
Object->DocT=DocT;
}
//---------------------------------------------------------------
TpFIBQuery * THOT_DMDocRealImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void THOT_DMDocRealImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TFIBDateTimeField * THOT_DMDocRealImpl::get_DocAllPOS_HOT_GALLDOC(void)
{
return Object->DocAllPOS_HOT_GALLDOC;
}
//---------------------------------------------------------------
void THOT_DMDocRealImpl::set_DocAllPOS_HOT_GALLDOC(TFIBDateTimeField * DocAllPOS_HOT_GALLDOC)
{
Object->DocAllPOS_HOT_GALLDOC=DocAllPOS_HOT_GALLDOC;
}
//---------------------------------------------------------------
TFIBSmallIntField * THOT_DMDocRealImpl::get_DocAllPR_HOT_GALLDOC(void)
{
return Object->DocAllPR_HOT_GALLDOC;
}
//---------------------------------------------------------------
void THOT_DMDocRealImpl::set_DocAllPR_HOT_GALLDOC(TFIBSmallIntField * DocAllPR_HOT_GALLDOC)
{
Object->DocAllPR_HOT_GALLDOC=DocAllPR_HOT_GALLDOC;
}
//---------------------------------------------------------------
TFIBBCDField * THOT_DMDocRealImpl::get_DocAllSUM_HOT_GALLDOC(void)
{
return Object->DocAllSUM_HOT_GALLDOC;
}
//---------------------------------------------------------------
void THOT_DMDocRealImpl::set_DocAllSUM_HOT_GALLDOC(TFIBBCDField * DocAllSUM_HOT_GALLDOC)
{
Object->DocAllSUM_HOT_GALLDOC=DocAllSUM_HOT_GALLDOC;
}
//---------------------------------------------------------------
TFIBSmallIntField * THOT_DMDocRealImpl::get_DocTTUSL_HOT_DREALT(void)
{
return Object->DocTTUSL_HOT_DREALT;
}
//---------------------------------------------------------------
void THOT_DMDocRealImpl::set_DocTTUSL_HOT_DREALT(TFIBSmallIntField * DocTTUSL_HOT_DREALT)
{
Object->DocTTUSL_HOT_DREALT=DocTTUSL_HOT_DREALT;
}
//---------------------------------------------------------------
TFIBBCDField * THOT_DMDocRealImpl::get_DocTKOL_HOT_DREALT(void)
{
return Object->DocTKOL_HOT_DREALT;
}
//---------------------------------------------------------------
void THOT_DMDocRealImpl::set_DocTKOL_HOT_DREALT(TFIBBCDField * DocTKOL_HOT_DREALT)
{
Object->DocTKOL_HOT_DREALT=DocTKOL_HOT_DREALT;
}
//---------------------------------------------------------------
TFIBBCDField * THOT_DMDocRealImpl::get_DocTKF_HOT_DREALT(void)
{
return Object->DocTKF_HOT_DREALT;
}
//---------------------------------------------------------------
void THOT_DMDocRealImpl::set_DocTKF_HOT_DREALT(TFIBBCDField * DocTKF_HOT_DREALT)
{
Object->DocTKF_HOT_DREALT=DocTKF_HOT_DREALT;
}
//---------------------------------------------------------------
TFIBBCDField * THOT_DMDocRealImpl::get_DocTPRICE_HOT_DREALT(void)
{
return Object->DocTPRICE_HOT_DREALT;
}
//---------------------------------------------------------------
void THOT_DMDocRealImpl::set_DocTPRICE_HOT_DREALT(TFIBBCDField * DocTPRICE_HOT_DREALT)
{
Object->DocTPRICE_HOT_DREALT=DocTPRICE_HOT_DREALT;
}
//---------------------------------------------------------------
TFIBBCDField * THOT_DMDocRealImpl::get_DocTSUM_HOT_DREALT(void)
{
return Object->DocTSUM_HOT_DREALT;
}
//---------------------------------------------------------------
void THOT_DMDocRealImpl::set_DocTSUM_HOT_DREALT(TFIBBCDField * DocTSUM_HOT_DREALT)
{
Object->DocTSUM_HOT_DREALT=DocTSUM_HOT_DREALT;
}
//---------------------------------------------------------------
TFIBIntegerField * THOT_DMDocRealImpl::get_DocTTNOM(void)
{
return Object->DocTTNOM;
}
//---------------------------------------------------------------
void THOT_DMDocRealImpl::set_DocTTNOM(TFIBIntegerField * DocTTNOM)
{
Object->DocTTNOM=DocTTNOM;
}
//---------------------------------------------------------------
TIntegerField * THOT_DMDocRealImpl::get_DocTRECNO(void)
{
return Object->DocTRECNO;
}
//---------------------------------------------------------------
void THOT_DMDocRealImpl::set_DocTRECNO(TIntegerField * DocTRECNO)
{
Object->DocTRECNO=DocTRECNO;
}
//---------------------------------------------------------------
TpFIBQuery * THOT_DMDocRealImpl::get_QueryDvReg(void)
{
return Object->QueryDvReg;
}
//---------------------------------------------------------------
void THOT_DMDocRealImpl::set_QueryDvReg(TpFIBQuery * QueryDvReg)
{
Object->QueryDvReg=QueryDvReg;
}
//---------------------------------------------------------------
TpFIBQuery * THOT_DMDocRealImpl::get_QueryCancelDvReg(void)
{
return Object->QueryCancelDvReg;
}
//---------------------------------------------------------------
void THOT_DMDocRealImpl::set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg)
{
Object->QueryCancelDvReg=QueryCancelDvReg;
}
//---------------------------------------------------------------
TpFIBDataSet * THOT_DMDocRealImpl::get_TypePriceDataSet(void)
{
return Object->TypePriceDataSet;
}
//---------------------------------------------------------------
void THOT_DMDocRealImpl::set_TypePriceDataSet(TpFIBDataSet * TypePriceDataSet)
{
Object->TypePriceDataSet=TypePriceDataSet;
}
//---------------------------------------------------------------
TFIBDateTimeField * THOT_DMDocRealImpl::get_DocTPOSNACH_HOT_DREALT(void)
{
return Object->DocTPOSNACH_HOT_DREALT;
}
//---------------------------------------------------------------
void THOT_DMDocRealImpl::set_DocTPOSNACH_HOT_DREALT(TFIBDateTimeField * DocTPOSNACH_HOT_DREALT)
{
Object->DocTPOSNACH_HOT_DREALT=DocTPOSNACH_HOT_DREALT;
}
//---------------------------------------------------------------
TFIBDateTimeField * THOT_DMDocRealImpl::get_DocTPOSCON_HOT_DREALT(void)
{
return Object->DocTPOSCON_HOT_DREALT;
}
//---------------------------------------------------------------
void THOT_DMDocRealImpl::set_DocTPOSCON_HOT_DREALT(TFIBDateTimeField * DocTPOSCON_HOT_DREALT)
{
Object->DocTPOSCON_HOT_DREALT=DocTPOSCON_HOT_DREALT;
}
//---------------------------------------------------------------
TpFIBDataSet * THOT_DMDocRealImpl::get_SpisokGuestOsnUslug(void)
{
return Object->SpisokGuestOsnUslug;
}
//---------------------------------------------------------------
void THOT_DMDocRealImpl::set_SpisokGuestOsnUslug(TpFIBDataSet * SpisokGuestOsnUslug)
{
Object->SpisokGuestOsnUslug=SpisokGuestOsnUslug;
}
//---------------------------------------------------------------
TpFIBDataSet * THOT_DMDocRealImpl::get_SpisokGuestDopUslug(void)
{
return Object->SpisokGuestDopUslug;
}
//---------------------------------------------------------------
void THOT_DMDocRealImpl::set_SpisokGuestDopUslug(TpFIBDataSet * SpisokGuestDopUslug)
{
Object->SpisokGuestDopUslug=SpisokGuestDopUslug;
}
//---------------------------------------------------------------
TFIBFloatField * THOT_DMDocRealImpl::get_SpisokGuestOsnUslugSUMKOL(void)
{
return Object->SpisokGuestOsnUslugSUMKOL;
}
//---------------------------------------------------------------
void THOT_DMDocRealImpl::set_SpisokGuestOsnUslugSUMKOL(TFIBFloatField * SpisokGuestOsnUslugSUMKOL)
{
Object->SpisokGuestOsnUslugSUMKOL=SpisokGuestOsnUslugSUMKOL;
}
//---------------------------------------------------------------
TFIBBCDField * THOT_DMDocRealImpl::get_SpisokGuestDopUslugSUM(void)
{
return Object->SpisokGuestDopUslugSUM;
}
//---------------------------------------------------------------
void THOT_DMDocRealImpl::set_SpisokGuestDopUslugSUM(TFIBBCDField * SpisokGuestDopUslugSUM)
{
Object->SpisokGuestDopUslugSUM=SpisokGuestDopUslugSUM;
}
//---------------------------------------------------------------
TFIBBCDField * THOT_DMDocRealImpl::get_SpisokGuestDopUslugIDKLIENT(void)
{
return Object->SpisokGuestDopUslugIDKLIENT;
}
//---------------------------------------------------------------
void THOT_DMDocRealImpl::set_SpisokGuestDopUslugIDKLIENT(TFIBBCDField * SpisokGuestDopUslugIDKLIENT)
{
Object->SpisokGuestDopUslugIDKLIENT=SpisokGuestDopUslugIDKLIENT;
}
//---------------------------------------------------------------
TFIBBCDField * THOT_DMDocRealImpl::get_SpisokGuestOsnUslugIDKLIENT(void)
{
return Object->SpisokGuestOsnUslugIDKLIENT;
}
//---------------------------------------------------------------
void THOT_DMDocRealImpl::set_SpisokGuestOsnUslugIDKLIENT(TFIBBCDField * SpisokGuestOsnUslugIDKLIENT)
{
Object->SpisokGuestOsnUslugIDKLIENT=SpisokGuestOsnUslugIDKLIENT;
}
//---------------------------------------------------------------
TpFIBDataSet * THOT_DMDocRealImpl::get_NumDoc(void)
{
return Object->NumDoc;
}
//---------------------------------------------------------------
void THOT_DMDocRealImpl::set_NumDoc(TpFIBDataSet * NumDoc)
{
Object->NumDoc=NumDoc;
}
//---------------------------------------------------------------
TFIBIntegerField * THOT_DMDocRealImpl::get_NumDocMAXNUMBER(void)
{
return Object->NumDocMAXNUMBER;
}
//---------------------------------------------------------------
void THOT_DMDocRealImpl::set_NumDocMAXNUMBER(TFIBIntegerField * NumDocMAXNUMBER)
{
Object->NumDocMAXNUMBER=NumDocMAXNUMBER;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMDocRealImpl::get_SpisokGuestOsnUslugNAMEKLIENT(void)
{
return Object->SpisokGuestOsnUslugNAMEKLIENT;
}
//---------------------------------------------------------------
void THOT_DMDocRealImpl::set_SpisokGuestOsnUslugNAMEKLIENT(TFIBWideStringField * SpisokGuestOsnUslugNAMEKLIENT)
{
Object->SpisokGuestOsnUslugNAMEKLIENT=SpisokGuestOsnUslugNAMEKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMDocRealImpl::get_SpisokGuestDopUslugNAMEKLIENT(void)
{
return Object->SpisokGuestDopUslugNAMEKLIENT;
}
//---------------------------------------------------------------
void THOT_DMDocRealImpl::set_SpisokGuestDopUslugNAMEKLIENT(TFIBWideStringField * SpisokGuestDopUslugNAMEKLIENT)
{
Object->SpisokGuestDopUslugNAMEKLIENT=SpisokGuestDopUslugNAMEKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMDocRealImpl::get_DocAllTDOC_HOT_GALLDOC(void)
{
return Object->DocAllTDOC_HOT_GALLDOC;
}
//---------------------------------------------------------------
void THOT_DMDocRealImpl::set_DocAllTDOC_HOT_GALLDOC(TFIBWideStringField * DocAllTDOC_HOT_GALLDOC)
{
Object->DocAllTDOC_HOT_GALLDOC=DocAllTDOC_HOT_GALLDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * THOT_DMDocRealImpl::get_DocAllNUMBER_HOT_GALLDOC(void)
{
return Object->DocAllNUMBER_HOT_GALLDOC;
}
//---------------------------------------------------------------
void THOT_DMDocRealImpl::set_DocAllNUMBER_HOT_GALLDOC(TFIBIntegerField * DocAllNUMBER_HOT_GALLDOC)
{
Object->DocAllNUMBER_HOT_GALLDOC=DocAllNUMBER_HOT_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMDocRealImpl::get_DocAllNAME_SINFBASE_OBMEN(void)
{
return Object->DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void THOT_DMDocRealImpl::set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN)
{
Object->DocAllNAME_SINFBASE_OBMEN=DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMDocRealImpl::get_DocAllNAMEFIRM(void)
{
return Object->DocAllNAMEFIRM;
}
//---------------------------------------------------------------
void THOT_DMDocRealImpl::set_DocAllNAMEFIRM(TFIBWideStringField * DocAllNAMEFIRM)
{
Object->DocAllNAMEFIRM=DocAllNAMEFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMDocRealImpl::get_DocAllNAMEKLIENT(void)
{
return Object->DocAllNAMEKLIENT;
}
//---------------------------------------------------------------
void THOT_DMDocRealImpl::set_DocAllNAMEKLIENT(TFIBWideStringField * DocAllNAMEKLIENT)
{
Object->DocAllNAMEKLIENT=DocAllNAMEKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMDocRealImpl::get_DocAllFNAME_USER(void)
{
return Object->DocAllFNAME_USER;
}
//---------------------------------------------------------------
void THOT_DMDocRealImpl::set_DocAllFNAME_USER(TFIBWideStringField * DocAllFNAME_USER)
{
Object->DocAllFNAME_USER=DocAllFNAME_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMDocRealImpl::get_DocAllNAMESKLAD(void)
{
return Object->DocAllNAMESKLAD;
}
//---------------------------------------------------------------
void THOT_DMDocRealImpl::set_DocAllNAMESKLAD(TFIBWideStringField * DocAllNAMESKLAD)
{
Object->DocAllNAMESKLAD=DocAllNAMESKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMDocRealImpl::get_DocPRIM_HOT_DREAL(void)
{
return Object->DocPRIM_HOT_DREAL;
}
//---------------------------------------------------------------
void THOT_DMDocRealImpl::set_DocPRIM_HOT_DREAL(TFIBWideStringField * DocPRIM_HOT_DREAL)
{
Object->DocPRIM_HOT_DREAL=DocPRIM_HOT_DREAL;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMDocRealImpl::get_DocNAMEKKM_HOT_DREAL(void)
{
return Object->DocNAMEKKM_HOT_DREAL;
}
//---------------------------------------------------------------
void THOT_DMDocRealImpl::set_DocNAMEKKM_HOT_DREAL(TFIBWideStringField * DocNAMEKKM_HOT_DREAL)
{
Object->DocNAMEKKM_HOT_DREAL=DocNAMEKKM_HOT_DREAL;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMDocRealImpl::get_DocZAVNUM_HOT_DREAL(void)
{
return Object->DocZAVNUM_HOT_DREAL;
}
//---------------------------------------------------------------
void THOT_DMDocRealImpl::set_DocZAVNUM_HOT_DREAL(TFIBWideStringField * DocZAVNUM_HOT_DREAL)
{
Object->DocZAVNUM_HOT_DREAL=DocZAVNUM_HOT_DREAL;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMDocRealImpl::get_DocREGNUM_HOT_DREAL(void)
{
return Object->DocREGNUM_HOT_DREAL;
}
//---------------------------------------------------------------
void THOT_DMDocRealImpl::set_DocREGNUM_HOT_DREAL(TFIBWideStringField * DocREGNUM_HOT_DREAL)
{
Object->DocREGNUM_HOT_DREAL=DocREGNUM_HOT_DREAL;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMDocRealImpl::get_DocNUMCHECK_HOT_DREAL(void)
{
return Object->DocNUMCHECK_HOT_DREAL;
}
//---------------------------------------------------------------
void THOT_DMDocRealImpl::set_DocNUMCHECK_HOT_DREAL(TFIBWideStringField * DocNUMCHECK_HOT_DREAL)
{
Object->DocNUMCHECK_HOT_DREAL=DocNUMCHECK_HOT_DREAL;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMDocRealImpl::get_DocNUMKL_HOT_DREAL(void)
{
return Object->DocNUMKL_HOT_DREAL;
}
//---------------------------------------------------------------
void THOT_DMDocRealImpl::set_DocNUMKL_HOT_DREAL(TFIBWideStringField * DocNUMKL_HOT_DREAL)
{
Object->DocNUMKL_HOT_DREAL=DocNUMKL_HOT_DREAL;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMDocRealImpl::get_DocTNAMENOM(void)
{
return Object->DocTNAMENOM;
}
//---------------------------------------------------------------
void THOT_DMDocRealImpl::set_DocTNAMENOM(TFIBWideStringField * DocTNAMENOM)
{
Object->DocTNAMENOM=DocTNAMENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMDocRealImpl::get_DocTNAMEED(void)
{
return Object->DocTNAMEED;
}
//---------------------------------------------------------------
void THOT_DMDocRealImpl::set_DocTNAMEED(TFIBWideStringField * DocTNAMEED)
{
Object->DocTNAMEED=DocTNAMEED;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMDocRealImpl::get_DocTNAME_TPRICE(void)
{
return Object->DocTNAME_TPRICE;
}
//---------------------------------------------------------------
void THOT_DMDocRealImpl::set_DocTNAME_TPRICE(TFIBWideStringField * DocTNAME_TPRICE)
{
Object->DocTNAME_TPRICE=DocTNAME_TPRICE;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMDocRealImpl::get_DocTNAME_HOT_SNF(void)
{
return Object->DocTNAME_HOT_SNF;
}
//---------------------------------------------------------------
void THOT_DMDocRealImpl::set_DocTNAME_HOT_SNF(TFIBWideStringField * DocTNAME_HOT_SNF)
{
Object->DocTNAME_HOT_SNF=DocTNAME_HOT_SNF;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMDocRealImpl::get_DocTNAME_HOT_SCATNOM(void)
{
return Object->DocTNAME_HOT_SCATNOM;
}
//---------------------------------------------------------------
void THOT_DMDocRealImpl::set_DocTNAME_HOT_SCATNOM(TFIBWideStringField * DocTNAME_HOT_SCATNOM)
{
Object->DocTNAME_HOT_SCATNOM=DocTNAME_HOT_SCATNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMDocRealImpl::get_DocTNAME_HOT_STYPEPOS(void)
{
return Object->DocTNAME_HOT_STYPEPOS;
}
//---------------------------------------------------------------
void THOT_DMDocRealImpl::set_DocTNAME_HOT_STYPEPOS(TFIBWideStringField * DocTNAME_HOT_STYPEPOS)
{
Object->DocTNAME_HOT_STYPEPOS=DocTNAME_HOT_STYPEPOS;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMDocRealImpl::get_DocTNAMEKLIENT(void)
{
return Object->DocTNAMEKLIENT;
}
//---------------------------------------------------------------
void THOT_DMDocRealImpl::set_DocTNAMEKLIENT(TFIBWideStringField * DocTNAMEKLIENT)
{
Object->DocTNAMEKLIENT=DocTNAMEKLIENT;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocRealImpl::get_DocAllID_HOT_GALLDOC(void)
{
return Object->DocAllID_HOT_GALLDOC;
}
//---------------------------------------------------------------
void THOT_DMDocRealImpl::set_DocAllID_HOT_GALLDOC(TFIBLargeIntField * DocAllID_HOT_GALLDOC)
{
Object->DocAllID_HOT_GALLDOC=DocAllID_HOT_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocRealImpl::get_DocAllIDFIRM_HOT_GALLDOC(void)
{
return Object->DocAllIDFIRM_HOT_GALLDOC;
}
//---------------------------------------------------------------
void THOT_DMDocRealImpl::set_DocAllIDFIRM_HOT_GALLDOC(TFIBLargeIntField * DocAllIDFIRM_HOT_GALLDOC)
{
Object->DocAllIDFIRM_HOT_GALLDOC=DocAllIDFIRM_HOT_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocRealImpl::get_DocAllIDKL_HOT_GALLDOC(void)
{
return Object->DocAllIDKL_HOT_GALLDOC;
}
//---------------------------------------------------------------
void THOT_DMDocRealImpl::set_DocAllIDKL_HOT_GALLDOC(TFIBLargeIntField * DocAllIDKL_HOT_GALLDOC)
{
Object->DocAllIDKL_HOT_GALLDOC=DocAllIDKL_HOT_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocRealImpl::get_DocAllIDUSER_HOT_GALLDOC(void)
{
return Object->DocAllIDUSER_HOT_GALLDOC;
}
//---------------------------------------------------------------
void THOT_DMDocRealImpl::set_DocAllIDUSER_HOT_GALLDOC(TFIBLargeIntField * DocAllIDUSER_HOT_GALLDOC)
{
Object->DocAllIDUSER_HOT_GALLDOC=DocAllIDUSER_HOT_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocRealImpl::get_DocAllIDDOCOSN_HOT_GALLDOC(void)
{
return Object->DocAllIDDOCOSN_HOT_GALLDOC;
}
//---------------------------------------------------------------
void THOT_DMDocRealImpl::set_DocAllIDDOCOSN_HOT_GALLDOC(TFIBLargeIntField * DocAllIDDOCOSN_HOT_GALLDOC)
{
Object->DocAllIDDOCOSN_HOT_GALLDOC=DocAllIDDOCOSN_HOT_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocRealImpl::get_DocAllIDSKLAD_HOT_GALLDOC(void)
{
return Object->DocAllIDSKLAD_HOT_GALLDOC;
}
//---------------------------------------------------------------
void THOT_DMDocRealImpl::set_DocAllIDSKLAD_HOT_GALLDOC(TFIBLargeIntField * DocAllIDSKLAD_HOT_GALLDOC)
{
Object->DocAllIDSKLAD_HOT_GALLDOC=DocAllIDSKLAD_HOT_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocRealImpl::get_DocAllIDBASE_HOT_GALLDOC(void)
{
return Object->DocAllIDBASE_HOT_GALLDOC;
}
//---------------------------------------------------------------
void THOT_DMDocRealImpl::set_DocAllIDBASE_HOT_GALLDOC(TFIBLargeIntField * DocAllIDBASE_HOT_GALLDOC)
{
Object->DocAllIDBASE_HOT_GALLDOC=DocAllIDBASE_HOT_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocRealImpl::get_DocID_HOT_DREAL(void)
{
return Object->DocID_HOT_DREAL;
}
//---------------------------------------------------------------
void THOT_DMDocRealImpl::set_DocID_HOT_DREAL(TFIBLargeIntField * DocID_HOT_DREAL)
{
Object->DocID_HOT_DREAL=DocID_HOT_DREAL;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocRealImpl::get_DocIDDOCH_HOT_DREAL(void)
{
return Object->DocIDDOCH_HOT_DREAL;
}
//---------------------------------------------------------------
void THOT_DMDocRealImpl::set_DocIDDOCH_HOT_DREAL(TFIBLargeIntField * DocIDDOCH_HOT_DREAL)
{
Object->DocIDDOCH_HOT_DREAL=DocIDDOCH_HOT_DREAL;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocRealImpl::get_DocIDBASE_HOT_DREAL(void)
{
return Object->DocIDBASE_HOT_DREAL;
}
//---------------------------------------------------------------
void THOT_DMDocRealImpl::set_DocIDBASE_HOT_DREAL(TFIBLargeIntField * DocIDBASE_HOT_DREAL)
{
Object->DocIDBASE_HOT_DREAL=DocIDBASE_HOT_DREAL;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocRealImpl::get_DocIDTPRICE_HOT_DREAL(void)
{
return Object->DocIDTPRICE_HOT_DREAL;
}
//---------------------------------------------------------------
void THOT_DMDocRealImpl::set_DocIDTPRICE_HOT_DREAL(TFIBLargeIntField * DocIDTPRICE_HOT_DREAL)
{
Object->DocIDTPRICE_HOT_DREAL=DocIDTPRICE_HOT_DREAL;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocRealImpl::get_DocTID_HOT_DREALT(void)
{
return Object->DocTID_HOT_DREALT;
}
//---------------------------------------------------------------
void THOT_DMDocRealImpl::set_DocTID_HOT_DREALT(TFIBLargeIntField * DocTID_HOT_DREALT)
{
Object->DocTID_HOT_DREALT=DocTID_HOT_DREALT;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocRealImpl::get_DocTIDDOCH_HOT_DREALT(void)
{
return Object->DocTIDDOCH_HOT_DREALT;
}
//---------------------------------------------------------------
void THOT_DMDocRealImpl::set_DocTIDDOCH_HOT_DREALT(TFIBLargeIntField * DocTIDDOCH_HOT_DREALT)
{
Object->DocTIDDOCH_HOT_DREALT=DocTIDDOCH_HOT_DREALT;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocRealImpl::get_DocTIDTPRICE_HOT_DREALT(void)
{
return Object->DocTIDTPRICE_HOT_DREALT;
}
//---------------------------------------------------------------
void THOT_DMDocRealImpl::set_DocTIDTPRICE_HOT_DREALT(TFIBLargeIntField * DocTIDTPRICE_HOT_DREALT)
{
Object->DocTIDTPRICE_HOT_DREALT=DocTIDTPRICE_HOT_DREALT;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocRealImpl::get_DocTIDNOM_HOT_DREALT(void)
{
return Object->DocTIDNOM_HOT_DREALT;
}
//---------------------------------------------------------------
void THOT_DMDocRealImpl::set_DocTIDNOM_HOT_DREALT(TFIBLargeIntField * DocTIDNOM_HOT_DREALT)
{
Object->DocTIDNOM_HOT_DREALT=DocTIDNOM_HOT_DREALT;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocRealImpl::get_DocTIDED_HOT_DREALT(void)
{
return Object->DocTIDED_HOT_DREALT;
}
//---------------------------------------------------------------
void THOT_DMDocRealImpl::set_DocTIDED_HOT_DREALT(TFIBLargeIntField * DocTIDED_HOT_DREALT)
{
Object->DocTIDED_HOT_DREALT=DocTIDED_HOT_DREALT;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocRealImpl::get_DocTIDNOMER_HOT_DREALT(void)
{
return Object->DocTIDNOMER_HOT_DREALT;
}
//---------------------------------------------------------------
void THOT_DMDocRealImpl::set_DocTIDNOMER_HOT_DREALT(TFIBLargeIntField * DocTIDNOMER_HOT_DREALT)
{
Object->DocTIDNOMER_HOT_DREALT=DocTIDNOMER_HOT_DREALT;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocRealImpl::get_DocTIDCAT_HOT_DREALT(void)
{
return Object->DocTIDCAT_HOT_DREALT;
}
//---------------------------------------------------------------
void THOT_DMDocRealImpl::set_DocTIDCAT_HOT_DREALT(TFIBLargeIntField * DocTIDCAT_HOT_DREALT)
{
Object->DocTIDCAT_HOT_DREALT=DocTIDCAT_HOT_DREALT;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocRealImpl::get_DocTIDGUEST_HOT_DREALT(void)
{
return Object->DocTIDGUEST_HOT_DREALT;
}
//---------------------------------------------------------------
void THOT_DMDocRealImpl::set_DocTIDGUEST_HOT_DREALT(TFIBLargeIntField * DocTIDGUEST_HOT_DREALT)
{
Object->DocTIDGUEST_HOT_DREALT=DocTIDGUEST_HOT_DREALT;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocRealImpl::get_DocTIDTPOS_HOT_DREALT(void)
{
return Object->DocTIDTPOS_HOT_DREALT;
}
//---------------------------------------------------------------
void THOT_DMDocRealImpl::set_DocTIDTPOS_HOT_DREALT(TFIBLargeIntField * DocTIDTPOS_HOT_DREALT)
{
Object->DocTIDTPOS_HOT_DREALT=DocTIDTPOS_HOT_DREALT;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocRealImpl::get_DocTIDBASE_HOT_DREALT(void)
{
return Object->DocTIDBASE_HOT_DREALT;
}
//---------------------------------------------------------------
void THOT_DMDocRealImpl::set_DocTIDBASE_HOT_DREALT(TFIBLargeIntField * DocTIDBASE_HOT_DREALT)
{
Object->DocTIDBASE_HOT_DREALT=DocTIDBASE_HOT_DREALT;
}
//---------------------------------------------------------------
bool THOT_DMDocRealImpl::get_Prosmotr(void)
{
return Object->Prosmotr;
}
//---------------------------------------------------------------
void THOT_DMDocRealImpl::set_Prosmotr(bool Prosmotr)
{
Object->Prosmotr=Prosmotr;
}
//---------------------------------------------------------------
bool THOT_DMDocRealImpl::get_NoEdit(void)
{
return Object->NoEdit;
}
//---------------------------------------------------------------
void THOT_DMDocRealImpl::set_NoEdit(bool NoEdit)
{
Object->NoEdit=NoEdit;
}
//---------------------------------------------------------------
bool THOT_DMDocRealImpl::get_Vibor(void)
{
return Object->Vibor;
}
//---------------------------------------------------------------
void THOT_DMDocRealImpl::set_Vibor(bool Vibor)
{
Object->Vibor=Vibor;
}
//---------------------------------------------------------------
void THOT_DMDocRealImpl::NewDoc(void)
{
return Object->NewDoc();
}
//---------------------------------------------------------------
void THOT_DMDocRealImpl::OpenDoc(__int64 IdDoc)
{
return Object->OpenDoc(IdDoc);
}
//---------------------------------------------------------------
bool THOT_DMDocRealImpl::SaveDoc(void)
{
return Object->SaveDoc();
}
//---------------------------------------------------------------
bool THOT_DMDocRealImpl::DvRegDoc(void)
{
return Object->DvRegDoc();
}
//---------------------------------------------------------------
bool THOT_DMDocRealImpl::CancelDvRegDoc(void)
{
return Object->CancelDvRegDoc();
}
//---------------------------------------------------------------
void THOT_DMDocRealImpl::AddDocNewString(void)
{
return Object->AddDocNewString();
}
//---------------------------------------------------------------
void THOT_DMDocRealImpl::DeleteStringDoc(void)
{
return Object->DeleteStringDoc();
}
//---------------------------------------------------------------
void THOT_DMDocRealImpl::CloseDoc(void)
{
return Object->CloseDoc();
}
//---------------------------------------------------------------
bool THOT_DMDocRealImpl::DeleteDoc(__int64 id)
{
return Object->DeleteDoc(id);
}
//---------------------------------------------------------------
void THOT_DMDocRealImpl::GetSpisokGuest(void)
{
return Object->GetSpisokGuest();
}
//---------------------------------------------------------------
double THOT_DMDocRealImpl::GetKolOsnUslugGuest(__int64 id_guest)
{
return Object->GetKolOsnUslugGuest(id_guest);
}
//---------------------------------------------------------------
double THOT_DMDocRealImpl::GetSumDopUslugGuest(__int64 id_guest)
{
return Object->GetSumDopUslugGuest(id_guest);
}
//---------------------------------------------------------------
