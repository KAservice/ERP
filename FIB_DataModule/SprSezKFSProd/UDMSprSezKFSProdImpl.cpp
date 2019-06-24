#include <vcl.h>
#pragma hdrstop


#include "UDMSprSezKFSProdImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprSezKFSProdImpl::TDMSprSezKFSProdImpl()           
{                                            
Object=new TDMSprSezKFSProd(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprSezKFSProdImpl::~TDMSprSezKFSProdImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprSezKFSProdImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprSezKFSProdImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprSezKFSProd)                        
   {                                                                     
   *ppv=static_cast<IDMSprSezKFSProd*> (this);                                
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
int TDMSprSezKFSProdImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprSezKFSProdImpl::kanRelease(void)                                  
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

//---------------------------------------------------------------
int  TDMSprSezKFSProdImpl::get_CodeError(void)                      
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprSezKFSProdImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprSezKFSProdImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprSezKFSProdImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprSezKFSProdImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object)
{
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl);
kanRelease();
Object->ClsIdImpl=CLSID_TDMSprSezKFSProdImpl;
Object->InterfaceMainObject=i_main_object;
Object->InterfaceOwnerObject=i_owner_object;
return Object->Init();
}
//---------------------------------------------------------------
int TDMSprSezKFSProdImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//INameModulEdit->Text
TDataSource * TDMSprSezKFSProdImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprSezKFSProdImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprSezKFSProdImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprSezKFSProdImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprSezKFSProdImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprSezKFSProdImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprSezKFSProdImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprSezKFSProdImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprSezKFSProdImpl::get_TableMONTH_SSEZKF_SPROD(void)
{
return Object->TableMONTH_SSEZKF_SPROD;
}
//---------------------------------------------------------------
void TDMSprSezKFSProdImpl::set_TableMONTH_SSEZKF_SPROD(TFIBIntegerField * TableMONTH_SSEZKF_SPROD)
{
Object->TableMONTH_SSEZKF_SPROD=TableMONTH_SSEZKF_SPROD;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprSezKFSProdImpl::get_TableVALUE_SSEZKF_SPROD(void)
{
return Object->TableVALUE_SSEZKF_SPROD;
}
//---------------------------------------------------------------
void TDMSprSezKFSProdImpl::set_TableVALUE_SSEZKF_SPROD(TFIBBCDField * TableVALUE_SSEZKF_SPROD)
{
Object->TableVALUE_SSEZKF_SPROD=TableVALUE_SSEZKF_SPROD;
}
//---------------------------------------------------------------
TIntegerField * TDMSprSezKFSProdImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TDMSprSezKFSProdImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprSezKFSProdImpl::get_TableID_SSEZKF_SPROD(void)
{
return Object->TableID_SSEZKF_SPROD;
}
//---------------------------------------------------------------
void TDMSprSezKFSProdImpl::set_TableID_SSEZKF_SPROD(TFIBBCDField * TableID_SSEZKF_SPROD)
{
Object->TableID_SSEZKF_SPROD=TableID_SSEZKF_SPROD;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprSezKFSProdImpl::get_TableIDSSPROD_SSEZKF_SPROD(void)
{
return Object->TableIDSSPROD_SSEZKF_SPROD;
}
//---------------------------------------------------------------
void TDMSprSezKFSProdImpl::set_TableIDSSPROD_SSEZKF_SPROD(TFIBBCDField * TableIDSSPROD_SSEZKF_SPROD)
{
Object->TableIDSSPROD_SSEZKF_SPROD=TableIDSSPROD_SSEZKF_SPROD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprSezKFSProdImpl::get_TableGID_SSEZKF_SPROD(void)
{
return Object->TableGID_SSEZKF_SPROD;
}
//---------------------------------------------------------------
void TDMSprSezKFSProdImpl::set_TableGID_SSEZKF_SPROD(TFIBWideStringField * TableGID_SSEZKF_SPROD)
{
Object->TableGID_SSEZKF_SPROD=TableGID_SSEZKF_SPROD;
}
//---------------------------------------------------------------
__int64 TDMSprSezKFSProdImpl::get_IdSProd(void)
{
return Object->IdSProd;
}
//---------------------------------------------------------------
void TDMSprSezKFSProdImpl::set_IdSProd(__int64 IdSProd)
{
Object->IdSProd=IdSProd;
}
//---------------------------------------------------------------
void TDMSprSezKFSProdImpl::OpenTable(__int64 idSProd)
{
return Object->OpenTable(idSProd);
}
//---------------------------------------------------------------
void TDMSprSezKFSProdImpl::NewElement(__int64 idSProd)
{
return Object->NewElement(idSProd);
}
//---------------------------------------------------------------
void TDMSprSezKFSProdImpl::DeleteElement()
{
return Object->DeleteElement();
}
//---------------------------------------------------------------
void TDMSprSezKFSProdImpl::SaveIsmen()
{
return Object->SaveIsmen();
}
//---------------------------------------------------------------
void TDMSprSezKFSProdImpl::CancelIsmen()
{
return Object->CancelIsmen();
}
//---------------------------------------------------------------
