#include "vcl.h"
#pragma hdrstop


#include "UDMGurDocPerImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMGurDocPerImpl::TDMGurDocPerImpl()           
{                                            
Object=new TDMGurDocPer(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMGurDocPerImpl::~TDMGurDocPerImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMGurDocPerImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMGurDocPerImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMGurDocPer)                        
   {                                                                     
   *ppv=static_cast<IDMGurDocPer*> (this);                                
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
int TDMGurDocPerImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMGurDocPerImpl::kanRelease(void)                                  
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
int  TDMGurDocPerImpl::get_CodeError(void)                      
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMGurDocPerImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMGurDocPerImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMGurDocPerImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMGurDocPerImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object)
{
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl);
kanRelease();
Object->ClsIdImpl=CLSID_TDMGurDocPerImpl;
Object->InterfaceMainObject=i_main_object;
Object->InterfaceOwnerObject=i_owner_object;
return Object->Init();
}
//---------------------------------------------------------------
int TDMGurDocPerImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMGurDocPer
TDataSource * TDMGurDocPerImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMGurDocPerImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMGurDocPerImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMGurDocPerImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMGurDocPerImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMGurDocPerImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMGurDocPerImpl::get_TableNUMDOC(void)
{
return Object->TableNUMDOC;
}
//---------------------------------------------------------------
void TDMGurDocPerImpl::set_TableNUMDOC(TFIBIntegerField * TableNUMDOC)
{
Object->TableNUMDOC=TableNUMDOC;
}
//---------------------------------------------------------------
TFIBDateTimeField * TDMGurDocPerImpl::get_TablePOSDOC(void)
{
return Object->TablePOSDOC;
}
//---------------------------------------------------------------
void TDMGurDocPerImpl::set_TablePOSDOC(TFIBDateTimeField * TablePOSDOC)
{
Object->TablePOSDOC=TablePOSDOC;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMGurDocPerImpl::get_TablePRDOC(void)
{
return Object->TablePRDOC;
}
//---------------------------------------------------------------
void TDMGurDocPerImpl::set_TablePRDOC(TFIBSmallIntField * TablePRDOC)
{
Object->TablePRDOC=TablePRDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMGurDocPerImpl::get_TableSUMDOC(void)
{
return Object->TableSUMDOC;
}
//---------------------------------------------------------------
void TDMGurDocPerImpl::set_TableSUMDOC(TFIBBCDField * TableSUMDOC)
{
Object->TableSUMDOC=TableSUMDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMGurDocPerImpl::get_TableIDDOC(void)
{
return Object->TableIDDOC;
}
//---------------------------------------------------------------
void TDMGurDocPerImpl::set_TableIDDOC(TFIBBCDField * TableIDDOC)
{
Object->TableIDDOC=TableIDDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMGurDocPerImpl::get_TableNAMEFIRM(void)
{
return Object->TableNAMEFIRM;
}
//---------------------------------------------------------------
void TDMGurDocPerImpl::set_TableNAMEFIRM(TFIBWideStringField * TableNAMEFIRM)
{
Object->TableNAMEFIRM=TableNAMEFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMGurDocPerImpl::get_TableNAMESKLAD(void)
{
return Object->TableNAMESKLAD;
}
//---------------------------------------------------------------
void TDMGurDocPerImpl::set_TableNAMESKLAD(TFIBWideStringField * TableNAMESKLAD)
{
Object->TableNAMESKLAD=TableNAMESKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMGurDocPerImpl::get_TableNAMESKLADPOL(void)
{
return Object->TableNAMESKLADPOL;
}
//---------------------------------------------------------------
void TDMGurDocPerImpl::set_TableNAMESKLADPOL(TFIBWideStringField * TableNAMESKLADPOL)
{
Object->TableNAMESKLADPOL=TableNAMESKLADPOL;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMGurDocPerImpl::get_TableNAME_USER(void)
{
return Object->TableNAME_USER;
}
//---------------------------------------------------------------
void TDMGurDocPerImpl::set_TableNAME_USER(TFIBWideStringField * TableNAME_USER)
{
Object->TableNAME_USER=TableNAME_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMGurDocPerImpl::get_TablePRIMPER(void)
{
return Object->TablePRIMPER;
}
//---------------------------------------------------------------
void TDMGurDocPerImpl::set_TablePRIMPER(TFIBWideStringField * TablePRIMPER)
{
Object->TablePRIMPER=TablePRIMPER;
}
//---------------------------------------------------------------
__int64 TDMGurDocPerImpl::get_IdDoc(void)
{
return Object->IdDoc;
}
//---------------------------------------------------------------
void TDMGurDocPerImpl::set_IdDoc(__int64 IdDoc)
{
Object->IdDoc=IdDoc;
}
//---------------------------------------------------------------
TDateTime TDMGurDocPerImpl::get_PosNach(void)
{
return Object->PosNach;
}
//---------------------------------------------------------------
void TDMGurDocPerImpl::set_PosNach(TDateTime PosNach)
{
Object->PosNach=PosNach;
}
//---------------------------------------------------------------
TDateTime TDMGurDocPerImpl::get_PosCon(void)
{
return Object->PosCon;
}
//---------------------------------------------------------------
void TDMGurDocPerImpl::set_PosCon(TDateTime PosCon)
{
Object->PosCon=PosCon;
}
//---------------------------------------------------------------
void TDMGurDocPerImpl::OpenTable()
{
return Object->OpenTable();
}
//---------------------------------------------------------------
void TDMGurDocPerImpl::UpdateTable(void)
{
return Object->UpdateTable();
}
//---------------------------------------------------------------
