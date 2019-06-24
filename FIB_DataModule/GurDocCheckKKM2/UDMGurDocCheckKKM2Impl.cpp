#include "vcl.h"
#pragma hdrstop


#include "UDMGurDocCheckKKM2Impl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMGurDocCheckKKM2Impl::TDMGurDocCheckKKM2Impl()           
{                                            
Object=new TDMGurDocCheckKKM2(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMGurDocCheckKKM2Impl::~TDMGurDocCheckKKM2Impl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMGurDocCheckKKM2Impl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMGurDocCheckKKM2Impl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMGurDocCheckKKM2)                        
   {                                                                     
   *ppv=static_cast<IDMGurDocCheckKKM2*> (this);                                
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
int TDMGurDocCheckKKM2Impl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMGurDocCheckKKM2Impl::kanRelease(void)                                  
{                                                                      
if (--NumRefs==0)                                                     
   {                                                                  
   delete this;                                                       
   }                                                                  
return NumRefs;                                                       
}                                                                     
//---------------------------------------------------------------

//IMainInterface 
                                                              
//---------------------------------------------------------------
int  TDMGurDocCheckKKM2Impl::get_CodeError(void)                      
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMGurDocCheckKKM2Impl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMGurDocCheckKKM2Impl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMGurDocCheckKKM2Impl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMGurDocCheckKKM2Impl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object)
{
Object->InterfaceMainObject=i_main_object;
Object->InterfaceOwnerObject=i_owner_object;
return Object->Init();
}
//---------------------------------------------------------------
int TDMGurDocCheckKKM2Impl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMGurDocCheckKKM2
TDataSource * TDMGurDocCheckKKM2Impl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMGurDocCheckKKM2Impl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMGurDocCheckKKM2Impl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMGurDocCheckKKM2Impl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMGurDocCheckKKM2Impl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMGurDocCheckKKM2Impl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMGurDocCheckKKM2Impl::get_TableNUMDOC(void)
{
return Object->TableNUMDOC;
}
//---------------------------------------------------------------
void TDMGurDocCheckKKM2Impl::set_TableNUMDOC(TFIBIntegerField * TableNUMDOC)
{
Object->TableNUMDOC=TableNUMDOC;
}
//---------------------------------------------------------------
TFIBDateTimeField * TDMGurDocCheckKKM2Impl::get_TablePOSDOC(void)
{
return Object->TablePOSDOC;
}
//---------------------------------------------------------------
void TDMGurDocCheckKKM2Impl::set_TablePOSDOC(TFIBDateTimeField * TablePOSDOC)
{
Object->TablePOSDOC=TablePOSDOC;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMGurDocCheckKKM2Impl::get_TablePRDOC(void)
{
return Object->TablePRDOC;
}
//---------------------------------------------------------------
void TDMGurDocCheckKKM2Impl::set_TablePRDOC(TFIBSmallIntField * TablePRDOC)
{
Object->TablePRDOC=TablePRDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMGurDocCheckKKM2Impl::get_TableSUMDOC(void)
{
return Object->TableSUMDOC;
}
//---------------------------------------------------------------
void TDMGurDocCheckKKM2Impl::set_TableSUMDOC(TFIBBCDField * TableSUMDOC)
{
Object->TableSUMDOC=TableSUMDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMGurDocCheckKKM2Impl::get_TableIDDOC(void)
{
return Object->TableIDDOC;
}
//---------------------------------------------------------------
void TDMGurDocCheckKKM2Impl::set_TableIDDOC(TFIBBCDField * TableIDDOC)
{
Object->TableIDDOC=TableIDDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMGurDocCheckKKM2Impl::get_TableNCHECKCHK(void)
{
return Object->TableNCHECKCHK;
}
//---------------------------------------------------------------
void TDMGurDocCheckKKM2Impl::set_TableNCHECKCHK(TFIBIntegerField * TableNCHECKCHK)
{
Object->TableNCHECKCHK=TableNCHECKCHK;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMGurDocCheckKKM2Impl::get_TableNKLCHK(void)
{
return Object->TableNKLCHK;
}
//---------------------------------------------------------------
void TDMGurDocCheckKKM2Impl::set_TableNKLCHK(TFIBIntegerField * TableNKLCHK)
{
Object->TableNKLCHK=TableNKLCHK;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMGurDocCheckKKM2Impl::get_TableOPERCHK(void)
{
return Object->TableOPERCHK;
}
//---------------------------------------------------------------
void TDMGurDocCheckKKM2Impl::set_TableOPERCHK(TFIBIntegerField * TableOPERCHK)
{
Object->TableOPERCHK=TableOPERCHK;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMGurDocCheckKKM2Impl::get_TableNAMEKKM(void)
{
return Object->TableNAMEKKM;
}
//---------------------------------------------------------------
void TDMGurDocCheckKKM2Impl::set_TableNAMEKKM(TFIBWideStringField * TableNAMEKKM)
{
Object->TableNAMEKKM=TableNAMEKKM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMGurDocCheckKKM2Impl::get_TableNAMEFIRM(void)
{
return Object->TableNAMEFIRM;
}
//---------------------------------------------------------------
void TDMGurDocCheckKKM2Impl::set_TableNAMEFIRM(TFIBWideStringField * TableNAMEFIRM)
{
Object->TableNAMEFIRM=TableNAMEFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMGurDocCheckKKM2Impl::get_TableNAMESKLAD(void)
{
return Object->TableNAMESKLAD;
}
//---------------------------------------------------------------
void TDMGurDocCheckKKM2Impl::set_TableNAMESKLAD(TFIBWideStringField * TableNAMESKLAD)
{
Object->TableNAMESKLAD=TableNAMESKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMGurDocCheckKKM2Impl::get_TableNAMEKLIENT(void)
{
return Object->TableNAMEKLIENT;
}
//---------------------------------------------------------------
void TDMGurDocCheckKKM2Impl::set_TableNAMEKLIENT(TFIBWideStringField * TableNAMEKLIENT)
{
Object->TableNAMEKLIENT=TableNAMEKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMGurDocCheckKKM2Impl::get_TableNAME_USER(void)
{
return Object->TableNAME_USER;
}
//---------------------------------------------------------------
void TDMGurDocCheckKKM2Impl::set_TableNAME_USER(TFIBWideStringField * TableNAME_USER)
{
Object->TableNAME_USER=TableNAME_USER;
}
//---------------------------------------------------------------
TIntegerField * TDMGurDocCheckKKM2Impl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TDMGurDocCheckKKM2Impl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
__int64 TDMGurDocCheckKKM2Impl::get_IdDoc(void)
{
return Object->IdDoc;
}
//---------------------------------------------------------------
void TDMGurDocCheckKKM2Impl::set_IdDoc(__int64 IdDoc)
{
Object->IdDoc=IdDoc;
}
//---------------------------------------------------------------
TDateTime TDMGurDocCheckKKM2Impl::get_PosNach(void)
{
return Object->PosNach;
}
//---------------------------------------------------------------
void TDMGurDocCheckKKM2Impl::set_PosNach(TDateTime PosNach)
{
Object->PosNach=PosNach;
}
//---------------------------------------------------------------
TDateTime TDMGurDocCheckKKM2Impl::get_PosCon(void)
{
return Object->PosCon;
}
//---------------------------------------------------------------
void TDMGurDocCheckKKM2Impl::set_PosCon(TDateTime PosCon)
{
Object->PosCon=PosCon;
}
//---------------------------------------------------------------
__int64 TDMGurDocCheckKKM2Impl::get_IdKKM(void)
{
return Object->IdKKM;
}
//---------------------------------------------------------------
void TDMGurDocCheckKKM2Impl::set_IdKKM(__int64 IdKKM)
{
Object->IdKKM=IdKKM;
}
//---------------------------------------------------------------
int TDMGurDocCheckKKM2Impl::get_NumberKL(void)
{
return Object->NumberKL;
}
//---------------------------------------------------------------
void TDMGurDocCheckKKM2Impl::set_NumberKL(int NumberKL)
{
Object->NumberKL=NumberKL;
}
//---------------------------------------------------------------
bool TDMGurDocCheckKKM2Impl::OpenTable(void)
{
return Object->OpenTable();
}
//---------------------------------------------------------------
void TDMGurDocCheckKKM2Impl::UpdateTable(void)
{
return Object->UpdateTable();
}
//---------------------------------------------------------------
