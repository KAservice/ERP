#include "vcl.h"
#pragma hdrstop


#include "UREM_DMSprHardwareIspImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_DMSprHardwareIspImpl::TREM_DMSprHardwareIspImpl()           
{                                            
Object=new TREM_DMSprHardwareIsp(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_DMSprHardwareIspImpl::~TREM_DMSprHardwareIspImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_DMSprHardwareIspImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_DMSprHardwareIspImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_DMSprHardwareIsp)                        
   {                                                                     
   *ppv=static_cast<IREM_DMSprHardwareIsp*> (this);                                
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
int TREM_DMSprHardwareIspImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_DMSprHardwareIspImpl::kanRelease(void)                                  
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
int  TREM_DMSprHardwareIspImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMSprHardwareIspImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_DMSprHardwareIspImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMSprHardwareIspImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_DMSprHardwareIspImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_DMSprHardwareIspImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_DMSprHardwareIspImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IREM_DMSprHardwareIsp
TDataSource * TREM_DMSprHardwareIspImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareIspImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TREM_DMSprHardwareIspImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareIspImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMSprHardwareIspImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareIspImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMSprHardwareIspImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareIspImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMSprHardwareIspImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareIspImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMSprHardwareIspImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareIspImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMSprHardwareIspImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareIspImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprHardwareIspImpl::get_TableID_REM_SHARDWARE_ISP(void)
{
return Object->TableID_REM_SHARDWARE_ISP;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareIspImpl::set_TableID_REM_SHARDWARE_ISP(TFIBLargeIntField * TableID_REM_SHARDWARE_ISP)
{
Object->TableID_REM_SHARDWARE_ISP=TableID_REM_SHARDWARE_ISP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprHardwareIspImpl::get_TableIDBASE_REM_SHARDWARE_ISP(void)
{
return Object->TableIDBASE_REM_SHARDWARE_ISP;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareIspImpl::set_TableIDBASE_REM_SHARDWARE_ISP(TFIBLargeIntField * TableIDBASE_REM_SHARDWARE_ISP)
{
Object->TableIDBASE_REM_SHARDWARE_ISP=TableIDBASE_REM_SHARDWARE_ISP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprHardwareIspImpl::get_TableIDHW_REM_SHARDWARE_ISP(void)
{
return Object->TableIDHW_REM_SHARDWARE_ISP;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareIspImpl::set_TableIDHW_REM_SHARDWARE_ISP(TFIBLargeIntField * TableIDHW_REM_SHARDWARE_ISP)
{
Object->TableIDHW_REM_SHARDWARE_ISP=TableIDHW_REM_SHARDWARE_ISP;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMSprHardwareIspImpl::get_TablePOS_REM_SHARDWARE_ISP(void)
{
return Object->TablePOS_REM_SHARDWARE_ISP;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareIspImpl::set_TablePOS_REM_SHARDWARE_ISP(TFIBDateTimeField * TablePOS_REM_SHARDWARE_ISP)
{
Object->TablePOS_REM_SHARDWARE_ISP=TablePOS_REM_SHARDWARE_ISP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprHardwareIspImpl::get_TableIDUSER_REM_SHARDWARE_ISP(void)
{
return Object->TableIDUSER_REM_SHARDWARE_ISP;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareIspImpl::set_TableIDUSER_REM_SHARDWARE_ISP(TFIBLargeIntField * TableIDUSER_REM_SHARDWARE_ISP)
{
Object->TableIDUSER_REM_SHARDWARE_ISP=TableIDUSER_REM_SHARDWARE_ISP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprHardwareIspImpl::get_TableIDTYPEUSEL_REM_SHARDWARE_ISP(void)
{
return Object->TableIDTYPEUSEL_REM_SHARDWARE_ISP;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareIspImpl::set_TableIDTYPEUSEL_REM_SHARDWARE_ISP(TFIBLargeIntField * TableIDTYPEUSEL_REM_SHARDWARE_ISP)
{
Object->TableIDTYPEUSEL_REM_SHARDWARE_ISP=TableIDTYPEUSEL_REM_SHARDWARE_ISP;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMSprHardwareIspImpl::get_TableKOL_REM_SHARDWARE_ISP(void)
{
return Object->TableKOL_REM_SHARDWARE_ISP;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareIspImpl::set_TableKOL_REM_SHARDWARE_ISP(TFIBBCDField * TableKOL_REM_SHARDWARE_ISP)
{
Object->TableKOL_REM_SHARDWARE_ISP=TableKOL_REM_SHARDWARE_ISP;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprHardwareIspImpl::get_TableDESCR_REM_SHARDWARE_ISP(void)
{
return Object->TableDESCR_REM_SHARDWARE_ISP;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareIspImpl::set_TableDESCR_REM_SHARDWARE_ISP(TFIBWideStringField * TableDESCR_REM_SHARDWARE_ISP)
{
Object->TableDESCR_REM_SHARDWARE_ISP=TableDESCR_REM_SHARDWARE_ISP;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMSprHardwareIspImpl::get_TableFL_OTCH_PR_REM_SHARDWARE_ISP(void)
{
return Object->TableFL_OTCH_PR_REM_SHARDWARE_ISP;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareIspImpl::set_TableFL_OTCH_PR_REM_SHARDWARE_ISP(TFIBSmallIntField * TableFL_OTCH_PR_REM_SHARDWARE_ISP)
{
Object->TableFL_OTCH_PR_REM_SHARDWARE_ISP=TableFL_OTCH_PR_REM_SHARDWARE_ISP;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMSprHardwareIspImpl::get_TableFL_REAL_ISP_REM_SHARDWARE_ISP(void)
{
return Object->TableFL_REAL_ISP_REM_SHARDWARE_ISP;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareIspImpl::set_TableFL_REAL_ISP_REM_SHARDWARE_ISP(TFIBSmallIntField * TableFL_REAL_ISP_REM_SHARDWARE_ISP)
{
Object->TableFL_REAL_ISP_REM_SHARDWARE_ISP=TableFL_REAL_ISP_REM_SHARDWARE_ISP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprHardwareIspImpl::get_TableIDZ_REM_SHARDWARE_ISP(void)
{
return Object->TableIDZ_REM_SHARDWARE_ISP;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareIspImpl::set_TableIDZ_REM_SHARDWARE_ISP(TFIBLargeIntField * TableIDZ_REM_SHARDWARE_ISP)
{
Object->TableIDZ_REM_SHARDWARE_ISP=TableIDZ_REM_SHARDWARE_ISP;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprHardwareIspImpl::get_TableNAME_REM_STYPUSLOV(void)
{
return Object->TableNAME_REM_STYPUSLOV;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareIspImpl::set_TableNAME_REM_STYPUSLOV(TFIBWideStringField * TableNAME_REM_STYPUSLOV)
{
Object->TableNAME_REM_STYPUSLOV=TableNAME_REM_STYPUSLOV;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprHardwareIspImpl::get_TableNAME_USER(void)
{
return Object->TableNAME_USER;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareIspImpl::set_TableNAME_USER(TFIBWideStringField * TableNAME_USER)
{
Object->TableNAME_USER=TableNAME_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprHardwareIspImpl::get_TableNAME_REM_Z(void)
{
return Object->TableNAME_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareIspImpl::set_TableNAME_REM_Z(TFIBWideStringField * TableNAME_REM_Z)
{
Object->TableNAME_REM_Z=TableNAME_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprHardwareIspImpl::get_TablePREFIKS_NUM_REM_Z(void)
{
return Object->TablePREFIKS_NUM_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareIspImpl::set_TablePREFIKS_NUM_REM_Z(TFIBWideStringField * TablePREFIKS_NUM_REM_Z)
{
Object->TablePREFIKS_NUM_REM_Z=TablePREFIKS_NUM_REM_Z;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMSprHardwareIspImpl::get_TablePOS_REM_Z(void)
{
return Object->TablePOS_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareIspImpl::set_TablePOS_REM_Z(TFIBDateTimeField * TablePOS_REM_Z)
{
Object->TablePOS_REM_Z=TablePOS_REM_Z;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMSprHardwareIspImpl::get_TableNUM_REM_Z(void)
{
return Object->TableNUM_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareIspImpl::set_TableNUM_REM_Z(TFIBIntegerField * TableNUM_REM_Z)
{
Object->TableNUM_REM_Z=TableNUM_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprHardwareIspImpl::get_TableMODEL_REM_Z(void)
{
return Object->TableMODEL_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareIspImpl::set_TableMODEL_REM_Z(TFIBWideStringField * TableMODEL_REM_Z)
{
Object->TableMODEL_REM_Z=TableMODEL_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprHardwareIspImpl::get_TableSERNUM_REM_Z(void)
{
return Object->TableSERNUM_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareIspImpl::set_TableSERNUM_REM_Z(TFIBWideStringField * TableSERNUM_REM_Z)
{
Object->TableSERNUM_REM_Z=TableSERNUM_REM_Z;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprHardwareIspImpl::get_ElementID_REM_SHARDWARE_ISP(void)
{
return Object->ElementID_REM_SHARDWARE_ISP;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareIspImpl::set_ElementID_REM_SHARDWARE_ISP(TFIBLargeIntField * ElementID_REM_SHARDWARE_ISP)
{
Object->ElementID_REM_SHARDWARE_ISP=ElementID_REM_SHARDWARE_ISP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprHardwareIspImpl::get_ElementIDBASE_REM_SHARDWARE_ISP(void)
{
return Object->ElementIDBASE_REM_SHARDWARE_ISP;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareIspImpl::set_ElementIDBASE_REM_SHARDWARE_ISP(TFIBLargeIntField * ElementIDBASE_REM_SHARDWARE_ISP)
{
Object->ElementIDBASE_REM_SHARDWARE_ISP=ElementIDBASE_REM_SHARDWARE_ISP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprHardwareIspImpl::get_ElementIDHW_REM_SHARDWARE_ISP(void)
{
return Object->ElementIDHW_REM_SHARDWARE_ISP;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareIspImpl::set_ElementIDHW_REM_SHARDWARE_ISP(TFIBLargeIntField * ElementIDHW_REM_SHARDWARE_ISP)
{
Object->ElementIDHW_REM_SHARDWARE_ISP=ElementIDHW_REM_SHARDWARE_ISP;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMSprHardwareIspImpl::get_ElementPOS_REM_SHARDWARE_ISP(void)
{
return Object->ElementPOS_REM_SHARDWARE_ISP;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareIspImpl::set_ElementPOS_REM_SHARDWARE_ISP(TFIBDateTimeField * ElementPOS_REM_SHARDWARE_ISP)
{
Object->ElementPOS_REM_SHARDWARE_ISP=ElementPOS_REM_SHARDWARE_ISP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprHardwareIspImpl::get_ElementIDUSER_REM_SHARDWARE_ISP(void)
{
return Object->ElementIDUSER_REM_SHARDWARE_ISP;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareIspImpl::set_ElementIDUSER_REM_SHARDWARE_ISP(TFIBLargeIntField * ElementIDUSER_REM_SHARDWARE_ISP)
{
Object->ElementIDUSER_REM_SHARDWARE_ISP=ElementIDUSER_REM_SHARDWARE_ISP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprHardwareIspImpl::get_ElementIDTYPEUSEL_REM_SHARDWARE_ISP(void)
{
return Object->ElementIDTYPEUSEL_REM_SHARDWARE_ISP;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareIspImpl::set_ElementIDTYPEUSEL_REM_SHARDWARE_ISP(TFIBLargeIntField * ElementIDTYPEUSEL_REM_SHARDWARE_ISP)
{
Object->ElementIDTYPEUSEL_REM_SHARDWARE_ISP=ElementIDTYPEUSEL_REM_SHARDWARE_ISP;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMSprHardwareIspImpl::get_ElementKOL_REM_SHARDWARE_ISP(void)
{
return Object->ElementKOL_REM_SHARDWARE_ISP;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareIspImpl::set_ElementKOL_REM_SHARDWARE_ISP(TFIBBCDField * ElementKOL_REM_SHARDWARE_ISP)
{
Object->ElementKOL_REM_SHARDWARE_ISP=ElementKOL_REM_SHARDWARE_ISP;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprHardwareIspImpl::get_ElementDESCR_REM_SHARDWARE_ISP(void)
{
return Object->ElementDESCR_REM_SHARDWARE_ISP;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareIspImpl::set_ElementDESCR_REM_SHARDWARE_ISP(TFIBWideStringField * ElementDESCR_REM_SHARDWARE_ISP)
{
Object->ElementDESCR_REM_SHARDWARE_ISP=ElementDESCR_REM_SHARDWARE_ISP;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMSprHardwareIspImpl::get_ElementFL_OTCH_PR_REM_SHARDWARE_ISP(void)
{
return Object->ElementFL_OTCH_PR_REM_SHARDWARE_ISP;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareIspImpl::set_ElementFL_OTCH_PR_REM_SHARDWARE_ISP(TFIBSmallIntField * ElementFL_OTCH_PR_REM_SHARDWARE_ISP)
{
Object->ElementFL_OTCH_PR_REM_SHARDWARE_ISP=ElementFL_OTCH_PR_REM_SHARDWARE_ISP;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMSprHardwareIspImpl::get_ElementFL_REAL_ISP_REM_SHARDWARE_ISP(void)
{
return Object->ElementFL_REAL_ISP_REM_SHARDWARE_ISP;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareIspImpl::set_ElementFL_REAL_ISP_REM_SHARDWARE_ISP(TFIBSmallIntField * ElementFL_REAL_ISP_REM_SHARDWARE_ISP)
{
Object->ElementFL_REAL_ISP_REM_SHARDWARE_ISP=ElementFL_REAL_ISP_REM_SHARDWARE_ISP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprHardwareIspImpl::get_ElementIDZ_REM_SHARDWARE_ISP(void)
{
return Object->ElementIDZ_REM_SHARDWARE_ISP;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareIspImpl::set_ElementIDZ_REM_SHARDWARE_ISP(TFIBLargeIntField * ElementIDZ_REM_SHARDWARE_ISP)
{
Object->ElementIDZ_REM_SHARDWARE_ISP=ElementIDZ_REM_SHARDWARE_ISP;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprHardwareIspImpl::get_ElementNAME_REM_STYPUSLOV(void)
{
return Object->ElementNAME_REM_STYPUSLOV;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareIspImpl::set_ElementNAME_REM_STYPUSLOV(TFIBWideStringField * ElementNAME_REM_STYPUSLOV)
{
Object->ElementNAME_REM_STYPUSLOV=ElementNAME_REM_STYPUSLOV;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprHardwareIspImpl::get_ElementNAME_USER(void)
{
return Object->ElementNAME_USER;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareIspImpl::set_ElementNAME_USER(TFIBWideStringField * ElementNAME_USER)
{
Object->ElementNAME_USER=ElementNAME_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprHardwareIspImpl::get_ElementNAME_REM_Z(void)
{
return Object->ElementNAME_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareIspImpl::set_ElementNAME_REM_Z(TFIBWideStringField * ElementNAME_REM_Z)
{
Object->ElementNAME_REM_Z=ElementNAME_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprHardwareIspImpl::get_ElementPREFIKS_NUM_REM_Z(void)
{
return Object->ElementPREFIKS_NUM_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareIspImpl::set_ElementPREFIKS_NUM_REM_Z(TFIBWideStringField * ElementPREFIKS_NUM_REM_Z)
{
Object->ElementPREFIKS_NUM_REM_Z=ElementPREFIKS_NUM_REM_Z;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMSprHardwareIspImpl::get_ElementPOS_REM_Z(void)
{
return Object->ElementPOS_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareIspImpl::set_ElementPOS_REM_Z(TFIBDateTimeField * ElementPOS_REM_Z)
{
Object->ElementPOS_REM_Z=ElementPOS_REM_Z;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMSprHardwareIspImpl::get_ElementNUM_REM_Z(void)
{
return Object->ElementNUM_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareIspImpl::set_ElementNUM_REM_Z(TFIBIntegerField * ElementNUM_REM_Z)
{
Object->ElementNUM_REM_Z=ElementNUM_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprHardwareIspImpl::get_ElementMODEL_REM_Z(void)
{
return Object->ElementMODEL_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareIspImpl::set_ElementMODEL_REM_Z(TFIBWideStringField * ElementMODEL_REM_Z)
{
Object->ElementMODEL_REM_Z=ElementMODEL_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprHardwareIspImpl::get_ElementSERNUM_REM_Z(void)
{
return Object->ElementSERNUM_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareIspImpl::set_ElementSERNUM_REM_Z(TFIBWideStringField * ElementSERNUM_REM_Z)
{
Object->ElementSERNUM_REM_Z=ElementSERNUM_REM_Z;
}
//---------------------------------------------------------------
__int64 TREM_DMSprHardwareIspImpl::get_IdOwner(void)
{
return Object->IdOwner;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareIspImpl::set_IdOwner(__int64 IdOwner)
{
Object->IdOwner=IdOwner;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareIspImpl::OpenTable(__int64 id_owner)
{
return Object->OpenTable(id_owner);
}
//---------------------------------------------------------------
int TREM_DMSprHardwareIspImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
bool TREM_DMSprHardwareIspImpl::NewElement(__int64 id_owner)
{
return Object->NewElement(id_owner);
}
//---------------------------------------------------------------
bool TREM_DMSprHardwareIspImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TREM_DMSprHardwareIspImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
