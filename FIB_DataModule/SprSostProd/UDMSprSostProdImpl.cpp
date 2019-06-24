#include "vcl.h"
#pragma hdrstop


#include "UDMSprSostProdImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprSostProdImpl::TDMSprSostProdImpl()           
{                                            
Object=new TDMSprSostProd(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprSostProdImpl::~TDMSprSostProdImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprSostProdImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprSostProdImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprSostProd)                        
   {                                                                     
   *ppv=static_cast<IDMSprSostProd*> (this);                                
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
int TDMSprSostProdImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprSostProdImpl::kanRelease(void)                                  
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
int  TDMSprSostProdImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprSostProdImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprSostProdImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprSostProdImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprSostProdImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMSprSostProdImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMSprSostProdImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMSprSostProd
TDataSource * TDMSprSostProdImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprSostProdImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprSostProdImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprSostProdImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprSostProdImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprSostProdImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprSostProdImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprSostProdImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprSostProdImpl::get_TableNKOL_SPROD(void)
{
return Object->TableNKOL_SPROD;
}
//---------------------------------------------------------------
void TDMSprSostProdImpl::set_TableNKOL_SPROD(TFIBBCDField * TableNKOL_SPROD)
{
Object->TableNKOL_SPROD=TableNKOL_SPROD;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprSostProdImpl::get_TableBKOL_SPROD(void)
{
return Object->TableBKOL_SPROD;
}
//---------------------------------------------------------------
void TDMSprSostProdImpl::set_TableBKOL_SPROD(TFIBBCDField * TableBKOL_SPROD)
{
Object->TableBKOL_SPROD=TableBKOL_SPROD;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprSostProdImpl::get_TableKFPRICE_SPROD(void)
{
return Object->TableKFPRICE_SPROD;
}
//---------------------------------------------------------------
void TDMSprSostProdImpl::set_TableKFPRICE_SPROD(TFIBBCDField * TableKFPRICE_SPROD)
{
Object->TableKFPRICE_SPROD=TableKFPRICE_SPROD;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprSostProdImpl::get_TableSPIS_SPROD(void)
{
return Object->TableSPIS_SPROD;
}
//---------------------------------------------------------------
void TDMSprSostProdImpl::set_TableSPIS_SPROD(TFIBSmallIntField * TableSPIS_SPROD)
{
Object->TableSPIS_SPROD=TableSPIS_SPROD;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprSostProdImpl::get_TableKF_SPROD(void)
{
return Object->TableKF_SPROD;
}
//---------------------------------------------------------------
void TDMSprSostProdImpl::set_TableKF_SPROD(TFIBBCDField * TableKF_SPROD)
{
Object->TableKF_SPROD=TableKF_SPROD;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprSostProdImpl::get_TableTNOM(void)
{
return Object->TableTNOM;
}
//---------------------------------------------------------------
void TDMSprSostProdImpl::set_TableTNOM(TFIBIntegerField * TableTNOM)
{
Object->TableTNOM=TableTNOM;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprSostProdImpl::get_TableVALUE_SSEZKF(void)
{
return Object->TableVALUE_SSEZKF;
}
//---------------------------------------------------------------
void TDMSprSostProdImpl::set_TableVALUE_SSEZKF(TFIBBCDField * TableVALUE_SSEZKF)
{
Object->TableVALUE_SSEZKF=TableVALUE_SSEZKF;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprSostProdImpl::get_TableVALUE_SSEZKF_SPROD(void)
{
return Object->TableVALUE_SSEZKF_SPROD;
}
//---------------------------------------------------------------
void TDMSprSostProdImpl::set_TableVALUE_SSEZKF_SPROD(TFIBBCDField * TableVALUE_SSEZKF_SPROD)
{
Object->TableVALUE_SSEZKF_SPROD=TableVALUE_SSEZKF_SPROD;
}
//---------------------------------------------------------------
TIntegerField * TDMSprSostProdImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TDMSprSostProdImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TFloatField * TDMSprSostProdImpl::get_TableNABASED(void)
{
return Object->TableNABASED;
}
//---------------------------------------------------------------
void TDMSprSostProdImpl::set_TableNABASED(TFloatField * TableNABASED)
{
Object->TableNABASED=TableNABASED;
}
//---------------------------------------------------------------
TFloatField * TDMSprSostProdImpl::get_TableNNABASED(void)
{
return Object->TableNNABASED;
}
//---------------------------------------------------------------
void TDMSprSostProdImpl::set_TableNNABASED(TFloatField * TableNNABASED)
{
Object->TableNNABASED=TableNNABASED;
}
//---------------------------------------------------------------
TFloatField * TDMSprSostProdImpl::get_TableSEZKF(void)
{
return Object->TableSEZKF;
}
//---------------------------------------------------------------
void TDMSprSostProdImpl::set_TableSEZKF(TFloatField * TableSEZKF)
{
Object->TableSEZKF=TableSEZKF;
}
//---------------------------------------------------------------
TFloatField * TDMSprSostProdImpl::get_TableSEZKF_SPROD(void)
{
return Object->TableSEZKF_SPROD;
}
//---------------------------------------------------------------
void TDMSprSostProdImpl::set_TableSEZKF_SPROD(TFloatField * TableSEZKF_SPROD)
{
Object->TableSEZKF_SPROD=TableSEZKF_SPROD;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprSostProdImpl::get_TableID_SPROD(void)
{
return Object->TableID_SPROD;
}
//---------------------------------------------------------------
void TDMSprSostProdImpl::set_TableID_SPROD(TFIBBCDField * TableID_SPROD)
{
Object->TableID_SPROD=TableID_SPROD;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprSostProdImpl::get_TableIDNOMREST_SPROD(void)
{
return Object->TableIDNOMREST_SPROD;
}
//---------------------------------------------------------------
void TDMSprSostProdImpl::set_TableIDNOMREST_SPROD(TFIBBCDField * TableIDNOMREST_SPROD)
{
Object->TableIDNOMREST_SPROD=TableIDNOMREST_SPROD;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprSostProdImpl::get_TableIDKOMPL_SPROD(void)
{
return Object->TableIDKOMPL_SPROD;
}
//---------------------------------------------------------------
void TDMSprSostProdImpl::set_TableIDKOMPL_SPROD(TFIBBCDField * TableIDKOMPL_SPROD)
{
Object->TableIDKOMPL_SPROD=TableIDKOMPL_SPROD;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprSostProdImpl::get_TableIDED_SPROD(void)
{
return Object->TableIDED_SPROD;
}
//---------------------------------------------------------------
void TDMSprSostProdImpl::set_TableIDED_SPROD(TFIBBCDField * TableIDED_SPROD)
{
Object->TableIDED_SPROD=TableIDED_SPROD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprSostProdImpl::get_TableGID_SSPROD(void)
{
return Object->TableGID_SSPROD;
}
//---------------------------------------------------------------
void TDMSprSostProdImpl::set_TableGID_SSPROD(TFIBWideStringField * TableGID_SSPROD)
{
Object->TableGID_SSPROD=TableGID_SSPROD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprSostProdImpl::get_TableNAMENOM(void)
{
return Object->TableNAMENOM;
}
//---------------------------------------------------------------
void TDMSprSostProdImpl::set_TableNAMENOM(TFIBWideStringField * TableNAMENOM)
{
Object->TableNAMENOM=TableNAMENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprSostProdImpl::get_TableNAMEED(void)
{
return Object->TableNAMEED;
}
//---------------------------------------------------------------
void TDMSprSostProdImpl::set_TableNAMEED(TFIBWideStringField * TableNAMEED)
{
Object->TableNAMEED=TableNAMEED;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprSostProdImpl::get_TableIDPRODUCE_SSPROD(void)
{
return Object->TableIDPRODUCE_SSPROD;
}
//---------------------------------------------------------------
void TDMSprSostProdImpl::set_TableIDPRODUCE_SSPROD(TFIBBCDField * TableIDPRODUCE_SSPROD)
{
Object->TableIDPRODUCE_SSPROD=TableIDPRODUCE_SSPROD;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprSostProdImpl::get_TableIDLOSTFACTOR_SSPROD(void)
{
return Object->TableIDLOSTFACTOR_SSPROD;
}
//---------------------------------------------------------------
void TDMSprSostProdImpl::set_TableIDLOSTFACTOR_SSPROD(TFIBBCDField * TableIDLOSTFACTOR_SSPROD)
{
Object->TableIDLOSTFACTOR_SSPROD=TableIDLOSTFACTOR_SSPROD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprSostProdImpl::get_TableNAME_SPRODUCE(void)
{
return Object->TableNAME_SPRODUCE;
}
//---------------------------------------------------------------
void TDMSprSostProdImpl::set_TableNAME_SPRODUCE(TFIBWideStringField * TableNAME_SPRODUCE)
{
Object->TableNAME_SPRODUCE=TableNAME_SPRODUCE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprSostProdImpl::get_TableNAME_SLOSS_FACTOR(void)
{
return Object->TableNAME_SLOSS_FACTOR;
}
//---------------------------------------------------------------
void TDMSprSostProdImpl::set_TableNAME_SLOSS_FACTOR(TFIBWideStringField * TableNAME_SLOSS_FACTOR)
{
Object->TableNAME_SLOSS_FACTOR=TableNAME_SLOSS_FACTOR;
}
//---------------------------------------------------------------
__int64 TDMSprSostProdImpl::get_IdNom(void)
{
return Object->IdNom;
}
//---------------------------------------------------------------
void TDMSprSostProdImpl::set_IdNom(__int64 IdNom)
{
Object->IdNom=IdNom;
}
//---------------------------------------------------------------
__int64 TDMSprSostProdImpl::get_IdNomRest(void)
{
return Object->IdNomRest;
}
//---------------------------------------------------------------
void TDMSprSostProdImpl::set_IdNomRest(__int64 IdNomRest)
{
Object->IdNomRest=IdNomRest;
}
//---------------------------------------------------------------
float TDMSprSostProdImpl::get_KolEdProd(void)
{
return Object->KolEdProd;
}
//---------------------------------------------------------------
void TDMSprSostProdImpl::set_KolEdProd(float KolEdProd)
{
Object->KolEdProd=KolEdProd;
}
//---------------------------------------------------------------
float TDMSprSostProdImpl::get_KFEdProd(void)
{
return Object->KFEdProd;
}
//---------------------------------------------------------------
void TDMSprSostProdImpl::set_KFEdProd(float KFEdProd)
{
Object->KFEdProd=KFEdProd;
}
//---------------------------------------------------------------
TDateTime TDMSprSostProdImpl::get_Pos(void)
{
return Object->Pos;
}
//---------------------------------------------------------------
void TDMSprSostProdImpl::set_Pos(TDateTime Pos)
{
Object->Pos=Pos;
}
//---------------------------------------------------------------
void TDMSprSostProdImpl::OpenTable(__int64 Nom)
{
return Object->OpenTable(Nom);
}
//---------------------------------------------------------------
void TDMSprSostProdImpl::NewElement(__int64 Nom)
{
return Object->NewElement(Nom);
}
//---------------------------------------------------------------
void TDMSprSostProdImpl::DeleteElement()
{
return Object->DeleteElement();
}
//---------------------------------------------------------------
void TDMSprSostProdImpl::SaveIsmen()
{
return Object->SaveIsmen();
}
//---------------------------------------------------------------
void TDMSprSostProdImpl::CancelIsmen()
{
return Object->CancelIsmen();
}
//---------------------------------------------------------------
