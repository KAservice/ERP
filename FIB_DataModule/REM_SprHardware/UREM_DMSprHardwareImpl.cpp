#include "vcl.h"
#pragma hdrstop


#include "UREM_DMSprHardwareImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_DMSprHardwareImpl::TREM_DMSprHardwareImpl()           
{                                            
Object=new TREM_DMSprHardware(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_DMSprHardwareImpl::~TREM_DMSprHardwareImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_DMSprHardwareImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_DMSprHardware)                        
   {                                                                     
   *ppv=static_cast<IREM_DMSprHardware*> (this);                                
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
int TREM_DMSprHardwareImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_DMSprHardwareImpl::kanRelease(void)                                  
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
int  TREM_DMSprHardwareImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_DMSprHardwareImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_DMSprHardwareImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_DMSprHardwareImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_DMSprHardwareImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IREM_DMSprHardware
TDataSource * TREM_DMSprHardwareImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TREM_DMSprHardwareImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMSprHardwareImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMSprHardwareImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMSprHardwareImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMSprHardwareImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMSprHardwareImpl::get_Query(void)
{
return Object->Query;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_Query(TpFIBQuery * Query)
{
Object->Query=Query;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprHardwareImpl::get_TableID_REM_SHARDWARE(void)
{
return Object->TableID_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_TableID_REM_SHARDWARE(TFIBLargeIntField * TableID_REM_SHARDWARE)
{
Object->TableID_REM_SHARDWARE=TableID_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprHardwareImpl::get_TableNAME_REM_SHARDWARE(void)
{
return Object->TableNAME_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_TableNAME_REM_SHARDWARE(TFIBWideStringField * TableNAME_REM_SHARDWARE)
{
Object->TableNAME_REM_SHARDWARE=TableNAME_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprHardwareImpl::get_TableSERNUM_REM_SHARDWARE(void)
{
return Object->TableSERNUM_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_TableSERNUM_REM_SHARDWARE(TFIBWideStringField * TableSERNUM_REM_SHARDWARE)
{
Object->TableSERNUM_REM_SHARDWARE=TableSERNUM_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMSprHardwareImpl::get_TableCODE_REM_SHARDWARE(void)
{
return Object->TableCODE_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_TableCODE_REM_SHARDWARE(TFIBIntegerField * TableCODE_REM_SHARDWARE)
{
Object->TableCODE_REM_SHARDWARE=TableCODE_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMSprHardwareImpl::get_TableSROKWARRANTY_REM_SHARDWARE(void)
{
return Object->TableSROKWARRANTY_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_TableSROKWARRANTY_REM_SHARDWARE(TFIBIntegerField * TableSROKWARRANTY_REM_SHARDWARE)
{
Object->TableSROKWARRANTY_REM_SHARDWARE=TableSROKWARRANTY_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprHardwareImpl::get_TableSERNUM2_REM_SHARDWARE(void)
{
return Object->TableSERNUM2_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_TableSERNUM2_REM_SHARDWARE(TFIBWideStringField * TableSERNUM2_REM_SHARDWARE)
{
Object->TableSERNUM2_REM_SHARDWARE=TableSERNUM2_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprHardwareImpl::get_TableSERNUM_STR_REM_SHARDWARE(void)
{
return Object->TableSERNUM_STR_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_TableSERNUM_STR_REM_SHARDWARE(TFIBWideStringField * TableSERNUM_STR_REM_SHARDWARE)
{
Object->TableSERNUM_STR_REM_SHARDWARE=TableSERNUM_STR_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMSprHardwareImpl::get_TableFL_NECOND_REM_SHARDWARE(void)
{
return Object->TableFL_NECOND_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_TableFL_NECOND_REM_SHARDWARE(TFIBSmallIntField * TableFL_NECOND_REM_SHARDWARE)
{
Object->TableFL_NECOND_REM_SHARDWARE=TableFL_NECOND_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMSprHardwareImpl::get_TablePRICE_REM_SHARDWARE(void)
{
return Object->TablePRICE_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_TablePRICE_REM_SHARDWARE(TFIBBCDField * TablePRICE_REM_SHARDWARE)
{
Object->TablePRICE_REM_SHARDWARE=TablePRICE_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMSprHardwareImpl::get_TableFL_FICT_REMONT_REM_SHARDWARE(void)
{
return Object->TableFL_FICT_REMONT_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_TableFL_FICT_REMONT_REM_SHARDWARE(TFIBSmallIntField * TableFL_FICT_REMONT_REM_SHARDWARE)
{
Object->TableFL_FICT_REMONT_REM_SHARDWARE=TableFL_FICT_REMONT_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMSprHardwareImpl::get_TableFL_REMONT_REM_SHARDWARE(void)
{
return Object->TableFL_REMONT_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_TableFL_REMONT_REM_SHARDWARE(TFIBSmallIntField * TableFL_REMONT_REM_SHARDWARE)
{
Object->TableFL_REMONT_REM_SHARDWARE=TableFL_REMONT_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMSprHardwareImpl::get_TableFL_ACT_REM_SHARDWARE(void)
{
return Object->TableFL_ACT_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_TableFL_ACT_REM_SHARDWARE(TFIBSmallIntField * TableFL_ACT_REM_SHARDWARE)
{
Object->TableFL_ACT_REM_SHARDWARE=TableFL_ACT_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprHardwareImpl::get_ElementID_REM_SHARDWARE(void)
{
return Object->ElementID_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_ElementID_REM_SHARDWARE(TFIBLargeIntField * ElementID_REM_SHARDWARE)
{
Object->ElementID_REM_SHARDWARE=ElementID_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprHardwareImpl::get_ElementIDBASE_REM_SHARDWARE(void)
{
return Object->ElementIDBASE_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_ElementIDBASE_REM_SHARDWARE(TFIBLargeIntField * ElementIDBASE_REM_SHARDWARE)
{
Object->ElementIDBASE_REM_SHARDWARE=ElementIDBASE_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprHardwareImpl::get_ElementNAME_REM_SHARDWARE(void)
{
return Object->ElementNAME_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_ElementNAME_REM_SHARDWARE(TFIBWideStringField * ElementNAME_REM_SHARDWARE)
{
Object->ElementNAME_REM_SHARDWARE=ElementNAME_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprHardwareImpl::get_ElementIDGRP_REM_SHARDWARE(void)
{
return Object->ElementIDGRP_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_ElementIDGRP_REM_SHARDWARE(TFIBLargeIntField * ElementIDGRP_REM_SHARDWARE)
{
Object->ElementIDGRP_REM_SHARDWARE=ElementIDGRP_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprHardwareImpl::get_ElementIDMODEL_REM_SHARDWARE(void)
{
return Object->ElementIDMODEL_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_ElementIDMODEL_REM_SHARDWARE(TFIBLargeIntField * ElementIDMODEL_REM_SHARDWARE)
{
Object->ElementIDMODEL_REM_SHARDWARE=ElementIDMODEL_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprHardwareImpl::get_ElementIDPOST_REM_SHARDWARE(void)
{
return Object->ElementIDPOST_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_ElementIDPOST_REM_SHARDWARE(TFIBLargeIntField * ElementIDPOST_REM_SHARDWARE)
{
Object->ElementIDPOST_REM_SHARDWARE=ElementIDPOST_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMSprHardwareImpl::get_ElementTYPESYSPOST_REM_SHARDWARE(void)
{
return Object->ElementTYPESYSPOST_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_ElementTYPESYSPOST_REM_SHARDWARE(TFIBSmallIntField * ElementTYPESYSPOST_REM_SHARDWARE)
{
Object->ElementTYPESYSPOST_REM_SHARDWARE=ElementTYPESYSPOST_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprHardwareImpl::get_ElementIDDOCPOST_REM_SHARDWARE(void)
{
return Object->ElementIDDOCPOST_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_ElementIDDOCPOST_REM_SHARDWARE(TFIBLargeIntField * ElementIDDOCPOST_REM_SHARDWARE)
{
Object->ElementIDDOCPOST_REM_SHARDWARE=ElementIDDOCPOST_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprHardwareImpl::get_ElementSERNUM_REM_SHARDWARE(void)
{
return Object->ElementSERNUM_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_ElementSERNUM_REM_SHARDWARE(TFIBWideStringField * ElementSERNUM_REM_SHARDWARE)
{
Object->ElementSERNUM_REM_SHARDWARE=ElementSERNUM_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBDateField * TREM_DMSprHardwareImpl::get_ElementWARRANTY_REM_SHARDWARE(void)
{
return Object->ElementWARRANTY_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_ElementWARRANTY_REM_SHARDWARE(TFIBDateField * ElementWARRANTY_REM_SHARDWARE)
{
Object->ElementWARRANTY_REM_SHARDWARE=ElementWARRANTY_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBDateField * TREM_DMSprHardwareImpl::get_ElementSALE_REM_SHARDWARE(void)
{
return Object->ElementSALE_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_ElementSALE_REM_SHARDWARE(TFIBDateField * ElementSALE_REM_SHARDWARE)
{
Object->ElementSALE_REM_SHARDWARE=ElementSALE_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprHardwareImpl::get_ElementIDVLAD_REM_SHARDWARE(void)
{
return Object->ElementIDVLAD_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_ElementIDVLAD_REM_SHARDWARE(TFIBLargeIntField * ElementIDVLAD_REM_SHARDWARE)
{
Object->ElementIDVLAD_REM_SHARDWARE=ElementIDVLAD_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprHardwareImpl::get_ElementNAMEVLAD_REM_SHARDWARE(void)
{
return Object->ElementNAMEVLAD_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_ElementNAMEVLAD_REM_SHARDWARE(TFIBWideStringField * ElementNAMEVLAD_REM_SHARDWARE)
{
Object->ElementNAMEVLAD_REM_SHARDWARE=ElementNAMEVLAD_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMSprHardwareImpl::get_ElementTYPESYSSALE_REM_SHARDWARE(void)
{
return Object->ElementTYPESYSSALE_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_ElementTYPESYSSALE_REM_SHARDWARE(TFIBSmallIntField * ElementTYPESYSSALE_REM_SHARDWARE)
{
Object->ElementTYPESYSSALE_REM_SHARDWARE=ElementTYPESYSSALE_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprHardwareImpl::get_ElementIDDOCSALE_REM_SHARDWARE(void)
{
return Object->ElementIDDOCSALE_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_ElementIDDOCSALE_REM_SHARDWARE(TFIBLargeIntField * ElementIDDOCSALE_REM_SHARDWARE)
{
Object->ElementIDDOCSALE_REM_SHARDWARE=ElementIDDOCSALE_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMSprHardwareImpl::get_ElementCODE_REM_SHARDWARE(void)
{
return Object->ElementCODE_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_ElementCODE_REM_SHARDWARE(TFIBIntegerField * ElementCODE_REM_SHARDWARE)
{
Object->ElementCODE_REM_SHARDWARE=ElementCODE_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMSprHardwareImpl::get_ElementSROKWARRANTY_REM_SHARDWARE(void)
{
return Object->ElementSROKWARRANTY_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_ElementSROKWARRANTY_REM_SHARDWARE(TFIBIntegerField * ElementSROKWARRANTY_REM_SHARDWARE)
{
Object->ElementSROKWARRANTY_REM_SHARDWARE=ElementSROKWARRANTY_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprHardwareImpl::get_ElementIDDOCREM_SALE_REM_SHARDWARE(void)
{
return Object->ElementIDDOCREM_SALE_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_ElementIDDOCREM_SALE_REM_SHARDWARE(TFIBLargeIntField * ElementIDDOCREM_SALE_REM_SHARDWARE)
{
Object->ElementIDDOCREM_SALE_REM_SHARDWARE=ElementIDDOCREM_SALE_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprHardwareImpl::get_ElementSERNUM2_REM_SHARDWARE(void)
{
return Object->ElementSERNUM2_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_ElementSERNUM2_REM_SHARDWARE(TFIBWideStringField * ElementSERNUM2_REM_SHARDWARE)
{
Object->ElementSERNUM2_REM_SHARDWARE=ElementSERNUM2_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprHardwareImpl::get_ElementSERNUM_STR_REM_SHARDWARE(void)
{
return Object->ElementSERNUM_STR_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_ElementSERNUM_STR_REM_SHARDWARE(TFIBWideStringField * ElementSERNUM_STR_REM_SHARDWARE)
{
Object->ElementSERNUM_STR_REM_SHARDWARE=ElementSERNUM_STR_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMSprHardwareImpl::get_ElementFL_NECOND_REM_SHARDWARE(void)
{
return Object->ElementFL_NECOND_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_ElementFL_NECOND_REM_SHARDWARE(TFIBSmallIntField * ElementFL_NECOND_REM_SHARDWARE)
{
Object->ElementFL_NECOND_REM_SHARDWARE=ElementFL_NECOND_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMSprHardwareImpl::get_ElementPRICE_REM_SHARDWARE(void)
{
return Object->ElementPRICE_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_ElementPRICE_REM_SHARDWARE(TFIBBCDField * ElementPRICE_REM_SHARDWARE)
{
Object->ElementPRICE_REM_SHARDWARE=ElementPRICE_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprHardwareImpl::get_ElementPRICHINA_REM_SHARDWARE(void)
{
return Object->ElementPRICHINA_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_ElementPRICHINA_REM_SHARDWARE(TFIBWideStringField * ElementPRICHINA_REM_SHARDWARE)
{
Object->ElementPRICHINA_REM_SHARDWARE=ElementPRICHINA_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprHardwareImpl::get_ElementPRIM_REM_SHARDWARE(void)
{
return Object->ElementPRIM_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_ElementPRIM_REM_SHARDWARE(TFIBWideStringField * ElementPRIM_REM_SHARDWARE)
{
Object->ElementPRIM_REM_SHARDWARE=ElementPRIM_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMSprHardwareImpl::get_ElementFL_FICT_REMONT_REM_SHARDWARE(void)
{
return Object->ElementFL_FICT_REMONT_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_ElementFL_FICT_REMONT_REM_SHARDWARE(TFIBSmallIntField * ElementFL_FICT_REMONT_REM_SHARDWARE)
{
Object->ElementFL_FICT_REMONT_REM_SHARDWARE=ElementFL_FICT_REMONT_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMSprHardwareImpl::get_ElementFL_REMONT_REM_SHARDWARE(void)
{
return Object->ElementFL_REMONT_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_ElementFL_REMONT_REM_SHARDWARE(TFIBSmallIntField * ElementFL_REMONT_REM_SHARDWARE)
{
Object->ElementFL_REMONT_REM_SHARDWARE=ElementFL_REMONT_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprHardwareImpl::get_ElementIDPRODUCER_REM_SHARDWARE(void)
{
return Object->ElementIDPRODUCER_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_ElementIDPRODUCER_REM_SHARDWARE(TFIBLargeIntField * ElementIDPRODUCER_REM_SHARDWARE)
{
Object->ElementIDPRODUCER_REM_SHARDWARE=ElementIDPRODUCER_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprHardwareImpl::get_ElementIDBRAND_REM_SHARDWARE(void)
{
return Object->ElementIDBRAND_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_ElementIDBRAND_REM_SHARDWARE(TFIBLargeIntField * ElementIDBRAND_REM_SHARDWARE)
{
Object->ElementIDBRAND_REM_SHARDWARE=ElementIDBRAND_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprHardwareImpl::get_ElementIDZ_REM_SHARDWARE(void)
{
return Object->ElementIDZ_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_ElementIDZ_REM_SHARDWARE(TFIBLargeIntField * ElementIDZ_REM_SHARDWARE)
{
Object->ElementIDZ_REM_SHARDWARE=ElementIDZ_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMSprHardwareImpl::get_ElementTYPE_ELEMENTA_REM_SHARDWARE(void)
{
return Object->ElementTYPE_ELEMENTA_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_ElementTYPE_ELEMENTA_REM_SHARDWARE(TFIBIntegerField * ElementTYPE_ELEMENTA_REM_SHARDWARE)
{
Object->ElementTYPE_ELEMENTA_REM_SHARDWARE=ElementTYPE_ELEMENTA_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMSprHardwareImpl::get_ElementFL_ACT_REM_SHARDWARE(void)
{
return Object->ElementFL_ACT_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_ElementFL_ACT_REM_SHARDWARE(TFIBSmallIntField * ElementFL_ACT_REM_SHARDWARE)
{
Object->ElementFL_ACT_REM_SHARDWARE=ElementFL_ACT_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMSprHardwareImpl::get_ElementFL_UTILIZ_REM_SHARDWARE(void)
{
return Object->ElementFL_UTILIZ_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_ElementFL_UTILIZ_REM_SHARDWARE(TFIBSmallIntField * ElementFL_UTILIZ_REM_SHARDWARE)
{
Object->ElementFL_UTILIZ_REM_SHARDWARE=ElementFL_UTILIZ_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMSprHardwareImpl::get_ElementPOS_POST_REM_SHARDWARE(void)
{
return Object->ElementPOS_POST_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_ElementPOS_POST_REM_SHARDWARE(TFIBDateTimeField * ElementPOS_POST_REM_SHARDWARE)
{
Object->ElementPOS_POST_REM_SHARDWARE=ElementPOS_POST_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMSprHardwareImpl::get_ElementPOS_UTILIZ_REM_SHARDWARE(void)
{
return Object->ElementPOS_UTILIZ_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_ElementPOS_UTILIZ_REM_SHARDWARE(TFIBDateTimeField * ElementPOS_UTILIZ_REM_SHARDWARE)
{
Object->ElementPOS_UTILIZ_REM_SHARDWARE=ElementPOS_UTILIZ_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMSprHardwareImpl::get_ElementPOS_HRAN_DO_REM_SHARDWARE(void)
{
return Object->ElementPOS_HRAN_DO_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_ElementPOS_HRAN_DO_REM_SHARDWARE(TFIBDateTimeField * ElementPOS_HRAN_DO_REM_SHARDWARE)
{
Object->ElementPOS_HRAN_DO_REM_SHARDWARE=ElementPOS_HRAN_DO_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprHardwareImpl::get_ElementIDPRMODEL_REM_SHARDWARE(void)
{
return Object->ElementIDPRMODEL_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_ElementIDPRMODEL_REM_SHARDWARE(TFIBLargeIntField * ElementIDPRMODEL_REM_SHARDWARE)
{
Object->ElementIDPRMODEL_REM_SHARDWARE=ElementIDPRMODEL_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprHardwareImpl::get_ElementNAME_REM_SMODEL(void)
{
return Object->ElementNAME_REM_SMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_ElementNAME_REM_SMODEL(TFIBWideStringField * ElementNAME_REM_SMODEL)
{
Object->ElementNAME_REM_SMODEL=ElementNAME_REM_SMODEL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprHardwareImpl::get_ElementSUPPLIER_NAME(void)
{
return Object->ElementSUPPLIER_NAME;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_ElementSUPPLIER_NAME(TFIBWideStringField * ElementSUPPLIER_NAME)
{
Object->ElementSUPPLIER_NAME=ElementSUPPLIER_NAME;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprHardwareImpl::get_ElementOWNER_NAME(void)
{
return Object->ElementOWNER_NAME;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_ElementOWNER_NAME(TFIBWideStringField * ElementOWNER_NAME)
{
Object->ElementOWNER_NAME=ElementOWNER_NAME;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprHardwareImpl::get_ElementTDOC_DOCPOST(void)
{
return Object->ElementTDOC_DOCPOST;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_ElementTDOC_DOCPOST(TFIBWideStringField * ElementTDOC_DOCPOST)
{
Object->ElementTDOC_DOCPOST=ElementTDOC_DOCPOST;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMSprHardwareImpl::get_ElementPOSDOC_DOCPOST(void)
{
return Object->ElementPOSDOC_DOCPOST;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_ElementPOSDOC_DOCPOST(TFIBDateTimeField * ElementPOSDOC_DOCPOST)
{
Object->ElementPOSDOC_DOCPOST=ElementPOSDOC_DOCPOST;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMSprHardwareImpl::get_ElementNUMDOC_DOCPOST(void)
{
return Object->ElementNUMDOC_DOCPOST;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_ElementNUMDOC_DOCPOST(TFIBIntegerField * ElementNUMDOC_DOCPOST)
{
Object->ElementNUMDOC_DOCPOST=ElementNUMDOC_DOCPOST;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprHardwareImpl::get_ElementTDOC_DOCSALE(void)
{
return Object->ElementTDOC_DOCSALE;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_ElementTDOC_DOCSALE(TFIBWideStringField * ElementTDOC_DOCSALE)
{
Object->ElementTDOC_DOCSALE=ElementTDOC_DOCSALE;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMSprHardwareImpl::get_ElementPOSDOC_DOCSALE(void)
{
return Object->ElementPOSDOC_DOCSALE;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_ElementPOSDOC_DOCSALE(TFIBDateTimeField * ElementPOSDOC_DOCSALE)
{
Object->ElementPOSDOC_DOCSALE=ElementPOSDOC_DOCSALE;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMSprHardwareImpl::get_ElementNUMDOC_DOCSALE(void)
{
return Object->ElementNUMDOC_DOCSALE;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_ElementNUMDOC_DOCSALE(TFIBIntegerField * ElementNUMDOC_DOCSALE)
{
Object->ElementNUMDOC_DOCSALE=ElementNUMDOC_DOCSALE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprHardwareImpl::get_ElementNAME_SBRAND(void)
{
return Object->ElementNAME_SBRAND;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_ElementNAME_SBRAND(TFIBWideStringField * ElementNAME_SBRAND)
{
Object->ElementNAME_SBRAND=ElementNAME_SBRAND;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprHardwareImpl::get_ElementNAME_SPRODUCER(void)
{
return Object->ElementNAME_SPRODUCER;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_ElementNAME_SPRODUCER(TFIBWideStringField * ElementNAME_SPRODUCER)
{
Object->ElementNAME_SPRODUCER=ElementNAME_SPRODUCER;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprHardwareImpl::get_ElementNAME_REM_Z(void)
{
return Object->ElementNAME_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_ElementNAME_REM_Z(TFIBWideStringField * ElementNAME_REM_Z)
{
Object->ElementNAME_REM_Z=ElementNAME_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprHardwareImpl::get_ElementPREFIKS_NUM_REM_Z(void)
{
return Object->ElementPREFIKS_NUM_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_ElementPREFIKS_NUM_REM_Z(TFIBWideStringField * ElementPREFIKS_NUM_REM_Z)
{
Object->ElementPREFIKS_NUM_REM_Z=ElementPREFIKS_NUM_REM_Z;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMSprHardwareImpl::get_ElementPOS_REM_Z(void)
{
return Object->ElementPOS_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_ElementPOS_REM_Z(TFIBDateTimeField * ElementPOS_REM_Z)
{
Object->ElementPOS_REM_Z=ElementPOS_REM_Z;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMSprHardwareImpl::get_ElementNUM_REM_Z(void)
{
return Object->ElementNUM_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_ElementNUM_REM_Z(TFIBIntegerField * ElementNUM_REM_Z)
{
Object->ElementNUM_REM_Z=ElementNUM_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprHardwareImpl::get_ElementMODEL_REM_Z(void)
{
return Object->ElementMODEL_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_ElementMODEL_REM_Z(TFIBWideStringField * ElementMODEL_REM_Z)
{
Object->ElementMODEL_REM_Z=ElementMODEL_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprHardwareImpl::get_ElementSERNUM_REM_Z(void)
{
return Object->ElementSERNUM_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_ElementSERNUM_REM_Z(TFIBWideStringField * ElementSERNUM_REM_Z)
{
Object->ElementSERNUM_REM_Z=ElementSERNUM_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprHardwareImpl::get_ElementNAME_REM_SPRMODEL(void)
{
return Object->ElementNAME_REM_SPRMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_ElementNAME_REM_SPRMODEL(TFIBWideStringField * ElementNAME_REM_SPRMODEL)
{
Object->ElementNAME_REM_SPRMODEL=ElementNAME_REM_SPRMODEL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprHardwareImpl::get_TableNAME_ENG_REM_SHARDWARE(void)
{
return Object->TableNAME_ENG_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_TableNAME_ENG_REM_SHARDWARE(TFIBWideStringField * TableNAME_ENG_REM_SHARDWARE)
{
Object->TableNAME_ENG_REM_SHARDWARE=TableNAME_ENG_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprHardwareImpl::get_TableARTIKUL_REM_SHARDWARE(void)
{
return Object->TableARTIKUL_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_TableARTIKUL_REM_SHARDWARE(TFIBWideStringField * TableARTIKUL_REM_SHARDWARE)
{
Object->TableARTIKUL_REM_SHARDWARE=TableARTIKUL_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprHardwareImpl::get_TablePARTNUM_REM_SHARDWARE(void)
{
return Object->TablePARTNUM_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_TablePARTNUM_REM_SHARDWARE(TFIBWideStringField * TablePARTNUM_REM_SHARDWARE)
{
Object->TablePARTNUM_REM_SHARDWARE=TablePARTNUM_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprHardwareImpl::get_ElementSERNUM3_REM_SHARDWARE(void)
{
return Object->ElementSERNUM3_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_ElementSERNUM3_REM_SHARDWARE(TFIBWideStringField * ElementSERNUM3_REM_SHARDWARE)
{
Object->ElementSERNUM3_REM_SHARDWARE=ElementSERNUM3_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprHardwareImpl::get_ElementSERNUM4_REM_SHARDWARE(void)
{
return Object->ElementSERNUM4_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_ElementSERNUM4_REM_SHARDWARE(TFIBWideStringField * ElementSERNUM4_REM_SHARDWARE)
{
Object->ElementSERNUM4_REM_SHARDWARE=ElementSERNUM4_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprHardwareImpl::get_ElementNUMBAT_REM_SHARDWARE(void)
{
return Object->ElementNUMBAT_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_ElementNUMBAT_REM_SHARDWARE(TFIBWideStringField * ElementNUMBAT_REM_SHARDWARE)
{
Object->ElementNUMBAT_REM_SHARDWARE=ElementNUMBAT_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprHardwareImpl::get_ElementNUMGARTALON_REM_SHARDWARE(void)
{
return Object->ElementNUMGARTALON_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_ElementNUMGARTALON_REM_SHARDWARE(TFIBWideStringField * ElementNUMGARTALON_REM_SHARDWARE)
{
Object->ElementNUMGARTALON_REM_SHARDWARE=ElementNUMGARTALON_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprHardwareImpl::get_ElementSWCODE_REM_SHARDWARE(void)
{
return Object->ElementSWCODE_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_ElementSWCODE_REM_SHARDWARE(TFIBWideStringField * ElementSWCODE_REM_SHARDWARE)
{
Object->ElementSWCODE_REM_SHARDWARE=ElementSWCODE_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprHardwareImpl::get_ElementHWCODE_REM_SHARDWARE(void)
{
return Object->ElementHWCODE_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_ElementHWCODE_REM_SHARDWARE(TFIBWideStringField * ElementHWCODE_REM_SHARDWARE)
{
Object->ElementHWCODE_REM_SHARDWARE=ElementHWCODE_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprHardwareImpl::get_ElementVERPO_REM_SHARDWARE(void)
{
return Object->ElementVERPO_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_ElementVERPO_REM_SHARDWARE(TFIBWideStringField * ElementVERPO_REM_SHARDWARE)
{
Object->ElementVERPO_REM_SHARDWARE=ElementVERPO_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprHardwareImpl::get_ElementPARTNUM_REM_SHARDWARE(void)
{
return Object->ElementPARTNUM_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_ElementPARTNUM_REM_SHARDWARE(TFIBWideStringField * ElementPARTNUM_REM_SHARDWARE)
{
Object->ElementPARTNUM_REM_SHARDWARE=ElementPARTNUM_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprHardwareImpl::get_ElementMTM_REM_SHARDWARE(void)
{
return Object->ElementMTM_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_ElementMTM_REM_SHARDWARE(TFIBWideStringField * ElementMTM_REM_SHARDWARE)
{
Object->ElementMTM_REM_SHARDWARE=ElementMTM_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprHardwareImpl::get_ElementFRU_REM_SHARDWARE(void)
{
return Object->ElementFRU_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_ElementFRU_REM_SHARDWARE(TFIBWideStringField * ElementFRU_REM_SHARDWARE)
{
Object->ElementFRU_REM_SHARDWARE=ElementFRU_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprHardwareImpl::get_ElementNAME_ENG_REM_SHARDWARE(void)
{
return Object->ElementNAME_ENG_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_ElementNAME_ENG_REM_SHARDWARE(TFIBWideStringField * ElementNAME_ENG_REM_SHARDWARE)
{
Object->ElementNAME_ENG_REM_SHARDWARE=ElementNAME_ENG_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprHardwareImpl::get_ElementCRU_REM_SHARDWARE(void)
{
return Object->ElementCRU_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_ElementCRU_REM_SHARDWARE(TFIBWideStringField * ElementCRU_REM_SHARDWARE)
{
Object->ElementCRU_REM_SHARDWARE=ElementCRU_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprHardwareImpl::get_ElementARTIKUL_REM_SHARDWARE(void)
{
return Object->ElementARTIKUL_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_ElementARTIKUL_REM_SHARDWARE(TFIBWideStringField * ElementARTIKUL_REM_SHARDWARE)
{
Object->ElementARTIKUL_REM_SHARDWARE=ElementARTIKUL_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprHardwareImpl::get_TableOUT_IDFIRM(void)
{
return Object->TableOUT_IDFIRM;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_TableOUT_IDFIRM(TFIBLargeIntField * TableOUT_IDFIRM)
{
Object->TableOUT_IDFIRM=TableOUT_IDFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprHardwareImpl::get_TableOUT_NAME_FIRM(void)
{
return Object->TableOUT_NAME_FIRM;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_TableOUT_NAME_FIRM(TFIBWideStringField * TableOUT_NAME_FIRM)
{
Object->TableOUT_NAME_FIRM=TableOUT_NAME_FIRM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprHardwareImpl::get_TableOUT_IDSKLAD(void)
{
return Object->TableOUT_IDSKLAD;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_TableOUT_IDSKLAD(TFIBLargeIntField * TableOUT_IDSKLAD)
{
Object->TableOUT_IDSKLAD=TableOUT_IDSKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprHardwareImpl::get_TableOUT_NAME_SKLAD(void)
{
return Object->TableOUT_NAME_SKLAD;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_TableOUT_NAME_SKLAD(TFIBWideStringField * TableOUT_NAME_SKLAD)
{
Object->TableOUT_NAME_SKLAD=TableOUT_NAME_SKLAD;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprHardwareImpl::get_TableOUT_IDTNOM(void)
{
return Object->TableOUT_IDTNOM;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_TableOUT_IDTNOM(TFIBLargeIntField * TableOUT_IDTNOM)
{
Object->TableOUT_IDTNOM=TableOUT_IDTNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprHardwareImpl::get_TableOUT_NAME_TYPE_NOM(void)
{
return Object->TableOUT_NAME_TYPE_NOM;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_TableOUT_NAME_TYPE_NOM(TFIBWideStringField * TableOUT_NAME_TYPE_NOM)
{
Object->TableOUT_NAME_TYPE_NOM=TableOUT_NAME_TYPE_NOM;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMSprHardwareImpl::get_TableOUT_OST(void)
{
return Object->TableOUT_OST;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_TableOUT_OST(TFIBBCDField * TableOUT_OST)
{
Object->TableOUT_OST=TableOUT_OST;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprHardwareImpl::get_TableIDGRP_REM_SHARDWARE(void)
{
return Object->TableIDGRP_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_TableIDGRP_REM_SHARDWARE(TFIBLargeIntField * TableIDGRP_REM_SHARDWARE)
{
Object->TableIDGRP_REM_SHARDWARE=TableIDGRP_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprHardwareImpl::get_TableOUT_IDMHRAN(void)
{
return Object->TableOUT_IDMHRAN;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_TableOUT_IDMHRAN(TFIBLargeIntField * TableOUT_IDMHRAN)
{
Object->TableOUT_IDMHRAN=TableOUT_IDMHRAN;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprHardwareImpl::get_TableOUT_NAME_MHRAN(void)
{
return Object->TableOUT_NAME_MHRAN;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_TableOUT_NAME_MHRAN(TFIBWideStringField * TableOUT_NAME_MHRAN)
{
Object->TableOUT_NAME_MHRAN=TableOUT_NAME_MHRAN;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMSprHardwareImpl::get_TableOUT_FL_OTCH_PROIZV(void)
{
return Object->TableOUT_FL_OTCH_PROIZV;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_TableOUT_FL_OTCH_PROIZV(TFIBSmallIntField * TableOUT_FL_OTCH_PROIZV)
{
Object->TableOUT_FL_OTCH_PROIZV=TableOUT_FL_OTCH_PROIZV;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMSprHardwareImpl::get_TableOUT_FL_NO_RAZBOR(void)
{
return Object->TableOUT_FL_NO_RAZBOR;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_TableOUT_FL_NO_RAZBOR(TFIBSmallIntField * TableOUT_FL_NO_RAZBOR)
{
Object->TableOUT_FL_NO_RAZBOR=TableOUT_FL_NO_RAZBOR;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMSprHardwareImpl::get_ElementFL_OTCH_PROIZV_REM_SHARDWARE(void)
{
return Object->ElementFL_OTCH_PROIZV_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_ElementFL_OTCH_PROIZV_REM_SHARDWARE(TFIBSmallIntField * ElementFL_OTCH_PROIZV_REM_SHARDWARE)
{
Object->ElementFL_OTCH_PROIZV_REM_SHARDWARE=ElementFL_OTCH_PROIZV_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMSprHardwareImpl::get_ElementFL_NO_RAZBOR_REM_SHARDWARE(void)
{
return Object->ElementFL_NO_RAZBOR_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_ElementFL_NO_RAZBOR_REM_SHARDWARE(TFIBSmallIntField * ElementFL_NO_RAZBOR_REM_SHARDWARE)
{
Object->ElementFL_NO_RAZBOR_REM_SHARDWARE=ElementFL_NO_RAZBOR_REM_SHARDWARE;
}
//---------------------------------------------------------------
__int64 TREM_DMSprHardwareImpl::get_IdGrp(void)
{
return Object->IdGrp;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_IdGrp(__int64 IdGrp)
{
Object->IdGrp=IdGrp;
}
//---------------------------------------------------------------
bool TREM_DMSprHardwareImpl::get_AllElement(void)
{
return Object->AllElement;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_AllElement(bool AllElement)
{
Object->AllElement=AllElement;
}
//---------------------------------------------------------------
__int64 TREM_DMSprHardwareImpl::get_IdElement(void)
{
return Object->IdElement;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::set_IdElement(__int64 IdElement)
{
Object->IdElement=IdElement;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::OpenTable(__int64 id_grp, bool all)
{
return Object->OpenTable(id_grp, all);
}
//---------------------------------------------------------------
UnicodeString TREM_DMSprHardwareImpl::GetTextQuery(__int64 id_grp, bool all)
{
return Object->GetTextQuery( id_grp,  all);
}
//---------------------------------------------------------------
int TREM_DMSprHardwareImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
bool TREM_DMSprHardwareImpl::NewElement(__int64 id_grp)
{
return Object->NewElement(id_grp);
}
//---------------------------------------------------------------
bool TREM_DMSprHardwareImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TREM_DMSprHardwareImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement( id);
}
//---------------------------------------------------------------
void TREM_DMSprHardwareImpl::ChancheGrp(__int64 new_id_grp, __int64 id_el)
{
return Object->ChancheGrp(new_id_grp,id_el);
}
//---------------------------------------------------------------
__int64 TREM_DMSprHardwareImpl::FindPoName(UnicodeString name)
{
return Object->FindPoName(name);
}
//---------------------------------------------------------------
__int64 TREM_DMSprHardwareImpl::GetIdGrpElementa(__int64 id_element)
{
return Object->GetIdGrpElementa(id_element);
}
//---------------------------------------------------------------
__int64 TREM_DMSprHardwareImpl::GetIdPoCodu(int code)
{
return Object->GetIdPoCodu(code);
}
//---------------------------------------------------------------
bool TREM_DMSprHardwareImpl::Table_FindPoSerNum1Like(__int64 id_grp, bool all, UnicodeString ser_num)
{
return Object->Table_FindPoSerNum1Like(id_grp, all, ser_num);
}
//---------------------------------------------------------------
bool TREM_DMSprHardwareImpl::Table_FindPoSerNum2Like(__int64 id_grp, bool all, UnicodeString ser_num)
{
return Object->Table_FindPoSerNum2Like( id_grp, all, ser_num);
}
//---------------------------------------------------------------
bool TREM_DMSprHardwareImpl::Table_FindPoSerNumStrLike(__int64 id_grp, bool all, UnicodeString ser_num)
{
return Object->Table_FindPoSerNumStrLike(id_grp, all,  ser_num);
}
//---------------------------------------------------------------
