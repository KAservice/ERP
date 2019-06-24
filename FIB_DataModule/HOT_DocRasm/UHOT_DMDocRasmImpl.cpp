#include "vcl.h"
#pragma hdrstop


#include "UHOT_DMDocRasmImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
THOT_DMDocRasmImpl::THOT_DMDocRasmImpl()           
{                                            
Object=new THOT_DMDocRasm(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
THOT_DMDocRasmImpl::~THOT_DMDocRasmImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void THOT_DMDocRasmImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int THOT_DMDocRasmImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IHOT_DMDocRasm)                        
   {                                                                     
   *ppv=static_cast<IHOT_DMDocRasm*> (this);                                
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
int THOT_DMDocRasmImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int THOT_DMDocRasmImpl::kanRelease(void)                                  
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
int  THOT_DMDocRasmImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void THOT_DMDocRasmImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  THOT_DMDocRasmImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void THOT_DMDocRasmImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int THOT_DMDocRasmImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl);
kanRelease();
Object->ClsIdImpl=CLSID_THOT_DMDocRasmImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int THOT_DMDocRasmImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IHOT_DMDocRasm
TDataSource * THOT_DMDocRasmImpl::get_DataSourceDoc(void)
{
return Object->DataSourceDoc;
}
//---------------------------------------------------------------
void THOT_DMDocRasmImpl::set_DataSourceDoc(TDataSource * DataSourceDoc)
{
Object->DataSourceDoc=DataSourceDoc;
}
//---------------------------------------------------------------
TDataSource * THOT_DMDocRasmImpl::get_DataSourceDocAll(void)
{
return Object->DataSourceDocAll;
}
//---------------------------------------------------------------
void THOT_DMDocRasmImpl::set_DataSourceDocAll(TDataSource * DataSourceDocAll)
{
Object->DataSourceDocAll=DataSourceDocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * THOT_DMDocRasmImpl::get_DocAll(void)
{
return Object->DocAll;
}
//---------------------------------------------------------------
void THOT_DMDocRasmImpl::set_DocAll(TpFIBDataSet * DocAll)
{
Object->DocAll=DocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * THOT_DMDocRasmImpl::get_Doc(void)
{
return Object->Doc;
}
//---------------------------------------------------------------
void THOT_DMDocRasmImpl::set_Doc(TpFIBDataSet * Doc)
{
Object->Doc=Doc;
}
//---------------------------------------------------------------
TpFIBDataSet * THOT_DMDocRasmImpl::get_NumDoc(void)
{
return Object->NumDoc;
}
//---------------------------------------------------------------
void THOT_DMDocRasmImpl::set_NumDoc(TpFIBDataSet * NumDoc)
{
Object->NumDoc=NumDoc;
}
//---------------------------------------------------------------
TFIBIntegerField * THOT_DMDocRasmImpl::get_NumDocMAXNUMBER(void)
{
return Object->NumDocMAXNUMBER;
}
//---------------------------------------------------------------
void THOT_DMDocRasmImpl::set_NumDocMAXNUMBER(TFIBIntegerField * NumDocMAXNUMBER)
{
Object->NumDocMAXNUMBER=NumDocMAXNUMBER;
}
//---------------------------------------------------------------
TFIBDateTimeField * THOT_DMDocRasmImpl::get_DocAllPOS_HOT_GALLDOC(void)
{
return Object->DocAllPOS_HOT_GALLDOC;
}
//---------------------------------------------------------------
void THOT_DMDocRasmImpl::set_DocAllPOS_HOT_GALLDOC(TFIBDateTimeField * DocAllPOS_HOT_GALLDOC)
{
Object->DocAllPOS_HOT_GALLDOC=DocAllPOS_HOT_GALLDOC;
}
//---------------------------------------------------------------
TFIBSmallIntField * THOT_DMDocRasmImpl::get_DocAllPR_HOT_GALLDOC(void)
{
return Object->DocAllPR_HOT_GALLDOC;
}
//---------------------------------------------------------------
void THOT_DMDocRasmImpl::set_DocAllPR_HOT_GALLDOC(TFIBSmallIntField * DocAllPR_HOT_GALLDOC)
{
Object->DocAllPR_HOT_GALLDOC=DocAllPR_HOT_GALLDOC;
}
//---------------------------------------------------------------
TFIBBCDField * THOT_DMDocRasmImpl::get_DocAllSUM_HOT_GALLDOC(void)
{
return Object->DocAllSUM_HOT_GALLDOC;
}
//---------------------------------------------------------------
void THOT_DMDocRasmImpl::set_DocAllSUM_HOT_GALLDOC(TFIBBCDField * DocAllSUM_HOT_GALLDOC)
{
Object->DocAllSUM_HOT_GALLDOC=DocAllSUM_HOT_GALLDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * THOT_DMDocRasmImpl::get_DocAllNUMBER_HOT_GALLDOC(void)
{
return Object->DocAllNUMBER_HOT_GALLDOC;
}
//---------------------------------------------------------------
void THOT_DMDocRasmImpl::set_DocAllNUMBER_HOT_GALLDOC(TFIBIntegerField * DocAllNUMBER_HOT_GALLDOC)
{
Object->DocAllNUMBER_HOT_GALLDOC=DocAllNUMBER_HOT_GALLDOC;
}
//---------------------------------------------------------------
TpFIBQuery * THOT_DMDocRasmImpl::get_QueryDvReg(void)
{
return Object->QueryDvReg;
}
//---------------------------------------------------------------
void THOT_DMDocRasmImpl::set_QueryDvReg(TpFIBQuery * QueryDvReg)
{
Object->QueryDvReg=QueryDvReg;
}
//---------------------------------------------------------------
TpFIBQuery * THOT_DMDocRasmImpl::get_QueryCancelDvReg(void)
{
return Object->QueryCancelDvReg;
}
//---------------------------------------------------------------
void THOT_DMDocRasmImpl::set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg)
{
Object->QueryCancelDvReg=QueryCancelDvReg;
}
//---------------------------------------------------------------
TpFIBDataSet * THOT_DMDocRasmImpl::get_DocT(void)
{
return Object->DocT;
}
//---------------------------------------------------------------
void THOT_DMDocRasmImpl::set_DocT(TpFIBDataSet * DocT)
{
Object->DocT=DocT;
}
//---------------------------------------------------------------
TDataSource * THOT_DMDocRasmImpl::get_DataSourceDocT(void)
{
return Object->DataSourceDocT;
}
//---------------------------------------------------------------
void THOT_DMDocRasmImpl::set_DataSourceDocT(TDataSource * DataSourceDocT)
{
Object->DataSourceDocT=DataSourceDocT;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMDocRasmImpl::get_DocAllTDOC_HOT_GALLDOC(void)
{
return Object->DocAllTDOC_HOT_GALLDOC;
}
//---------------------------------------------------------------
void THOT_DMDocRasmImpl::set_DocAllTDOC_HOT_GALLDOC(TFIBWideStringField * DocAllTDOC_HOT_GALLDOC)
{
Object->DocAllTDOC_HOT_GALLDOC=DocAllTDOC_HOT_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMDocRasmImpl::get_DocAllFNAME_USER(void)
{
return Object->DocAllFNAME_USER;
}
//---------------------------------------------------------------
void THOT_DMDocRasmImpl::set_DocAllFNAME_USER(TFIBWideStringField * DocAllFNAME_USER)
{
Object->DocAllFNAME_USER=DocAllFNAME_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMDocRasmImpl::get_DocAllNAME_SINFBASE_OBMEN(void)
{
return Object->DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void THOT_DMDocRasmImpl::set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN)
{
Object->DocAllNAME_SINFBASE_OBMEN=DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMDocRasmImpl::get_DocAllNAMEFIRM(void)
{
return Object->DocAllNAMEFIRM;
}
//---------------------------------------------------------------
void THOT_DMDocRasmImpl::set_DocAllNAMEFIRM(TFIBWideStringField * DocAllNAMEFIRM)
{
Object->DocAllNAMEFIRM=DocAllNAMEFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMDocRasmImpl::get_DocAllNAMEKLIENT(void)
{
return Object->DocAllNAMEKLIENT;
}
//---------------------------------------------------------------
void THOT_DMDocRasmImpl::set_DocAllNAMEKLIENT(TFIBWideStringField * DocAllNAMEKLIENT)
{
Object->DocAllNAMEKLIENT=DocAllNAMEKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMDocRasmImpl::get_DocDESCR_HOT_DRASM(void)
{
return Object->DocDESCR_HOT_DRASM;
}
//---------------------------------------------------------------
void THOT_DMDocRasmImpl::set_DocDESCR_HOT_DRASM(TFIBWideStringField * DocDESCR_HOT_DRASM)
{
Object->DocDESCR_HOT_DRASM=DocDESCR_HOT_DRASM;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMDocRasmImpl::get_DocORG_HOT_DRASM(void)
{
return Object->DocORG_HOT_DRASM;
}
//---------------------------------------------------------------
void THOT_DMDocRasmImpl::set_DocORG_HOT_DRASM(TFIBWideStringField * DocORG_HOT_DRASM)
{
Object->DocORG_HOT_DRASM=DocORG_HOT_DRASM;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMDocRasmImpl::get_DocNAME_HOT_SCELPR(void)
{
return Object->DocNAME_HOT_SCELPR;
}
//---------------------------------------------------------------
void THOT_DMDocRasmImpl::set_DocNAME_HOT_SCELPR(TFIBWideStringField * DocNAME_HOT_SCELPR)
{
Object->DocNAME_HOT_SCELPR=DocNAME_HOT_SCELPR;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMDocRasmImpl::get_DocTBR_NAME_HOT_SNF(void)
{
return Object->DocTBR_NAME_HOT_SNF;
}
//---------------------------------------------------------------
void THOT_DMDocRasmImpl::set_DocTBR_NAME_HOT_SNF(TFIBWideStringField * DocTBR_NAME_HOT_SNF)
{
Object->DocTBR_NAME_HOT_SNF=DocTBR_NAME_HOT_SNF;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMDocRasmImpl::get_DocTBR_NAME_HOT_SCATNOM(void)
{
return Object->DocTBR_NAME_HOT_SCATNOM;
}
//---------------------------------------------------------------
void THOT_DMDocRasmImpl::set_DocTBR_NAME_HOT_SCATNOM(TFIBWideStringField * DocTBR_NAME_HOT_SCATNOM)
{
Object->DocTBR_NAME_HOT_SCATNOM=DocTBR_NAME_HOT_SCATNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMDocRasmImpl::get_DocTBR_NAME_HOT_STYPEPOS(void)
{
return Object->DocTBR_NAME_HOT_STYPEPOS;
}
//---------------------------------------------------------------
void THOT_DMDocRasmImpl::set_DocTBR_NAME_HOT_STYPEPOS(TFIBWideStringField * DocTBR_NAME_HOT_STYPEPOS)
{
Object->DocTBR_NAME_HOT_STYPEPOS=DocTBR_NAME_HOT_STYPEPOS;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMDocRasmImpl::get_DocTBR_NAMEGUEST(void)
{
return Object->DocTBR_NAMEGUEST;
}
//---------------------------------------------------------------
void THOT_DMDocRasmImpl::set_DocTBR_NAMEGUEST(TFIBWideStringField * DocTBR_NAMEGUEST)
{
Object->DocTBR_NAMEGUEST=DocTBR_NAMEGUEST;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMDocRasmImpl::get_DocTBR_NAME_HOT_SSOSTNOM(void)
{
return Object->DocTBR_NAME_HOT_SSOSTNOM;
}
//---------------------------------------------------------------
void THOT_DMDocRasmImpl::set_DocTBR_NAME_HOT_SSOSTNOM(TFIBWideStringField * DocTBR_NAME_HOT_SSOSTNOM)
{
Object->DocTBR_NAME_HOT_SSOSTNOM=DocTBR_NAME_HOT_SSOSTNOM;
}
//---------------------------------------------------------------
TFIBDateTimeField * THOT_DMDocRasmImpl::get_DocTBR_POSNACH_HOT_SOSTNF(void)
{
return Object->DocTBR_POSNACH_HOT_SOSTNF;
}
//---------------------------------------------------------------
void THOT_DMDocRasmImpl::set_DocTBR_POSNACH_HOT_SOSTNF(TFIBDateTimeField * DocTBR_POSNACH_HOT_SOSTNF)
{
Object->DocTBR_POSNACH_HOT_SOSTNF=DocTBR_POSNACH_HOT_SOSTNF;
}
//---------------------------------------------------------------
TFIBDateTimeField * THOT_DMDocRasmImpl::get_DocTBR_POSCON_HOT_SOSTNF(void)
{
return Object->DocTBR_POSCON_HOT_SOSTNF;
}
//---------------------------------------------------------------
void THOT_DMDocRasmImpl::set_DocTBR_POSCON_HOT_SOSTNF(TFIBDateTimeField * DocTBR_POSCON_HOT_SOSTNF)
{
Object->DocTBR_POSCON_HOT_SOSTNF=DocTBR_POSCON_HOT_SOSTNF;
}
//---------------------------------------------------------------
TFIBIntegerField * THOT_DMDocRasmImpl::get_DocTBR_KOLM_HOT_SOSTNF(void)
{
return Object->DocTBR_KOLM_HOT_SOSTNF;
}
//---------------------------------------------------------------
void THOT_DMDocRasmImpl::set_DocTBR_KOLM_HOT_SOSTNF(TFIBIntegerField * DocTBR_KOLM_HOT_SOSTNF)
{
Object->DocTBR_KOLM_HOT_SOSTNF=DocTBR_KOLM_HOT_SOSTNF;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMDocRasmImpl::get_DocTRASM_NAME_HOT_SNF(void)
{
return Object->DocTRASM_NAME_HOT_SNF;
}
//---------------------------------------------------------------
void THOT_DMDocRasmImpl::set_DocTRASM_NAME_HOT_SNF(TFIBWideStringField * DocTRASM_NAME_HOT_SNF)
{
Object->DocTRASM_NAME_HOT_SNF=DocTRASM_NAME_HOT_SNF;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMDocRasmImpl::get_DocTRASM_NAME_HOT_SCATNOM(void)
{
return Object->DocTRASM_NAME_HOT_SCATNOM;
}
//---------------------------------------------------------------
void THOT_DMDocRasmImpl::set_DocTRASM_NAME_HOT_SCATNOM(TFIBWideStringField * DocTRASM_NAME_HOT_SCATNOM)
{
Object->DocTRASM_NAME_HOT_SCATNOM=DocTRASM_NAME_HOT_SCATNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMDocRasmImpl::get_DocTRASM_NAME_HOT_STYPEPOS(void)
{
return Object->DocTRASM_NAME_HOT_STYPEPOS;
}
//---------------------------------------------------------------
void THOT_DMDocRasmImpl::set_DocTRASM_NAME_HOT_STYPEPOS(TFIBWideStringField * DocTRASM_NAME_HOT_STYPEPOS)
{
Object->DocTRASM_NAME_HOT_STYPEPOS=DocTRASM_NAME_HOT_STYPEPOS;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMDocRasmImpl::get_DocTRASM_NAMEGUEST(void)
{
return Object->DocTRASM_NAMEGUEST;
}
//---------------------------------------------------------------
void THOT_DMDocRasmImpl::set_DocTRASM_NAMEGUEST(TFIBWideStringField * DocTRASM_NAMEGUEST)
{
Object->DocTRASM_NAMEGUEST=DocTRASM_NAMEGUEST;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMDocRasmImpl::get_DocTRASM_NAME_HOT_SSOSTNOM(void)
{
return Object->DocTRASM_NAME_HOT_SSOSTNOM;
}
//---------------------------------------------------------------
void THOT_DMDocRasmImpl::set_DocTRASM_NAME_HOT_SSOSTNOM(TFIBWideStringField * DocTRASM_NAME_HOT_SSOSTNOM)
{
Object->DocTRASM_NAME_HOT_SSOSTNOM=DocTRASM_NAME_HOT_SSOSTNOM;
}
//---------------------------------------------------------------
TFIBDateTimeField * THOT_DMDocRasmImpl::get_DocTRASM_POSNACH_HOT_SOSTNF(void)
{
return Object->DocTRASM_POSNACH_HOT_SOSTNF;
}
//---------------------------------------------------------------
void THOT_DMDocRasmImpl::set_DocTRASM_POSNACH_HOT_SOSTNF(TFIBDateTimeField * DocTRASM_POSNACH_HOT_SOSTNF)
{
Object->DocTRASM_POSNACH_HOT_SOSTNF=DocTRASM_POSNACH_HOT_SOSTNF;
}
//---------------------------------------------------------------
TFIBDateTimeField * THOT_DMDocRasmImpl::get_DocTRASM_POSCON_HOT_SOSTNF(void)
{
return Object->DocTRASM_POSCON_HOT_SOSTNF;
}
//---------------------------------------------------------------
void THOT_DMDocRasmImpl::set_DocTRASM_POSCON_HOT_SOSTNF(TFIBDateTimeField * DocTRASM_POSCON_HOT_SOSTNF)
{
Object->DocTRASM_POSCON_HOT_SOSTNF=DocTRASM_POSCON_HOT_SOSTNF;
}
//---------------------------------------------------------------
TFIBIntegerField * THOT_DMDocRasmImpl::get_DocTRASM_KOLM_HOT_SOSTNF(void)
{
return Object->DocTRASM_KOLM_HOT_SOSTNF;
}
//---------------------------------------------------------------
void THOT_DMDocRasmImpl::set_DocTRASM_KOLM_HOT_SOSTNF(TFIBIntegerField * DocTRASM_KOLM_HOT_SOSTNF)
{
Object->DocTRASM_KOLM_HOT_SOSTNF=DocTRASM_KOLM_HOT_SOSTNF;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMDocRasmImpl::get_DocTBR2_NAME_HOT_SNF(void)
{
return Object->DocTBR2_NAME_HOT_SNF;
}
//---------------------------------------------------------------
void THOT_DMDocRasmImpl::set_DocTBR2_NAME_HOT_SNF(TFIBWideStringField * DocTBR2_NAME_HOT_SNF)
{
Object->DocTBR2_NAME_HOT_SNF=DocTBR2_NAME_HOT_SNF;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMDocRasmImpl::get_DocTBR2_NAME_HOT_SCATNOM(void)
{
return Object->DocTBR2_NAME_HOT_SCATNOM;
}
//---------------------------------------------------------------
void THOT_DMDocRasmImpl::set_DocTBR2_NAME_HOT_SCATNOM(TFIBWideStringField * DocTBR2_NAME_HOT_SCATNOM)
{
Object->DocTBR2_NAME_HOT_SCATNOM=DocTBR2_NAME_HOT_SCATNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMDocRasmImpl::get_DocTBR2_NAME_HOT_STYPEPOS(void)
{
return Object->DocTBR2_NAME_HOT_STYPEPOS;
}
//---------------------------------------------------------------
void THOT_DMDocRasmImpl::set_DocTBR2_NAME_HOT_STYPEPOS(TFIBWideStringField * DocTBR2_NAME_HOT_STYPEPOS)
{
Object->DocTBR2_NAME_HOT_STYPEPOS=DocTBR2_NAME_HOT_STYPEPOS;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMDocRasmImpl::get_DocTBR2_NAMEGUEST(void)
{
return Object->DocTBR2_NAMEGUEST;
}
//---------------------------------------------------------------
void THOT_DMDocRasmImpl::set_DocTBR2_NAMEGUEST(TFIBWideStringField * DocTBR2_NAMEGUEST)
{
Object->DocTBR2_NAMEGUEST=DocTBR2_NAMEGUEST;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMDocRasmImpl::get_DocTBR2_NAME_HOT_SSOSTNOM(void)
{
return Object->DocTBR2_NAME_HOT_SSOSTNOM;
}
//---------------------------------------------------------------
void THOT_DMDocRasmImpl::set_DocTBR2_NAME_HOT_SSOSTNOM(TFIBWideStringField * DocTBR2_NAME_HOT_SSOSTNOM)
{
Object->DocTBR2_NAME_HOT_SSOSTNOM=DocTBR2_NAME_HOT_SSOSTNOM;
}
//---------------------------------------------------------------
TFIBDateTimeField * THOT_DMDocRasmImpl::get_DocTBR2_POSNACH_HOT_SOSTNF(void)
{
return Object->DocTBR2_POSNACH_HOT_SOSTNF;
}
//---------------------------------------------------------------
void THOT_DMDocRasmImpl::set_DocTBR2_POSNACH_HOT_SOSTNF(TFIBDateTimeField * DocTBR2_POSNACH_HOT_SOSTNF)
{
Object->DocTBR2_POSNACH_HOT_SOSTNF=DocTBR2_POSNACH_HOT_SOSTNF;
}
//---------------------------------------------------------------
TFIBDateTimeField * THOT_DMDocRasmImpl::get_DocTBR2_POSCON_HOT_SOSTNF(void)
{
return Object->DocTBR2_POSCON_HOT_SOSTNF;
}
//---------------------------------------------------------------
void THOT_DMDocRasmImpl::set_DocTBR2_POSCON_HOT_SOSTNF(TFIBDateTimeField * DocTBR2_POSCON_HOT_SOSTNF)
{
Object->DocTBR2_POSCON_HOT_SOSTNF=DocTBR2_POSCON_HOT_SOSTNF;
}
//---------------------------------------------------------------
TFIBIntegerField * THOT_DMDocRasmImpl::get_DocTBR2_KOLM_HOT_SOSTNF(void)
{
return Object->DocTBR2_KOLM_HOT_SOSTNF;
}
//---------------------------------------------------------------
void THOT_DMDocRasmImpl::set_DocTBR2_KOLM_HOT_SOSTNF(TFIBIntegerField * DocTBR2_KOLM_HOT_SOSTNF)
{
Object->DocTBR2_KOLM_HOT_SOSTNF=DocTBR2_KOLM_HOT_SOSTNF;
}
//---------------------------------------------------------------
TStringField * THOT_DMDocRasmImpl::get_DocTBR(void)
{
return Object->DocTBR;
}
//---------------------------------------------------------------
void THOT_DMDocRasmImpl::set_DocTBR(TStringField * DocTBR)
{
Object->DocTBR=DocTBR;
}
//---------------------------------------------------------------
TStringField * THOT_DMDocRasmImpl::get_DocTRASM(void)
{
return Object->DocTRASM;
}
//---------------------------------------------------------------
void THOT_DMDocRasmImpl::set_DocTRASM(TStringField * DocTRASM)
{
Object->DocTRASM=DocTRASM;
}
//---------------------------------------------------------------
TStringField * THOT_DMDocRasmImpl::get_DocTBR2(void)
{
return Object->DocTBR2;
}
//---------------------------------------------------------------
void THOT_DMDocRasmImpl::set_DocTBR2(TStringField * DocTBR2)
{
Object->DocTBR2=DocTBR2;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocRasmImpl::get_DocAllID_HOT_GALLDOC(void)
{
return Object->DocAllID_HOT_GALLDOC;
}
//---------------------------------------------------------------
void THOT_DMDocRasmImpl::set_DocAllID_HOT_GALLDOC(TFIBLargeIntField * DocAllID_HOT_GALLDOC)
{
Object->DocAllID_HOT_GALLDOC=DocAllID_HOT_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocRasmImpl::get_DocAllIDFIRM_HOT_GALLDOC(void)
{
return Object->DocAllIDFIRM_HOT_GALLDOC;
}
//---------------------------------------------------------------
void THOT_DMDocRasmImpl::set_DocAllIDFIRM_HOT_GALLDOC(TFIBLargeIntField * DocAllIDFIRM_HOT_GALLDOC)
{
Object->DocAllIDFIRM_HOT_GALLDOC=DocAllIDFIRM_HOT_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocRasmImpl::get_DocAllIDKL_HOT_GALLDOC(void)
{
return Object->DocAllIDKL_HOT_GALLDOC;
}
//---------------------------------------------------------------
void THOT_DMDocRasmImpl::set_DocAllIDKL_HOT_GALLDOC(TFIBLargeIntField * DocAllIDKL_HOT_GALLDOC)
{
Object->DocAllIDKL_HOT_GALLDOC=DocAllIDKL_HOT_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocRasmImpl::get_DocAllIDUSER_HOT_GALLDOC(void)
{
return Object->DocAllIDUSER_HOT_GALLDOC;
}
//---------------------------------------------------------------
void THOT_DMDocRasmImpl::set_DocAllIDUSER_HOT_GALLDOC(TFIBLargeIntField * DocAllIDUSER_HOT_GALLDOC)
{
Object->DocAllIDUSER_HOT_GALLDOC=DocAllIDUSER_HOT_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocRasmImpl::get_DocAllIDDOCOSN_HOT_GALLDOC(void)
{
return Object->DocAllIDDOCOSN_HOT_GALLDOC;
}
//---------------------------------------------------------------
void THOT_DMDocRasmImpl::set_DocAllIDDOCOSN_HOT_GALLDOC(TFIBLargeIntField * DocAllIDDOCOSN_HOT_GALLDOC)
{
Object->DocAllIDDOCOSN_HOT_GALLDOC=DocAllIDDOCOSN_HOT_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocRasmImpl::get_DocAllIDBASE_HOT_GALLDOC(void)
{
return Object->DocAllIDBASE_HOT_GALLDOC;
}
//---------------------------------------------------------------
void THOT_DMDocRasmImpl::set_DocAllIDBASE_HOT_GALLDOC(TFIBLargeIntField * DocAllIDBASE_HOT_GALLDOC)
{
Object->DocAllIDBASE_HOT_GALLDOC=DocAllIDBASE_HOT_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocRasmImpl::get_DocID_HOT_DRASM(void)
{
return Object->DocID_HOT_DRASM;
}
//---------------------------------------------------------------
void THOT_DMDocRasmImpl::set_DocID_HOT_DRASM(TFIBLargeIntField * DocID_HOT_DRASM)
{
Object->DocID_HOT_DRASM=DocID_HOT_DRASM;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocRasmImpl::get_DocIDDOCH_HOT_DRASM(void)
{
return Object->DocIDDOCH_HOT_DRASM;
}
//---------------------------------------------------------------
void THOT_DMDocRasmImpl::set_DocIDDOCH_HOT_DRASM(TFIBLargeIntField * DocIDDOCH_HOT_DRASM)
{
Object->DocIDDOCH_HOT_DRASM=DocIDDOCH_HOT_DRASM;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocRasmImpl::get_DocIDCELPR_HOT_DRASM(void)
{
return Object->DocIDCELPR_HOT_DRASM;
}
//---------------------------------------------------------------
void THOT_DMDocRasmImpl::set_DocIDCELPR_HOT_DRASM(TFIBLargeIntField * DocIDCELPR_HOT_DRASM)
{
Object->DocIDCELPR_HOT_DRASM=DocIDCELPR_HOT_DRASM;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocRasmImpl::get_DocIDBASE_HOT_DRASM(void)
{
return Object->DocIDBASE_HOT_DRASM;
}
//---------------------------------------------------------------
void THOT_DMDocRasmImpl::set_DocIDBASE_HOT_DRASM(TFIBLargeIntField * DocIDBASE_HOT_DRASM)
{
Object->DocIDBASE_HOT_DRASM=DocIDBASE_HOT_DRASM;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocRasmImpl::get_DocIDTPRICE_HOT_DRASM(void)
{
return Object->DocIDTPRICE_HOT_DRASM;
}
//---------------------------------------------------------------
void THOT_DMDocRasmImpl::set_DocIDTPRICE_HOT_DRASM(TFIBLargeIntField * DocIDTPRICE_HOT_DRASM)
{
Object->DocIDTPRICE_HOT_DRASM=DocIDTPRICE_HOT_DRASM;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocRasmImpl::get_DocTID_HOT_DRASMT(void)
{
return Object->DocTID_HOT_DRASMT;
}
//---------------------------------------------------------------
void THOT_DMDocRasmImpl::set_DocTID_HOT_DRASMT(TFIBLargeIntField * DocTID_HOT_DRASMT)
{
Object->DocTID_HOT_DRASMT=DocTID_HOT_DRASMT;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocRasmImpl::get_DocTIDDOCH_HOT_DRASMT(void)
{
return Object->DocTIDDOCH_HOT_DRASMT;
}
//---------------------------------------------------------------
void THOT_DMDocRasmImpl::set_DocTIDDOCH_HOT_DRASMT(TFIBLargeIntField * DocTIDDOCH_HOT_DRASMT)
{
Object->DocTIDDOCH_HOT_DRASMT=DocTIDDOCH_HOT_DRASMT;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocRasmImpl::get_DocTIDSOSTBR_HOT_DRASMT(void)
{
return Object->DocTIDSOSTBR_HOT_DRASMT;
}
//---------------------------------------------------------------
void THOT_DMDocRasmImpl::set_DocTIDSOSTBR_HOT_DRASMT(TFIBLargeIntField * DocTIDSOSTBR_HOT_DRASMT)
{
Object->DocTIDSOSTBR_HOT_DRASMT=DocTIDSOSTBR_HOT_DRASMT;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocRasmImpl::get_DocTIDSOSTRASM_HOT_DRASMT(void)
{
return Object->DocTIDSOSTRASM_HOT_DRASMT;
}
//---------------------------------------------------------------
void THOT_DMDocRasmImpl::set_DocTIDSOSTRASM_HOT_DRASMT(TFIBLargeIntField * DocTIDSOSTRASM_HOT_DRASMT)
{
Object->DocTIDSOSTRASM_HOT_DRASMT=DocTIDSOSTRASM_HOT_DRASMT;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocRasmImpl::get_DocTIDSOSTBR2_HOT_DRASMT(void)
{
return Object->DocTIDSOSTBR2_HOT_DRASMT;
}
//---------------------------------------------------------------
void THOT_DMDocRasmImpl::set_DocTIDSOSTBR2_HOT_DRASMT(TFIBLargeIntField * DocTIDSOSTBR2_HOT_DRASMT)
{
Object->DocTIDSOSTBR2_HOT_DRASMT=DocTIDSOSTBR2_HOT_DRASMT;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocRasmImpl::get_DocTIDBASE_HOT_DRASMT(void)
{
return Object->DocTIDBASE_HOT_DRASMT;
}
//---------------------------------------------------------------
void THOT_DMDocRasmImpl::set_DocTIDBASE_HOT_DRASMT(TFIBLargeIntField * DocTIDBASE_HOT_DRASMT)
{
Object->DocTIDBASE_HOT_DRASMT=DocTIDBASE_HOT_DRASMT;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocRasmImpl::get_DocTRASM_ID_HOT_SNF(void)
{
return Object->DocTRASM_ID_HOT_SNF;
}
//---------------------------------------------------------------
void THOT_DMDocRasmImpl::set_DocTRASM_ID_HOT_SNF(TFIBLargeIntField * DocTRASM_ID_HOT_SNF)
{
Object->DocTRASM_ID_HOT_SNF=DocTRASM_ID_HOT_SNF;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocRasmImpl::get_DocTRASM_ID_HOT_SCATNOM(void)
{
return Object->DocTRASM_ID_HOT_SCATNOM;
}
//---------------------------------------------------------------
void THOT_DMDocRasmImpl::set_DocTRASM_ID_HOT_SCATNOM(TFIBLargeIntField * DocTRASM_ID_HOT_SCATNOM)
{
Object->DocTRASM_ID_HOT_SCATNOM=DocTRASM_ID_HOT_SCATNOM;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocRasmImpl::get_DocTRASM_ID_HOT_STYPEPOS(void)
{
return Object->DocTRASM_ID_HOT_STYPEPOS;
}
//---------------------------------------------------------------
void THOT_DMDocRasmImpl::set_DocTRASM_ID_HOT_STYPEPOS(TFIBLargeIntField * DocTRASM_ID_HOT_STYPEPOS)
{
Object->DocTRASM_ID_HOT_STYPEPOS=DocTRASM_ID_HOT_STYPEPOS;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocRasmImpl::get_DocTRASM_IDGUEST(void)
{
return Object->DocTRASM_IDGUEST;
}
//---------------------------------------------------------------
void THOT_DMDocRasmImpl::set_DocTRASM_IDGUEST(TFIBLargeIntField * DocTRASM_IDGUEST)
{
Object->DocTRASM_IDGUEST=DocTRASM_IDGUEST;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocRasmImpl::get_DocTRASM_ID_HOT_SSOSTNOM(void)
{
return Object->DocTRASM_ID_HOT_SSOSTNOM;
}
//---------------------------------------------------------------
void THOT_DMDocRasmImpl::set_DocTRASM_ID_HOT_SSOSTNOM(TFIBLargeIntField * DocTRASM_ID_HOT_SSOSTNOM)
{
Object->DocTRASM_ID_HOT_SSOSTNOM=DocTRASM_ID_HOT_SSOSTNOM;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocRasmImpl::get_DocTBR2_ID_HOT_SNF(void)
{
return Object->DocTBR2_ID_HOT_SNF;
}
//---------------------------------------------------------------
void THOT_DMDocRasmImpl::set_DocTBR2_ID_HOT_SNF(TFIBLargeIntField * DocTBR2_ID_HOT_SNF)
{
Object->DocTBR2_ID_HOT_SNF=DocTBR2_ID_HOT_SNF;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocRasmImpl::get_DocTBR2_ID_HOT_SCATNOM(void)
{
return Object->DocTBR2_ID_HOT_SCATNOM;
}
//---------------------------------------------------------------
void THOT_DMDocRasmImpl::set_DocTBR2_ID_HOT_SCATNOM(TFIBLargeIntField * DocTBR2_ID_HOT_SCATNOM)
{
Object->DocTBR2_ID_HOT_SCATNOM=DocTBR2_ID_HOT_SCATNOM;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocRasmImpl::get_DocTBR2_ID_HOT_STYPEPOS(void)
{
return Object->DocTBR2_ID_HOT_STYPEPOS;
}
//---------------------------------------------------------------
void THOT_DMDocRasmImpl::set_DocTBR2_ID_HOT_STYPEPOS(TFIBLargeIntField * DocTBR2_ID_HOT_STYPEPOS)
{
Object->DocTBR2_ID_HOT_STYPEPOS=DocTBR2_ID_HOT_STYPEPOS;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocRasmImpl::get_DocTBR2_IDGUEST(void)
{
return Object->DocTBR2_IDGUEST;
}
//---------------------------------------------------------------
void THOT_DMDocRasmImpl::set_DocTBR2_IDGUEST(TFIBLargeIntField * DocTBR2_IDGUEST)
{
Object->DocTBR2_IDGUEST=DocTBR2_IDGUEST;
}
//---------------------------------------------------------------
TFIBLargeIntField * THOT_DMDocRasmImpl::get_DocTBR2_ID_HOT_SSOSTNOM(void)
{
return Object->DocTBR2_ID_HOT_SSOSTNOM;
}
//---------------------------------------------------------------
void THOT_DMDocRasmImpl::set_DocTBR2_ID_HOT_SSOSTNOM(TFIBLargeIntField * DocTBR2_ID_HOT_SSOSTNOM)
{
Object->DocTBR2_ID_HOT_SSOSTNOM=DocTBR2_ID_HOT_SSOSTNOM;
}
//---------------------------------------------------------------
bool THOT_DMDocRasmImpl::get_Prosmotr(void)
{
return Object->Prosmotr;
}
//---------------------------------------------------------------
void THOT_DMDocRasmImpl::set_Prosmotr(bool Prosmotr)
{
Object->Prosmotr=Prosmotr;
}
//---------------------------------------------------------------
bool THOT_DMDocRasmImpl::get_Vibor(void)
{
return Object->Vibor;
}
//---------------------------------------------------------------
void THOT_DMDocRasmImpl::set_Vibor(bool Vibor)
{
Object->Vibor=Vibor;
}
//---------------------------------------------------------------
void THOT_DMDocRasmImpl::NewDoc(void)
{
return Object->NewDoc();
}
//---------------------------------------------------------------
void THOT_DMDocRasmImpl::OpenDoc(__int64 IdDoc)
{
return Object->OpenDoc(IdDoc);
}
//---------------------------------------------------------------
bool THOT_DMDocRasmImpl::SaveDoc(void)
{
return Object->SaveDoc();
}
//---------------------------------------------------------------
bool THOT_DMDocRasmImpl::DvRegDoc(void)
{
return Object->DvRegDoc();
}
//---------------------------------------------------------------
bool THOT_DMDocRasmImpl::CancelDvRegDoc(void)
{
return Object->CancelDvRegDoc();
}
//---------------------------------------------------------------
void THOT_DMDocRasmImpl::CloseDoc(void)
{
return Object->CloseDoc();
}
//---------------------------------------------------------------
bool THOT_DMDocRasmImpl::DeleteDoc(__int64 id)
{
return Object->DeleteDoc(id);
}
//---------------------------------------------------------------
void THOT_DMDocRasmImpl::AddString(void)
{
return Object->AddString();
}
//---------------------------------------------------------------
void THOT_DMDocRasmImpl::DeleteString(void)
{
return Object->DeleteString();
}
//---------------------------------------------------------------
