#include "vcl.h"
#pragma hdrstop


#include "UREM_DMCustQueryImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_DMCustQueryImpl::TREM_DMCustQueryImpl()           
{                                            
Object=new TREM_DMCustQuery(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_DMCustQueryImpl::~TREM_DMCustQueryImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_DMCustQueryImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_DMCustQuery)                        
   {                                                                     
   *ppv=static_cast<IREM_DMCustQuery*> (this);                                
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
int TREM_DMCustQueryImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_DMCustQueryImpl::kanRelease(void)                                  
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
int  TREM_DMCustQueryImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_DMCustQueryImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_DMCustQueryImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_DMCustQueryImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_DMCustQueryImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IREM_DMCustQuery
TDataSource * TREM_DMCustQueryImpl::get_DataSourceDocT(void)
{
return Object->DataSourceDocT;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DataSourceDocT(TDataSource * DataSourceDocT)
{
Object->DataSourceDocT=DataSourceDocT;
}
//---------------------------------------------------------------
TDataSource * TREM_DMCustQueryImpl::get_DataSourceDoc(void)
{
return Object->DataSourceDoc;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DataSourceDoc(TDataSource * DataSourceDoc)
{
Object->DataSourceDoc=DataSourceDoc;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMCustQueryImpl::get_Doc(void)
{
return Object->Doc;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_Doc(TpFIBDataSet * Doc)
{
Object->Doc=Doc;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMCustQueryImpl::get_DocT(void)
{
return Object->DocT;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DocT(TpFIBDataSet * DocT)
{
Object->DocT=DocT;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMCustQueryImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMCustQueryImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMCustQueryImpl::get_NumDoc(void)
{
return Object->NumDoc;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_NumDoc(TpFIBDataSet * NumDoc)
{
Object->NumDoc=NumDoc;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMCustQueryImpl::get_DocID_REM_CQUERY(void)
{
return Object->DocID_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DocID_REM_CQUERY(TFIBLargeIntField * DocID_REM_CQUERY)
{
Object->DocID_REM_CQUERY=DocID_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMCustQueryImpl::get_DocGID_REM_CQUERY(void)
{
return Object->DocGID_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DocGID_REM_CQUERY(TFIBWideStringField * DocGID_REM_CQUERY)
{
Object->DocGID_REM_CQUERY=DocGID_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMCustQueryImpl::get_DocIDBASE_REM_CQUERY(void)
{
return Object->DocIDBASE_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DocIDBASE_REM_CQUERY(TFIBLargeIntField * DocIDBASE_REM_CQUERY)
{
Object->DocIDBASE_REM_CQUERY=DocIDBASE_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMCustQueryImpl::get_DocPOS_REM_CQUERY(void)
{
return Object->DocPOS_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DocPOS_REM_CQUERY(TFIBDateTimeField * DocPOS_REM_CQUERY)
{
Object->DocPOS_REM_CQUERY=DocPOS_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMCustQueryImpl::get_DocNUM_REM_CQUERY(void)
{
return Object->DocNUM_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DocNUM_REM_CQUERY(TFIBIntegerField * DocNUM_REM_CQUERY)
{
Object->DocNUM_REM_CQUERY=DocNUM_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMCustQueryImpl::get_DocIDFIRM_REM_CQUERY(void)
{
return Object->DocIDFIRM_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DocIDFIRM_REM_CQUERY(TFIBLargeIntField * DocIDFIRM_REM_CQUERY)
{
Object->DocIDFIRM_REM_CQUERY=DocIDFIRM_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMCustQueryImpl::get_DocIDSKLAD_REM_CQUERY(void)
{
return Object->DocIDSKLAD_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DocIDSKLAD_REM_CQUERY(TFIBLargeIntField * DocIDSKLAD_REM_CQUERY)
{
Object->DocIDSKLAD_REM_CQUERY=DocIDSKLAD_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMCustQueryImpl::get_DocIDUSER_REM_CQUERY(void)
{
return Object->DocIDUSER_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DocIDUSER_REM_CQUERY(TFIBLargeIntField * DocIDUSER_REM_CQUERY)
{
Object->DocIDUSER_REM_CQUERY=DocIDUSER_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMCustQueryImpl::get_DocIDKLIENT_REM_CQUERY(void)
{
return Object->DocIDKLIENT_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DocIDKLIENT_REM_CQUERY(TFIBLargeIntField * DocIDKLIENT_REM_CQUERY)
{
Object->DocIDKLIENT_REM_CQUERY=DocIDKLIENT_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMCustQueryImpl::get_DocKLIENT_NAME_REM_CQUERY(void)
{
return Object->DocKLIENT_NAME_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DocKLIENT_NAME_REM_CQUERY(TFIBWideStringField * DocKLIENT_NAME_REM_CQUERY)
{
Object->DocKLIENT_NAME_REM_CQUERY=DocKLIENT_NAME_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMCustQueryImpl::get_DocKLIENT_ADR_REM_CQUERY(void)
{
return Object->DocKLIENT_ADR_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DocKLIENT_ADR_REM_CQUERY(TFIBWideStringField * DocKLIENT_ADR_REM_CQUERY)
{
Object->DocKLIENT_ADR_REM_CQUERY=DocKLIENT_ADR_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMCustQueryImpl::get_DocKLIENT_PHONE_REM_CQUERY(void)
{
return Object->DocKLIENT_PHONE_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DocKLIENT_PHONE_REM_CQUERY(TFIBWideStringField * DocKLIENT_PHONE_REM_CQUERY)
{
Object->DocKLIENT_PHONE_REM_CQUERY=DocKLIENT_PHONE_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMCustQueryImpl::get_DocCOMMENTS_REM_CQUERY(void)
{
return Object->DocCOMMENTS_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DocCOMMENTS_REM_CQUERY(TFIBWideStringField * DocCOMMENTS_REM_CQUERY)
{
Object->DocCOMMENTS_REM_CQUERY=DocCOMMENTS_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMCustQueryImpl::get_DocRUN_REM_CQUERY(void)
{
return Object->DocRUN_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DocRUN_REM_CQUERY(TFIBSmallIntField * DocRUN_REM_CQUERY)
{
Object->DocRUN_REM_CQUERY=DocRUN_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMCustQueryImpl::get_DocDO_SUM_REM_CQUERY(void)
{
return Object->DocDO_SUM_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DocDO_SUM_REM_CQUERY(TFIBBCDField * DocDO_SUM_REM_CQUERY)
{
Object->DocDO_SUM_REM_CQUERY=DocDO_SUM_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMCustQueryImpl::get_DocTEC_SUM_REM_CQUERY(void)
{
return Object->DocTEC_SUM_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DocTEC_SUM_REM_CQUERY(TFIBBCDField * DocTEC_SUM_REM_CQUERY)
{
Object->DocTEC_SUM_REM_CQUERY=DocTEC_SUM_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMCustQueryImpl::get_DocSOGL_SUM_REM_CQUERY(void)
{
return Object->DocSOGL_SUM_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DocSOGL_SUM_REM_CQUERY(TFIBBCDField * DocSOGL_SUM_REM_CQUERY)
{
Object->DocSOGL_SUM_REM_CQUERY=DocSOGL_SUM_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMCustQueryImpl::get_DocIDZ_REM_CQUERY(void)
{
return Object->DocIDZ_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DocIDZ_REM_CQUERY(TFIBLargeIntField * DocIDZ_REM_CQUERY)
{
Object->DocIDZ_REM_CQUERY=DocIDZ_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMCustQueryImpl::get_DocIDMODEL_REM_CQUERY(void)
{
return Object->DocIDMODEL_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DocIDMODEL_REM_CQUERY(TFIBLargeIntField * DocIDMODEL_REM_CQUERY)
{
Object->DocIDMODEL_REM_CQUERY=DocIDMODEL_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMCustQueryImpl::get_DocNAME_MODEL_REM_CQUERY(void)
{
return Object->DocNAME_MODEL_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DocNAME_MODEL_REM_CQUERY(TFIBWideStringField * DocNAME_MODEL_REM_CQUERY)
{
Object->DocNAME_MODEL_REM_CQUERY=DocNAME_MODEL_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMCustQueryImpl::get_DocNAMEFIRM(void)
{
return Object->DocNAMEFIRM;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DocNAMEFIRM(TFIBWideStringField * DocNAMEFIRM)
{
Object->DocNAMEFIRM=DocNAMEFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMCustQueryImpl::get_DocNAME_SINFBASE_OBMEN(void)
{
return Object->DocNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DocNAME_SINFBASE_OBMEN(TFIBWideStringField * DocNAME_SINFBASE_OBMEN)
{
Object->DocNAME_SINFBASE_OBMEN=DocNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMCustQueryImpl::get_DocNAME_REM_SMODEL(void)
{
return Object->DocNAME_REM_SMODEL;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DocNAME_REM_SMODEL(TFIBWideStringField * DocNAME_REM_SMODEL)
{
Object->DocNAME_REM_SMODEL=DocNAME_REM_SMODEL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMCustQueryImpl::get_DocNAMESKLAD(void)
{
return Object->DocNAMESKLAD;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DocNAMESKLAD(TFIBWideStringField * DocNAMESKLAD)
{
Object->DocNAMESKLAD=DocNAMESKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMCustQueryImpl::get_DocNAMEKLIENT(void)
{
return Object->DocNAMEKLIENT;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DocNAMEKLIENT(TFIBWideStringField * DocNAMEKLIENT)
{
Object->DocNAMEKLIENT=DocNAMEKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMCustQueryImpl::get_DocNAME_REM_Z(void)
{
return Object->DocNAME_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DocNAME_REM_Z(TFIBWideStringField * DocNAME_REM_Z)
{
Object->DocNAME_REM_Z=DocNAME_REM_Z;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMCustQueryImpl::get_DocNUM_REM_Z(void)
{
return Object->DocNUM_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DocNUM_REM_Z(TFIBIntegerField * DocNUM_REM_Z)
{
Object->DocNUM_REM_Z=DocNUM_REM_Z;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMCustQueryImpl::get_DocPOS_REM_Z(void)
{
return Object->DocPOS_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DocPOS_REM_Z(TFIBDateTimeField * DocPOS_REM_Z)
{
Object->DocPOS_REM_Z=DocPOS_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMCustQueryImpl::get_DocKLIENT_NAME_REM_Z(void)
{
return Object->DocKLIENT_NAME_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DocKLIENT_NAME_REM_Z(TFIBWideStringField * DocKLIENT_NAME_REM_Z)
{
Object->DocKLIENT_NAME_REM_Z=DocKLIENT_NAME_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMCustQueryImpl::get_DocMODEL_REM_Z(void)
{
return Object->DocMODEL_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DocMODEL_REM_Z(TFIBWideStringField * DocMODEL_REM_Z)
{
Object->DocMODEL_REM_Z=DocMODEL_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMCustQueryImpl::get_DocNAME_USER(void)
{
return Object->DocNAME_USER;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DocNAME_USER(TFIBWideStringField * DocNAME_USER)
{
Object->DocNAME_USER=DocNAME_USER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMCustQueryImpl::get_DocTID_REM_CQUERYT(void)
{
return Object->DocTID_REM_CQUERYT;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DocTID_REM_CQUERYT(TFIBLargeIntField * DocTID_REM_CQUERYT)
{
Object->DocTID_REM_CQUERYT=DocTID_REM_CQUERYT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMCustQueryImpl::get_DocTGID_REM_CQUERYT(void)
{
return Object->DocTGID_REM_CQUERYT;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DocTGID_REM_CQUERYT(TFIBWideStringField * DocTGID_REM_CQUERYT)
{
Object->DocTGID_REM_CQUERYT=DocTGID_REM_CQUERYT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMCustQueryImpl::get_DocTIDBASE_REM_CQUERYT(void)
{
return Object->DocTIDBASE_REM_CQUERYT;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DocTIDBASE_REM_CQUERYT(TFIBLargeIntField * DocTIDBASE_REM_CQUERYT)
{
Object->DocTIDBASE_REM_CQUERYT=DocTIDBASE_REM_CQUERYT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMCustQueryImpl::get_DocTIDCQ_REM_CQUERYT(void)
{
return Object->DocTIDCQ_REM_CQUERYT;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DocTIDCQ_REM_CQUERYT(TFIBLargeIntField * DocTIDCQ_REM_CQUERYT)
{
Object->DocTIDCQ_REM_CQUERYT=DocTIDCQ_REM_CQUERYT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMCustQueryImpl::get_DocTIDNOM_REM_CQUERYT(void)
{
return Object->DocTIDNOM_REM_CQUERYT;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DocTIDNOM_REM_CQUERYT(TFIBLargeIntField * DocTIDNOM_REM_CQUERYT)
{
Object->DocTIDNOM_REM_CQUERYT=DocTIDNOM_REM_CQUERYT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMCustQueryImpl::get_DocTIDED_REM_CQUERYT(void)
{
return Object->DocTIDED_REM_CQUERYT;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DocTIDED_REM_CQUERYT(TFIBLargeIntField * DocTIDED_REM_CQUERYT)
{
Object->DocTIDED_REM_CQUERYT=DocTIDED_REM_CQUERYT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMCustQueryImpl::get_DocTIDSOST_REM_CQUERYT(void)
{
return Object->DocTIDSOST_REM_CQUERYT;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DocTIDSOST_REM_CQUERYT(TFIBLargeIntField * DocTIDSOST_REM_CQUERYT)
{
Object->DocTIDSOST_REM_CQUERYT=DocTIDSOST_REM_CQUERYT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMCustQueryImpl::get_DocTNAMENOM_REM_CQUERYT(void)
{
return Object->DocTNAMENOM_REM_CQUERYT;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DocTNAMENOM_REM_CQUERYT(TFIBWideStringField * DocTNAMENOM_REM_CQUERYT)
{
Object->DocTNAMENOM_REM_CQUERYT=DocTNAMENOM_REM_CQUERYT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMCustQueryImpl::get_DocTKOL_REM_CQUERYT(void)
{
return Object->DocTKOL_REM_CQUERYT;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DocTKOL_REM_CQUERYT(TFIBBCDField * DocTKOL_REM_CQUERYT)
{
Object->DocTKOL_REM_CQUERYT=DocTKOL_REM_CQUERYT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMCustQueryImpl::get_DocTKF_REM_CQUERYT(void)
{
return Object->DocTKF_REM_CQUERYT;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DocTKF_REM_CQUERYT(TFIBBCDField * DocTKF_REM_CQUERYT)
{
Object->DocTKF_REM_CQUERYT=DocTKF_REM_CQUERYT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMCustQueryImpl::get_DocTPRICE_REM_CQUERYT(void)
{
return Object->DocTPRICE_REM_CQUERYT;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DocTPRICE_REM_CQUERYT(TFIBBCDField * DocTPRICE_REM_CQUERYT)
{
Object->DocTPRICE_REM_CQUERYT=DocTPRICE_REM_CQUERYT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMCustQueryImpl::get_DocTSUM_REM_CQUERYT(void)
{
return Object->DocTSUM_REM_CQUERYT;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DocTSUM_REM_CQUERYT(TFIBBCDField * DocTSUM_REM_CQUERYT)
{
Object->DocTSUM_REM_CQUERYT=DocTSUM_REM_CQUERYT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMCustQueryImpl::get_DocTPRICE_DO_REM_CQUERYT(void)
{
return Object->DocTPRICE_DO_REM_CQUERYT;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DocTPRICE_DO_REM_CQUERYT(TFIBBCDField * DocTPRICE_DO_REM_CQUERYT)
{
Object->DocTPRICE_DO_REM_CQUERYT=DocTPRICE_DO_REM_CQUERYT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMCustQueryImpl::get_DocTPRICE_TEC_REM_CQUERYT(void)
{
return Object->DocTPRICE_TEC_REM_CQUERYT;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DocTPRICE_TEC_REM_CQUERYT(TFIBBCDField * DocTPRICE_TEC_REM_CQUERYT)
{
Object->DocTPRICE_TEC_REM_CQUERYT=DocTPRICE_TEC_REM_CQUERYT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMCustQueryImpl::get_DocTPRICE_SOGL_REM_CQUERYT(void)
{
return Object->DocTPRICE_SOGL_REM_CQUERYT;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DocTPRICE_SOGL_REM_CQUERYT(TFIBBCDField * DocTPRICE_SOGL_REM_CQUERYT)
{
Object->DocTPRICE_SOGL_REM_CQUERYT=DocTPRICE_SOGL_REM_CQUERYT;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMCustQueryImpl::get_DocTSROK_POST_REM_CQUERYT(void)
{
return Object->DocTSROK_POST_REM_CQUERYT;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DocTSROK_POST_REM_CQUERYT(TFIBIntegerField * DocTSROK_POST_REM_CQUERYT)
{
Object->DocTSROK_POST_REM_CQUERYT=DocTSROK_POST_REM_CQUERYT;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMCustQueryImpl::get_DocTPOS_POST_REM_CQUERYT(void)
{
return Object->DocTPOS_POST_REM_CQUERYT;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DocTPOS_POST_REM_CQUERYT(TFIBDateTimeField * DocTPOS_POST_REM_CQUERYT)
{
Object->DocTPOS_POST_REM_CQUERYT=DocTPOS_POST_REM_CQUERYT;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMCustQueryImpl::get_DocTRUN_REM_CQUERYT(void)
{
return Object->DocTRUN_REM_CQUERYT;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DocTRUN_REM_CQUERYT(TFIBSmallIntField * DocTRUN_REM_CQUERYT)
{
Object->DocTRUN_REM_CQUERYT=DocTRUN_REM_CQUERYT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMCustQueryImpl::get_DocTCOMMENTS_REM_CQUERYT(void)
{
return Object->DocTCOMMENTS_REM_CQUERYT;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DocTCOMMENTS_REM_CQUERYT(TFIBWideStringField * DocTCOMMENTS_REM_CQUERYT)
{
Object->DocTCOMMENTS_REM_CQUERYT=DocTCOMMENTS_REM_CQUERYT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMCustQueryImpl::get_DocTNAMENOM(void)
{
return Object->DocTNAMENOM;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DocTNAMENOM(TFIBWideStringField * DocTNAMENOM)
{
Object->DocTNAMENOM=DocTNAMENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMCustQueryImpl::get_DocTNAMEED(void)
{
return Object->DocTNAMEED;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DocTNAMEED(TFIBWideStringField * DocTNAMEED)
{
Object->DocTNAMEED=DocTNAMEED;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMCustQueryImpl::get_DocTNAME_REM_SSOST_CQUERY(void)
{
return Object->DocTNAME_REM_SSOST_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DocTNAME_REM_SSOST_CQUERY(TFIBWideStringField * DocTNAME_REM_SSOST_CQUERY)
{
Object->DocTNAME_REM_SSOST_CQUERY=DocTNAME_REM_SSOST_CQUERY;
}
//---------------------------------------------------------------
TIntegerField * TREM_DMCustQueryImpl::get_DocTRECNO(void)
{
return Object->DocTRECNO;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DocTRECNO(TIntegerField * DocTRECNO)
{
Object->DocTRECNO=DocTRECNO;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMCustQueryImpl::get_NumDocMAXNUMBER(void)
{
return Object->NumDocMAXNUMBER;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_NumDocMAXNUMBER(TFIBIntegerField * NumDocMAXNUMBER)
{
Object->NumDocMAXNUMBER=NumDocMAXNUMBER;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMCustQueryImpl::get_DocTACT_REM_CQUERYT(void)
{
return Object->DocTACT_REM_CQUERYT;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DocTACT_REM_CQUERYT(TFIBSmallIntField * DocTACT_REM_CQUERYT)
{
Object->DocTACT_REM_CQUERYT=DocTACT_REM_CQUERYT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMCustQueryImpl::get_DocTIDPRNOM_REM_CQUERYT(void)
{
return Object->DocTIDPRNOM_REM_CQUERYT;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DocTIDPRNOM_REM_CQUERYT(TFIBLargeIntField * DocTIDPRNOM_REM_CQUERYT)
{
Object->DocTIDPRNOM_REM_CQUERYT=DocTIDPRNOM_REM_CQUERYT;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMCustQueryImpl::get_DocTCODENOM(void)
{
return Object->DocTCODENOM;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DocTCODENOM(TFIBIntegerField * DocTCODENOM)
{
Object->DocTCODENOM=DocTCODENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMCustQueryImpl::get_DocTARTNOM(void)
{
return Object->DocTARTNOM;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DocTARTNOM(TFIBWideStringField * DocTARTNOM)
{
Object->DocTARTNOM=DocTARTNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMCustQueryImpl::get_DocTSHED(void)
{
return Object->DocTSHED;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DocTSHED(TFIBWideStringField * DocTSHED)
{
Object->DocTSHED=DocTSHED;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMCustQueryImpl::get_DocTART_SPRNOM(void)
{
return Object->DocTART_SPRNOM;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DocTART_SPRNOM(TFIBWideStringField * DocTART_SPRNOM)
{
Object->DocTART_SPRNOM=DocTART_SPRNOM;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMCustQueryImpl::get_DocTCODE_SPRNOM(void)
{
return Object->DocTCODE_SPRNOM;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DocTCODE_SPRNOM(TFIBIntegerField * DocTCODE_SPRNOM)
{
Object->DocTCODE_SPRNOM=DocTCODE_SPRNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMCustQueryImpl::get_DocTNAME_SPRNOM(void)
{
return Object->DocTNAME_SPRNOM;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DocTNAME_SPRNOM(TFIBWideStringField * DocTNAME_SPRNOM)
{
Object->DocTNAME_SPRNOM=DocTNAME_SPRNOM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMCustQueryImpl::get_DocIDBRAND_REM_CQUERY(void)
{
return Object->DocIDBRAND_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DocIDBRAND_REM_CQUERY(TFIBLargeIntField * DocIDBRAND_REM_CQUERY)
{
Object->DocIDBRAND_REM_CQUERY=DocIDBRAND_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMCustQueryImpl::get_DocIDPRODUCER_REM_CQUERY(void)
{
return Object->DocIDPRODUCER_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DocIDPRODUCER_REM_CQUERY(TFIBLargeIntField * DocIDPRODUCER_REM_CQUERY)
{
Object->DocIDPRODUCER_REM_CQUERY=DocIDPRODUCER_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMCustQueryImpl::get_DocFL_KLIENT_UVEDOML_REM_CQUERY(void)
{
return Object->DocFL_KLIENT_UVEDOML_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DocFL_KLIENT_UVEDOML_REM_CQUERY(TFIBSmallIntField * DocFL_KLIENT_UVEDOML_REM_CQUERY)
{
Object->DocFL_KLIENT_UVEDOML_REM_CQUERY=DocFL_KLIENT_UVEDOML_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMCustQueryImpl::get_DocNAME_SBRAND(void)
{
return Object->DocNAME_SBRAND;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DocNAME_SBRAND(TFIBWideStringField * DocNAME_SBRAND)
{
Object->DocNAME_SBRAND=DocNAME_SBRAND;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMCustQueryImpl::get_DocNAME_SPRODUCER(void)
{
return Object->DocNAME_SPRODUCER;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DocNAME_SPRODUCER(TFIBWideStringField * DocNAME_SPRODUCER)
{
Object->DocNAME_SPRODUCER=DocNAME_SPRODUCER;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMCustQueryImpl::get_DocNUM_ZAKAZA_REM_CQUERY(void)
{
return Object->DocNUM_ZAKAZA_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DocNUM_ZAKAZA_REM_CQUERY(TFIBIntegerField * DocNUM_ZAKAZA_REM_CQUERY)
{
Object->DocNUM_ZAKAZA_REM_CQUERY=DocNUM_ZAKAZA_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBDateField * TREM_DMCustQueryImpl::get_DocDATE_ZAKAZA_REM_CQUERY(void)
{
return Object->DocDATE_ZAKAZA_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DocDATE_ZAKAZA_REM_CQUERY(TFIBDateField * DocDATE_ZAKAZA_REM_CQUERY)
{
Object->DocDATE_ZAKAZA_REM_CQUERY=DocDATE_ZAKAZA_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMCustQueryImpl::get_DocIDHW_REM_CQUERY(void)
{
return Object->DocIDHW_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DocIDHW_REM_CQUERY(TFIBLargeIntField * DocIDHW_REM_CQUERY)
{
Object->DocIDHW_REM_CQUERY=DocIDHW_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMCustQueryImpl::get_DocTYPE_REM_CQUERY(void)
{
return Object->DocTYPE_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DocTYPE_REM_CQUERY(TFIBIntegerField * DocTYPE_REM_CQUERY)
{
Object->DocTYPE_REM_CQUERY=DocTYPE_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMCustQueryImpl::get_DocNAME_REM_SHARDWARE(void)
{
return Object->DocNAME_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DocNAME_REM_SHARDWARE(TFIBWideStringField * DocNAME_REM_SHARDWARE)
{
Object->DocNAME_REM_SHARDWARE=DocNAME_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMCustQueryImpl::get_DocSERNUM_REM_SHARDWARE(void)
{
return Object->DocSERNUM_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DocSERNUM_REM_SHARDWARE(TFIBWideStringField * DocSERNUM_REM_SHARDWARE)
{
Object->DocSERNUM_REM_SHARDWARE=DocSERNUM_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMCustQueryImpl::get_DocSERNUM2_REM_SHARDWARE(void)
{
return Object->DocSERNUM2_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DocSERNUM2_REM_SHARDWARE(TFIBWideStringField * DocSERNUM2_REM_SHARDWARE)
{
Object->DocSERNUM2_REM_SHARDWARE=DocSERNUM2_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMCustQueryImpl::get_DocIDPRMODEL_REM_CQUERY(void)
{
return Object->DocIDPRMODEL_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DocIDPRMODEL_REM_CQUERY(TFIBLargeIntField * DocIDPRMODEL_REM_CQUERY)
{
Object->DocIDPRMODEL_REM_CQUERY=DocIDPRMODEL_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMCustQueryImpl::get_DocPOSTUPILO_REM_CQUERY(void)
{
return Object->DocPOSTUPILO_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DocPOSTUPILO_REM_CQUERY(TFIBDateTimeField * DocPOSTUPILO_REM_CQUERY)
{
Object->DocPOSTUPILO_REM_CQUERY=DocPOSTUPILO_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMCustQueryImpl::get_DocCODE_REM_SMODEL(void)
{
return Object->DocCODE_REM_SMODEL;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DocCODE_REM_SMODEL(TFIBWideStringField * DocCODE_REM_SMODEL)
{
Object->DocCODE_REM_SMODEL=DocCODE_REM_SMODEL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMCustQueryImpl::get_DocNAME_REM_SPRMODEL(void)
{
return Object->DocNAME_REM_SPRMODEL;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DocNAME_REM_SPRMODEL(TFIBWideStringField * DocNAME_REM_SPRMODEL)
{
Object->DocNAME_REM_SPRMODEL=DocNAME_REM_SPRMODEL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMCustQueryImpl::get_DocCODE_REM_SPRMODEL(void)
{
return Object->DocCODE_REM_SPRMODEL;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DocCODE_REM_SPRMODEL(TFIBWideStringField * DocCODE_REM_SPRMODEL)
{
Object->DocCODE_REM_SPRMODEL=DocCODE_REM_SPRMODEL;
}
//---------------------------------------------------------------
TFIBDateField * TREM_DMCustQueryImpl::get_DocPLAN_POSTAVKI_REM_CQUERY(void)
{
return Object->DocPLAN_POSTAVKI_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DocPLAN_POSTAVKI_REM_CQUERY(TFIBDateField * DocPLAN_POSTAVKI_REM_CQUERY)
{
Object->DocPLAN_POSTAVKI_REM_CQUERY=DocPLAN_POSTAVKI_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMCustQueryImpl::get_DocZAKAZANO_REM_CQUERY(void)
{
return Object->DocZAKAZANO_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DocZAKAZANO_REM_CQUERY(TFIBDateTimeField * DocZAKAZANO_REM_CQUERY)
{
Object->DocZAKAZANO_REM_CQUERY=DocZAKAZANO_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMCustQueryImpl::get_DocOTPRAVLENO_REM_CQUERY(void)
{
return Object->DocOTPRAVLENO_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DocOTPRAVLENO_REM_CQUERY(TFIBDateTimeField * DocOTPRAVLENO_REM_CQUERY)
{
Object->DocOTPRAVLENO_REM_CQUERY=DocOTPRAVLENO_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMCustQueryImpl::get_DocTART_REM_CQUERYT(void)
{
return Object->DocTART_REM_CQUERYT;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DocTART_REM_CQUERYT(TFIBWideStringField * DocTART_REM_CQUERYT)
{
Object->DocTART_REM_CQUERYT=DocTART_REM_CQUERYT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMCustQueryImpl::get_DocNAME_REM_CQUERY(void)
{
return Object->DocNAME_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DocNAME_REM_CQUERY(TFIBWideStringField * DocNAME_REM_CQUERY)
{
Object->DocNAME_REM_CQUERY=DocNAME_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMCustQueryImpl::get_DocNUM_STR_ZAK_POST_REM_CQUERY(void)
{
return Object->DocNUM_STR_ZAK_POST_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DocNUM_STR_ZAK_POST_REM_CQUERY(TFIBWideStringField * DocNUM_STR_ZAK_POST_REM_CQUERY)
{
Object->DocNUM_STR_ZAK_POST_REM_CQUERY=DocNUM_STR_ZAK_POST_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMCustQueryImpl::get_DocTFL_ADD_IN_SOBORUD_SNOM(void)
{
return Object->DocTFL_ADD_IN_SOBORUD_SNOM;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DocTFL_ADD_IN_SOBORUD_SNOM(TFIBSmallIntField * DocTFL_ADD_IN_SOBORUD_SNOM)
{
Object->DocTFL_ADD_IN_SOBORUD_SNOM=DocTFL_ADD_IN_SOBORUD_SNOM;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMCustQueryImpl::get_DocPOS_ZAK_POST_REM_CQUERY(void)
{
return Object->DocPOS_ZAK_POST_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DocPOS_ZAK_POST_REM_CQUERY(TFIBDateTimeField * DocPOS_ZAK_POST_REM_CQUERY)
{
Object->DocPOS_ZAK_POST_REM_CQUERY=DocPOS_ZAK_POST_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMCustQueryImpl::get_DocNUM_STR_ZAK_SPROV_REM_CQUERY(void)
{
return Object->DocNUM_STR_ZAK_SPROV_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DocNUM_STR_ZAK_SPROV_REM_CQUERY(TFIBWideStringField * DocNUM_STR_ZAK_SPROV_REM_CQUERY)
{
Object->DocNUM_STR_ZAK_SPROV_REM_CQUERY=DocNUM_STR_ZAK_SPROV_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMCustQueryImpl::get_DocPOS_ZAK_SPROV_REM_CQUERY(void)
{
return Object->DocPOS_ZAK_SPROV_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DocPOS_ZAK_SPROV_REM_CQUERY(TFIBDateTimeField * DocPOS_ZAK_SPROV_REM_CQUERY)
{
Object->DocPOS_ZAK_SPROV_REM_CQUERY=DocPOS_ZAK_SPROV_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMCustQueryImpl::get_DocNUM_DOC_OTPR_POST_REM_CQUERY(void)
{
return Object->DocNUM_DOC_OTPR_POST_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DocNUM_DOC_OTPR_POST_REM_CQUERY(TFIBWideStringField * DocNUM_DOC_OTPR_POST_REM_CQUERY)
{
Object->DocNUM_DOC_OTPR_POST_REM_CQUERY=DocNUM_DOC_OTPR_POST_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMCustQueryImpl::get_DocPOS_DOC_OTPR_POST_REM_CQUERY(void)
{
return Object->DocPOS_DOC_OTPR_POST_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DocPOS_DOC_OTPR_POST_REM_CQUERY(TFIBDateTimeField * DocPOS_DOC_OTPR_POST_REM_CQUERY)
{
Object->DocPOS_DOC_OTPR_POST_REM_CQUERY=DocPOS_DOC_OTPR_POST_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMCustQueryImpl::get_DocNUMDOCTK_REM_CQUERY(void)
{
return Object->DocNUMDOCTK_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DocNUMDOCTK_REM_CQUERY(TFIBWideStringField * DocNUMDOCTK_REM_CQUERY)
{
Object->DocNUMDOCTK_REM_CQUERY=DocNUMDOCTK_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMCustQueryImpl::get_DocTK_REM_CQUERY(void)
{
return Object->DocTK_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DocTK_REM_CQUERY(TFIBWideStringField * DocTK_REM_CQUERY)
{
Object->DocTK_REM_CQUERY=DocTK_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMCustQueryImpl::get_DocIDPRODAVEC_REM_CQUERY(void)
{
return Object->DocIDPRODAVEC_REM_CQUERY;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DocIDPRODAVEC_REM_CQUERY(TFIBLargeIntField * DocIDPRODAVEC_REM_CQUERY)
{
Object->DocIDPRODAVEC_REM_CQUERY=DocIDPRODAVEC_REM_CQUERY;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMCustQueryImpl::get_DocPRODAVEC_NAME(void)
{
return Object->DocPRODAVEC_NAME;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DocPRODAVEC_NAME(TFIBWideStringField * DocPRODAVEC_NAME)
{
Object->DocPRODAVEC_NAME=DocPRODAVEC_NAME;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMCustQueryImpl::get_DocTSER_NUM_REM_CQUERYT(void)
{
return Object->DocTSER_NUM_REM_CQUERYT;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DocTSER_NUM_REM_CQUERYT(TFIBWideStringField * DocTSER_NUM_REM_CQUERYT)
{
Object->DocTSER_NUM_REM_CQUERYT=DocTSER_NUM_REM_CQUERYT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMCustQueryImpl::get_DocTUCH_SER_NUM_REM_CQUERYT(void)
{
return Object->DocTUCH_SER_NUM_REM_CQUERYT;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DocTUCH_SER_NUM_REM_CQUERYT(TFIBWideStringField * DocTUCH_SER_NUM_REM_CQUERYT)
{
Object->DocTUCH_SER_NUM_REM_CQUERYT=DocTUCH_SER_NUM_REM_CQUERYT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMCustQueryImpl::get_DocTREF_REM_CQUERYT(void)
{
return Object->DocTREF_REM_CQUERYT;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_DocTREF_REM_CQUERYT(TFIBWideStringField * DocTREF_REM_CQUERYT)
{
Object->DocTREF_REM_CQUERYT=DocTREF_REM_CQUERYT;
}
//---------------------------------------------------------------
bool TREM_DMCustQueryImpl::get_Prosmotr(void)
{
return Object->Prosmotr;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_Prosmotr(bool Prosmotr)
{
Object->Prosmotr=Prosmotr;
}
//---------------------------------------------------------------
__int64 TREM_DMCustQueryImpl::get_IdCQ(void)
{
return Object->IdCQ;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_IdCQ(__int64 IdCQ)
{
Object->IdCQ=IdCQ;
}
//---------------------------------------------------------------
bool TREM_DMCustQueryImpl::get_flChangeData(void)
{
return Object->flChangeData;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::set_flChangeData(bool flChangeData)
{
Object->flChangeData=flChangeData;
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::NewDoc(void)
{
return Object->NewDoc();
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::OpenDoc(__int64 id)
{
return Object->OpenDoc(id);
}
//---------------------------------------------------------------
bool TREM_DMCustQueryImpl::SaveDoc(void)
{
return Object->SaveDoc();
}
//---------------------------------------------------------------
bool TREM_DMCustQueryImpl::DeleteDoc(__int64 id)
{
return Object->DeleteDoc(id);
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::CloseDoc(void)
{
return Object->CloseDoc();
}
//---------------------------------------------------------------
void TREM_DMCustQueryImpl::AddNewRecordDv(void)
{
return Object->AddNewRecordDv();
}
//---------------------------------------------------------------
