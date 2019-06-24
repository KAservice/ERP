#include "vcl.h"
#pragma hdrstop


#include "UDMGurDocCheckKKMImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMGurDocCheckKKMImpl::TDMGurDocCheckKKMImpl()           
{                                            
Object=new TDMGurDocCheckKKM(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMGurDocCheckKKMImpl::~TDMGurDocCheckKKMImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMGurDocCheckKKMImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMGurDocCheckKKMImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMGurDocCheckKKM)                        
   {                                                                     
   *ppv=static_cast<IDMGurDocCheckKKM*> (this);                                
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
int TDMGurDocCheckKKMImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMGurDocCheckKKMImpl::kanRelease(void)                                  
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
int  TDMGurDocCheckKKMImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMGurDocCheckKKMImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMGurDocCheckKKMImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMGurDocCheckKKMImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMGurDocCheckKKMImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMGurDocCheckKKMImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMGurDocCheckKKMImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMGurDocCheckKKM
TDataSource * TDMGurDocCheckKKMImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMGurDocCheckKKMImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMGurDocCheckKKMImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMGurDocCheckKKMImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMGurDocCheckKKMImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMGurDocCheckKKMImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMGurDocCheckKKMImpl::get_TableNUMDOC(void)
{
return Object->TableNUMDOC;
}
//---------------------------------------------------------------
void TDMGurDocCheckKKMImpl::set_TableNUMDOC(TFIBIntegerField * TableNUMDOC)
{
Object->TableNUMDOC=TableNUMDOC;
}
//---------------------------------------------------------------
TFIBDateTimeField * TDMGurDocCheckKKMImpl::get_TablePOSDOC(void)
{
return Object->TablePOSDOC;
}
//---------------------------------------------------------------
void TDMGurDocCheckKKMImpl::set_TablePOSDOC(TFIBDateTimeField * TablePOSDOC)
{
Object->TablePOSDOC=TablePOSDOC;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMGurDocCheckKKMImpl::get_TablePRDOC(void)
{
return Object->TablePRDOC;
}
//---------------------------------------------------------------
void TDMGurDocCheckKKMImpl::set_TablePRDOC(TFIBSmallIntField * TablePRDOC)
{
Object->TablePRDOC=TablePRDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMGurDocCheckKKMImpl::get_TableSUMDOC(void)
{
return Object->TableSUMDOC;
}
//---------------------------------------------------------------
void TDMGurDocCheckKKMImpl::set_TableSUMDOC(TFIBBCDField * TableSUMDOC)
{
Object->TableSUMDOC=TableSUMDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMGurDocCheckKKMImpl::get_TableIDDOC(void)
{
return Object->TableIDDOC;
}
//---------------------------------------------------------------
void TDMGurDocCheckKKMImpl::set_TableIDDOC(TFIBLargeIntField * TableIDDOC)
{
Object->TableIDDOC=TableIDDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMGurDocCheckKKMImpl::get_TableNCHECKCHK(void)
{
return Object->TableNCHECKCHK;
}
//---------------------------------------------------------------
void TDMGurDocCheckKKMImpl::set_TableNCHECKCHK(TFIBIntegerField * TableNCHECKCHK)
{
Object->TableNCHECKCHK=TableNCHECKCHK;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMGurDocCheckKKMImpl::get_TableNKLCHK(void)
{
return Object->TableNKLCHK;
}
//---------------------------------------------------------------
void TDMGurDocCheckKKMImpl::set_TableNKLCHK(TFIBIntegerField * TableNKLCHK)
{
Object->TableNKLCHK=TableNKLCHK;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMGurDocCheckKKMImpl::get_TableOPERCHK(void)
{
return Object->TableOPERCHK;
}
//---------------------------------------------------------------
void TDMGurDocCheckKKMImpl::set_TableOPERCHK(TFIBIntegerField * TableOPERCHK)
{
Object->TableOPERCHK=TableOPERCHK;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMGurDocCheckKKMImpl::get_TableNAMEKKM(void)
{
return Object->TableNAMEKKM;
}
//---------------------------------------------------------------
void TDMGurDocCheckKKMImpl::set_TableNAMEKKM(TFIBWideStringField * TableNAMEKKM)
{
Object->TableNAMEKKM=TableNAMEKKM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMGurDocCheckKKMImpl::get_TableNAMEFIRM(void)
{
return Object->TableNAMEFIRM;
}
//---------------------------------------------------------------
void TDMGurDocCheckKKMImpl::set_TableNAMEFIRM(TFIBWideStringField * TableNAMEFIRM)
{
Object->TableNAMEFIRM=TableNAMEFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMGurDocCheckKKMImpl::get_TableNAMESKLAD(void)
{
return Object->TableNAMESKLAD;
}
//---------------------------------------------------------------
void TDMGurDocCheckKKMImpl::set_TableNAMESKLAD(TFIBWideStringField * TableNAMESKLAD)
{
Object->TableNAMESKLAD=TableNAMESKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMGurDocCheckKKMImpl::get_TableNAMEKLIENT(void)
{
return Object->TableNAMEKLIENT;
}
//---------------------------------------------------------------
void TDMGurDocCheckKKMImpl::set_TableNAMEKLIENT(TFIBWideStringField * TableNAMEKLIENT)
{
Object->TableNAMEKLIENT=TableNAMEKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMGurDocCheckKKMImpl::get_TableNAME_USER(void)
{
return Object->TableNAME_USER;
}
//---------------------------------------------------------------
void TDMGurDocCheckKKMImpl::set_TableNAME_USER(TFIBWideStringField * TableNAME_USER)
{
Object->TableNAME_USER=TableNAME_USER;
}
//---------------------------------------------------------------
TFIBBCDField * TDMGurDocCheckKKMImpl::get_TableOPLNALCHK(void)
{
return Object->TableOPLNALCHK;
}
//---------------------------------------------------------------
void TDMGurDocCheckKKMImpl::set_TableOPLNALCHK(TFIBBCDField * TableOPLNALCHK)
{
Object->TableOPLNALCHK=TableOPLNALCHK;
}
//---------------------------------------------------------------
TFIBBCDField * TDMGurDocCheckKKMImpl::get_TableOPLPCCHK(void)
{
return Object->TableOPLPCCHK;
}
//---------------------------------------------------------------
void TDMGurDocCheckKKMImpl::set_TableOPLPCCHK(TFIBBCDField * TableOPLPCCHK)
{
Object->TableOPLPCCHK=TableOPLPCCHK;
}
//---------------------------------------------------------------
TFIBBCDField * TDMGurDocCheckKKMImpl::get_TableOPLPLATCARD_ALL_DCHK(void)
{
return Object->TableOPLPLATCARD_ALL_DCHK;
}
//---------------------------------------------------------------
void TDMGurDocCheckKKMImpl::set_TableOPLPLATCARD_ALL_DCHK(TFIBBCDField * TableOPLPLATCARD_ALL_DCHK)
{
Object->TableOPLPLATCARD_ALL_DCHK=TableOPLPLATCARD_ALL_DCHK;
}
//---------------------------------------------------------------
TFIBBCDField * TDMGurDocCheckKKMImpl::get_TableOPLCREDITCARD_ALL_DCHK(void)
{
return Object->TableOPLCREDITCARD_ALL_DCHK;
}
//---------------------------------------------------------------
void TDMGurDocCheckKKMImpl::set_TableOPLCREDITCARD_ALL_DCHK(TFIBBCDField * TableOPLCREDITCARD_ALL_DCHK)
{
Object->TableOPLCREDITCARD_ALL_DCHK=TableOPLCREDITCARD_ALL_DCHK;
}
//---------------------------------------------------------------
TFIBBCDField * TDMGurDocCheckKKMImpl::get_TableOPL_OTHER_DCHK(void)
{
return Object->TableOPL_OTHER_DCHK;
}
//---------------------------------------------------------------
void TDMGurDocCheckKKMImpl::set_TableOPL_OTHER_DCHK(TFIBBCDField * TableOPL_OTHER_DCHK)
{
Object->TableOPL_OTHER_DCHK=TableOPL_OTHER_DCHK;
}
//---------------------------------------------------------------
__int64 TDMGurDocCheckKKMImpl::get_IdDoc(void)
{
return Object->IdDoc;
}
//---------------------------------------------------------------
void TDMGurDocCheckKKMImpl::set_IdDoc(__int64 IdDoc)
{
Object->IdDoc=IdDoc;
}
//---------------------------------------------------------------
TDateTime TDMGurDocCheckKKMImpl::get_PosNach(void)
{
return Object->PosNach;
}
//---------------------------------------------------------------
void TDMGurDocCheckKKMImpl::set_PosNach(TDateTime PosNach)
{
Object->PosNach=PosNach;
}
//---------------------------------------------------------------
TDateTime TDMGurDocCheckKKMImpl::get_PosCon(void)
{
return Object->PosCon;
}
//---------------------------------------------------------------
void TDMGurDocCheckKKMImpl::set_PosCon(TDateTime PosCon)
{
Object->PosCon=PosCon;
}
//---------------------------------------------------------------
__int64 TDMGurDocCheckKKMImpl::get_IdKKM(void)
{
return Object->IdKKM;
}
//---------------------------------------------------------------
void TDMGurDocCheckKKMImpl::set_IdKKM(__int64 IdKKM)
{
Object->IdKKM=IdKKM;
}
//---------------------------------------------------------------
int TDMGurDocCheckKKMImpl::get_NumberKL(void)
{
return Object->NumberKL;
}
//---------------------------------------------------------------
void TDMGurDocCheckKKMImpl::set_NumberKL(int NumberKL)
{
Object->NumberKL=NumberKL;
}
//---------------------------------------------------------------
void TDMGurDocCheckKKMImpl::OpenTable()
{
return Object->OpenTable();
}
//---------------------------------------------------------------
void TDMGurDocCheckKKMImpl::UpdateTable(void)
{
return Object->UpdateTable();
}
//---------------------------------------------------------------
