#include "vcl.h"
#pragma hdrstop


#include "UDMGurLogImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMGurLogImpl::TDMGurLogImpl()           
{                                            
Object=new TDMGurLog(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMGurLogImpl::~TDMGurLogImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMGurLogImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMGurLogImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMGurLog)                        
   {                                                                     
   *ppv=static_cast<IDMGurLog*> (this);                                
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
int TDMGurLogImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMGurLogImpl::kanRelease(void)                                  
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
int  TDMGurLogImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMGurLogImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMGurLogImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMGurLogImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMGurLogImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl);
kanRelease();
Object->ClsIdImpl=CLSID_TDMGurLogImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMGurLogImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMGurLog
TDataSource * TDMGurLogImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMGurLogImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMGurLogImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMGurLogImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMGurLogImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMGurLogImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBQuery * TDMGurLogImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TDMGurLogImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TFIBDateTimeField * TDMGurLogImpl::get_TablePOS_LOG(void)
{
return Object->TablePOS_LOG;
}
//---------------------------------------------------------------
void TDMGurLogImpl::set_TablePOS_LOG(TFIBDateTimeField * TablePOS_LOG)
{
Object->TablePOS_LOG=TablePOS_LOG;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMGurLogImpl::get_TableTYPE_LOG(void)
{
return Object->TableTYPE_LOG;
}
//---------------------------------------------------------------
void TDMGurLogImpl::set_TableTYPE_LOG(TFIBIntegerField * TableTYPE_LOG)
{
Object->TableTYPE_LOG=TableTYPE_LOG;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMGurLogImpl::get_TableOPER_LOG(void)
{
return Object->TableOPER_LOG;
}
//---------------------------------------------------------------
void TDMGurLogImpl::set_TableOPER_LOG(TFIBIntegerField * TableOPER_LOG)
{
Object->TableOPER_LOG=TableOPER_LOG;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMGurLogImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMGurLogImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TFIBBCDField * TDMGurLogImpl::get_TableID_LOG(void)
{
return Object->TableID_LOG;
}
//---------------------------------------------------------------
void TDMGurLogImpl::set_TableID_LOG(TFIBBCDField * TableID_LOG)
{
Object->TableID_LOG=TableID_LOG;
}
//---------------------------------------------------------------
TFIBBCDField * TDMGurLogImpl::get_TableIDUSER_LOG(void)
{
return Object->TableIDUSER_LOG;
}
//---------------------------------------------------------------
void TDMGurLogImpl::set_TableIDUSER_LOG(TFIBBCDField * TableIDUSER_LOG)
{
Object->TableIDUSER_LOG=TableIDUSER_LOG;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMGurLogImpl::get_TableMESSAGE_LOG(void)
{
return Object->TableMESSAGE_LOG;
}
//---------------------------------------------------------------
void TDMGurLogImpl::set_TableMESSAGE_LOG(TFIBWideStringField * TableMESSAGE_LOG)
{
Object->TableMESSAGE_LOG=TableMESSAGE_LOG;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMGurLogImpl::get_TableOBJECT_LOG(void)
{
return Object->TableOBJECT_LOG;
}
//---------------------------------------------------------------
void TDMGurLogImpl::set_TableOBJECT_LOG(TFIBIntegerField * TableOBJECT_LOG)
{
Object->TableOBJECT_LOG=TableOBJECT_LOG;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMGurLogImpl::get_TableNAME_USER(void)
{
return Object->TableNAME_USER;
}
//---------------------------------------------------------------
void TDMGurLogImpl::set_TableNAME_USER(TFIBWideStringField * TableNAME_USER)
{
Object->TableNAME_USER=TableNAME_USER;
}
//---------------------------------------------------------------
__int64 TDMGurLogImpl::get_IdUser(void)
{
return Object->IdUser;
}
//---------------------------------------------------------------
void TDMGurLogImpl::set_IdUser(__int64 IdUser)
{
Object->IdUser=IdUser;
}
//---------------------------------------------------------------
int TDMGurLogImpl::get_Type(void)
{
return Object->Type;
}
//---------------------------------------------------------------
void TDMGurLogImpl::set_Type(int Type)
{
Object->Type=Type;
}
//---------------------------------------------------------------
int TDMGurLogImpl::get_ObjectLog(void)
{
return Object->ObjectLog;
}
//---------------------------------------------------------------
void TDMGurLogImpl::set_ObjectLog(int ObjectLog)
{
Object->ObjectLog=ObjectLog;
}
//---------------------------------------------------------------
int TDMGurLogImpl::get_Oper(void)
{
return Object->Oper;
}
//---------------------------------------------------------------
void TDMGurLogImpl::set_Oper(int Oper)
{
Object->Oper=Oper;
}
//---------------------------------------------------------------
bool TDMGurLogImpl::get_OtborVkl(void)
{
return Object->OtborVkl;
}
//---------------------------------------------------------------
void TDMGurLogImpl::set_OtborVkl(bool OtborVkl)
{
Object->OtborVkl=OtborVkl;
}
//---------------------------------------------------------------
bool TDMGurLogImpl::get_OtborPoUser(void)
{
return Object->OtborPoUser;
}
//---------------------------------------------------------------
void TDMGurLogImpl::set_OtborPoUser(bool OtborPoUser)
{
Object->OtborPoUser=OtborPoUser;
}
//---------------------------------------------------------------
bool TDMGurLogImpl::get_OtborPoType(void)
{
return Object->OtborPoType;
}
//---------------------------------------------------------------
void TDMGurLogImpl::set_OtborPoType(bool OtborPoType)
{
Object->OtborPoType=OtborPoType;
}
//---------------------------------------------------------------
bool TDMGurLogImpl::get_OtborPoObject(void)
{
return Object->OtborPoObject;
}
//---------------------------------------------------------------
void TDMGurLogImpl::set_OtborPoObject(bool OtborPoObject)
{
Object->OtborPoObject=OtborPoObject;
}
//---------------------------------------------------------------
bool TDMGurLogImpl::get_OtborPoOper(void)
{
return Object->OtborPoOper;
}
//---------------------------------------------------------------
void TDMGurLogImpl::set_OtborPoOper(bool OtborPoOper)
{
Object->OtborPoOper=OtborPoOper;
}
//---------------------------------------------------------------
TDateTime TDMGurLogImpl::get_PosNach(void)
{
return Object->PosNach;
}
//---------------------------------------------------------------
void TDMGurLogImpl::set_PosNach(TDateTime PosNach)
{
Object->PosNach=PosNach;
}
//---------------------------------------------------------------
TDateTime TDMGurLogImpl::get_PosCon(void)
{
return Object->PosCon;
}
//---------------------------------------------------------------
void TDMGurLogImpl::set_PosCon(TDateTime PosCon)
{
Object->PosCon=PosCon;
}
//---------------------------------------------------------------
void TDMGurLogImpl::OpenTable()
{
return Object->OpenTable();
}
//---------------------------------------------------------------
void TDMGurLogImpl::UpdateTable(void)
{
return Object->UpdateTable();
}
//---------------------------------------------------------------
