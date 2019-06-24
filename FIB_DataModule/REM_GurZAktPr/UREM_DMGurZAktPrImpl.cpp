#include "vcl.h"
#pragma hdrstop


#include "UREM_DMGurZAktPrImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_DMGurZAktPrImpl::TREM_DMGurZAktPrImpl()           
{                                            
Object=new TREM_DMGurZAktPr(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_DMGurZAktPrImpl::~TREM_DMGurZAktPrImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_DMGurZAktPrImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_DMGurZAktPrImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_DMGurZAktPr)                        
   {                                                                     
   *ppv=static_cast<IREM_DMGurZAktPr*> (this);                                
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
int TREM_DMGurZAktPrImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_DMGurZAktPrImpl::kanRelease(void)                                  
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
int  TREM_DMGurZAktPrImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMGurZAktPrImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_DMGurZAktPrImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMGurZAktPrImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_DMGurZAktPrImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_DMGurZAktPrImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_DMGurZAktPrImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IREM_DMGurZAktPr
TDataSource * TREM_DMGurZAktPrImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TREM_DMGurZAktPrImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMGurZAktPrImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TREM_DMGurZAktPrImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMGurZAktPrImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TREM_DMGurZAktPrImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMGurZAktPrImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TREM_DMGurZAktPrImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMGurZAktPrImpl::get_TablePOS_REM_GALLDOC(void)
{
return Object->TablePOS_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMGurZAktPrImpl::set_TablePOS_REM_GALLDOC(TFIBDateTimeField * TablePOS_REM_GALLDOC)
{
Object->TablePOS_REM_GALLDOC=TablePOS_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMGurZAktPrImpl::get_TableNUM_REM_GALLDOC(void)
{
return Object->TableNUM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMGurZAktPrImpl::set_TableNUM_REM_GALLDOC(TFIBIntegerField * TableNUM_REM_GALLDOC)
{
Object->TableNUM_REM_GALLDOC=TableNUM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMGurZAktPrImpl::get_TablePOS_REM_Z(void)
{
return Object->TablePOS_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMGurZAktPrImpl::set_TablePOS_REM_Z(TFIBDateTimeField * TablePOS_REM_Z)
{
Object->TablePOS_REM_Z=TablePOS_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurZAktPrImpl::get_TablePREFIKS_NUM_REM_Z(void)
{
return Object->TablePREFIKS_NUM_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMGurZAktPrImpl::set_TablePREFIKS_NUM_REM_Z(TFIBWideStringField * TablePREFIKS_NUM_REM_Z)
{
Object->TablePREFIKS_NUM_REM_Z=TablePREFIKS_NUM_REM_Z;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMGurZAktPrImpl::get_TableNUM_REM_Z(void)
{
return Object->TableNUM_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMGurZAktPrImpl::set_TableNUM_REM_Z(TFIBIntegerField * TableNUM_REM_Z)
{
Object->TableNUM_REM_Z=TableNUM_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurZAktPrImpl::get_TableNUM_GARDOC_REM_Z(void)
{
return Object->TableNUM_GARDOC_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMGurZAktPrImpl::set_TableNUM_GARDOC_REM_Z(TFIBWideStringField * TableNUM_GARDOC_REM_Z)
{
Object->TableNUM_GARDOC_REM_Z=TableNUM_GARDOC_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurZAktPrImpl::get_TableSERNUM_REM_Z(void)
{
return Object->TableSERNUM_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMGurZAktPrImpl::set_TableSERNUM_REM_Z(TFIBWideStringField * TableSERNUM_REM_Z)
{
Object->TableSERNUM_REM_Z=TableSERNUM_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurZAktPrImpl::get_TableSERNUM2_REM_Z(void)
{
return Object->TableSERNUM2_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMGurZAktPrImpl::set_TableSERNUM2_REM_Z(TFIBWideStringField * TableSERNUM2_REM_Z)
{
Object->TableSERNUM2_REM_Z=TableSERNUM2_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurZAktPrImpl::get_TableNAMEFIRM(void)
{
return Object->TableNAMEFIRM;
}
//---------------------------------------------------------------
void TREM_DMGurZAktPrImpl::set_TableNAMEFIRM(TFIBWideStringField * TableNAMEFIRM)
{
Object->TableNAMEFIRM=TableNAMEFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurZAktPrImpl::get_TableNAMESKLAD(void)
{
return Object->TableNAMESKLAD;
}
//---------------------------------------------------------------
void TREM_DMGurZAktPrImpl::set_TableNAMESKLAD(TFIBWideStringField * TableNAMESKLAD)
{
Object->TableNAMESKLAD=TableNAMESKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurZAktPrImpl::get_TableNAMEKLIENT(void)
{
return Object->TableNAMEKLIENT;
}
//---------------------------------------------------------------
void TREM_DMGurZAktPrImpl::set_TableNAMEKLIENT(TFIBWideStringField * TableNAMEKLIENT)
{
Object->TableNAMEKLIENT=TableNAMEKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurZAktPrImpl::get_TableNAME_USER(void)
{
return Object->TableNAME_USER;
}
//---------------------------------------------------------------
void TREM_DMGurZAktPrImpl::set_TableNAME_USER(TFIBWideStringField * TableNAME_USER)
{
Object->TableNAME_USER=TableNAME_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurZAktPrImpl::get_TableNAME_SINFBASE_OBMEN(void)
{
return Object->TableNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void TREM_DMGurZAktPrImpl::set_TableNAME_SINFBASE_OBMEN(TFIBWideStringField * TableNAME_SINFBASE_OBMEN)
{
Object->TableNAME_SINFBASE_OBMEN=TableNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurZAktPrImpl::get_TableKLIENT_NAME_REM_DZAKTPR(void)
{
return Object->TableKLIENT_NAME_REM_DZAKTPR;
}
//---------------------------------------------------------------
void TREM_DMGurZAktPrImpl::set_TableKLIENT_NAME_REM_DZAKTPR(TFIBWideStringField * TableKLIENT_NAME_REM_DZAKTPR)
{
Object->TableKLIENT_NAME_REM_DZAKTPR=TableKLIENT_NAME_REM_DZAKTPR;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurZAktPrImpl::get_TableKLIENT_ADR_REM_DZAKTPR(void)
{
return Object->TableKLIENT_ADR_REM_DZAKTPR;
}
//---------------------------------------------------------------
void TREM_DMGurZAktPrImpl::set_TableKLIENT_ADR_REM_DZAKTPR(TFIBWideStringField * TableKLIENT_ADR_REM_DZAKTPR)
{
Object->TableKLIENT_ADR_REM_DZAKTPR=TableKLIENT_ADR_REM_DZAKTPR;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurZAktPrImpl::get_TableKLIENT_PHONE_REM_DZAKTPR(void)
{
return Object->TableKLIENT_PHONE_REM_DZAKTPR;
}
//---------------------------------------------------------------
void TREM_DMGurZAktPrImpl::set_TableKLIENT_PHONE_REM_DZAKTPR(TFIBWideStringField * TableKLIENT_PHONE_REM_DZAKTPR)
{
Object->TableKLIENT_PHONE_REM_DZAKTPR=TableKLIENT_PHONE_REM_DZAKTPR;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMGurZAktPrImpl::get_TableIDDOC_REM_DZAKTPR(void)
{
return Object->TableIDDOC_REM_DZAKTPR;
}
//---------------------------------------------------------------
void TREM_DMGurZAktPrImpl::set_TableIDDOC_REM_DZAKTPR(TFIBLargeIntField * TableIDDOC_REM_DZAKTPR)
{
Object->TableIDDOC_REM_DZAKTPR=TableIDDOC_REM_DZAKTPR;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMGurZAktPrImpl::get_TableFL_FICTIV_REM_DZAKTPR(void)
{
return Object->TableFL_FICTIV_REM_DZAKTPR;
}
//---------------------------------------------------------------
void TREM_DMGurZAktPrImpl::set_TableFL_FICTIV_REM_DZAKTPR(TFIBIntegerField * TableFL_FICTIV_REM_DZAKTPR)
{
Object->TableFL_FICTIV_REM_DZAKTPR=TableFL_FICTIV_REM_DZAKTPR;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMGurZAktPrImpl::get_TablePR_REM_GALLDOC(void)
{
return Object->TablePR_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMGurZAktPrImpl::set_TablePR_REM_GALLDOC(TFIBSmallIntField * TablePR_REM_GALLDOC)
{
Object->TablePR_REM_GALLDOC=TablePR_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurZAktPrImpl::get_TablePREFIKS_NUM_REM_GALLDOC(void)
{
return Object->TablePREFIKS_NUM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMGurZAktPrImpl::set_TablePREFIKS_NUM_REM_GALLDOC(TFIBWideStringField * TablePREFIKS_NUM_REM_GALLDOC)
{
Object->TablePREFIKS_NUM_REM_GALLDOC=TablePREFIKS_NUM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMGurZAktPrImpl::get_TableSUM_REM_GALLDOC(void)
{
return Object->TableSUM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMGurZAktPrImpl::set_TableSUM_REM_GALLDOC(TFIBBCDField * TableSUM_REM_GALLDOC)
{
Object->TableSUM_REM_GALLDOC=TableSUM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurZAktPrImpl::get_TableNAME_REM_SPRMODEL(void)
{
return Object->TableNAME_REM_SPRMODEL;
}
//---------------------------------------------------------------
void TREM_DMGurZAktPrImpl::set_TableNAME_REM_SPRMODEL(TFIBWideStringField * TableNAME_REM_SPRMODEL)
{
Object->TableNAME_REM_SPRMODEL=TableNAME_REM_SPRMODEL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurZAktPrImpl::get_TableNUMGARTALON_REM_DZAKTPR(void)
{
return Object->TableNUMGARTALON_REM_DZAKTPR;
}
//---------------------------------------------------------------
void TREM_DMGurZAktPrImpl::set_TableNUMGARTALON_REM_DZAKTPR(TFIBWideStringField * TableNUMGARTALON_REM_DZAKTPR)
{
Object->TableNUMGARTALON_REM_DZAKTPR=TableNUMGARTALON_REM_DZAKTPR;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMGurZAktPrImpl::get_TableFL_POVTOR_REM_Z(void)
{
return Object->TableFL_POVTOR_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMGurZAktPrImpl::set_TableFL_POVTOR_REM_Z(TFIBSmallIntField * TableFL_POVTOR_REM_Z)
{
Object->TableFL_POVTOR_REM_Z=TableFL_POVTOR_REM_Z;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMGurZAktPrImpl::get_TableFL_ADDREPORT_REM_Z(void)
{
return Object->TableFL_ADDREPORT_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMGurZAktPrImpl::set_TableFL_ADDREPORT_REM_Z(TFIBSmallIntField * TableFL_ADDREPORT_REM_Z)
{
Object->TableFL_ADDREPORT_REM_Z=TableFL_ADDREPORT_REM_Z;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMGurZAktPrImpl::get_TableFL_FICTIV_REM_Z(void)
{
return Object->TableFL_FICTIV_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMGurZAktPrImpl::set_TableFL_FICTIV_REM_Z(TFIBIntegerField * TableFL_FICTIV_REM_Z)
{
Object->TableFL_FICTIV_REM_Z=TableFL_FICTIV_REM_Z;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMGurZAktPrImpl::get_TableFL_NE_OTCH_REM_Z(void)
{
return Object->TableFL_NE_OTCH_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMGurZAktPrImpl::set_TableFL_NE_OTCH_REM_Z(TFIBSmallIntField * TableFL_NE_OTCH_REM_Z)
{
Object->TableFL_NE_OTCH_REM_Z=TableFL_NE_OTCH_REM_Z;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMGurZAktPrImpl::get_TableFL_NADO_OTCH_REM_Z(void)
{
return Object->TableFL_NADO_OTCH_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMGurZAktPrImpl::set_TableFL_NADO_OTCH_REM_Z(TFIBSmallIntField * TableFL_NADO_OTCH_REM_Z)
{
Object->TableFL_NADO_OTCH_REM_Z=TableFL_NADO_OTCH_REM_Z;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMGurZAktPrImpl::get_TableFL_NE_OTCH_REM_DZAKTPR(void)
{
return Object->TableFL_NE_OTCH_REM_DZAKTPR;
}
//---------------------------------------------------------------
void TREM_DMGurZAktPrImpl::set_TableFL_NE_OTCH_REM_DZAKTPR(TFIBSmallIntField * TableFL_NE_OTCH_REM_DZAKTPR)
{
Object->TableFL_NE_OTCH_REM_DZAKTPR=TableFL_NE_OTCH_REM_DZAKTPR;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMGurZAktPrImpl::get_TableFL_NADO_OTCH_REM_DZAKTPR(void)
{
return Object->TableFL_NADO_OTCH_REM_DZAKTPR;
}
//---------------------------------------------------------------
void TREM_DMGurZAktPrImpl::set_TableFL_NADO_OTCH_REM_DZAKTPR(TFIBSmallIntField * TableFL_NADO_OTCH_REM_DZAKTPR)
{
Object->TableFL_NADO_OTCH_REM_DZAKTPR=TableFL_NADO_OTCH_REM_DZAKTPR;
}
//---------------------------------------------------------------
TIntegerField * TREM_DMGurZAktPrImpl::get_TableSROK_REMONTA(void)
{
return Object->TableSROK_REMONTA;
}
//---------------------------------------------------------------
void TREM_DMGurZAktPrImpl::set_TableSROK_REMONTA(TIntegerField * TableSROK_REMONTA)
{
Object->TableSROK_REMONTA=TableSROK_REMONTA;
}
//---------------------------------------------------------------
TIntegerField * TREM_DMGurZAktPrImpl::get_TableSROK_REMONTA_NOW(void)
{
return Object->TableSROK_REMONTA_NOW;
}
//---------------------------------------------------------------
void TREM_DMGurZAktPrImpl::set_TableSROK_REMONTA_NOW(TIntegerField * TableSROK_REMONTA_NOW)
{
Object->TableSROK_REMONTA_NOW=TableSROK_REMONTA_NOW;
}
//---------------------------------------------------------------
TIntegerField * TREM_DMGurZAktPrImpl::get_TableSROK_REMONTA_IS_DOC(void)
{
return Object->TableSROK_REMONTA_IS_DOC;
}
//---------------------------------------------------------------
void TREM_DMGurZAktPrImpl::set_TableSROK_REMONTA_IS_DOC(TIntegerField * TableSROK_REMONTA_IS_DOC)
{
Object->TableSROK_REMONTA_IS_DOC=TableSROK_REMONTA_IS_DOC;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMGurZAktPrImpl::get_TablePOSPRIEMA_REM_DZAKTPR(void)
{
return Object->TablePOSPRIEMA_REM_DZAKTPR;
}
//---------------------------------------------------------------
void TREM_DMGurZAktPrImpl::set_TablePOSPRIEMA_REM_DZAKTPR(TFIBDateTimeField * TablePOSPRIEMA_REM_DZAKTPR)
{
Object->TablePOSPRIEMA_REM_DZAKTPR=TablePOSPRIEMA_REM_DZAKTPR;
}
//---------------------------------------------------------------
TDateTime TREM_DMGurZAktPrImpl::get_PosNach(void)
{
return Object->PosNach;
}
//---------------------------------------------------------------
void TREM_DMGurZAktPrImpl::set_PosNach(TDateTime PosNach)
{
Object->PosNach=PosNach;
}
//---------------------------------------------------------------
TDateTime TREM_DMGurZAktPrImpl::get_PosCon(void)
{
return Object->PosCon;
}
//---------------------------------------------------------------
void TREM_DMGurZAktPrImpl::set_PosCon(TDateTime PosCon)
{
Object->PosCon=PosCon;
}
//---------------------------------------------------------------
__int64 TREM_DMGurZAktPrImpl::get_IdDoc(void)
{
return Object->IdDoc;
}
//---------------------------------------------------------------
void TREM_DMGurZAktPrImpl::set_IdDoc(__int64 IdDoc)
{
Object->IdDoc=IdDoc;
}
//---------------------------------------------------------------
__int64 TREM_DMGurZAktPrImpl::get_IdKlient(void)
{
return Object->IdKlient;
}
//---------------------------------------------------------------
void TREM_DMGurZAktPrImpl::set_IdKlient(__int64 IdKlient)
{
Object->IdKlient=IdKlient;
}
//---------------------------------------------------------------
__int64 TREM_DMGurZAktPrImpl::get_IdSklad(void)
{
return Object->IdSklad;
}
//---------------------------------------------------------------
void TREM_DMGurZAktPrImpl::set_IdSklad(__int64 IdSklad)
{
Object->IdSklad=IdSklad;
}
//---------------------------------------------------------------
__int64 TREM_DMGurZAktPrImpl::get_IdFirm(void)
{
return Object->IdFirm;
}
//---------------------------------------------------------------
void TREM_DMGurZAktPrImpl::set_IdFirm(__int64 IdFirm)
{
Object->IdFirm=IdFirm;
}
//---------------------------------------------------------------
void TREM_DMGurZAktPrImpl::OpenTable()
{
return Object->OpenTable();
}
//---------------------------------------------------------------
void TREM_DMGurZAktPrImpl::UpdateTable(void)
{
return Object->UpdateTable();
}
//---------------------------------------------------------------
bool TREM_DMGurZAktPrImpl::OpenTableOnlyHardware(__int64 id_hw)
{
return Object->OpenTableOnlyHardware(id_hw);
}
//---------------------------------------------------------------
bool TREM_DMGurZAktPrImpl::OpenTableOnlyZayavka(__int64 id_z)
{
return Object->OpenTableOnlyZayavka(id_z);
}
//---------------------------------------------------------------
void TREM_DMGurZAktPrImpl::PoiskPoSerNum1(UnicodeString ser_num)
{
return Object->PoiskPoSerNum1(ser_num);
}
//---------------------------------------------------------------
void TREM_DMGurZAktPrImpl::PoiskPoSerNum2(UnicodeString ser_num)
{
return Object->PoiskPoSerNum2(ser_num);
}
//---------------------------------------------------------------
void TREM_DMGurZAktPrImpl::PoiskPoKlient(UnicodeString value)
{
return Object->PoiskPoKlient(value);
}
//---------------------------------------------------------------
void TREM_DMGurZAktPrImpl::PoiskPoModel(UnicodeString value)
{
return Object->PoiskPoModel(value);
}
//---------------------------------------------------------------
void TREM_DMGurZAktPrImpl::PoiskPoIdHardware(__int64 id_hw)
{
return Object->PoiskPoIdHardware(id_hw);
}
//---------------------------------------------------------------
void TREM_DMGurZAktPrImpl::PoiskPoNumGarDoc(UnicodeString num_gar_doc)
{
return Object->PoiskPoNumGarDoc(num_gar_doc);
}
//---------------------------------------------------------------
