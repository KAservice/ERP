#include "vcl.h"
#pragma hdrstop


#include "UDMGurPlatImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMGurPlatImpl::TDMGurPlatImpl()           
{                                            
Object=new TDMGurPlat(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMGurPlatImpl::~TDMGurPlatImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMGurPlatImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMGurPlatImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMGurPlat)                        
   {                                                                     
   *ppv=static_cast<IDMGurPlat*> (this);                                
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
int TDMGurPlatImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMGurPlatImpl::kanRelease(void)                                  
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
int  TDMGurPlatImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMGurPlatImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMGurPlatImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMGurPlatImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMGurPlatImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMGurPlatImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMGurPlatImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMGurPlat
TDataSource * TDMGurPlatImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMGurPlatImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TDMGurPlatImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TDMGurPlatImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMGurPlatImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMGurPlatImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMGurPlatImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMGurPlatImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMGurPlatImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMGurPlatImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMGurPlatImpl::get_IBQ(void)
{
return Object->IBQ;
}
//---------------------------------------------------------------
void TDMGurPlatImpl::set_IBQ(TpFIBDataSet * IBQ)
{
Object->IBQ=IBQ;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMGurPlatImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMGurPlatImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBQuery * TDMGurPlatImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TDMGurPlatImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMGurPlatImpl::get_GurPlat(void)
{
return Object->GurPlat;
}
//---------------------------------------------------------------
void TDMGurPlatImpl::set_GurPlat(TpFIBDataSet * GurPlat)
{
Object->GurPlat=GurPlat;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMGurPlatImpl::get_TableID_GURNALPLAT(void)
{
return Object->TableID_GURNALPLAT;
}
//---------------------------------------------------------------
void TDMGurPlatImpl::set_TableID_GURNALPLAT(TFIBLargeIntField * TableID_GURNALPLAT)
{
Object->TableID_GURNALPLAT=TableID_GURNALPLAT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMGurPlatImpl::get_TableGID_GURNALPLAT(void)
{
return Object->TableGID_GURNALPLAT;
}
//---------------------------------------------------------------
void TDMGurPlatImpl::set_TableGID_GURNALPLAT(TFIBWideStringField * TableGID_GURNALPLAT)
{
Object->TableGID_GURNALPLAT=TableGID_GURNALPLAT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMGurPlatImpl::get_TableCODE_GURNALPLAT(void)
{
return Object->TableCODE_GURNALPLAT;
}
//---------------------------------------------------------------
void TDMGurPlatImpl::set_TableCODE_GURNALPLAT(TFIBWideStringField * TableCODE_GURNALPLAT)
{
Object->TableCODE_GURNALPLAT=TableCODE_GURNALPLAT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMGurPlatImpl::get_TableNUMTEL_GURNALPLAT(void)
{
return Object->TableNUMTEL_GURNALPLAT;
}
//---------------------------------------------------------------
void TDMGurPlatImpl::set_TableNUMTEL_GURNALPLAT(TFIBWideStringField * TableNUMTEL_GURNALPLAT)
{
Object->TableNUMTEL_GURNALPLAT=TableNUMTEL_GURNALPLAT;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMGurPlatImpl::get_TableNUMKV_GURNALPLAT(void)
{
return Object->TableNUMKV_GURNALPLAT;
}
//---------------------------------------------------------------
void TDMGurPlatImpl::set_TableNUMKV_GURNALPLAT(TFIBIntegerField * TableNUMKV_GURNALPLAT)
{
Object->TableNUMKV_GURNALPLAT=TableNUMKV_GURNALPLAT;
}
//---------------------------------------------------------------
TFIBDateTimeField * TDMGurPlatImpl::get_TablePOS_GURNALPLAT(void)
{
return Object->TablePOS_GURNALPLAT;
}
//---------------------------------------------------------------
void TDMGurPlatImpl::set_TablePOS_GURNALPLAT(TFIBDateTimeField * TablePOS_GURNALPLAT)
{
Object->TablePOS_GURNALPLAT=TablePOS_GURNALPLAT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMGurPlatImpl::get_TableIDUSER_GURNALPLAT(void)
{
return Object->TableIDUSER_GURNALPLAT;
}
//---------------------------------------------------------------
void TDMGurPlatImpl::set_TableIDUSER_GURNALPLAT(TFIBLargeIntField * TableIDUSER_GURNALPLAT)
{
Object->TableIDUSER_GURNALPLAT=TableIDUSER_GURNALPLAT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMGurPlatImpl::get_TableSUM_GURNALPLAT(void)
{
return Object->TableSUM_GURNALPLAT;
}
//---------------------------------------------------------------
void TDMGurPlatImpl::set_TableSUM_GURNALPLAT(TFIBBCDField * TableSUM_GURNALPLAT)
{
Object->TableSUM_GURNALPLAT=TableSUM_GURNALPLAT;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMGurPlatImpl::get_TableOUT_GURNALPLAT(void)
{
return Object->TableOUT_GURNALPLAT;
}
//---------------------------------------------------------------
void TDMGurPlatImpl::set_TableOUT_GURNALPLAT(TFIBSmallIntField * TableOUT_GURNALPLAT)
{
Object->TableOUT_GURNALPLAT=TableOUT_GURNALPLAT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMGurPlatImpl::get_TableCODOPER_GURNALPLAT(void)
{
return Object->TableCODOPER_GURNALPLAT;
}
//---------------------------------------------------------------
void TDMGurPlatImpl::set_TableCODOPER_GURNALPLAT(TFIBWideStringField * TableCODOPER_GURNALPLAT)
{
Object->TableCODOPER_GURNALPLAT=TableCODOPER_GURNALPLAT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMGurPlatImpl::get_TableSUMKL_GURNALPLAT(void)
{
return Object->TableSUMKL_GURNALPLAT;
}
//---------------------------------------------------------------
void TDMGurPlatImpl::set_TableSUMKL_GURNALPLAT(TFIBBCDField * TableSUMKL_GURNALPLAT)
{
Object->TableSUMKL_GURNALPLAT=TableSUMKL_GURNALPLAT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMGurPlatImpl::get_TablePROCENT_COMMISSION_GURNALPLAT(void)
{
return Object->TablePROCENT_COMMISSION_GURNALPLAT;
}
//---------------------------------------------------------------
void TDMGurPlatImpl::set_TablePROCENT_COMMISSION_GURNALPLAT(TFIBBCDField * TablePROCENT_COMMISSION_GURNALPLAT)
{
Object->TablePROCENT_COMMISSION_GURNALPLAT=TablePROCENT_COMMISSION_GURNALPLAT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMGurPlatImpl::get_TableIDKLIENT_GURNALPLAT(void)
{
return Object->TableIDKLIENT_GURNALPLAT;
}
//---------------------------------------------------------------
void TDMGurPlatImpl::set_TableIDKLIENT_GURNALPLAT(TFIBLargeIntField * TableIDKLIENT_GURNALPLAT)
{
Object->TableIDKLIENT_GURNALPLAT=TableIDKLIENT_GURNALPLAT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMGurPlatImpl::get_TableIDBASE_GURNALPLAT(void)
{
return Object->TableIDBASE_GURNALPLAT;
}
//---------------------------------------------------------------
void TDMGurPlatImpl::set_TableIDBASE_GURNALPLAT(TFIBLargeIntField * TableIDBASE_GURNALPLAT)
{
Object->TableIDBASE_GURNALPLAT=TableIDBASE_GURNALPLAT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMGurPlatImpl::get_TableIDOPERATOR_GURNALPLAT(void)
{
return Object->TableIDOPERATOR_GURNALPLAT;
}
//---------------------------------------------------------------
void TDMGurPlatImpl::set_TableIDOPERATOR_GURNALPLAT(TFIBLargeIntField * TableIDOPERATOR_GURNALPLAT)
{
Object->TableIDOPERATOR_GURNALPLAT=TableIDOPERATOR_GURNALPLAT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMGurPlatImpl::get_TableIDCODETEL_GURNALPLAT(void)
{
return Object->TableIDCODETEL_GURNALPLAT;
}
//---------------------------------------------------------------
void TDMGurPlatImpl::set_TableIDCODETEL_GURNALPLAT(TFIBLargeIntField * TableIDCODETEL_GURNALPLAT)
{
Object->TableIDCODETEL_GURNALPLAT=TableIDCODETEL_GURNALPLAT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMGurPlatImpl::get_TableNAME_USER(void)
{
return Object->TableNAME_USER;
}
//---------------------------------------------------------------
void TDMGurPlatImpl::set_TableNAME_USER(TFIBWideStringField * TableNAME_USER)
{
Object->TableNAME_USER=TableNAME_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMGurPlatImpl::get_TableNAMEKLIENT(void)
{
return Object->TableNAMEKLIENT;
}
//---------------------------------------------------------------
void TDMGurPlatImpl::set_TableNAMEKLIENT(TFIBWideStringField * TableNAMEKLIENT)
{
Object->TableNAMEKLIENT=TableNAMEKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMGurPlatImpl::get_TableNAME_CODETEL(void)
{
return Object->TableNAME_CODETEL;
}
//---------------------------------------------------------------
void TDMGurPlatImpl::set_TableNAME_CODETEL(TFIBWideStringField * TableNAME_CODETEL)
{
Object->TableNAME_CODETEL=TableNAME_CODETEL;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMGurPlatImpl::get_TableCODOPER_CODETEL(void)
{
return Object->TableCODOPER_CODETEL;
}
//---------------------------------------------------------------
void TDMGurPlatImpl::set_TableCODOPER_CODETEL(TFIBWideStringField * TableCODOPER_CODETEL)
{
Object->TableCODOPER_CODETEL=TableCODOPER_CODETEL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMGurPlatImpl::get_GurPlatID_GURNALPLAT(void)
{
return Object->GurPlatID_GURNALPLAT;
}
//---------------------------------------------------------------
void TDMGurPlatImpl::set_GurPlatID_GURNALPLAT(TFIBLargeIntField * GurPlatID_GURNALPLAT)
{
Object->GurPlatID_GURNALPLAT=GurPlatID_GURNALPLAT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMGurPlatImpl::get_ElementID_GURNALPLAT(void)
{
return Object->ElementID_GURNALPLAT;
}
//---------------------------------------------------------------
void TDMGurPlatImpl::set_ElementID_GURNALPLAT(TFIBLargeIntField * ElementID_GURNALPLAT)
{
Object->ElementID_GURNALPLAT=ElementID_GURNALPLAT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMGurPlatImpl::get_ElementGID_GURNALPLAT(void)
{
return Object->ElementGID_GURNALPLAT;
}
//---------------------------------------------------------------
void TDMGurPlatImpl::set_ElementGID_GURNALPLAT(TFIBWideStringField * ElementGID_GURNALPLAT)
{
Object->ElementGID_GURNALPLAT=ElementGID_GURNALPLAT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMGurPlatImpl::get_ElementCODE_GURNALPLAT(void)
{
return Object->ElementCODE_GURNALPLAT;
}
//---------------------------------------------------------------
void TDMGurPlatImpl::set_ElementCODE_GURNALPLAT(TFIBWideStringField * ElementCODE_GURNALPLAT)
{
Object->ElementCODE_GURNALPLAT=ElementCODE_GURNALPLAT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMGurPlatImpl::get_ElementNUMTEL_GURNALPLAT(void)
{
return Object->ElementNUMTEL_GURNALPLAT;
}
//---------------------------------------------------------------
void TDMGurPlatImpl::set_ElementNUMTEL_GURNALPLAT(TFIBWideStringField * ElementNUMTEL_GURNALPLAT)
{
Object->ElementNUMTEL_GURNALPLAT=ElementNUMTEL_GURNALPLAT;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMGurPlatImpl::get_ElementNUMKV_GURNALPLAT(void)
{
return Object->ElementNUMKV_GURNALPLAT;
}
//---------------------------------------------------------------
void TDMGurPlatImpl::set_ElementNUMKV_GURNALPLAT(TFIBIntegerField * ElementNUMKV_GURNALPLAT)
{
Object->ElementNUMKV_GURNALPLAT=ElementNUMKV_GURNALPLAT;
}
//---------------------------------------------------------------
TFIBDateTimeField * TDMGurPlatImpl::get_ElementPOS_GURNALPLAT(void)
{
return Object->ElementPOS_GURNALPLAT;
}
//---------------------------------------------------------------
void TDMGurPlatImpl::set_ElementPOS_GURNALPLAT(TFIBDateTimeField * ElementPOS_GURNALPLAT)
{
Object->ElementPOS_GURNALPLAT=ElementPOS_GURNALPLAT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMGurPlatImpl::get_ElementIDUSER_GURNALPLAT(void)
{
return Object->ElementIDUSER_GURNALPLAT;
}
//---------------------------------------------------------------
void TDMGurPlatImpl::set_ElementIDUSER_GURNALPLAT(TFIBLargeIntField * ElementIDUSER_GURNALPLAT)
{
Object->ElementIDUSER_GURNALPLAT=ElementIDUSER_GURNALPLAT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMGurPlatImpl::get_ElementSUM_GURNALPLAT(void)
{
return Object->ElementSUM_GURNALPLAT;
}
//---------------------------------------------------------------
void TDMGurPlatImpl::set_ElementSUM_GURNALPLAT(TFIBBCDField * ElementSUM_GURNALPLAT)
{
Object->ElementSUM_GURNALPLAT=ElementSUM_GURNALPLAT;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMGurPlatImpl::get_ElementOUT_GURNALPLAT(void)
{
return Object->ElementOUT_GURNALPLAT;
}
//---------------------------------------------------------------
void TDMGurPlatImpl::set_ElementOUT_GURNALPLAT(TFIBSmallIntField * ElementOUT_GURNALPLAT)
{
Object->ElementOUT_GURNALPLAT=ElementOUT_GURNALPLAT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMGurPlatImpl::get_ElementCODOPER_GURNALPLAT(void)
{
return Object->ElementCODOPER_GURNALPLAT;
}
//---------------------------------------------------------------
void TDMGurPlatImpl::set_ElementCODOPER_GURNALPLAT(TFIBWideStringField * ElementCODOPER_GURNALPLAT)
{
Object->ElementCODOPER_GURNALPLAT=ElementCODOPER_GURNALPLAT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMGurPlatImpl::get_ElementSUMKL_GURNALPLAT(void)
{
return Object->ElementSUMKL_GURNALPLAT;
}
//---------------------------------------------------------------
void TDMGurPlatImpl::set_ElementSUMKL_GURNALPLAT(TFIBBCDField * ElementSUMKL_GURNALPLAT)
{
Object->ElementSUMKL_GURNALPLAT=ElementSUMKL_GURNALPLAT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMGurPlatImpl::get_ElementPROCENT_COMMISSION_GURNALPLAT(void)
{
return Object->ElementPROCENT_COMMISSION_GURNALPLAT;
}
//---------------------------------------------------------------
void TDMGurPlatImpl::set_ElementPROCENT_COMMISSION_GURNALPLAT(TFIBBCDField * ElementPROCENT_COMMISSION_GURNALPLAT)
{
Object->ElementPROCENT_COMMISSION_GURNALPLAT=ElementPROCENT_COMMISSION_GURNALPLAT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMGurPlatImpl::get_ElementIDKLIENT_GURNALPLAT(void)
{
return Object->ElementIDKLIENT_GURNALPLAT;
}
//---------------------------------------------------------------
void TDMGurPlatImpl::set_ElementIDKLIENT_GURNALPLAT(TFIBLargeIntField * ElementIDKLIENT_GURNALPLAT)
{
Object->ElementIDKLIENT_GURNALPLAT=ElementIDKLIENT_GURNALPLAT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMGurPlatImpl::get_ElementIDBASE_GURNALPLAT(void)
{
return Object->ElementIDBASE_GURNALPLAT;
}
//---------------------------------------------------------------
void TDMGurPlatImpl::set_ElementIDBASE_GURNALPLAT(TFIBLargeIntField * ElementIDBASE_GURNALPLAT)
{
Object->ElementIDBASE_GURNALPLAT=ElementIDBASE_GURNALPLAT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMGurPlatImpl::get_ElementIDOPERATOR_GURNALPLAT(void)
{
return Object->ElementIDOPERATOR_GURNALPLAT;
}
//---------------------------------------------------------------
void TDMGurPlatImpl::set_ElementIDOPERATOR_GURNALPLAT(TFIBLargeIntField * ElementIDOPERATOR_GURNALPLAT)
{
Object->ElementIDOPERATOR_GURNALPLAT=ElementIDOPERATOR_GURNALPLAT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMGurPlatImpl::get_ElementIDCODETEL_GURNALPLAT(void)
{
return Object->ElementIDCODETEL_GURNALPLAT;
}
//---------------------------------------------------------------
void TDMGurPlatImpl::set_ElementIDCODETEL_GURNALPLAT(TFIBLargeIntField * ElementIDCODETEL_GURNALPLAT)
{
Object->ElementIDCODETEL_GURNALPLAT=ElementIDCODETEL_GURNALPLAT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMGurPlatImpl::get_ElementNAME_USER(void)
{
return Object->ElementNAME_USER;
}
//---------------------------------------------------------------
void TDMGurPlatImpl::set_ElementNAME_USER(TFIBWideStringField * ElementNAME_USER)
{
Object->ElementNAME_USER=ElementNAME_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMGurPlatImpl::get_ElementNAMEKLIENT(void)
{
return Object->ElementNAMEKLIENT;
}
//---------------------------------------------------------------
void TDMGurPlatImpl::set_ElementNAMEKLIENT(TFIBWideStringField * ElementNAMEKLIENT)
{
Object->ElementNAMEKLIENT=ElementNAMEKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMGurPlatImpl::get_ElementNAME_CODETEL(void)
{
return Object->ElementNAME_CODETEL;
}
//---------------------------------------------------------------
void TDMGurPlatImpl::set_ElementNAME_CODETEL(TFIBWideStringField * ElementNAME_CODETEL)
{
Object->ElementNAME_CODETEL=ElementNAME_CODETEL;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMGurPlatImpl::get_ElementCODOPER_CODETEL(void)
{
return Object->ElementCODOPER_CODETEL;
}
//---------------------------------------------------------------
void TDMGurPlatImpl::set_ElementCODOPER_CODETEL(TFIBWideStringField * ElementCODOPER_CODETEL)
{
Object->ElementCODOPER_CODETEL=ElementCODOPER_CODETEL;
}
//---------------------------------------------------------------
bool TDMGurPlatImpl::get_NoOnlyOut(void)
{
return Object->NoOnlyOut;
}
//---------------------------------------------------------------
void TDMGurPlatImpl::set_NoOnlyOut(bool NoOnlyOut)
{
Object->NoOnlyOut=NoOnlyOut;
}
//---------------------------------------------------------------
AnsiString TDMGurPlatImpl::get_CodeTel(void)
{
return Object->CodeTel;
}
//---------------------------------------------------------------
void TDMGurPlatImpl::set_CodeTel(AnsiString CodeTel)
{
Object->CodeTel=CodeTel;
}
//---------------------------------------------------------------
__int64 TDMGurPlatImpl::get_IdPlat(void)
{
return Object->IdPlat;
}
//---------------------------------------------------------------
void TDMGurPlatImpl::set_IdPlat(__int64 IdPlat)
{
Object->IdPlat=IdPlat;
}
//---------------------------------------------------------------
TDateTime TDMGurPlatImpl::get_PosNach(void)
{
return Object->PosNach;
}
//---------------------------------------------------------------
void TDMGurPlatImpl::set_PosNach(TDateTime PosNach)
{
Object->PosNach=PosNach;
}
//---------------------------------------------------------------
TDateTime TDMGurPlatImpl::get_PosCon(void)
{
return Object->PosCon;
}
//---------------------------------------------------------------
void TDMGurPlatImpl::set_PosCon(TDateTime PosCon)
{
Object->PosCon=PosCon;
}
//---------------------------------------------------------------
void TDMGurPlatImpl::OpenTable()
{
return Object->OpenTable();
}
//---------------------------------------------------------------
void TDMGurPlatImpl::UpdateTable(void)
{
return Object->UpdateTable();
}
//---------------------------------------------------------------
void TDMGurPlatImpl::NewElement(void)
{
return Object->NewElement();
}
//---------------------------------------------------------------
int TDMGurPlatImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
void TDMGurPlatImpl::SaveElement()
{
return Object->SaveElement();
}
//---------------------------------------------------------------
void TDMGurPlatImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
void TDMGurPlatImpl::DeleteAllElement(bool NoDeleteEndRecord)
{
return Object->DeleteAllElement(NoDeleteEndRecord);
}
//---------------------------------------------------------------
bool TDMGurPlatImpl::AddPlat(AnsiString cod, AnsiString number, double sum, int number_kv, AnsiString code_operator, double procent_commission, double sum_klient, __int64 id_klient, __int64 id_spr_code_tel)
{
return Object->AddPlat(cod, number, sum,number_kv, code_operator,procent_commission,sum_klient, id_klient, id_spr_code_tel);
}
//---------------------------------------------------------------
bool TDMGurPlatImpl::CheckPlat(AnsiString cod,AnsiString number,double sum,int number_kv, __int64 id_spr_code_tel)
{
return Object->CheckPlat(cod,number,sum,number_kv,id_spr_code_tel);
}
//---------------------------------------------------------------
int TDMGurPlatImpl::GetNumberKv(AnsiString cod)
{
return Object->GetNumberKv(cod);
}
//---------------------------------------------------------------
