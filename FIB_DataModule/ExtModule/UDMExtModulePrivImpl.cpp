#include "vcl.h"
#pragma hdrstop


#include "UDMExtModulePrivImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMExtModulePrivImpl::TDMExtModulePrivImpl()           
{                                            
Object=new TDMExtModulePriv(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMExtModulePrivImpl::~TDMExtModulePrivImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMExtModulePrivImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMExtModulePrivImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMExtModulePriv)                        
   {                                                                     
   *ppv=static_cast<IDMExtModulePriv*> (this);                                
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
int TDMExtModulePrivImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMExtModulePrivImpl::kanRelease(void)                                  
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
int  TDMExtModulePrivImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMExtModulePrivImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMExtModulePrivImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMExtModulePrivImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMExtModulePrivImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl);
kanRelease();
Object->ClsIdImpl=CLSID_TDMExtModulePrivImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMExtModulePrivImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMExtModulePriv
TDataSource * TDMExtModulePrivImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMExtModulePrivImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMExtModulePrivImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMExtModulePrivImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMExtModulePrivImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMExtModulePrivImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMExtModulePrivImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMExtModulePrivImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TFIBBCDField * TDMExtModulePrivImpl::get_TableIDMODULE_EXT_MODULE_PRIV(void)
{
return Object->TableIDMODULE_EXT_MODULE_PRIV;
}
//---------------------------------------------------------------
void TDMExtModulePrivImpl::set_TableIDMODULE_EXT_MODULE_PRIV(TFIBBCDField * TableIDMODULE_EXT_MODULE_PRIV)
{
Object->TableIDMODULE_EXT_MODULE_PRIV=TableIDMODULE_EXT_MODULE_PRIV;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMExtModulePrivImpl::get_TableINS_EXT_MODULE_PRIV(void)
{
return Object->TableINS_EXT_MODULE_PRIV;
}
//---------------------------------------------------------------
void TDMExtModulePrivImpl::set_TableINS_EXT_MODULE_PRIV(TFIBSmallIntField * TableINS_EXT_MODULE_PRIV)
{
Object->TableINS_EXT_MODULE_PRIV=TableINS_EXT_MODULE_PRIV;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMExtModulePrivImpl::get_TableEDIT_EXT_MODULE_PRIV(void)
{
return Object->TableEDIT_EXT_MODULE_PRIV;
}
//---------------------------------------------------------------
void TDMExtModulePrivImpl::set_TableEDIT_EXT_MODULE_PRIV(TFIBSmallIntField * TableEDIT_EXT_MODULE_PRIV)
{
Object->TableEDIT_EXT_MODULE_PRIV=TableEDIT_EXT_MODULE_PRIV;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMExtModulePrivImpl::get_TableDEL_EXT_MODULE_PRIV(void)
{
return Object->TableDEL_EXT_MODULE_PRIV;
}
//---------------------------------------------------------------
void TDMExtModulePrivImpl::set_TableDEL_EXT_MODULE_PRIV(TFIBSmallIntField * TableDEL_EXT_MODULE_PRIV)
{
Object->TableDEL_EXT_MODULE_PRIV=TableDEL_EXT_MODULE_PRIV;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMExtModulePrivImpl::get_TableEXEC_EXT_MODULE_PRIV(void)
{
return Object->TableEXEC_EXT_MODULE_PRIV;
}
//---------------------------------------------------------------
void TDMExtModulePrivImpl::set_TableEXEC_EXT_MODULE_PRIV(TFIBSmallIntField * TableEXEC_EXT_MODULE_PRIV)
{
Object->TableEXEC_EXT_MODULE_PRIV=TableEXEC_EXT_MODULE_PRIV;
}
//---------------------------------------------------------------
TFIBBCDField * TDMExtModulePrivImpl::get_TableID_EXT_MODULE_PRIV(void)
{
return Object->TableID_EXT_MODULE_PRIV;
}
//---------------------------------------------------------------
void TDMExtModulePrivImpl::set_TableID_EXT_MODULE_PRIV(TFIBBCDField * TableID_EXT_MODULE_PRIV)
{
Object->TableID_EXT_MODULE_PRIV=TableID_EXT_MODULE_PRIV;
}
//---------------------------------------------------------------
TFIBBCDField * TDMExtModulePrivImpl::get_TableIDGRPUSER_EXT_MODULE_PRIV(void)
{
return Object->TableIDGRPUSER_EXT_MODULE_PRIV;
}
//---------------------------------------------------------------
void TDMExtModulePrivImpl::set_TableIDGRPUSER_EXT_MODULE_PRIV(TFIBBCDField * TableIDGRPUSER_EXT_MODULE_PRIV)
{
Object->TableIDGRPUSER_EXT_MODULE_PRIV=TableIDGRPUSER_EXT_MODULE_PRIV;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMExtModulePrivImpl::get_SprGrpUser(void)
{
return Object->SprGrpUser;
}
//---------------------------------------------------------------
void TDMExtModulePrivImpl::set_SprGrpUser(TpFIBDataSet * SprGrpUser)
{
Object->SprGrpUser=SprGrpUser;
}
//---------------------------------------------------------------
TDataSource * TDMExtModulePrivImpl::get_DataSourceSprGrpUser(void)
{
return Object->DataSourceSprGrpUser;
}
//---------------------------------------------------------------
void TDMExtModulePrivImpl::set_DataSourceSprGrpUser(TDataSource * DataSourceSprGrpUser)
{
Object->DataSourceSprGrpUser=DataSourceSprGrpUser;
}
//---------------------------------------------------------------
TFIBBCDField * TDMExtModulePrivImpl::get_SprGrpUserID_SGRPUSER(void)
{
return Object->SprGrpUserID_SGRPUSER;
}
//---------------------------------------------------------------
void TDMExtModulePrivImpl::set_SprGrpUserID_SGRPUSER(TFIBBCDField * SprGrpUserID_SGRPUSER)
{
Object->SprGrpUserID_SGRPUSER=SprGrpUserID_SGRPUSER;
}
//---------------------------------------------------------------
TpFIBQuery * TDMExtModulePrivImpl::get_Query(void)
{
return Object->Query;
}
//---------------------------------------------------------------
void TDMExtModulePrivImpl::set_Query(TpFIBQuery * Query)
{
Object->Query=Query;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMExtModulePrivImpl::get_SprGrpUserNAME_SGRPUSER(void)
{
return Object->SprGrpUserNAME_SGRPUSER;
}
//---------------------------------------------------------------
void TDMExtModulePrivImpl::set_SprGrpUserNAME_SGRPUSER(TFIBWideStringField * SprGrpUserNAME_SGRPUSER)
{
Object->SprGrpUserNAME_SGRPUSER=SprGrpUserNAME_SGRPUSER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMExtModulePrivImpl::get_SprGrpUserROLE_SGRPUSER(void)
{
return Object->SprGrpUserROLE_SGRPUSER;
}
//---------------------------------------------------------------
void TDMExtModulePrivImpl::set_SprGrpUserROLE_SGRPUSER(TFIBWideStringField * SprGrpUserROLE_SGRPUSER)
{
Object->SprGrpUserROLE_SGRPUSER=SprGrpUserROLE_SGRPUSER;
}
//---------------------------------------------------------------
__int64 TDMExtModulePrivImpl::get_IdModule(void)
{
return Object->IdModule;
}
//---------------------------------------------------------------
void TDMExtModulePrivImpl::set_IdModule(__int64 IdModule)
{
Object->IdModule=IdModule;
}
//---------------------------------------------------------------
__int64 TDMExtModulePrivImpl::get_IdGrpUser(void)
{
return Object->IdGrpUser;
}
//---------------------------------------------------------------
void TDMExtModulePrivImpl::set_IdGrpUser(__int64 IdGrpUser)
{
Object->IdGrpUser=IdGrpUser;
}
//---------------------------------------------------------------
void TDMExtModulePrivImpl::OpenTable(__int64 id_module)
{
return Object->OpenTable(id_module);
}
//---------------------------------------------------------------
void TDMExtModulePrivImpl::SaveIsmen(void)
{
return Object->SaveIsmen();
}
//---------------------------------------------------------------
void TDMExtModulePrivImpl::CancelIsmen(void)
{
return Object->CancelIsmen();
}
//---------------------------------------------------------------
void TDMExtModulePrivImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
bool TDMExtModulePrivImpl::CheckPriv(__int64 id_module, __int64 idgrp_user)
{
return Object->CheckPriv(id_module, idgrp_user);
}
//---------------------------------------------------------------
