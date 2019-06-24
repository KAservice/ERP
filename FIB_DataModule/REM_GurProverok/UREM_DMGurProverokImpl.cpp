#include "vcl.h"
#pragma hdrstop


#include "UREM_DMGurProverokImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_DMGurProverokImpl::TREM_DMGurProverokImpl()           
{                                            
Object=new TREM_DMGurProverok(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_DMGurProverokImpl::~TREM_DMGurProverokImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_DMGurProverokImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_DMGurProverokImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_DMGurProverok)                        
   {                                                                     
   *ppv=static_cast<IREM_DMGurProverok*> (this);                                
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
int TREM_DMGurProverokImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_DMGurProverokImpl::kanRelease(void)                                  
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
int  TREM_DMGurProverokImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMGurProverokImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_DMGurProverokImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMGurProverokImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_DMGurProverokImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_DMGurProverokImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_DMGurProverokImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IREM_DMGurProverok
TDataSource * TREM_DMGurProverokImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TREM_DMGurProverokImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMGurProverokImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TREM_DMGurProverokImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMGurProverokImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TREM_DMGurProverokImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMGurProverokImpl::get_IBQ(void)
{
return Object->IBQ;
}
//---------------------------------------------------------------
void TREM_DMGurProverokImpl::set_IBQ(TpFIBDataSet * IBQ)
{
Object->IBQ=IBQ;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMGurProverokImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TREM_DMGurProverokImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMGurProverokImpl::get_TableID_REM_GUR_PROV(void)
{
return Object->TableID_REM_GUR_PROV;
}
//---------------------------------------------------------------
void TREM_DMGurProverokImpl::set_TableID_REM_GUR_PROV(TFIBLargeIntField * TableID_REM_GUR_PROV)
{
Object->TableID_REM_GUR_PROV=TableID_REM_GUR_PROV;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMGurProverokImpl::get_TableIDBASE_REM_GUR_PROV(void)
{
return Object->TableIDBASE_REM_GUR_PROV;
}
//---------------------------------------------------------------
void TREM_DMGurProverokImpl::set_TableIDBASE_REM_GUR_PROV(TFIBLargeIntField * TableIDBASE_REM_GUR_PROV)
{
Object->TableIDBASE_REM_GUR_PROV=TableIDBASE_REM_GUR_PROV;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMGurProverokImpl::get_TablePOS_REM_GUR_PROV(void)
{
return Object->TablePOS_REM_GUR_PROV;
}
//---------------------------------------------------------------
void TREM_DMGurProverokImpl::set_TablePOS_REM_GUR_PROV(TFIBDateTimeField * TablePOS_REM_GUR_PROV)
{
Object->TablePOS_REM_GUR_PROV=TablePOS_REM_GUR_PROV;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMGurProverokImpl::get_TableNUM_REM_GUR_PROV(void)
{
return Object->TableNUM_REM_GUR_PROV;
}
//---------------------------------------------------------------
void TREM_DMGurProverokImpl::set_TableNUM_REM_GUR_PROV(TFIBIntegerField * TableNUM_REM_GUR_PROV)
{
Object->TableNUM_REM_GUR_PROV=TableNUM_REM_GUR_PROV;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurProverokImpl::get_TableDESCR_REM_GUR_PROV(void)
{
return Object->TableDESCR_REM_GUR_PROV;
}
//---------------------------------------------------------------
void TREM_DMGurProverokImpl::set_TableDESCR_REM_GUR_PROV(TFIBWideStringField * TableDESCR_REM_GUR_PROV)
{
Object->TableDESCR_REM_GUR_PROV=TableDESCR_REM_GUR_PROV;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMGurProverokImpl::get_TableIDDOC_REM_GUR_PROV(void)
{
return Object->TableIDDOC_REM_GUR_PROV;
}
//---------------------------------------------------------------
void TREM_DMGurProverokImpl::set_TableIDDOC_REM_GUR_PROV(TFIBLargeIntField * TableIDDOC_REM_GUR_PROV)
{
Object->TableIDDOC_REM_GUR_PROV=TableIDDOC_REM_GUR_PROV;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMGurProverokImpl::get_TableIDUSER_REM_GUR_PROV(void)
{
return Object->TableIDUSER_REM_GUR_PROV;
}
//---------------------------------------------------------------
void TREM_DMGurProverokImpl::set_TableIDUSER_REM_GUR_PROV(TFIBLargeIntField * TableIDUSER_REM_GUR_PROV)
{
Object->TableIDUSER_REM_GUR_PROV=TableIDUSER_REM_GUR_PROV;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMGurProverokImpl::get_TableRES_REM_GUR_PROV(void)
{
return Object->TableRES_REM_GUR_PROV;
}
//---------------------------------------------------------------
void TREM_DMGurProverokImpl::set_TableRES_REM_GUR_PROV(TFIBIntegerField * TableRES_REM_GUR_PROV)
{
Object->TableRES_REM_GUR_PROV=TableRES_REM_GUR_PROV;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurProverokImpl::get_TableNAMEFIRM(void)
{
return Object->TableNAMEFIRM;
}
//---------------------------------------------------------------
void TREM_DMGurProverokImpl::set_TableNAMEFIRM(TFIBWideStringField * TableNAMEFIRM)
{
Object->TableNAMEFIRM=TableNAMEFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurProverokImpl::get_TableNAMESKLAD(void)
{
return Object->TableNAMESKLAD;
}
//---------------------------------------------------------------
void TREM_DMGurProverokImpl::set_TableNAMESKLAD(TFIBWideStringField * TableNAMESKLAD)
{
Object->TableNAMESKLAD=TableNAMESKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurProverokImpl::get_TableNAMEKLIENT(void)
{
return Object->TableNAMEKLIENT;
}
//---------------------------------------------------------------
void TREM_DMGurProverokImpl::set_TableNAMEKLIENT(TFIBWideStringField * TableNAMEKLIENT)
{
Object->TableNAMEKLIENT=TableNAMEKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurProverokImpl::get_TableNAME_USER_DOC(void)
{
return Object->TableNAME_USER_DOC;
}
//---------------------------------------------------------------
void TREM_DMGurProverokImpl::set_TableNAME_USER_DOC(TFIBWideStringField * TableNAME_USER_DOC)
{
Object->TableNAME_USER_DOC=TableNAME_USER_DOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurProverokImpl::get_TableNAME_USER_PROV(void)
{
return Object->TableNAME_USER_PROV;
}
//---------------------------------------------------------------
void TREM_DMGurProverokImpl::set_TableNAME_USER_PROV(TFIBWideStringField * TableNAME_USER_PROV)
{
Object->TableNAME_USER_PROV=TableNAME_USER_PROV;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurProverokImpl::get_TableNAME_SINFBASE_OBMEN(void)
{
return Object->TableNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void TREM_DMGurProverokImpl::set_TableNAME_SINFBASE_OBMEN(TFIBWideStringField * TableNAME_SINFBASE_OBMEN)
{
Object->TableNAME_SINFBASE_OBMEN=TableNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurProverokImpl::get_TablePREFIKS_NUM_REM_GALLDOC(void)
{
return Object->TablePREFIKS_NUM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMGurProverokImpl::set_TablePREFIKS_NUM_REM_GALLDOC(TFIBWideStringField * TablePREFIKS_NUM_REM_GALLDOC)
{
Object->TablePREFIKS_NUM_REM_GALLDOC=TablePREFIKS_NUM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMGurProverokImpl::get_TablePR_REM_GALLDOC(void)
{
return Object->TablePR_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMGurProverokImpl::set_TablePR_REM_GALLDOC(TFIBSmallIntField * TablePR_REM_GALLDOC)
{
Object->TablePR_REM_GALLDOC=TablePR_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMGurProverokImpl::get_TableNUM_REM_GALLDOC(void)
{
return Object->TableNUM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMGurProverokImpl::set_TableNUM_REM_GALLDOC(TFIBIntegerField * TableNUM_REM_GALLDOC)
{
Object->TableNUM_REM_GALLDOC=TableNUM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMGurProverokImpl::get_TablePOS_REM_GALLDOC(void)
{
return Object->TablePOS_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMGurProverokImpl::set_TablePOS_REM_GALLDOC(TFIBDateTimeField * TablePOS_REM_GALLDOC)
{
Object->TablePOS_REM_GALLDOC=TablePOS_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurProverokImpl::get_TableTDOC_REM_GALLDOC(void)
{
return Object->TableTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMGurProverokImpl::set_TableTDOC_REM_GALLDOC(TFIBWideStringField * TableTDOC_REM_GALLDOC)
{
Object->TableTDOC_REM_GALLDOC=TableTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
TDateTime TREM_DMGurProverokImpl::get_PosNach(void)
{
return Object->PosNach;
}
//---------------------------------------------------------------
void TREM_DMGurProverokImpl::set_PosNach(TDateTime PosNach)
{
Object->PosNach=PosNach;
}
//---------------------------------------------------------------
TDateTime TREM_DMGurProverokImpl::get_PosCon(void)
{
return Object->PosCon;
}
//---------------------------------------------------------------
void TREM_DMGurProverokImpl::set_PosCon(TDateTime PosCon)
{
Object->PosCon=PosCon;
}
//---------------------------------------------------------------
__int64 TREM_DMGurProverokImpl::get_IdDoc(void)
{
return Object->IdDoc;
}
//---------------------------------------------------------------
void TREM_DMGurProverokImpl::set_IdDoc(__int64 IdDoc)
{
Object->IdDoc=IdDoc;
}
//---------------------------------------------------------------
__int64 TREM_DMGurProverokImpl::get_IdKlient(void)
{
return Object->IdKlient;
}
//---------------------------------------------------------------
void TREM_DMGurProverokImpl::set_IdKlient(__int64 IdKlient)
{
Object->IdKlient=IdKlient;
}
//---------------------------------------------------------------
__int64 TREM_DMGurProverokImpl::get_IdSklad(void)
{
return Object->IdSklad;
}
//---------------------------------------------------------------
void TREM_DMGurProverokImpl::set_IdSklad(__int64 IdSklad)
{
Object->IdSklad=IdSklad;
}
//---------------------------------------------------------------
__int64 TREM_DMGurProverokImpl::get_IdFirm(void)
{
return Object->IdFirm;
}
//---------------------------------------------------------------
void TREM_DMGurProverokImpl::set_IdFirm(__int64 IdFirm)
{
Object->IdFirm=IdFirm;
}
//---------------------------------------------------------------
UnicodeString TREM_DMGurProverokImpl::get_StringTypeDoc(void)
{
return Object->StringTypeDoc;
}
//---------------------------------------------------------------
void TREM_DMGurProverokImpl::set_StringTypeDoc(UnicodeString StringTypeDoc)
{
Object->StringTypeDoc=StringTypeDoc;
}
//---------------------------------------------------------------
bool TREM_DMGurProverokImpl::get_OtborVkl(void)
{
return Object->OtborVkl;
}
//---------------------------------------------------------------
void TREM_DMGurProverokImpl::set_OtborVkl(bool OtborVkl)
{
Object->OtborVkl=OtborVkl;
}
//---------------------------------------------------------------
void TREM_DMGurProverokImpl::OpenTable()
{
return Object->OpenTable();
}
//---------------------------------------------------------------
void TREM_DMGurProverokImpl::UpdateTable(void)
{
return Object->UpdateTable();
}
//---------------------------------------------------------------
