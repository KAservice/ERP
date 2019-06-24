#include "vcl.h"
#pragma hdrstop


#include "UDMSprDiscountAutoImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprDiscountAutoImpl::TDMSprDiscountAutoImpl()           
{                                            
Object=new TDMSprDiscountAuto(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprDiscountAutoImpl::~TDMSprDiscountAutoImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprDiscountAutoImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprDiscountAutoImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprDiscountAuto)                        
   {                                                                     
   *ppv=static_cast<IDMSprDiscountAuto*> (this);                                
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
int TDMSprDiscountAutoImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprDiscountAutoImpl::kanRelease(void)                                  
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
int  TDMSprDiscountAutoImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprDiscountAutoImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprDiscountAutoImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprDiscountAutoImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprDiscountAutoImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMSprDiscountAutoImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMSprDiscountAutoImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMSprDiscountAuto
TDataSource * TDMSprDiscountAutoImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprDiscountAutoImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TDMSprDiscountAutoImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TDMSprDiscountAutoImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprDiscountAutoImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprDiscountAutoImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprDiscountAutoImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprDiscountAutoImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprDiscountAutoImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprDiscountAutoImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprDiscountAutoImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprDiscountAutoImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBQuery * TDMSprDiscountAutoImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TDMSprDiscountAutoImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TIntegerField * TDMSprDiscountAutoImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TDMSprDiscountAutoImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprDiscountAutoImpl::get_TableDiscountAuto(void)
{
return Object->TableDiscountAuto;
}
//---------------------------------------------------------------
void TDMSprDiscountAutoImpl::set_TableDiscountAuto(TpFIBDataSet * TableDiscountAuto)
{
Object->TableDiscountAuto=TableDiscountAuto;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprDiscountAutoImpl::get_TableID_SDISCOUNT_AUTO(void)
{
return Object->TableID_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
void TDMSprDiscountAutoImpl::set_TableID_SDISCOUNT_AUTO(TFIBLargeIntField * TableID_SDISCOUNT_AUTO)
{
Object->TableID_SDISCOUNT_AUTO=TableID_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprDiscountAutoImpl::get_TableGID_SDISCOUNT_AUTO(void)
{
return Object->TableGID_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
void TDMSprDiscountAutoImpl::set_TableGID_SDISCOUNT_AUTO(TFIBWideStringField * TableGID_SDISCOUNT_AUTO)
{
Object->TableGID_SDISCOUNT_AUTO=TableGID_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprDiscountAutoImpl::get_TableNAME_SDISCOUNT_AUTO(void)
{
return Object->TableNAME_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
void TDMSprDiscountAutoImpl::set_TableNAME_SDISCOUNT_AUTO(TFIBWideStringField * TableNAME_SDISCOUNT_AUTO)
{
Object->TableNAME_SDISCOUNT_AUTO=TableNAME_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprDiscountAutoImpl::get_TableACT_SDISCOUNT_AUTO(void)
{
return Object->TableACT_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
void TDMSprDiscountAutoImpl::set_TableACT_SDISCOUNT_AUTO(TFIBSmallIntField * TableACT_SDISCOUNT_AUTO)
{
Object->TableACT_SDISCOUNT_AUTO=TableACT_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
TFIBDateTimeField * TDMSprDiscountAutoImpl::get_TableNACH_SDISCOUNT_AUTO(void)
{
return Object->TableNACH_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
void TDMSprDiscountAutoImpl::set_TableNACH_SDISCOUNT_AUTO(TFIBDateTimeField * TableNACH_SDISCOUNT_AUTO)
{
Object->TableNACH_SDISCOUNT_AUTO=TableNACH_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
TFIBDateTimeField * TDMSprDiscountAutoImpl::get_TableCON_SDISCOUNT_AUTO(void)
{
return Object->TableCON_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
void TDMSprDiscountAutoImpl::set_TableCON_SDISCOUNT_AUTO(TFIBDateTimeField * TableCON_SDISCOUNT_AUTO)
{
Object->TableCON_SDISCOUNT_AUTO=TableCON_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprDiscountAutoImpl::get_TablePRSK_SDISCOUNT_AUTO(void)
{
return Object->TablePRSK_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
void TDMSprDiscountAutoImpl::set_TablePRSK_SDISCOUNT_AUTO(TFIBBCDField * TablePRSK_SDISCOUNT_AUTO)
{
Object->TablePRSK_SDISCOUNT_AUTO=TablePRSK_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprDiscountAutoImpl::get_TableSUM_SDISCOUNT_AUTO(void)
{
return Object->TableSUM_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
void TDMSprDiscountAutoImpl::set_TableSUM_SDISCOUNT_AUTO(TFIBBCDField * TableSUM_SDISCOUNT_AUTO)
{
Object->TableSUM_SDISCOUNT_AUTO=TableSUM_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
TFIBTimeField * TDMSprDiscountAutoImpl::get_TableTIME_NACH_SDISCOUNT_AUTO(void)
{
return Object->TableTIME_NACH_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
void TDMSprDiscountAutoImpl::set_TableTIME_NACH_SDISCOUNT_AUTO(TFIBTimeField * TableTIME_NACH_SDISCOUNT_AUTO)
{
Object->TableTIME_NACH_SDISCOUNT_AUTO=TableTIME_NACH_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
TFIBTimeField * TDMSprDiscountAutoImpl::get_TableTIME_CON_SDISCOUNT_AUTO(void)
{
return Object->TableTIME_CON_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
void TDMSprDiscountAutoImpl::set_TableTIME_CON_SDISCOUNT_AUTO(TFIBTimeField * TableTIME_CON_SDISCOUNT_AUTO)
{
Object->TableTIME_CON_SDISCOUNT_AUTO=TableTIME_CON_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprDiscountAutoImpl::get_TableDAY_SDISCOUNT_AUTO(void)
{
return Object->TableDAY_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
void TDMSprDiscountAutoImpl::set_TableDAY_SDISCOUNT_AUTO(TFIBSmallIntField * TableDAY_SDISCOUNT_AUTO)
{
Object->TableDAY_SDISCOUNT_AUTO=TableDAY_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprDiscountAutoImpl::get_TableIDVIDNOM_SDISCOUNT_AUTO(void)
{
return Object->TableIDVIDNOM_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
void TDMSprDiscountAutoImpl::set_TableIDVIDNOM_SDISCOUNT_AUTO(TFIBLargeIntField * TableIDVIDNOM_SDISCOUNT_AUTO)
{
Object->TableIDVIDNOM_SDISCOUNT_AUTO=TableIDVIDNOM_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprDiscountAutoImpl::get_TableIDSKLAD_SDISCOUNT_AUTO(void)
{
return Object->TableIDSKLAD_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
void TDMSprDiscountAutoImpl::set_TableIDSKLAD_SDISCOUNT_AUTO(TFIBLargeIntField * TableIDSKLAD_SDISCOUNT_AUTO)
{
Object->TableIDSKLAD_SDISCOUNT_AUTO=TableIDSKLAD_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprDiscountAutoImpl::get_TableIDBASE_SDISCOUNT_AUTO(void)
{
return Object->TableIDBASE_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
void TDMSprDiscountAutoImpl::set_TableIDBASE_SDISCOUNT_AUTO(TFIBLargeIntField * TableIDBASE_SDISCOUNT_AUTO)
{
Object->TableIDBASE_SDISCOUNT_AUTO=TableIDBASE_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprDiscountAutoImpl::get_TableNUM_SKIDKI_SDISCOUNT_AUTO(void)
{
return Object->TableNUM_SKIDKI_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
void TDMSprDiscountAutoImpl::set_TableNUM_SKIDKI_SDISCOUNT_AUTO(TFIBSmallIntField * TableNUM_SKIDKI_SDISCOUNT_AUTO)
{
Object->TableNUM_SKIDKI_SDISCOUNT_AUTO=TableNUM_SKIDKI_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprDiscountAutoImpl::get_TableIDGRPNOM_SDISCOUNT_AUTO(void)
{
return Object->TableIDGRPNOM_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
void TDMSprDiscountAutoImpl::set_TableIDGRPNOM_SDISCOUNT_AUTO(TFIBLargeIntField * TableIDGRPNOM_SDISCOUNT_AUTO)
{
Object->TableIDGRPNOM_SDISCOUNT_AUTO=TableIDGRPNOM_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprDiscountAutoImpl::get_TableTYPE_ACTION_SDISCOUNT_AUTO(void)
{
return Object->TableTYPE_ACTION_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
void TDMSprDiscountAutoImpl::set_TableTYPE_ACTION_SDISCOUNT_AUTO(TFIBIntegerField * TableTYPE_ACTION_SDISCOUNT_AUTO)
{
Object->TableTYPE_ACTION_SDISCOUNT_AUTO=TableTYPE_ACTION_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprDiscountAutoImpl::get_TableMESSAGE_SDISCOUNT_AUTO(void)
{
return Object->TableMESSAGE_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
void TDMSprDiscountAutoImpl::set_TableMESSAGE_SDISCOUNT_AUTO(TFIBWideStringField * TableMESSAGE_SDISCOUNT_AUTO)
{
Object->TableMESSAGE_SDISCOUNT_AUTO=TableMESSAGE_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprDiscountAutoImpl::get_TableNAMESKLAD(void)
{
return Object->TableNAMESKLAD;
}
//---------------------------------------------------------------
void TDMSprDiscountAutoImpl::set_TableNAMESKLAD(TFIBWideStringField * TableNAMESKLAD)
{
Object->TableNAMESKLAD=TableNAMESKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprDiscountAutoImpl::get_TableNAMEGN(void)
{
return Object->TableNAMEGN;
}
//---------------------------------------------------------------
void TDMSprDiscountAutoImpl::set_TableNAMEGN(TFIBWideStringField * TableNAMEGN)
{
Object->TableNAMEGN=TableNAMEGN;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprDiscountAutoImpl::get_TableNAME_SVIDNOM(void)
{
return Object->TableNAME_SVIDNOM;
}
//---------------------------------------------------------------
void TDMSprDiscountAutoImpl::set_TableNAME_SVIDNOM(TFIBWideStringField * TableNAME_SVIDNOM)
{
Object->TableNAME_SVIDNOM=TableNAME_SVIDNOM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprDiscountAutoImpl::get_ElementID_SDISCOUNT_AUTO(void)
{
return Object->ElementID_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
void TDMSprDiscountAutoImpl::set_ElementID_SDISCOUNT_AUTO(TFIBLargeIntField * ElementID_SDISCOUNT_AUTO)
{
Object->ElementID_SDISCOUNT_AUTO=ElementID_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprDiscountAutoImpl::get_ElementGID_SDISCOUNT_AUTO(void)
{
return Object->ElementGID_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
void TDMSprDiscountAutoImpl::set_ElementGID_SDISCOUNT_AUTO(TFIBWideStringField * ElementGID_SDISCOUNT_AUTO)
{
Object->ElementGID_SDISCOUNT_AUTO=ElementGID_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprDiscountAutoImpl::get_ElementNAME_SDISCOUNT_AUTO(void)
{
return Object->ElementNAME_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
void TDMSprDiscountAutoImpl::set_ElementNAME_SDISCOUNT_AUTO(TFIBWideStringField * ElementNAME_SDISCOUNT_AUTO)
{
Object->ElementNAME_SDISCOUNT_AUTO=ElementNAME_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprDiscountAutoImpl::get_ElementACT_SDISCOUNT_AUTO(void)
{
return Object->ElementACT_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
void TDMSprDiscountAutoImpl::set_ElementACT_SDISCOUNT_AUTO(TFIBSmallIntField * ElementACT_SDISCOUNT_AUTO)
{
Object->ElementACT_SDISCOUNT_AUTO=ElementACT_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
TFIBDateTimeField * TDMSprDiscountAutoImpl::get_ElementNACH_SDISCOUNT_AUTO(void)
{
return Object->ElementNACH_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
void TDMSprDiscountAutoImpl::set_ElementNACH_SDISCOUNT_AUTO(TFIBDateTimeField * ElementNACH_SDISCOUNT_AUTO)
{
Object->ElementNACH_SDISCOUNT_AUTO=ElementNACH_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
TFIBDateTimeField * TDMSprDiscountAutoImpl::get_ElementCON_SDISCOUNT_AUTO(void)
{
return Object->ElementCON_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
void TDMSprDiscountAutoImpl::set_ElementCON_SDISCOUNT_AUTO(TFIBDateTimeField * ElementCON_SDISCOUNT_AUTO)
{
Object->ElementCON_SDISCOUNT_AUTO=ElementCON_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprDiscountAutoImpl::get_ElementPRSK_SDISCOUNT_AUTO(void)
{
return Object->ElementPRSK_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
void TDMSprDiscountAutoImpl::set_ElementPRSK_SDISCOUNT_AUTO(TFIBBCDField * ElementPRSK_SDISCOUNT_AUTO)
{
Object->ElementPRSK_SDISCOUNT_AUTO=ElementPRSK_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprDiscountAutoImpl::get_ElementSUM_SDISCOUNT_AUTO(void)
{
return Object->ElementSUM_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
void TDMSprDiscountAutoImpl::set_ElementSUM_SDISCOUNT_AUTO(TFIBBCDField * ElementSUM_SDISCOUNT_AUTO)
{
Object->ElementSUM_SDISCOUNT_AUTO=ElementSUM_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
TFIBTimeField * TDMSprDiscountAutoImpl::get_ElementTIME_NACH_SDISCOUNT_AUTO(void)
{
return Object->ElementTIME_NACH_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
void TDMSprDiscountAutoImpl::set_ElementTIME_NACH_SDISCOUNT_AUTO(TFIBTimeField * ElementTIME_NACH_SDISCOUNT_AUTO)
{
Object->ElementTIME_NACH_SDISCOUNT_AUTO=ElementTIME_NACH_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
TFIBTimeField * TDMSprDiscountAutoImpl::get_ElementTIME_CON_SDISCOUNT_AUTO(void)
{
return Object->ElementTIME_CON_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
void TDMSprDiscountAutoImpl::set_ElementTIME_CON_SDISCOUNT_AUTO(TFIBTimeField * ElementTIME_CON_SDISCOUNT_AUTO)
{
Object->ElementTIME_CON_SDISCOUNT_AUTO=ElementTIME_CON_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprDiscountAutoImpl::get_ElementDAY_SDISCOUNT_AUTO(void)
{
return Object->ElementDAY_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
void TDMSprDiscountAutoImpl::set_ElementDAY_SDISCOUNT_AUTO(TFIBSmallIntField * ElementDAY_SDISCOUNT_AUTO)
{
Object->ElementDAY_SDISCOUNT_AUTO=ElementDAY_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprDiscountAutoImpl::get_ElementIDVIDNOM_SDISCOUNT_AUTO(void)
{
return Object->ElementIDVIDNOM_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
void TDMSprDiscountAutoImpl::set_ElementIDVIDNOM_SDISCOUNT_AUTO(TFIBLargeIntField * ElementIDVIDNOM_SDISCOUNT_AUTO)
{
Object->ElementIDVIDNOM_SDISCOUNT_AUTO=ElementIDVIDNOM_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprDiscountAutoImpl::get_ElementIDSKLAD_SDISCOUNT_AUTO(void)
{
return Object->ElementIDSKLAD_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
void TDMSprDiscountAutoImpl::set_ElementIDSKLAD_SDISCOUNT_AUTO(TFIBLargeIntField * ElementIDSKLAD_SDISCOUNT_AUTO)
{
Object->ElementIDSKLAD_SDISCOUNT_AUTO=ElementIDSKLAD_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprDiscountAutoImpl::get_ElementIDBASE_SDISCOUNT_AUTO(void)
{
return Object->ElementIDBASE_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
void TDMSprDiscountAutoImpl::set_ElementIDBASE_SDISCOUNT_AUTO(TFIBLargeIntField * ElementIDBASE_SDISCOUNT_AUTO)
{
Object->ElementIDBASE_SDISCOUNT_AUTO=ElementIDBASE_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprDiscountAutoImpl::get_ElementNUM_SKIDKI_SDISCOUNT_AUTO(void)
{
return Object->ElementNUM_SKIDKI_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
void TDMSprDiscountAutoImpl::set_ElementNUM_SKIDKI_SDISCOUNT_AUTO(TFIBSmallIntField * ElementNUM_SKIDKI_SDISCOUNT_AUTO)
{
Object->ElementNUM_SKIDKI_SDISCOUNT_AUTO=ElementNUM_SKIDKI_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprDiscountAutoImpl::get_ElementIDGRPNOM_SDISCOUNT_AUTO(void)
{
return Object->ElementIDGRPNOM_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
void TDMSprDiscountAutoImpl::set_ElementIDGRPNOM_SDISCOUNT_AUTO(TFIBLargeIntField * ElementIDGRPNOM_SDISCOUNT_AUTO)
{
Object->ElementIDGRPNOM_SDISCOUNT_AUTO=ElementIDGRPNOM_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprDiscountAutoImpl::get_ElementTYPE_ACTION_SDISCOUNT_AUTO(void)
{
return Object->ElementTYPE_ACTION_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
void TDMSprDiscountAutoImpl::set_ElementTYPE_ACTION_SDISCOUNT_AUTO(TFIBIntegerField * ElementTYPE_ACTION_SDISCOUNT_AUTO)
{
Object->ElementTYPE_ACTION_SDISCOUNT_AUTO=ElementTYPE_ACTION_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprDiscountAutoImpl::get_ElementMESSAGE_SDISCOUNT_AUTO(void)
{
return Object->ElementMESSAGE_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
void TDMSprDiscountAutoImpl::set_ElementMESSAGE_SDISCOUNT_AUTO(TFIBWideStringField * ElementMESSAGE_SDISCOUNT_AUTO)
{
Object->ElementMESSAGE_SDISCOUNT_AUTO=ElementMESSAGE_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprDiscountAutoImpl::get_ElementNAMESKLAD(void)
{
return Object->ElementNAMESKLAD;
}
//---------------------------------------------------------------
void TDMSprDiscountAutoImpl::set_ElementNAMESKLAD(TFIBWideStringField * ElementNAMESKLAD)
{
Object->ElementNAMESKLAD=ElementNAMESKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprDiscountAutoImpl::get_ElementNAMEGN(void)
{
return Object->ElementNAMEGN;
}
//---------------------------------------------------------------
void TDMSprDiscountAutoImpl::set_ElementNAMEGN(TFIBWideStringField * ElementNAMEGN)
{
Object->ElementNAMEGN=ElementNAMEGN;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprDiscountAutoImpl::get_ElementNAME_SVIDNOM(void)
{
return Object->ElementNAME_SVIDNOM;
}
//---------------------------------------------------------------
void TDMSprDiscountAutoImpl::set_ElementNAME_SVIDNOM(TFIBWideStringField * ElementNAME_SVIDNOM)
{
Object->ElementNAME_SVIDNOM=ElementNAME_SVIDNOM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprDiscountAutoImpl::get_TableDiscountAutoID_SDISCOUNT_AUTO(void)
{
return Object->TableDiscountAutoID_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
void TDMSprDiscountAutoImpl::set_TableDiscountAutoID_SDISCOUNT_AUTO(TFIBLargeIntField * TableDiscountAutoID_SDISCOUNT_AUTO)
{
Object->TableDiscountAutoID_SDISCOUNT_AUTO=TableDiscountAutoID_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprDiscountAutoImpl::get_TableDiscountAutoGID_SDISCOUNT_AUTO(void)
{
return Object->TableDiscountAutoGID_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
void TDMSprDiscountAutoImpl::set_TableDiscountAutoGID_SDISCOUNT_AUTO(TFIBWideStringField * TableDiscountAutoGID_SDISCOUNT_AUTO)
{
Object->TableDiscountAutoGID_SDISCOUNT_AUTO=TableDiscountAutoGID_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprDiscountAutoImpl::get_TableDiscountAutoNAME_SDISCOUNT_AUTO(void)
{
return Object->TableDiscountAutoNAME_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
void TDMSprDiscountAutoImpl::set_TableDiscountAutoNAME_SDISCOUNT_AUTO(TFIBWideStringField * TableDiscountAutoNAME_SDISCOUNT_AUTO)
{
Object->TableDiscountAutoNAME_SDISCOUNT_AUTO=TableDiscountAutoNAME_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprDiscountAutoImpl::get_TableDiscountAutoACT_SDISCOUNT_AUTO(void)
{
return Object->TableDiscountAutoACT_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
void TDMSprDiscountAutoImpl::set_TableDiscountAutoACT_SDISCOUNT_AUTO(TFIBSmallIntField * TableDiscountAutoACT_SDISCOUNT_AUTO)
{
Object->TableDiscountAutoACT_SDISCOUNT_AUTO=TableDiscountAutoACT_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
TFIBDateTimeField * TDMSprDiscountAutoImpl::get_TableDiscountAutoNACH_SDISCOUNT_AUTO(void)
{
return Object->TableDiscountAutoNACH_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
void TDMSprDiscountAutoImpl::set_TableDiscountAutoNACH_SDISCOUNT_AUTO(TFIBDateTimeField * TableDiscountAutoNACH_SDISCOUNT_AUTO)
{
Object->TableDiscountAutoNACH_SDISCOUNT_AUTO=TableDiscountAutoNACH_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
TFIBDateTimeField * TDMSprDiscountAutoImpl::get_TableDiscountAutoCON_SDISCOUNT_AUTO(void)
{
return Object->TableDiscountAutoCON_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
void TDMSprDiscountAutoImpl::set_TableDiscountAutoCON_SDISCOUNT_AUTO(TFIBDateTimeField * TableDiscountAutoCON_SDISCOUNT_AUTO)
{
Object->TableDiscountAutoCON_SDISCOUNT_AUTO=TableDiscountAutoCON_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprDiscountAutoImpl::get_TableDiscountAutoPRSK_SDISCOUNT_AUTO(void)
{
return Object->TableDiscountAutoPRSK_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
void TDMSprDiscountAutoImpl::set_TableDiscountAutoPRSK_SDISCOUNT_AUTO(TFIBBCDField * TableDiscountAutoPRSK_SDISCOUNT_AUTO)
{
Object->TableDiscountAutoPRSK_SDISCOUNT_AUTO=TableDiscountAutoPRSK_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprDiscountAutoImpl::get_TableDiscountAutoSUM_SDISCOUNT_AUTO(void)
{
return Object->TableDiscountAutoSUM_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
void TDMSprDiscountAutoImpl::set_TableDiscountAutoSUM_SDISCOUNT_AUTO(TFIBBCDField * TableDiscountAutoSUM_SDISCOUNT_AUTO)
{
Object->TableDiscountAutoSUM_SDISCOUNT_AUTO=TableDiscountAutoSUM_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
TFIBTimeField * TDMSprDiscountAutoImpl::get_TableDiscountAutoTIME_NACH_SDISCOUNT_AUTO(void)
{
return Object->TableDiscountAutoTIME_NACH_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
void TDMSprDiscountAutoImpl::set_TableDiscountAutoTIME_NACH_SDISCOUNT_AUTO(TFIBTimeField * TableDiscountAutoTIME_NACH_SDISCOUNT_AUTO)
{
Object->TableDiscountAutoTIME_NACH_SDISCOUNT_AUTO=TableDiscountAutoTIME_NACH_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
TFIBTimeField * TDMSprDiscountAutoImpl::get_TableDiscountAutoTIME_CON_SDISCOUNT_AUTO(void)
{
return Object->TableDiscountAutoTIME_CON_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
void TDMSprDiscountAutoImpl::set_TableDiscountAutoTIME_CON_SDISCOUNT_AUTO(TFIBTimeField * TableDiscountAutoTIME_CON_SDISCOUNT_AUTO)
{
Object->TableDiscountAutoTIME_CON_SDISCOUNT_AUTO=TableDiscountAutoTIME_CON_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprDiscountAutoImpl::get_TableDiscountAutoDAY_SDISCOUNT_AUTO(void)
{
return Object->TableDiscountAutoDAY_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
void TDMSprDiscountAutoImpl::set_TableDiscountAutoDAY_SDISCOUNT_AUTO(TFIBSmallIntField * TableDiscountAutoDAY_SDISCOUNT_AUTO)
{
Object->TableDiscountAutoDAY_SDISCOUNT_AUTO=TableDiscountAutoDAY_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprDiscountAutoImpl::get_TableDiscountAutoIDVIDNOM_SDISCOUNT_AUTO(void)
{
return Object->TableDiscountAutoIDVIDNOM_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
void TDMSprDiscountAutoImpl::set_TableDiscountAutoIDVIDNOM_SDISCOUNT_AUTO(TFIBLargeIntField * TableDiscountAutoIDVIDNOM_SDISCOUNT_AUTO)
{
Object->TableDiscountAutoIDVIDNOM_SDISCOUNT_AUTO=TableDiscountAutoIDVIDNOM_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprDiscountAutoImpl::get_TableDiscountAutoIDSKLAD_SDISCOUNT_AUTO(void)
{
return Object->TableDiscountAutoIDSKLAD_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
void TDMSprDiscountAutoImpl::set_TableDiscountAutoIDSKLAD_SDISCOUNT_AUTO(TFIBLargeIntField * TableDiscountAutoIDSKLAD_SDISCOUNT_AUTO)
{
Object->TableDiscountAutoIDSKLAD_SDISCOUNT_AUTO=TableDiscountAutoIDSKLAD_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprDiscountAutoImpl::get_TableDiscountAutoIDBASE_SDISCOUNT_AUTO(void)
{
return Object->TableDiscountAutoIDBASE_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
void TDMSprDiscountAutoImpl::set_TableDiscountAutoIDBASE_SDISCOUNT_AUTO(TFIBLargeIntField * TableDiscountAutoIDBASE_SDISCOUNT_AUTO)
{
Object->TableDiscountAutoIDBASE_SDISCOUNT_AUTO=TableDiscountAutoIDBASE_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprDiscountAutoImpl::get_TableDiscountAutoNUM_SKIDKI_SDISCOUNT_AUTO(void)
{
return Object->TableDiscountAutoNUM_SKIDKI_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
void TDMSprDiscountAutoImpl::set_TableDiscountAutoNUM_SKIDKI_SDISCOUNT_AUTO(TFIBSmallIntField * TableDiscountAutoNUM_SKIDKI_SDISCOUNT_AUTO)
{
Object->TableDiscountAutoNUM_SKIDKI_SDISCOUNT_AUTO=TableDiscountAutoNUM_SKIDKI_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprDiscountAutoImpl::get_TableDiscountAutoIDGRPNOM_SDISCOUNT_AUTO(void)
{
return Object->TableDiscountAutoIDGRPNOM_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
void TDMSprDiscountAutoImpl::set_TableDiscountAutoIDGRPNOM_SDISCOUNT_AUTO(TFIBLargeIntField * TableDiscountAutoIDGRPNOM_SDISCOUNT_AUTO)
{
Object->TableDiscountAutoIDGRPNOM_SDISCOUNT_AUTO=TableDiscountAutoIDGRPNOM_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprDiscountAutoImpl::get_TableDiscountAutoTYPE_ACTION_SDISCOUNT_AUTO(void)
{
return Object->TableDiscountAutoTYPE_ACTION_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
void TDMSprDiscountAutoImpl::set_TableDiscountAutoTYPE_ACTION_SDISCOUNT_AUTO(TFIBIntegerField * TableDiscountAutoTYPE_ACTION_SDISCOUNT_AUTO)
{
Object->TableDiscountAutoTYPE_ACTION_SDISCOUNT_AUTO=TableDiscountAutoTYPE_ACTION_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprDiscountAutoImpl::get_TableDiscountAutoMESSAGE_SDISCOUNT_AUTO(void)
{
return Object->TableDiscountAutoMESSAGE_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
void TDMSprDiscountAutoImpl::set_TableDiscountAutoMESSAGE_SDISCOUNT_AUTO(TFIBWideStringField * TableDiscountAutoMESSAGE_SDISCOUNT_AUTO)
{
Object->TableDiscountAutoMESSAGE_SDISCOUNT_AUTO=TableDiscountAutoMESSAGE_SDISCOUNT_AUTO;
}
//---------------------------------------------------------------
void TDMSprDiscountAutoImpl::OpenTable(void)
{
return Object->OpenTable();
}
//---------------------------------------------------------------
int TDMSprDiscountAutoImpl::OpenElement(__int64 Id)
{
return Object->OpenElement(Id);
}
//---------------------------------------------------------------
void TDMSprDiscountAutoImpl::NewElement(void)
{
return Object->NewElement();
}
//---------------------------------------------------------------
bool TDMSprDiscountAutoImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
void TDMSprDiscountAutoImpl::CloseElement(void)
{
return Object->CloseElement();
}
//---------------------------------------------------------------
void TDMSprDiscountAutoImpl::DeleteElement(__int64 Id)
{
return Object->DeleteElement(Id);
}
//---------------------------------------------------------------
__int64 TDMSprDiscountAutoImpl::GetIDElement(UnicodeString gid)
{
return Object->GetIDElement(gid);
}
//---------------------------------------------------------------
AnsiString TDMSprDiscountAutoImpl::GetGIDElement(__int64 id)
{
return Object->GetGIDElement(id);
}
//---------------------------------------------------------------
int TDMSprDiscountAutoImpl::GetIndexElementaPoID(__int64 id)
{
return Object->GetIndexElementaPoID(id);
}
//---------------------------------------------------------------
void TDMSprDiscountAutoImpl::OpenTableDiscountAuto(__int64 id_sklad)
{
return Object->OpenTableDiscountAuto(id_sklad);
}
//---------------------------------------------------------------
