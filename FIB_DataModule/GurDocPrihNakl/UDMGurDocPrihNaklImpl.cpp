#include "vcl.h"
#pragma hdrstop


#include "UDMGurDocPrihNaklImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMGurDocPrihNaklImpl::TDMGurDocPrihNaklImpl()           
{                                            
Object=new TDMGurDocPrihNakl(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMGurDocPrihNaklImpl::~TDMGurDocPrihNaklImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMGurDocPrihNaklImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMGurDocPrihNaklImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMGurDocPrihNakl)                        
   {                                                                     
   *ppv=static_cast<IDMGurDocPrihNakl*> (this);                                
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
int TDMGurDocPrihNaklImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMGurDocPrihNaklImpl::kanRelease(void)                                  
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
int  TDMGurDocPrihNaklImpl::get_CodeError(void)                      
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMGurDocPrihNaklImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMGurDocPrihNaklImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMGurDocPrihNaklImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMGurDocPrihNaklImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object)
{
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl);
kanRelease();
Object->ClsIdImpl=CLSID_TDMGurDocPrihNaklImpl;
Object->InterfaceMainObject=i_main_object;
Object->InterfaceOwnerObject=i_owner_object;
return Object->Init();
}
//---------------------------------------------------------------
int TDMGurDocPrihNaklImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMGurDocPrihNakl
TDataSource * TDMGurDocPrihNaklImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMGurDocPrihNaklImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMGurDocPrihNaklImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMGurDocPrihNaklImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMGurDocPrihNaklImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMGurDocPrihNaklImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMGurDocPrihNaklImpl::get_TableNUMDOC(void)
{
return Object->TableNUMDOC;
}
//---------------------------------------------------------------
void TDMGurDocPrihNaklImpl::set_TableNUMDOC(TFIBIntegerField * TableNUMDOC)
{
Object->TableNUMDOC=TableNUMDOC;
}
//---------------------------------------------------------------
TFIBDateTimeField * TDMGurDocPrihNaklImpl::get_TablePOSDOC(void)
{
return Object->TablePOSDOC;
}
//---------------------------------------------------------------
void TDMGurDocPrihNaklImpl::set_TablePOSDOC(TFIBDateTimeField * TablePOSDOC)
{
Object->TablePOSDOC=TablePOSDOC;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMGurDocPrihNaklImpl::get_TablePRDOC(void)
{
return Object->TablePRDOC;
}
//---------------------------------------------------------------
void TDMGurDocPrihNaklImpl::set_TablePRDOC(TFIBSmallIntField * TablePRDOC)
{
Object->TablePRDOC=TablePRDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMGurDocPrihNaklImpl::get_TableSUMDOC(void)
{
return Object->TableSUMDOC;
}
//---------------------------------------------------------------
void TDMGurDocPrihNaklImpl::set_TableSUMDOC(TFIBBCDField * TableSUMDOC)
{
Object->TableSUMDOC=TableSUMDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMGurDocPrihNaklImpl::get_TableIDDOC(void)
{
return Object->TableIDDOC;
}
//---------------------------------------------------------------
void TDMGurDocPrihNaklImpl::set_TableIDDOC(TFIBBCDField * TableIDDOC)
{
Object->TableIDDOC=TableIDDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMGurDocPrihNaklImpl::get_TableRSUM_DPRN(void)
{
return Object->TableRSUM_DPRN;
}
//---------------------------------------------------------------
void TDMGurDocPrihNaklImpl::set_TableRSUM_DPRN(TFIBBCDField * TableRSUM_DPRN)
{
Object->TableRSUM_DPRN=TableRSUM_DPRN;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMGurDocPrihNaklImpl::get_TableNAMEFIRM(void)
{
return Object->TableNAMEFIRM;
}
//---------------------------------------------------------------
void TDMGurDocPrihNaklImpl::set_TableNAMEFIRM(TFIBWideStringField * TableNAMEFIRM)
{
Object->TableNAMEFIRM=TableNAMEFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMGurDocPrihNaklImpl::get_TableNAMESKLAD(void)
{
return Object->TableNAMESKLAD;
}
//---------------------------------------------------------------
void TDMGurDocPrihNaklImpl::set_TableNAMESKLAD(TFIBWideStringField * TableNAMESKLAD)
{
Object->TableNAMESKLAD=TableNAMESKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMGurDocPrihNaklImpl::get_TableNAMEKLIENT(void)
{
return Object->TableNAMEKLIENT;
}
//---------------------------------------------------------------
void TDMGurDocPrihNaklImpl::set_TableNAMEKLIENT(TFIBWideStringField * TableNAMEKLIENT)
{
Object->TableNAMEKLIENT=TableNAMEKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMGurDocPrihNaklImpl::get_TableNAME_USER(void)
{
return Object->TableNAME_USER;
}
//---------------------------------------------------------------
void TDMGurDocPrihNaklImpl::set_TableNAME_USER(TFIBWideStringField * TableNAME_USER)
{
Object->TableNAME_USER=TableNAME_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMGurDocPrihNaklImpl::get_TablePRIMDOC(void)
{
return Object->TablePRIMDOC;
}
//---------------------------------------------------------------
void TDMGurDocPrihNaklImpl::set_TablePRIMDOC(TFIBWideStringField * TablePRIMDOC)
{
Object->TablePRIMDOC=TablePRIMDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMGurDocPrihNaklImpl::get_TableNUMDOCPOST_DPRN(void)
{
return Object->TableNUMDOCPOST_DPRN;
}
//---------------------------------------------------------------
void TDMGurDocPrihNaklImpl::set_TableNUMDOCPOST_DPRN(TFIBWideStringField * TableNUMDOCPOST_DPRN)
{
Object->TableNUMDOCPOST_DPRN=TableNUMDOCPOST_DPRN;
}
//---------------------------------------------------------------
TFIBDateTimeField * TDMGurDocPrihNaklImpl::get_TablePOSDOCPOST_DPRN(void)
{
return Object->TablePOSDOCPOST_DPRN;
}
//---------------------------------------------------------------
void TDMGurDocPrihNaklImpl::set_TablePOSDOCPOST_DPRN(TFIBDateTimeField * TablePOSDOCPOST_DPRN)
{
Object->TablePOSDOCPOST_DPRN=TablePOSDOCPOST_DPRN;
}
//---------------------------------------------------------------
__int64 TDMGurDocPrihNaklImpl::get_IdDoc(void)
{
return Object->IdDoc;
}
//---------------------------------------------------------------
void TDMGurDocPrihNaklImpl::set_IdDoc(__int64 IdDoc)
{
Object->IdDoc=IdDoc;
}
//---------------------------------------------------------------
TDateTime TDMGurDocPrihNaklImpl::get_PosNach(void)
{
return Object->PosNach;
}
//---------------------------------------------------------------
void TDMGurDocPrihNaklImpl::set_PosNach(TDateTime PosNach)
{
Object->PosNach=PosNach;
}
//---------------------------------------------------------------
TDateTime TDMGurDocPrihNaklImpl::get_PosCon(void)
{
return Object->PosCon;
}
//---------------------------------------------------------------
void TDMGurDocPrihNaklImpl::set_PosCon(TDateTime PosCon)
{
Object->PosCon=PosCon;
}
//---------------------------------------------------------------
void TDMGurDocPrihNaklImpl::OpenTable()
{
return Object->OpenTable();
}
//---------------------------------------------------------------
void TDMGurDocPrihNaklImpl::UpdateTable(void)
{
return Object->UpdateTable();
}
//---------------------------------------------------------------
