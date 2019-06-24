#include "vcl.h"
#pragma hdrstop


#include "UREM_DMSprKKTImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_DMSprKKTImpl::TREM_DMSprKKTImpl()           
{                                            
Object=new TREM_DMSprKKT(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_DMSprKKTImpl::~TREM_DMSprKKTImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_DMSprKKTImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_DMSprKKTImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_DMSprKKT)                        
   {                                                                     
   *ppv=static_cast<IREM_DMSprKKT*> (this);                                
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
int TREM_DMSprKKTImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_DMSprKKTImpl::kanRelease(void)                                  
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
int  TREM_DMSprKKTImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMSprKKTImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_DMSprKKTImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMSprKKTImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_DMSprKKTImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_DMSprKKTImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_DMSprKKTImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IREM_DMSprKKT
TDataSource * TREM_DMSprKKTImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TREM_DMSprKKTImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TREM_DMSprKKTImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TREM_DMSprKKTImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMSprKKTImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TREM_DMSprKKTImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMSprKKTImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TREM_DMSprKKTImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMSprKKTImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TREM_DMSprKKTImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMSprKKTImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TREM_DMSprKKTImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMSprKKTImpl::get_Query(void)
{
return Object->Query;
}
//---------------------------------------------------------------
void TREM_DMSprKKTImpl::set_Query(TpFIBQuery * Query)
{
Object->Query=Query;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprKKTImpl::get_TableID_REM_SKKT(void)
{
return Object->TableID_REM_SKKT;
}
//---------------------------------------------------------------
void TREM_DMSprKKTImpl::set_TableID_REM_SKKT(TFIBLargeIntField * TableID_REM_SKKT)
{
Object->TableID_REM_SKKT=TableID_REM_SKKT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprKKTImpl::get_TableNAME_REM_SKKT(void)
{
return Object->TableNAME_REM_SKKT;
}
//---------------------------------------------------------------
void TREM_DMSprKKTImpl::set_TableNAME_REM_SKKT(TFIBWideStringField * TableNAME_REM_SKKT)
{
Object->TableNAME_REM_SKKT=TableNAME_REM_SKKT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprKKTImpl::get_TableSERNUM_REM_SKKT(void)
{
return Object->TableSERNUM_REM_SKKT;
}
//---------------------------------------------------------------
void TREM_DMSprKKTImpl::set_TableSERNUM_REM_SKKT(TFIBWideStringField * TableSERNUM_REM_SKKT)
{
Object->TableSERNUM_REM_SKKT=TableSERNUM_REM_SKKT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprKKTImpl::get_TableNAME_REM_SMODEL(void)
{
return Object->TableNAME_REM_SMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprKKTImpl::set_TableNAME_REM_SMODEL(TFIBWideStringField * TableNAME_REM_SMODEL)
{
Object->TableNAME_REM_SMODEL=TableNAME_REM_SMODEL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprKKTImpl::get_TableMESTOUST_REM_SKKT(void)
{
return Object->TableMESTOUST_REM_SKKT;
}
//---------------------------------------------------------------
void TREM_DMSprKKTImpl::set_TableMESTOUST_REM_SKKT(TFIBWideStringField * TableMESTOUST_REM_SKKT)
{
Object->TableMESTOUST_REM_SKKT=TableMESTOUST_REM_SKKT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprKKTImpl::get_TableIDGRP_REM_SKKT(void)
{
return Object->TableIDGRP_REM_SKKT;
}
//---------------------------------------------------------------
void TREM_DMSprKKTImpl::set_TableIDGRP_REM_SKKT(TFIBLargeIntField * TableIDGRP_REM_SKKT)
{
Object->TableIDGRP_REM_SKKT=TableIDGRP_REM_SKKT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprKKTImpl::get_ElementID_REM_SKKT(void)
{
return Object->ElementID_REM_SKKT;
}
//---------------------------------------------------------------
void TREM_DMSprKKTImpl::set_ElementID_REM_SKKT(TFIBLargeIntField * ElementID_REM_SKKT)
{
Object->ElementID_REM_SKKT=ElementID_REM_SKKT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprKKTImpl::get_ElementIDBASE_REM_SKKT(void)
{
return Object->ElementIDBASE_REM_SKKT;
}
//---------------------------------------------------------------
void TREM_DMSprKKTImpl::set_ElementIDBASE_REM_SKKT(TFIBLargeIntField * ElementIDBASE_REM_SKKT)
{
Object->ElementIDBASE_REM_SKKT=ElementIDBASE_REM_SKKT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprKKTImpl::get_ElementNAME_REM_SKKT(void)
{
return Object->ElementNAME_REM_SKKT;
}
//---------------------------------------------------------------
void TREM_DMSprKKTImpl::set_ElementNAME_REM_SKKT(TFIBWideStringField * ElementNAME_REM_SKKT)
{
Object->ElementNAME_REM_SKKT=ElementNAME_REM_SKKT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprKKTImpl::get_ElementSERNUM_REM_SKKT(void)
{
return Object->ElementSERNUM_REM_SKKT;
}
//---------------------------------------------------------------
void TREM_DMSprKKTImpl::set_ElementSERNUM_REM_SKKT(TFIBWideStringField * ElementSERNUM_REM_SKKT)
{
Object->ElementSERNUM_REM_SKKT=ElementSERNUM_REM_SKKT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprKKTImpl::get_ElementIDMODEL_REM_SKKT(void)
{
return Object->ElementIDMODEL_REM_SKKT;
}
//---------------------------------------------------------------
void TREM_DMSprKKTImpl::set_ElementIDMODEL_REM_SKKT(TFIBLargeIntField * ElementIDMODEL_REM_SKKT)
{
Object->ElementIDMODEL_REM_SKKT=ElementIDMODEL_REM_SKKT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprKKTImpl::get_ElementREGNUM_REM_SKKT(void)
{
return Object->ElementREGNUM_REM_SKKT;
}
//---------------------------------------------------------------
void TREM_DMSprKKTImpl::set_ElementREGNUM_REM_SKKT(TFIBWideStringField * ElementREGNUM_REM_SKKT)
{
Object->ElementREGNUM_REM_SKKT=ElementREGNUM_REM_SKKT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprKKTImpl::get_ElementIDKLIENT_REM_SKKT(void)
{
return Object->ElementIDKLIENT_REM_SKKT;
}
//---------------------------------------------------------------
void TREM_DMSprKKTImpl::set_ElementIDKLIENT_REM_SKKT(TFIBLargeIntField * ElementIDKLIENT_REM_SKKT)
{
Object->ElementIDKLIENT_REM_SKKT=ElementIDKLIENT_REM_SKKT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprKKTImpl::get_ElementMESTOUST_REM_SKKT(void)
{
return Object->ElementMESTOUST_REM_SKKT;
}
//---------------------------------------------------------------
void TREM_DMSprKKTImpl::set_ElementMESTOUST_REM_SKKT(TFIBWideStringField * ElementMESTOUST_REM_SKKT)
{
Object->ElementMESTOUST_REM_SKKT=ElementMESTOUST_REM_SKKT;
}
//---------------------------------------------------------------
TFIBDateField * TREM_DMSprKKTImpl::get_ElementRELEASE_REM_SKKT(void)
{
return Object->ElementRELEASE_REM_SKKT;
}
//---------------------------------------------------------------
void TREM_DMSprKKTImpl::set_ElementRELEASE_REM_SKKT(TFIBDateField * ElementRELEASE_REM_SKKT)
{
Object->ElementRELEASE_REM_SKKT=ElementRELEASE_REM_SKKT;
}
//---------------------------------------------------------------
TFIBDateField * TREM_DMSprKKTImpl::get_ElementVVOD_REM_SKKT(void)
{
return Object->ElementVVOD_REM_SKKT;
}
//---------------------------------------------------------------
void TREM_DMSprKKTImpl::set_ElementVVOD_REM_SKKT(TFIBDateField * ElementVVOD_REM_SKKT)
{
Object->ElementVVOD_REM_SKKT=ElementVVOD_REM_SKKT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprKKTImpl::get_ElementCBKGR_REM_SKKT(void)
{
return Object->ElementCBKGR_REM_SKKT;
}
//---------------------------------------------------------------
void TREM_DMSprKKTImpl::set_ElementCBKGR_REM_SKKT(TFIBWideStringField * ElementCBKGR_REM_SKKT)
{
Object->ElementCBKGR_REM_SKKT=ElementCBKGR_REM_SKKT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprKKTImpl::get_ElementCBKCO_REM_SKKT(void)
{
return Object->ElementCBKCO_REM_SKKT;
}
//---------------------------------------------------------------
void TREM_DMSprKKTImpl::set_ElementCBKCO_REM_SKKT(TFIBWideStringField * ElementCBKCO_REM_SKKT)
{
Object->ElementCBKCO_REM_SKKT=ElementCBKCO_REM_SKKT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprKKTImpl::get_ElementNUMCONTRACT_REM_SKKT(void)
{
return Object->ElementNUMCONTRACT_REM_SKKT;
}
//---------------------------------------------------------------
void TREM_DMSprKKTImpl::set_ElementNUMCONTRACT_REM_SKKT(TFIBWideStringField * ElementNUMCONTRACT_REM_SKKT)
{
Object->ElementNUMCONTRACT_REM_SKKT=ElementNUMCONTRACT_REM_SKKT;
}
//---------------------------------------------------------------
TFIBDateField * TREM_DMSprKKTImpl::get_ElementDATECONTRACT_REM_SKKT(void)
{
return Object->ElementDATECONTRACT_REM_SKKT;
}
//---------------------------------------------------------------
void TREM_DMSprKKTImpl::set_ElementDATECONTRACT_REM_SKKT(TFIBDateField * ElementDATECONTRACT_REM_SKKT)
{
Object->ElementDATECONTRACT_REM_SKKT=ElementDATECONTRACT_REM_SKKT;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMSprKKTImpl::get_ElementSUMCONTRACT_REM_SKKT(void)
{
return Object->ElementSUMCONTRACT_REM_SKKT;
}
//---------------------------------------------------------------
void TREM_DMSprKKTImpl::set_ElementSUMCONTRACT_REM_SKKT(TFIBBCDField * ElementSUMCONTRACT_REM_SKKT)
{
Object->ElementSUMCONTRACT_REM_SKKT=ElementSUMCONTRACT_REM_SKKT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprKKTImpl::get_ElementEKLZ_SERNUM_REM_SKKT(void)
{
return Object->ElementEKLZ_SERNUM_REM_SKKT;
}
//---------------------------------------------------------------
void TREM_DMSprKKTImpl::set_ElementEKLZ_SERNUM_REM_SKKT(TFIBWideStringField * ElementEKLZ_SERNUM_REM_SKKT)
{
Object->ElementEKLZ_SERNUM_REM_SKKT=ElementEKLZ_SERNUM_REM_SKKT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprKKTImpl::get_ElementEKLZ_REGNUM_REM_SKKT(void)
{
return Object->ElementEKLZ_REGNUM_REM_SKKT;
}
//---------------------------------------------------------------
void TREM_DMSprKKTImpl::set_ElementEKLZ_REGNUM_REM_SKKT(TFIBWideStringField * ElementEKLZ_REGNUM_REM_SKKT)
{
Object->ElementEKLZ_REGNUM_REM_SKKT=ElementEKLZ_REGNUM_REM_SKKT;
}
//---------------------------------------------------------------
TFIBDateField * TREM_DMSprKKTImpl::get_ElementEKLZ_ACT_REM_SKKT(void)
{
return Object->ElementEKLZ_ACT_REM_SKKT;
}
//---------------------------------------------------------------
void TREM_DMSprKKTImpl::set_ElementEKLZ_ACT_REM_SKKT(TFIBDateField * ElementEKLZ_ACT_REM_SKKT)
{
Object->ElementEKLZ_ACT_REM_SKKT=ElementEKLZ_ACT_REM_SKKT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprKKTImpl::get_ElementPAS_NUMVER_REM_SKKT(void)
{
return Object->ElementPAS_NUMVER_REM_SKKT;
}
//---------------------------------------------------------------
void TREM_DMSprKKTImpl::set_ElementPAS_NUMVER_REM_SKKT(TFIBWideStringField * ElementPAS_NUMVER_REM_SKKT)
{
Object->ElementPAS_NUMVER_REM_SKKT=ElementPAS_NUMVER_REM_SKKT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprKKTImpl::get_ElementPAS_NUMPAS_REM_SKKT(void)
{
return Object->ElementPAS_NUMPAS_REM_SKKT;
}
//---------------------------------------------------------------
void TREM_DMSprKKTImpl::set_ElementPAS_NUMPAS_REM_SKKT(TFIBWideStringField * ElementPAS_NUMPAS_REM_SKKT)
{
Object->ElementPAS_NUMPAS_REM_SKKT=ElementPAS_NUMPAS_REM_SKKT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprKKTImpl::get_ElementPAS_NUMPU_REM_SKKT(void)
{
return Object->ElementPAS_NUMPU_REM_SKKT;
}
//---------------------------------------------------------------
void TREM_DMSprKKTImpl::set_ElementPAS_NUMPU_REM_SKKT(TFIBWideStringField * ElementPAS_NUMPU_REM_SKKT)
{
Object->ElementPAS_NUMPU_REM_SKKT=ElementPAS_NUMPU_REM_SKKT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprKKTImpl::get_ElementPAS_NUMSP_REM_SKKT(void)
{
return Object->ElementPAS_NUMSP_REM_SKKT;
}
//---------------------------------------------------------------
void TREM_DMSprKKTImpl::set_ElementPAS_NUMSP_REM_SKKT(TFIBWideStringField * ElementPAS_NUMSP_REM_SKKT)
{
Object->ElementPAS_NUMSP_REM_SKKT=ElementPAS_NUMSP_REM_SKKT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprKKTImpl::get_ElementPAS_NUMSPPO_REM_SKKT(void)
{
return Object->ElementPAS_NUMSPPO_REM_SKKT;
}
//---------------------------------------------------------------
void TREM_DMSprKKTImpl::set_ElementPAS_NUMSPPO_REM_SKKT(TFIBWideStringField * ElementPAS_NUMSPPO_REM_SKKT)
{
Object->ElementPAS_NUMSPPO_REM_SKKT=ElementPAS_NUMSPPO_REM_SKKT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprKKTImpl::get_ElementPAS_NUMFP_REM_SKKT(void)
{
return Object->ElementPAS_NUMFP_REM_SKKT;
}
//---------------------------------------------------------------
void TREM_DMSprKKTImpl::set_ElementPAS_NUMFP_REM_SKKT(TFIBWideStringField * ElementPAS_NUMFP_REM_SKKT)
{
Object->ElementPAS_NUMFP_REM_SKKT=ElementPAS_NUMFP_REM_SKKT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprKKTImpl::get_ElementPAS_NUMFPPO_REM_SKKT(void)
{
return Object->ElementPAS_NUMFPPO_REM_SKKT;
}
//---------------------------------------------------------------
void TREM_DMSprKKTImpl::set_ElementPAS_NUMFPPO_REM_SKKT(TFIBWideStringField * ElementPAS_NUMFPPO_REM_SKKT)
{
Object->ElementPAS_NUMFPPO_REM_SKKT=ElementPAS_NUMFPPO_REM_SKKT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprKKTImpl::get_ElementPAS_NUMDO_REM_SKKT(void)
{
return Object->ElementPAS_NUMDO_REM_SKKT;
}
//---------------------------------------------------------------
void TREM_DMSprKKTImpl::set_ElementPAS_NUMDO_REM_SKKT(TFIBWideStringField * ElementPAS_NUMDO_REM_SKKT)
{
Object->ElementPAS_NUMDO_REM_SKKT=ElementPAS_NUMDO_REM_SKKT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprKKTImpl::get_ElementPAS_NUMDOPO_REM_SKKT(void)
{
return Object->ElementPAS_NUMDOPO_REM_SKKT;
}
//---------------------------------------------------------------
void TREM_DMSprKKTImpl::set_ElementPAS_NUMDOPO_REM_SKKT(TFIBWideStringField * ElementPAS_NUMDOPO_REM_SKKT)
{
Object->ElementPAS_NUMDOPO_REM_SKKT=ElementPAS_NUMDOPO_REM_SKKT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprKKTImpl::get_ElementPAS_NUMPPP_REM_SKKT(void)
{
return Object->ElementPAS_NUMPPP_REM_SKKT;
}
//---------------------------------------------------------------
void TREM_DMSprKKTImpl::set_ElementPAS_NUMPPP_REM_SKKT(TFIBWideStringField * ElementPAS_NUMPPP_REM_SKKT)
{
Object->ElementPAS_NUMPPP_REM_SKKT=ElementPAS_NUMPPP_REM_SKKT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprKKTImpl::get_ElementPAS_DOR_REM_SKKT(void)
{
return Object->ElementPAS_DOR_REM_SKKT;
}
//---------------------------------------------------------------
void TREM_DMSprKKTImpl::set_ElementPAS_DOR_REM_SKKT(TFIBWideStringField * ElementPAS_DOR_REM_SKKT)
{
Object->ElementPAS_DOR_REM_SKKT=ElementPAS_DOR_REM_SKKT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprKKTImpl::get_ElementPAS_PRIM_REM_SKKT(void)
{
return Object->ElementPAS_PRIM_REM_SKKT;
}
//---------------------------------------------------------------
void TREM_DMSprKKTImpl::set_ElementPAS_PRIM_REM_SKKT(TFIBWideStringField * ElementPAS_PRIM_REM_SKKT)
{
Object->ElementPAS_PRIM_REM_SKKT=ElementPAS_PRIM_REM_SKKT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprKKTImpl::get_ElementIDGRP_REM_SKKT(void)
{
return Object->ElementIDGRP_REM_SKKT;
}
//---------------------------------------------------------------
void TREM_DMSprKKTImpl::set_ElementIDGRP_REM_SKKT(TFIBLargeIntField * ElementIDGRP_REM_SKKT)
{
Object->ElementIDGRP_REM_SKKT=ElementIDGRP_REM_SKKT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprKKTImpl::get_ElementPRIM_REM_SKKT(void)
{
return Object->ElementPRIM_REM_SKKT;
}
//---------------------------------------------------------------
void TREM_DMSprKKTImpl::set_ElementPRIM_REM_SKKT(TFIBWideStringField * ElementPRIM_REM_SKKT)
{
Object->ElementPRIM_REM_SKKT=ElementPRIM_REM_SKKT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprKKTImpl::get_ElementNAME_REM_SMODEL(void)
{
return Object->ElementNAME_REM_SMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprKKTImpl::set_ElementNAME_REM_SMODEL(TFIBWideStringField * ElementNAME_REM_SMODEL)
{
Object->ElementNAME_REM_SMODEL=ElementNAME_REM_SMODEL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprKKTImpl::get_ElementOWNER_NAME(void)
{
return Object->ElementOWNER_NAME;
}
//---------------------------------------------------------------
void TREM_DMSprKKTImpl::set_ElementOWNER_NAME(TFIBWideStringField * ElementOWNER_NAME)
{
Object->ElementOWNER_NAME=ElementOWNER_NAME;
}
//---------------------------------------------------------------
__int64 TREM_DMSprKKTImpl::get_IdGrp(void)
{
return Object->IdGrp;
}
//---------------------------------------------------------------
void TREM_DMSprKKTImpl::set_IdGrp(__int64 IdGrp)
{
Object->IdGrp=IdGrp;
}
//---------------------------------------------------------------
bool TREM_DMSprKKTImpl::get_AllElement(void)
{
return Object->AllElement;
}
//---------------------------------------------------------------
void TREM_DMSprKKTImpl::set_AllElement(bool AllElement)
{
Object->AllElement=AllElement;
}
//---------------------------------------------------------------
__int64 TREM_DMSprKKTImpl::get_IdElement(void)
{
return Object->IdElement;
}
//---------------------------------------------------------------
void TREM_DMSprKKTImpl::set_IdElement(__int64 IdElement)
{
Object->IdElement=IdElement;
}
//---------------------------------------------------------------
bool TREM_DMSprKKTImpl::get_flChangeData(void)
{
return Object->flChangeData;
}
//---------------------------------------------------------------
void TREM_DMSprKKTImpl::set_flChangeData(bool flChangeData)
{
Object->flChangeData=flChangeData;
}
//---------------------------------------------------------------
void TREM_DMSprKKTImpl::OpenTable(__int64 id_grp, bool all)
{
return Object->OpenTable(id_grp, all);
}
//---------------------------------------------------------------
UnicodeString TREM_DMSprKKTImpl::GetTextQuery(__int64 id_grp, bool all)
{
return Object->GetTextQuery(id_grp, all);
}
//---------------------------------------------------------------
int TREM_DMSprKKTImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
bool TREM_DMSprKKTImpl::NewElement(__int64 id_grp)
{
return Object->NewElement( id_grp);
}
//---------------------------------------------------------------
bool TREM_DMSprKKTImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TREM_DMSprKKTImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
void TREM_DMSprKKTImpl::ChancheGrp(__int64 new_id_grp)
{
return Object->ChancheGrp(new_id_grp);
}
//---------------------------------------------------------------
__int64 TREM_DMSprKKTImpl::FindPoName(UnicodeString name)
{
return Object->FindPoName(name);
}
//---------------------------------------------------------------
__int64 TREM_DMSprKKTImpl::GetIdGrpElementa(__int64 id_element)
{
return Object->GetIdGrpElementa(id_element);
}
//---------------------------------------------------------------
void TREM_DMSprKKTImpl::AddNewRecordDv(void)
{
return Object->AddNewRecordDv();
}
//---------------------------------------------------------------
