#include "vcl.h"
#pragma hdrstop


#include "UDMRegZakImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMRegZakImpl::TDMRegZakImpl()           
{                                            
Object=new TDMRegZak(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMRegZakImpl::~TDMRegZakImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMRegZakImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMRegZakImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMRegZak)                        
   {                                                                     
   *ppv=static_cast<IDMRegZak*> (this);                                
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
int TDMRegZakImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMRegZakImpl::kanRelease(void)                                  
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
int  TDMRegZakImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMRegZakImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMRegZakImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMRegZakImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMRegZakImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl);
kanRelease();
Object->ClsIdImpl=CLSID_TDMRegZakImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMRegZakImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMRegZak
TDataSource * TDMRegZakImpl::get_DataSourceDoc(void)
{
return Object->DataSourceDoc;
}
//---------------------------------------------------------------
void TDMRegZakImpl::set_DataSourceDoc(TDataSource * DataSourceDoc)
{
Object->DataSourceDoc=DataSourceDoc;
}
//---------------------------------------------------------------
TDataSource * TDMRegZakImpl::get_DataSourceDocT(void)
{
return Object->DataSourceDocT;
}
//---------------------------------------------------------------
void TDMRegZakImpl::set_DataSourceDocT(TDataSource * DataSourceDocT)
{
Object->DataSourceDocT=DataSourceDocT;
}
//---------------------------------------------------------------
TDataSource * TDMRegZakImpl::get_DataSourceOb(void)
{
return Object->DataSourceOb;
}
//---------------------------------------------------------------
void TDMRegZakImpl::set_DataSourceOb(TDataSource * DataSourceOb)
{
Object->DataSourceOb=DataSourceOb;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMRegZakImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMRegZakImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMRegZakImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMRegZakImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMRegZakImpl::get_Doc(void)
{
return Object->Doc;
}
//---------------------------------------------------------------
void TDMRegZakImpl::set_Doc(TpFIBDataSet * Doc)
{
Object->Doc=Doc;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegZakImpl::get_DocSUM_ZAK(void)
{
return Object->DocSUM_ZAK;
}
//---------------------------------------------------------------
void TDMRegZakImpl::set_DocSUM_ZAK(TFIBBCDField * DocSUM_ZAK)
{
Object->DocSUM_ZAK=DocSUM_ZAK;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMRegZakImpl::get_DocSOST_ZAK(void)
{
return Object->DocSOST_ZAK;
}
//---------------------------------------------------------------
void TDMRegZakImpl::set_DocSOST_ZAK(TFIBSmallIntField * DocSOST_ZAK)
{
Object->DocSOST_ZAK=DocSOST_ZAK;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMRegZakImpl::get_DocT(void)
{
return Object->DocT;
}
//---------------------------------------------------------------
void TDMRegZakImpl::set_DocT(TpFIBDataSet * DocT)
{
Object->DocT=DocT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegZakImpl::get_DocTKOLPR_ZAKT(void)
{
return Object->DocTKOLPR_ZAKT;
}
//---------------------------------------------------------------
void TDMRegZakImpl::set_DocTKOLPR_ZAKT(TFIBBCDField * DocTKOLPR_ZAKT)
{
Object->DocTKOLPR_ZAKT=DocTKOLPR_ZAKT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegZakImpl::get_DocTKOLOT_ZAKT(void)
{
return Object->DocTKOLOT_ZAKT;
}
//---------------------------------------------------------------
void TDMRegZakImpl::set_DocTKOLOT_ZAKT(TFIBBCDField * DocTKOLOT_ZAKT)
{
Object->DocTKOLOT_ZAKT=DocTKOLOT_ZAKT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegZakImpl::get_DocTKOLZ_ZAKT(void)
{
return Object->DocTKOLZ_ZAKT;
}
//---------------------------------------------------------------
void TDMRegZakImpl::set_DocTKOLZ_ZAKT(TFIBBCDField * DocTKOLZ_ZAKT)
{
Object->DocTKOLZ_ZAKT=DocTKOLZ_ZAKT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegZakImpl::get_DocTKF_ZAKT(void)
{
return Object->DocTKF_ZAKT;
}
//---------------------------------------------------------------
void TDMRegZakImpl::set_DocTKF_ZAKT(TFIBBCDField * DocTKF_ZAKT)
{
Object->DocTKF_ZAKT=DocTKF_ZAKT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegZakImpl::get_DocTPRICE_ZAKT(void)
{
return Object->DocTPRICE_ZAKT;
}
//---------------------------------------------------------------
void TDMRegZakImpl::set_DocTPRICE_ZAKT(TFIBBCDField * DocTPRICE_ZAKT)
{
Object->DocTPRICE_ZAKT=DocTPRICE_ZAKT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegZakImpl::get_DocTSUM_ZAKT(void)
{
return Object->DocTSUM_ZAKT;
}
//---------------------------------------------------------------
void TDMRegZakImpl::set_DocTSUM_ZAKT(TFIBBCDField * DocTSUM_ZAKT)
{
Object->DocTSUM_ZAKT=DocTSUM_ZAKT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegZakImpl::get_DocTOTKAZ_ZAKT(void)
{
return Object->DocTOTKAZ_ZAKT;
}
//---------------------------------------------------------------
void TDMRegZakImpl::set_DocTOTKAZ_ZAKT(TFIBBCDField * DocTOTKAZ_ZAKT)
{
Object->DocTOTKAZ_ZAKT=DocTOTKAZ_ZAKT;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMRegZakImpl::get_DocTTNOM(void)
{
return Object->DocTTNOM;
}
//---------------------------------------------------------------
void TDMRegZakImpl::set_DocTTNOM(TFIBIntegerField * DocTTNOM)
{
Object->DocTTNOM=DocTTNOM;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegZakImpl::get_DocTZNACH_PRICE(void)
{
return Object->DocTZNACH_PRICE;
}
//---------------------------------------------------------------
void TDMRegZakImpl::set_DocTZNACH_PRICE(TFIBBCDField * DocTZNACH_PRICE)
{
Object->DocTZNACH_PRICE=DocTZNACH_PRICE;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMRegZakImpl::get_Ob(void)
{
return Object->Ob;
}
//---------------------------------------------------------------
void TDMRegZakImpl::set_Ob(TpFIBDataSet * Ob)
{
Object->Ob=Ob;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMRegZakImpl::get_ObGRP_STROB(void)
{
return Object->ObGRP_STROB;
}
//---------------------------------------------------------------
void TDMRegZakImpl::set_ObGRP_STROB(TFIBSmallIntField * ObGRP_STROB)
{
Object->ObGRP_STROB=ObGRP_STROB;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMRegZakImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMRegZakImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegZakImpl::get_TableSUM_ZAK(void)
{
return Object->TableSUM_ZAK;
}
//---------------------------------------------------------------
void TDMRegZakImpl::set_TableSUM_ZAK(TFIBBCDField * TableSUM_ZAK)
{
Object->TableSUM_ZAK=TableSUM_ZAK;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMRegZakImpl::get_TableSOST_ZAK(void)
{
return Object->TableSOST_ZAK;
}
//---------------------------------------------------------------
void TDMRegZakImpl::set_TableSOST_ZAK(TFIBSmallIntField * TableSOST_ZAK)
{
Object->TableSOST_ZAK=TableSOST_ZAK;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMRegZakImpl::get_IBQPrint(void)
{
return Object->IBQPrint;
}
//---------------------------------------------------------------
void TDMRegZakImpl::set_IBQPrint(TpFIBDataSet * IBQPrint)
{
Object->IBQPrint=IBQPrint;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMRegZakImpl::get_IBQMPrig(void)
{
return Object->IBQMPrig;
}
//---------------------------------------------------------------
void TDMRegZakImpl::set_IBQMPrig(TpFIBDataSet * IBQMPrig)
{
Object->IBQMPrig=IBQMPrig;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMRegZakImpl::get_IBQNom(void)
{
return Object->IBQNom;
}
//---------------------------------------------------------------
void TDMRegZakImpl::set_IBQNom(TpFIBDataSet * IBQNom)
{
Object->IBQNom=IBQNom;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegZakImpl::get_IBQPrintKF_ZAKT(void)
{
return Object->IBQPrintKF_ZAKT;
}
//---------------------------------------------------------------
void TDMRegZakImpl::set_IBQPrintKF_ZAKT(TFIBBCDField * IBQPrintKF_ZAKT)
{
Object->IBQPrintKF_ZAKT=IBQPrintKF_ZAKT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegZakImpl::get_IBQPrintKOLZ_ZAKT(void)
{
return Object->IBQPrintKOLZ_ZAKT;
}
//---------------------------------------------------------------
void TDMRegZakImpl::set_IBQPrintKOLZ_ZAKT(TFIBBCDField * IBQPrintKOLZ_ZAKT)
{
Object->IBQPrintKOLZ_ZAKT=IBQPrintKOLZ_ZAKT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegZakImpl::get_IBQPrintKOLPR_ZAKT(void)
{
return Object->IBQPrintKOLPR_ZAKT;
}
//---------------------------------------------------------------
void TDMRegZakImpl::set_IBQPrintKOLPR_ZAKT(TFIBBCDField * IBQPrintKOLPR_ZAKT)
{
Object->IBQPrintKOLPR_ZAKT=IBQPrintKOLPR_ZAKT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegZakImpl::get_IBQPrintOTKAZ_ZAKT(void)
{
return Object->IBQPrintOTKAZ_ZAKT;
}
//---------------------------------------------------------------
void TDMRegZakImpl::set_IBQPrintOTKAZ_ZAKT(TFIBBCDField * IBQPrintOTKAZ_ZAKT)
{
Object->IBQPrintOTKAZ_ZAKT=IBQPrintOTKAZ_ZAKT;
}
//---------------------------------------------------------------
TIntegerField * TDMRegZakImpl::get_DocTRECNO(void)
{
return Object->DocTRECNO;
}
//---------------------------------------------------------------
void TDMRegZakImpl::set_DocTRECNO(TIntegerField * DocTRECNO)
{
Object->DocTRECNO=DocTRECNO;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegZakImpl::get_IBQPrintID_ZAKT(void)
{
return Object->IBQPrintID_ZAKT;
}
//---------------------------------------------------------------
void TDMRegZakImpl::set_IBQPrintID_ZAKT(TFIBBCDField * IBQPrintID_ZAKT)
{
Object->IBQPrintID_ZAKT=IBQPrintID_ZAKT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegZakImpl::get_IBQPrintIDMPRIG_ZAKT(void)
{
return Object->IBQPrintIDMPRIG_ZAKT;
}
//---------------------------------------------------------------
void TDMRegZakImpl::set_IBQPrintIDMPRIG_ZAKT(TFIBBCDField * IBQPrintIDMPRIG_ZAKT)
{
Object->IBQPrintIDMPRIG_ZAKT=IBQPrintIDMPRIG_ZAKT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegZakImpl::get_TableID_ZAK(void)
{
return Object->TableID_ZAK;
}
//---------------------------------------------------------------
void TDMRegZakImpl::set_TableID_ZAK(TFIBBCDField * TableID_ZAK)
{
Object->TableID_ZAK=TableID_ZAK;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegZakImpl::get_TableIDOB_ZAK(void)
{
return Object->TableIDOB_ZAK;
}
//---------------------------------------------------------------
void TDMRegZakImpl::set_TableIDOB_ZAK(TFIBBCDField * TableIDOB_ZAK)
{
Object->TableIDOB_ZAK=TableIDOB_ZAK;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegZakImpl::get_TableIDKLIENT_ZAK(void)
{
return Object->TableIDKLIENT_ZAK;
}
//---------------------------------------------------------------
void TDMRegZakImpl::set_TableIDKLIENT_ZAK(TFIBBCDField * TableIDKLIENT_ZAK)
{
Object->TableIDKLIENT_ZAK=TableIDKLIENT_ZAK;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegZakImpl::get_TableIDUSER_ZAK(void)
{
return Object->TableIDUSER_ZAK;
}
//---------------------------------------------------------------
void TDMRegZakImpl::set_TableIDUSER_ZAK(TFIBBCDField * TableIDUSER_ZAK)
{
Object->TableIDUSER_ZAK=TableIDUSER_ZAK;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegZakImpl::get_DocID_ZAK(void)
{
return Object->DocID_ZAK;
}
//---------------------------------------------------------------
void TDMRegZakImpl::set_DocID_ZAK(TFIBBCDField * DocID_ZAK)
{
Object->DocID_ZAK=DocID_ZAK;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegZakImpl::get_DocIDOB_ZAK(void)
{
return Object->DocIDOB_ZAK;
}
//---------------------------------------------------------------
void TDMRegZakImpl::set_DocIDOB_ZAK(TFIBBCDField * DocIDOB_ZAK)
{
Object->DocIDOB_ZAK=DocIDOB_ZAK;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegZakImpl::get_DocIDKLIENT_ZAK(void)
{
return Object->DocIDKLIENT_ZAK;
}
//---------------------------------------------------------------
void TDMRegZakImpl::set_DocIDKLIENT_ZAK(TFIBBCDField * DocIDKLIENT_ZAK)
{
Object->DocIDKLIENT_ZAK=DocIDKLIENT_ZAK;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegZakImpl::get_DocIDUSER_ZAK(void)
{
return Object->DocIDUSER_ZAK;
}
//---------------------------------------------------------------
void TDMRegZakImpl::set_DocIDUSER_ZAK(TFIBBCDField * DocIDUSER_ZAK)
{
Object->DocIDUSER_ZAK=DocIDUSER_ZAK;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegZakImpl::get_DocIDKLIENT(void)
{
return Object->DocIDKLIENT;
}
//---------------------------------------------------------------
void TDMRegZakImpl::set_DocIDKLIENT(TFIBBCDField * DocIDKLIENT)
{
Object->DocIDKLIENT=DocIDKLIENT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegZakImpl::get_DocIDTYPEPRICE_ZAK(void)
{
return Object->DocIDTYPEPRICE_ZAK;
}
//---------------------------------------------------------------
void TDMRegZakImpl::set_DocIDTYPEPRICE_ZAK(TFIBBCDField * DocIDTYPEPRICE_ZAK)
{
Object->DocIDTYPEPRICE_ZAK=DocIDTYPEPRICE_ZAK;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegZakImpl::get_DocIDDISCOUNTCARD_ZAK(void)
{
return Object->DocIDDISCOUNTCARD_ZAK;
}
//---------------------------------------------------------------
void TDMRegZakImpl::set_DocIDDISCOUNTCARD_ZAK(TFIBBCDField * DocIDDISCOUNTCARD_ZAK)
{
Object->DocIDDISCOUNTCARD_ZAK=DocIDDISCOUNTCARD_ZAK;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegZakImpl::get_DocTPRSK_ZAKT(void)
{
return Object->DocTPRSK_ZAKT;
}
//---------------------------------------------------------------
void TDMRegZakImpl::set_DocTPRSK_ZAKT(TFIBBCDField * DocTPRSK_ZAKT)
{
Object->DocTPRSK_ZAKT=DocTPRSK_ZAKT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegZakImpl::get_DocTPRNAD_ZAKT(void)
{
return Object->DocTPRNAD_ZAKT;
}
//---------------------------------------------------------------
void TDMRegZakImpl::set_DocTPRNAD_ZAKT(TFIBBCDField * DocTPRNAD_ZAKT)
{
Object->DocTPRNAD_ZAKT=DocTPRNAD_ZAKT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegZakImpl::get_DocTSUMSK_ZAKT(void)
{
return Object->DocTSUMSK_ZAKT;
}
//---------------------------------------------------------------
void TDMRegZakImpl::set_DocTSUMSK_ZAKT(TFIBBCDField * DocTSUMSK_ZAKT)
{
Object->DocTSUMSK_ZAKT=DocTSUMSK_ZAKT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegZakImpl::get_DocTSUMNAD_ZAKT(void)
{
return Object->DocTSUMNAD_ZAKT;
}
//---------------------------------------------------------------
void TDMRegZakImpl::set_DocTSUMNAD_ZAKT(TFIBBCDField * DocTSUMNAD_ZAKT)
{
Object->DocTSUMNAD_ZAKT=DocTSUMNAD_ZAKT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegZakImpl::get_ObID_STROB(void)
{
return Object->ObID_STROB;
}
//---------------------------------------------------------------
void TDMRegZakImpl::set_ObID_STROB(TFIBBCDField * ObID_STROB)
{
Object->ObID_STROB=ObID_STROB;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegZakImpl::get_ObIDGRP_STROB(void)
{
return Object->ObIDGRP_STROB;
}
//---------------------------------------------------------------
void TDMRegZakImpl::set_ObIDGRP_STROB(TFIBBCDField * ObIDGRP_STROB)
{
Object->ObIDGRP_STROB=ObIDGRP_STROB;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegZakImpl::get_DocTID_ZAKT(void)
{
return Object->DocTID_ZAKT;
}
//---------------------------------------------------------------
void TDMRegZakImpl::set_DocTID_ZAKT(TFIBBCDField * DocTID_ZAKT)
{
Object->DocTID_ZAKT=DocTID_ZAKT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegZakImpl::get_DocTIDZ_ZAKT(void)
{
return Object->DocTIDZ_ZAKT;
}
//---------------------------------------------------------------
void TDMRegZakImpl::set_DocTIDZ_ZAKT(TFIBBCDField * DocTIDZ_ZAKT)
{
Object->DocTIDZ_ZAKT=DocTIDZ_ZAKT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegZakImpl::get_DocTIDNOM_ZAKT(void)
{
return Object->DocTIDNOM_ZAKT;
}
//---------------------------------------------------------------
void TDMRegZakImpl::set_DocTIDNOM_ZAKT(TFIBBCDField * DocTIDNOM_ZAKT)
{
Object->DocTIDNOM_ZAKT=DocTIDNOM_ZAKT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegZakImpl::get_DocTIDED_ZAKT(void)
{
return Object->DocTIDED_ZAKT;
}
//---------------------------------------------------------------
void TDMRegZakImpl::set_DocTIDED_ZAKT(TFIBBCDField * DocTIDED_ZAKT)
{
Object->DocTIDED_ZAKT=DocTIDED_ZAKT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegZakImpl::get_DocTIDMPRIG_ZAKT(void)
{
return Object->DocTIDMPRIG_ZAKT;
}
//---------------------------------------------------------------
void TDMRegZakImpl::set_DocTIDMPRIG_ZAKT(TFIBBCDField * DocTIDMPRIG_ZAKT)
{
Object->DocTIDMPRIG_ZAKT=DocTIDMPRIG_ZAKT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegZakImpl::get_DocTIDBASE_RGZAKT(void)
{
return Object->DocTIDBASE_RGZAKT;
}
//---------------------------------------------------------------
void TDMRegZakImpl::set_DocTIDBASE_RGZAKT(TFIBBCDField * DocTIDBASE_RGZAKT)
{
Object->DocTIDBASE_RGZAKT=DocTIDBASE_RGZAKT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegZakImpl::get_DocTPRSK_CARD_RGZAKT(void)
{
return Object->DocTPRSK_CARD_RGZAKT;
}
//---------------------------------------------------------------
void TDMRegZakImpl::set_DocTPRSK_CARD_RGZAKT(TFIBBCDField * DocTPRSK_CARD_RGZAKT)
{
Object->DocTPRSK_CARD_RGZAKT=DocTPRSK_CARD_RGZAKT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegZakImpl::get_DocTPRSK_AUTO_RGZAKT(void)
{
return Object->DocTPRSK_AUTO_RGZAKT;
}
//---------------------------------------------------------------
void TDMRegZakImpl::set_DocTPRSK_AUTO_RGZAKT(TFIBBCDField * DocTPRSK_AUTO_RGZAKT)
{
Object->DocTPRSK_AUTO_RGZAKT=DocTPRSK_AUTO_RGZAKT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMRegZakImpl::get_IBQPrintKRNAMENOM(void)
{
return Object->IBQPrintKRNAMENOM;
}
//---------------------------------------------------------------
void TDMRegZakImpl::set_IBQPrintKRNAMENOM(TFIBWideStringField * IBQPrintKRNAMENOM)
{
Object->IBQPrintKRNAMENOM=IBQPrintKRNAMENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMRegZakImpl::get_IBQPrintNAMEED(void)
{
return Object->IBQPrintNAMEED;
}
//---------------------------------------------------------------
void TDMRegZakImpl::set_IBQPrintNAMEED(TFIBWideStringField * IBQPrintNAMEED)
{
Object->IBQPrintNAMEED=IBQPrintNAMEED;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMRegZakImpl::get_IBQMPrigNAME_MPRIG(void)
{
return Object->IBQMPrigNAME_MPRIG;
}
//---------------------------------------------------------------
void TDMRegZakImpl::set_IBQMPrigNAME_MPRIG(TFIBWideStringField * IBQMPrigNAME_MPRIG)
{
Object->IBQMPrigNAME_MPRIG=IBQMPrigNAME_MPRIG;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMRegZakImpl::get_IBQMPrigCOMPNAME_OBORUD(void)
{
return Object->IBQMPrigCOMPNAME_OBORUD;
}
//---------------------------------------------------------------
void TDMRegZakImpl::set_IBQMPrigCOMPNAME_OBORUD(TFIBWideStringField * IBQMPrigCOMPNAME_OBORUD)
{
Object->IBQMPrigCOMPNAME_OBORUD=IBQMPrigCOMPNAME_OBORUD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMRegZakImpl::get_IBQMPrigCOMNAME_OBORUD(void)
{
return Object->IBQMPrigCOMNAME_OBORUD;
}
//---------------------------------------------------------------
void TDMRegZakImpl::set_IBQMPrigCOMNAME_OBORUD(TFIBWideStringField * IBQMPrigCOMNAME_OBORUD)
{
Object->IBQMPrigCOMNAME_OBORUD=IBQMPrigCOMNAME_OBORUD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMRegZakImpl::get_IBQMPrigBAUDRATE_OBORUD(void)
{
return Object->IBQMPrigBAUDRATE_OBORUD;
}
//---------------------------------------------------------------
void TDMRegZakImpl::set_IBQMPrigBAUDRATE_OBORUD(TFIBWideStringField * IBQMPrigBAUDRATE_OBORUD)
{
Object->IBQMPrigBAUDRATE_OBORUD=IBQMPrigBAUDRATE_OBORUD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMRegZakImpl::get_IBQNomNAME_MPRIG(void)
{
return Object->IBQNomNAME_MPRIG;
}
//---------------------------------------------------------------
void TDMRegZakImpl::set_IBQNomNAME_MPRIG(TFIBWideStringField * IBQNomNAME_MPRIG)
{
Object->IBQNomNAME_MPRIG=IBQNomNAME_MPRIG;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMRegZakImpl::get_ObNAME_STROB(void)
{
return Object->ObNAME_STROB;
}
//---------------------------------------------------------------
void TDMRegZakImpl::set_ObNAME_STROB(TFIBWideStringField * ObNAME_STROB)
{
Object->ObNAME_STROB=ObNAME_STROB;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMRegZakImpl::get_ObCODE_STROB(void)
{
return Object->ObCODE_STROB;
}
//---------------------------------------------------------------
void TDMRegZakImpl::set_ObCODE_STROB(TFIBIntegerField * ObCODE_STROB)
{
Object->ObCODE_STROB=ObCODE_STROB;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMRegZakImpl::get_ObGID_SSTROB(void)
{
return Object->ObGID_SSTROB;
}
//---------------------------------------------------------------
void TDMRegZakImpl::set_ObGID_SSTROB(TFIBWideStringField * ObGID_SSTROB)
{
Object->ObGID_SSTROB=ObGID_SSTROB;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMRegZakImpl::get_DocTNAMENOM(void)
{
return Object->DocTNAMENOM;
}
//---------------------------------------------------------------
void TDMRegZakImpl::set_DocTNAMENOM(TFIBWideStringField * DocTNAMENOM)
{
Object->DocTNAMENOM=DocTNAMENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMRegZakImpl::get_DocTKRNAMENOM(void)
{
return Object->DocTKRNAMENOM;
}
//---------------------------------------------------------------
void TDMRegZakImpl::set_DocTKRNAMENOM(TFIBWideStringField * DocTKRNAMENOM)
{
Object->DocTKRNAMENOM=DocTKRNAMENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMRegZakImpl::get_DocTNAMEED(void)
{
return Object->DocTNAMEED;
}
//---------------------------------------------------------------
void TDMRegZakImpl::set_DocTNAMEED(TFIBWideStringField * DocTNAMEED)
{
Object->DocTNAMEED=DocTNAMEED;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMRegZakImpl::get_DocTNAME_MPRIG(void)
{
return Object->DocTNAME_MPRIG;
}
//---------------------------------------------------------------
void TDMRegZakImpl::set_DocTNAME_MPRIG(TFIBWideStringField * DocTNAME_MPRIG)
{
Object->DocTNAME_MPRIG=DocTNAME_MPRIG;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMRegZakImpl::get_DocNAME_STROB(void)
{
return Object->DocNAME_STROB;
}
//---------------------------------------------------------------
void TDMRegZakImpl::set_DocNAME_STROB(TFIBWideStringField * DocNAME_STROB)
{
Object->DocNAME_STROB=DocNAME_STROB;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMRegZakImpl::get_DocNAMEKLIENT(void)
{
return Object->DocNAMEKLIENT;
}
//---------------------------------------------------------------
void TDMRegZakImpl::set_DocNAMEKLIENT(TFIBWideStringField * DocNAMEKLIENT)
{
Object->DocNAMEKLIENT=DocNAMEKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMRegZakImpl::get_DocNAME_USER(void)
{
return Object->DocNAME_USER;
}
//---------------------------------------------------------------
void TDMRegZakImpl::set_DocNAME_USER(TFIBWideStringField * DocNAME_USER)
{
Object->DocNAME_USER=DocNAME_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMRegZakImpl::get_DocNAME_TPRICE(void)
{
return Object->DocNAME_TPRICE;
}
//---------------------------------------------------------------
void TDMRegZakImpl::set_DocNAME_TPRICE(TFIBWideStringField * DocNAME_TPRICE)
{
Object->DocNAME_TPRICE=DocNAME_TPRICE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMRegZakImpl::get_DocNAME_SDISCOUNT_CARD(void)
{
return Object->DocNAME_SDISCOUNT_CARD;
}
//---------------------------------------------------------------
void TDMRegZakImpl::set_DocNAME_SDISCOUNT_CARD(TFIBWideStringField * DocNAME_SDISCOUNT_CARD)
{
Object->DocNAME_SDISCOUNT_CARD=DocNAME_SDISCOUNT_CARD;
}
//---------------------------------------------------------------
bool TDMRegZakImpl::get_Prosmotr(void)
{
return Object->Prosmotr;
}
//---------------------------------------------------------------
void TDMRegZakImpl::set_Prosmotr(bool Prosmotr)
{
Object->Prosmotr=Prosmotr;
}
//---------------------------------------------------------------
__int64 TDMRegZakImpl::get_IdDoc(void)
{
return Object->IdDoc;
}
//---------------------------------------------------------------
void TDMRegZakImpl::set_IdDoc(__int64 IdDoc)
{
Object->IdDoc=IdDoc;
}
//---------------------------------------------------------------
__int64 TDMRegZakImpl::get_IdOb(void)
{
return Object->IdOb;
}
//---------------------------------------------------------------
void TDMRegZakImpl::set_IdOb(__int64 IdOb)
{
Object->IdOb=IdOb;
}
//---------------------------------------------------------------
__int64 TDMRegZakImpl::get_IdTypePrice(void)
{
return Object->IdTypePrice;
}
//---------------------------------------------------------------
void TDMRegZakImpl::set_IdTypePrice(__int64 IdTypePrice)
{
Object->IdTypePrice=IdTypePrice;
}
//---------------------------------------------------------------
void TDMRegZakImpl::NewDoc(__int64 ob)
{
return Object->NewDoc(ob);
}
//---------------------------------------------------------------
void TDMRegZakImpl::OpenDoc(__int64 id)
{
return Object->OpenDoc(id);
}
//---------------------------------------------------------------
bool TDMRegZakImpl::SaveDoc(void)
{
return Object->SaveDoc();
}
//---------------------------------------------------------------
void TDMRegZakImpl::CloseDoc(void)
{
return Object->CloseDoc();
}
//---------------------------------------------------------------
void TDMRegZakImpl::AddDocNewString(void)
{
return Object->AddDocNewString();
}
//---------------------------------------------------------------
void TDMRegZakImpl::DeleteStringDoc(void)
{
return Object->DeleteStringDoc();
}
//---------------------------------------------------------------
bool TDMRegZakImpl::DeleteDoc(__int64 id)
{
return Object->DeleteDoc(id);
}
//---------------------------------------------------------------
void TDMRegZakImpl::OpenMPrig(void)
{
return Object->OpenMPrig();
}
//---------------------------------------------------------------
