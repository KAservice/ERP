#include "vcl.h"
#pragma hdrstop


#include "UREM_DMSprKKTDvImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_DMSprKKTDvImpl::TREM_DMSprKKTDvImpl()           
{                                            
Object=new TREM_DMSprKKTDv(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_DMSprKKTDvImpl::~TREM_DMSprKKTDvImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_DMSprKKTDvImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_DMSprKKTDvImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_DMSprKKTDv)                        
   {                                                                     
   *ppv=static_cast<IREM_DMSprKKTDv*> (this);                                
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
int TREM_DMSprKKTDvImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_DMSprKKTDvImpl::kanRelease(void)                                  
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
int  TREM_DMSprKKTDvImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMSprKKTDvImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_DMSprKKTDvImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMSprKKTDvImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_DMSprKKTDvImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_DMSprKKTDvImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_DMSprKKTDvImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IREM_DMSprKKTDv
TDataSource * TREM_DMSprKKTDvImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TREM_DMSprKKTDvImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TREM_DMSprKKTDvImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TREM_DMSprKKTDvImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMSprKKTDvImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TREM_DMSprKKTDvImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMSprKKTDvImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TREM_DMSprKKTDvImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMSprKKTDvImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TREM_DMSprKKTDvImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMSprKKTDvImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TREM_DMSprKKTDvImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMSprKKTDvImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TREM_DMSprKKTDvImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprKKTDvImpl::get_TableID_REM_SKKT_DV(void)
{
return Object->TableID_REM_SKKT_DV;
}
//---------------------------------------------------------------
void TREM_DMSprKKTDvImpl::set_TableID_REM_SKKT_DV(TFIBLargeIntField * TableID_REM_SKKT_DV)
{
Object->TableID_REM_SKKT_DV=TableID_REM_SKKT_DV;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprKKTDvImpl::get_TableIDBASE_REM_SKKT_DV(void)
{
return Object->TableIDBASE_REM_SKKT_DV;
}
//---------------------------------------------------------------
void TREM_DMSprKKTDvImpl::set_TableIDBASE_REM_SKKT_DV(TFIBLargeIntField * TableIDBASE_REM_SKKT_DV)
{
Object->TableIDBASE_REM_SKKT_DV=TableIDBASE_REM_SKKT_DV;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprKKTDvImpl::get_TableIDKKT_REM_SKKT_DV(void)
{
return Object->TableIDKKT_REM_SKKT_DV;
}
//---------------------------------------------------------------
void TREM_DMSprKKTDvImpl::set_TableIDKKT_REM_SKKT_DV(TFIBLargeIntField * TableIDKKT_REM_SKKT_DV)
{
Object->TableIDKKT_REM_SKKT_DV=TableIDKKT_REM_SKKT_DV;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMSprKKTDvImpl::get_TablePOS_REM_SKKT_DV(void)
{
return Object->TablePOS_REM_SKKT_DV;
}
//---------------------------------------------------------------
void TREM_DMSprKKTDvImpl::set_TablePOS_REM_SKKT_DV(TFIBDateTimeField * TablePOS_REM_SKKT_DV)
{
Object->TablePOS_REM_SKKT_DV=TablePOS_REM_SKKT_DV;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprKKTDvImpl::get_TableIDKLIENT_REM_SKKT_DV(void)
{
return Object->TableIDKLIENT_REM_SKKT_DV;
}
//---------------------------------------------------------------
void TREM_DMSprKKTDvImpl::set_TableIDKLIENT_REM_SKKT_DV(TFIBLargeIntField * TableIDKLIENT_REM_SKKT_DV)
{
Object->TableIDKLIENT_REM_SKKT_DV=TableIDKLIENT_REM_SKKT_DV;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprKKTDvImpl::get_TableMESTOUST_REM_SKKT_DV(void)
{
return Object->TableMESTOUST_REM_SKKT_DV;
}
//---------------------------------------------------------------
void TREM_DMSprKKTDvImpl::set_TableMESTOUST_REM_SKKT_DV(TFIBWideStringField * TableMESTOUST_REM_SKKT_DV)
{
Object->TableMESTOUST_REM_SKKT_DV=TableMESTOUST_REM_SKKT_DV;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprKKTDvImpl::get_TableREGNUM_REM_SKKT_DV(void)
{
return Object->TableREGNUM_REM_SKKT_DV;
}
//---------------------------------------------------------------
void TREM_DMSprKKTDvImpl::set_TableREGNUM_REM_SKKT_DV(TFIBWideStringField * TableREGNUM_REM_SKKT_DV)
{
Object->TableREGNUM_REM_SKKT_DV=TableREGNUM_REM_SKKT_DV;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprKKTDvImpl::get_TableCBKGR_REM_SKKT_DV(void)
{
return Object->TableCBKGR_REM_SKKT_DV;
}
//---------------------------------------------------------------
void TREM_DMSprKKTDvImpl::set_TableCBKGR_REM_SKKT_DV(TFIBWideStringField * TableCBKGR_REM_SKKT_DV)
{
Object->TableCBKGR_REM_SKKT_DV=TableCBKGR_REM_SKKT_DV;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprKKTDvImpl::get_TableCBKCO_REM_SKKT_DV(void)
{
return Object->TableCBKCO_REM_SKKT_DV;
}
//---------------------------------------------------------------
void TREM_DMSprKKTDvImpl::set_TableCBKCO_REM_SKKT_DV(TFIBWideStringField * TableCBKCO_REM_SKKT_DV)
{
Object->TableCBKCO_REM_SKKT_DV=TableCBKCO_REM_SKKT_DV;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprKKTDvImpl::get_TableNUMCONTRACT_REM_SKKT_DV(void)
{
return Object->TableNUMCONTRACT_REM_SKKT_DV;
}
//---------------------------------------------------------------
void TREM_DMSprKKTDvImpl::set_TableNUMCONTRACT_REM_SKKT_DV(TFIBWideStringField * TableNUMCONTRACT_REM_SKKT_DV)
{
Object->TableNUMCONTRACT_REM_SKKT_DV=TableNUMCONTRACT_REM_SKKT_DV;
}
//---------------------------------------------------------------
TFIBDateField * TREM_DMSprKKTDvImpl::get_TableDATECONTRACT_REM_SKKT_DV(void)
{
return Object->TableDATECONTRACT_REM_SKKT_DV;
}
//---------------------------------------------------------------
void TREM_DMSprKKTDvImpl::set_TableDATECONTRACT_REM_SKKT_DV(TFIBDateField * TableDATECONTRACT_REM_SKKT_DV)
{
Object->TableDATECONTRACT_REM_SKKT_DV=TableDATECONTRACT_REM_SKKT_DV;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMSprKKTDvImpl::get_TableSUMCONTRACT_REM_SKKT_DV(void)
{
return Object->TableSUMCONTRACT_REM_SKKT_DV;
}
//---------------------------------------------------------------
void TREM_DMSprKKTDvImpl::set_TableSUMCONTRACT_REM_SKKT_DV(TFIBBCDField * TableSUMCONTRACT_REM_SKKT_DV)
{
Object->TableSUMCONTRACT_REM_SKKT_DV=TableSUMCONTRACT_REM_SKKT_DV;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprKKTDvImpl::get_TableEKLZ_SERNUM_REM_SKKT_DV(void)
{
return Object->TableEKLZ_SERNUM_REM_SKKT_DV;
}
//---------------------------------------------------------------
void TREM_DMSprKKTDvImpl::set_TableEKLZ_SERNUM_REM_SKKT_DV(TFIBWideStringField * TableEKLZ_SERNUM_REM_SKKT_DV)
{
Object->TableEKLZ_SERNUM_REM_SKKT_DV=TableEKLZ_SERNUM_REM_SKKT_DV;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprKKTDvImpl::get_TableEKLZ_REGNUM_REM_SKKT_DV(void)
{
return Object->TableEKLZ_REGNUM_REM_SKKT_DV;
}
//---------------------------------------------------------------
void TREM_DMSprKKTDvImpl::set_TableEKLZ_REGNUM_REM_SKKT_DV(TFIBWideStringField * TableEKLZ_REGNUM_REM_SKKT_DV)
{
Object->TableEKLZ_REGNUM_REM_SKKT_DV=TableEKLZ_REGNUM_REM_SKKT_DV;
}
//---------------------------------------------------------------
TFIBDateField * TREM_DMSprKKTDvImpl::get_TableEKLZ_ACT_REM_SKKT_DV(void)
{
return Object->TableEKLZ_ACT_REM_SKKT_DV;
}
//---------------------------------------------------------------
void TREM_DMSprKKTDvImpl::set_TableEKLZ_ACT_REM_SKKT_DV(TFIBDateField * TableEKLZ_ACT_REM_SKKT_DV)
{
Object->TableEKLZ_ACT_REM_SKKT_DV=TableEKLZ_ACT_REM_SKKT_DV;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprKKTDvImpl::get_TableIDUSER_REM_SKKT_DV(void)
{
return Object->TableIDUSER_REM_SKKT_DV;
}
//---------------------------------------------------------------
void TREM_DMSprKKTDvImpl::set_TableIDUSER_REM_SKKT_DV(TFIBLargeIntField * TableIDUSER_REM_SKKT_DV)
{
Object->TableIDUSER_REM_SKKT_DV=TableIDUSER_REM_SKKT_DV;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprKKTDvImpl::get_TableNAMEKLIENT(void)
{
return Object->TableNAMEKLIENT;
}
//---------------------------------------------------------------
void TREM_DMSprKKTDvImpl::set_TableNAMEKLIENT(TFIBWideStringField * TableNAMEKLIENT)
{
Object->TableNAMEKLIENT=TableNAMEKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprKKTDvImpl::get_TableNAME_USER(void)
{
return Object->TableNAME_USER;
}
//---------------------------------------------------------------
void TREM_DMSprKKTDvImpl::set_TableNAME_USER(TFIBWideStringField * TableNAME_USER)
{
Object->TableNAME_USER=TableNAME_USER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprKKTDvImpl::get_ElementID_REM_SKKT_DV(void)
{
return Object->ElementID_REM_SKKT_DV;
}
//---------------------------------------------------------------
void TREM_DMSprKKTDvImpl::set_ElementID_REM_SKKT_DV(TFIBLargeIntField * ElementID_REM_SKKT_DV)
{
Object->ElementID_REM_SKKT_DV=ElementID_REM_SKKT_DV;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprKKTDvImpl::get_ElementIDBASE_REM_SKKT_DV(void)
{
return Object->ElementIDBASE_REM_SKKT_DV;
}
//---------------------------------------------------------------
void TREM_DMSprKKTDvImpl::set_ElementIDBASE_REM_SKKT_DV(TFIBLargeIntField * ElementIDBASE_REM_SKKT_DV)
{
Object->ElementIDBASE_REM_SKKT_DV=ElementIDBASE_REM_SKKT_DV;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprKKTDvImpl::get_ElementIDKKT_REM_SKKT_DV(void)
{
return Object->ElementIDKKT_REM_SKKT_DV;
}
//---------------------------------------------------------------
void TREM_DMSprKKTDvImpl::set_ElementIDKKT_REM_SKKT_DV(TFIBLargeIntField * ElementIDKKT_REM_SKKT_DV)
{
Object->ElementIDKKT_REM_SKKT_DV=ElementIDKKT_REM_SKKT_DV;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMSprKKTDvImpl::get_ElementPOS_REM_SKKT_DV(void)
{
return Object->ElementPOS_REM_SKKT_DV;
}
//---------------------------------------------------------------
void TREM_DMSprKKTDvImpl::set_ElementPOS_REM_SKKT_DV(TFIBDateTimeField * ElementPOS_REM_SKKT_DV)
{
Object->ElementPOS_REM_SKKT_DV=ElementPOS_REM_SKKT_DV;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprKKTDvImpl::get_ElementIDKLIENT_REM_SKKT_DV(void)
{
return Object->ElementIDKLIENT_REM_SKKT_DV;
}
//---------------------------------------------------------------
void TREM_DMSprKKTDvImpl::set_ElementIDKLIENT_REM_SKKT_DV(TFIBLargeIntField * ElementIDKLIENT_REM_SKKT_DV)
{
Object->ElementIDKLIENT_REM_SKKT_DV=ElementIDKLIENT_REM_SKKT_DV;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprKKTDvImpl::get_ElementMESTOUST_REM_SKKT_DV(void)
{
return Object->ElementMESTOUST_REM_SKKT_DV;
}
//---------------------------------------------------------------
void TREM_DMSprKKTDvImpl::set_ElementMESTOUST_REM_SKKT_DV(TFIBWideStringField * ElementMESTOUST_REM_SKKT_DV)
{
Object->ElementMESTOUST_REM_SKKT_DV=ElementMESTOUST_REM_SKKT_DV;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprKKTDvImpl::get_ElementREGNUM_REM_SKKT_DV(void)
{
return Object->ElementREGNUM_REM_SKKT_DV;
}
//---------------------------------------------------------------
void TREM_DMSprKKTDvImpl::set_ElementREGNUM_REM_SKKT_DV(TFIBWideStringField * ElementREGNUM_REM_SKKT_DV)
{
Object->ElementREGNUM_REM_SKKT_DV=ElementREGNUM_REM_SKKT_DV;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprKKTDvImpl::get_ElementCBKGR_REM_SKKT_DV(void)
{
return Object->ElementCBKGR_REM_SKKT_DV;
}
//---------------------------------------------------------------
void TREM_DMSprKKTDvImpl::set_ElementCBKGR_REM_SKKT_DV(TFIBWideStringField * ElementCBKGR_REM_SKKT_DV)
{
Object->ElementCBKGR_REM_SKKT_DV=ElementCBKGR_REM_SKKT_DV;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprKKTDvImpl::get_ElementCBKCO_REM_SKKT_DV(void)
{
return Object->ElementCBKCO_REM_SKKT_DV;
}
//---------------------------------------------------------------
void TREM_DMSprKKTDvImpl::set_ElementCBKCO_REM_SKKT_DV(TFIBWideStringField * ElementCBKCO_REM_SKKT_DV)
{
Object->ElementCBKCO_REM_SKKT_DV=ElementCBKCO_REM_SKKT_DV;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprKKTDvImpl::get_ElementNUMCONTRACT_REM_SKKT_DV(void)
{
return Object->ElementNUMCONTRACT_REM_SKKT_DV;
}
//---------------------------------------------------------------
void TREM_DMSprKKTDvImpl::set_ElementNUMCONTRACT_REM_SKKT_DV(TFIBWideStringField * ElementNUMCONTRACT_REM_SKKT_DV)
{
Object->ElementNUMCONTRACT_REM_SKKT_DV=ElementNUMCONTRACT_REM_SKKT_DV;
}
//---------------------------------------------------------------
TFIBDateField * TREM_DMSprKKTDvImpl::get_ElementDATECONTRACT_REM_SKKT_DV(void)
{
return Object->ElementDATECONTRACT_REM_SKKT_DV;
}
//---------------------------------------------------------------
void TREM_DMSprKKTDvImpl::set_ElementDATECONTRACT_REM_SKKT_DV(TFIBDateField * ElementDATECONTRACT_REM_SKKT_DV)
{
Object->ElementDATECONTRACT_REM_SKKT_DV=ElementDATECONTRACT_REM_SKKT_DV;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMSprKKTDvImpl::get_ElementSUMCONTRACT_REM_SKKT_DV(void)
{
return Object->ElementSUMCONTRACT_REM_SKKT_DV;
}
//---------------------------------------------------------------
void TREM_DMSprKKTDvImpl::set_ElementSUMCONTRACT_REM_SKKT_DV(TFIBBCDField * ElementSUMCONTRACT_REM_SKKT_DV)
{
Object->ElementSUMCONTRACT_REM_SKKT_DV=ElementSUMCONTRACT_REM_SKKT_DV;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprKKTDvImpl::get_ElementEKLZ_SERNUM_REM_SKKT_DV(void)
{
return Object->ElementEKLZ_SERNUM_REM_SKKT_DV;
}
//---------------------------------------------------------------
void TREM_DMSprKKTDvImpl::set_ElementEKLZ_SERNUM_REM_SKKT_DV(TFIBWideStringField * ElementEKLZ_SERNUM_REM_SKKT_DV)
{
Object->ElementEKLZ_SERNUM_REM_SKKT_DV=ElementEKLZ_SERNUM_REM_SKKT_DV;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprKKTDvImpl::get_ElementEKLZ_REGNUM_REM_SKKT_DV(void)
{
return Object->ElementEKLZ_REGNUM_REM_SKKT_DV;
}
//---------------------------------------------------------------
void TREM_DMSprKKTDvImpl::set_ElementEKLZ_REGNUM_REM_SKKT_DV(TFIBWideStringField * ElementEKLZ_REGNUM_REM_SKKT_DV)
{
Object->ElementEKLZ_REGNUM_REM_SKKT_DV=ElementEKLZ_REGNUM_REM_SKKT_DV;
}
//---------------------------------------------------------------
TFIBDateField * TREM_DMSprKKTDvImpl::get_ElementEKLZ_ACT_REM_SKKT_DV(void)
{
return Object->ElementEKLZ_ACT_REM_SKKT_DV;
}
//---------------------------------------------------------------
void TREM_DMSprKKTDvImpl::set_ElementEKLZ_ACT_REM_SKKT_DV(TFIBDateField * ElementEKLZ_ACT_REM_SKKT_DV)
{
Object->ElementEKLZ_ACT_REM_SKKT_DV=ElementEKLZ_ACT_REM_SKKT_DV;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprKKTDvImpl::get_ElementIDUSER_REM_SKKT_DV(void)
{
return Object->ElementIDUSER_REM_SKKT_DV;
}
//---------------------------------------------------------------
void TREM_DMSprKKTDvImpl::set_ElementIDUSER_REM_SKKT_DV(TFIBLargeIntField * ElementIDUSER_REM_SKKT_DV)
{
Object->ElementIDUSER_REM_SKKT_DV=ElementIDUSER_REM_SKKT_DV;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprKKTDvImpl::get_ElementNAMEKLIENT(void)
{
return Object->ElementNAMEKLIENT;
}
//---------------------------------------------------------------
void TREM_DMSprKKTDvImpl::set_ElementNAMEKLIENT(TFIBWideStringField * ElementNAMEKLIENT)
{
Object->ElementNAMEKLIENT=ElementNAMEKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprKKTDvImpl::get_ElementNAME_USER(void)
{
return Object->ElementNAME_USER;
}
//---------------------------------------------------------------
void TREM_DMSprKKTDvImpl::set_ElementNAME_USER(TFIBWideStringField * ElementNAME_USER)
{
Object->ElementNAME_USER=ElementNAME_USER;
}
//---------------------------------------------------------------
__int64 TREM_DMSprKKTDvImpl::get_IdOwner(void)
{
return Object->IdOwner;
}
//---------------------------------------------------------------
void TREM_DMSprKKTDvImpl::set_IdOwner(__int64 IdOwner)
{
Object->IdOwner=IdOwner;
}
//---------------------------------------------------------------
void TREM_DMSprKKTDvImpl::OpenTable(__int64 id_owner)
{
return Object->OpenTable(id_owner);
}
//---------------------------------------------------------------
int TREM_DMSprKKTDvImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
bool TREM_DMSprKKTDvImpl::NewElement(__int64 id_owner)
{
return Object->NewElement(id_owner);
}
//---------------------------------------------------------------
bool TREM_DMSprKKTDvImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TREM_DMSprKKTDvImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
bool TREM_DMSprKKTDvImpl::AddRecordDv(TDateTime pos,__int64 id_owner,__int64 id_klient,UnicodeString mesto_ust,UnicodeString reg_num,UnicodeString svk_gr,UnicodeString svk_so,UnicodeString num_contract,TDate date_contract,double sum_contract,UnicodeString eklz_ser_num,UnicodeString eklz_reg_num,TDate eklz_act,__int64 id_user)
{
return Object->AddRecordDv( pos,id_owner,id_klient, mesto_ust,reg_num,svk_gr,
						svk_so,num_contract,date_contract,sum_contract,eklz_ser_num,eklz_reg_num,eklz_act,id_user);
}
//---------------------------------------------------------------
