#include "vcl.h"
#pragma hdrstop


#include "UDMSprARMImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprARMImpl::TDMSprARMImpl()           
{                                            
Object=new TDMSprARM(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprARMImpl::~TDMSprARMImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprARMImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprARMImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprARM)                        
   {                                                                     
   *ppv=static_cast<IDMSprARM*> (this);                                
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
int TDMSprARMImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprARMImpl::kanRelease(void)                                  
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
int  TDMSprARMImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprARMImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprARMImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprARMImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprARMImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMSprARMImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMSprARMImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMSprARM
TDataSource * TDMSprARMImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprARMImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TDMSprARMImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TDMSprARMImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprARMImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprARMImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprARMImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprARMImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprARMImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprARMImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprARMImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprARMImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TIntegerField * TDMSprARMImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TDMSprARMImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TpFIBQuery * TDMSprARMImpl::get_Query(void)
{
return Object->Query;
}
//---------------------------------------------------------------
void TDMSprARMImpl::set_Query(TpFIBQuery * Query)
{
Object->Query=Query;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprARMImpl::get_TableID_SARM(void)
{
return Object->TableID_SARM;
}
//---------------------------------------------------------------
void TDMSprARMImpl::set_TableID_SARM(TFIBLargeIntField * TableID_SARM)
{
Object->TableID_SARM=TableID_SARM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprARMImpl::get_TableGID_SARM(void)
{
return Object->TableGID_SARM;
}
//---------------------------------------------------------------
void TDMSprARMImpl::set_TableGID_SARM(TFIBWideStringField * TableGID_SARM)
{
Object->TableGID_SARM=TableGID_SARM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprARMImpl::get_TableNAME_SARM(void)
{
return Object->TableNAME_SARM;
}
//---------------------------------------------------------------
void TDMSprARMImpl::set_TableNAME_SARM(TFIBWideStringField * TableNAME_SARM)
{
Object->TableNAME_SARM=TableNAME_SARM;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprARMImpl::get_TableCODE_SARM(void)
{
return Object->TableCODE_SARM;
}
//---------------------------------------------------------------
void TDMSprARMImpl::set_TableCODE_SARM(TFIBIntegerField * TableCODE_SARM)
{
Object->TableCODE_SARM=TableCODE_SARM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprARMImpl::get_TableIDFIRM_SARM(void)
{
return Object->TableIDFIRM_SARM;
}
//---------------------------------------------------------------
void TDMSprARMImpl::set_TableIDFIRM_SARM(TFIBLargeIntField * TableIDFIRM_SARM)
{
Object->TableIDFIRM_SARM=TableIDFIRM_SARM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprARMImpl::get_TableIDSKLAD_SARM(void)
{
return Object->TableIDSKLAD_SARM;
}
//---------------------------------------------------------------
void TDMSprARMImpl::set_TableIDSKLAD_SARM(TFIBLargeIntField * TableIDSKLAD_SARM)
{
Object->TableIDSKLAD_SARM=TableIDSKLAD_SARM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprARMImpl::get_TableIDPODR_SARM(void)
{
return Object->TableIDPODR_SARM;
}
//---------------------------------------------------------------
void TDMSprARMImpl::set_TableIDPODR_SARM(TFIBLargeIntField * TableIDPODR_SARM)
{
Object->TableIDPODR_SARM=TableIDPODR_SARM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprARMImpl::get_TableIDKKM_SARM(void)
{
return Object->TableIDKKM_SARM;
}
//---------------------------------------------------------------
void TDMSprARMImpl::set_TableIDKKM_SARM(TFIBLargeIntField * TableIDKKM_SARM)
{
Object->TableIDKKM_SARM=TableIDKKM_SARM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprARMImpl::get_TableSTRPAR_SARM(void)
{
return Object->TableSTRPAR_SARM;
}
//---------------------------------------------------------------
void TDMSprARMImpl::set_TableSTRPAR_SARM(TFIBWideStringField * TableSTRPAR_SARM)
{
Object->TableSTRPAR_SARM=TableSTRPAR_SARM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprARMImpl::get_TablePREFIKS_SARM(void)
{
return Object->TablePREFIKS_SARM;
}
//---------------------------------------------------------------
void TDMSprARMImpl::set_TablePREFIKS_SARM(TFIBWideStringField * TablePREFIKS_SARM)
{
Object->TablePREFIKS_SARM=TablePREFIKS_SARM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprARMImpl::get_TableIDBASE_SARM(void)
{
return Object->TableIDBASE_SARM;
}
//---------------------------------------------------------------
void TDMSprARMImpl::set_TableIDBASE_SARM(TFIBLargeIntField * TableIDBASE_SARM)
{
Object->TableIDBASE_SARM=TableIDBASE_SARM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprARMImpl::get_TableIDACTCATEGORY_SARM(void)
{
return Object->TableIDACTCATEGORY_SARM;
}
//---------------------------------------------------------------
void TDMSprARMImpl::set_TableIDACTCATEGORY_SARM(TFIBLargeIntField * TableIDACTCATEGORY_SARM)
{
Object->TableIDACTCATEGORY_SARM=TableIDACTCATEGORY_SARM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprARMImpl::get_ElementID_SARM(void)
{
return Object->ElementID_SARM;
}
//---------------------------------------------------------------
void TDMSprARMImpl::set_ElementID_SARM(TFIBLargeIntField * ElementID_SARM)
{
Object->ElementID_SARM=ElementID_SARM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprARMImpl::get_ElementGID_SARM(void)
{
return Object->ElementGID_SARM;
}
//---------------------------------------------------------------
void TDMSprARMImpl::set_ElementGID_SARM(TFIBWideStringField * ElementGID_SARM)
{
Object->ElementGID_SARM=ElementGID_SARM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprARMImpl::get_ElementNAME_SARM(void)
{
return Object->ElementNAME_SARM;
}
//---------------------------------------------------------------
void TDMSprARMImpl::set_ElementNAME_SARM(TFIBWideStringField * ElementNAME_SARM)
{
Object->ElementNAME_SARM=ElementNAME_SARM;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprARMImpl::get_ElementCODE_SARM(void)
{
return Object->ElementCODE_SARM;
}
//---------------------------------------------------------------
void TDMSprARMImpl::set_ElementCODE_SARM(TFIBIntegerField * ElementCODE_SARM)
{
Object->ElementCODE_SARM=ElementCODE_SARM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprARMImpl::get_ElementIDFIRM_SARM(void)
{
return Object->ElementIDFIRM_SARM;
}
//---------------------------------------------------------------
void TDMSprARMImpl::set_ElementIDFIRM_SARM(TFIBLargeIntField * ElementIDFIRM_SARM)
{
Object->ElementIDFIRM_SARM=ElementIDFIRM_SARM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprARMImpl::get_ElementIDSKLAD_SARM(void)
{
return Object->ElementIDSKLAD_SARM;
}
//---------------------------------------------------------------
void TDMSprARMImpl::set_ElementIDSKLAD_SARM(TFIBLargeIntField * ElementIDSKLAD_SARM)
{
Object->ElementIDSKLAD_SARM=ElementIDSKLAD_SARM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprARMImpl::get_ElementIDPODR_SARM(void)
{
return Object->ElementIDPODR_SARM;
}
//---------------------------------------------------------------
void TDMSprARMImpl::set_ElementIDPODR_SARM(TFIBLargeIntField * ElementIDPODR_SARM)
{
Object->ElementIDPODR_SARM=ElementIDPODR_SARM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprARMImpl::get_ElementIDKKM_SARM(void)
{
return Object->ElementIDKKM_SARM;
}
//---------------------------------------------------------------
void TDMSprARMImpl::set_ElementIDKKM_SARM(TFIBLargeIntField * ElementIDKKM_SARM)
{
Object->ElementIDKKM_SARM=ElementIDKKM_SARM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprARMImpl::get_ElementSTRPAR_SARM(void)
{
return Object->ElementSTRPAR_SARM;
}
//---------------------------------------------------------------
void TDMSprARMImpl::set_ElementSTRPAR_SARM(TFIBWideStringField * ElementSTRPAR_SARM)
{
Object->ElementSTRPAR_SARM=ElementSTRPAR_SARM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprARMImpl::get_ElementPREFIKS_SARM(void)
{
return Object->ElementPREFIKS_SARM;
}
//---------------------------------------------------------------
void TDMSprARMImpl::set_ElementPREFIKS_SARM(TFIBWideStringField * ElementPREFIKS_SARM)
{
Object->ElementPREFIKS_SARM=ElementPREFIKS_SARM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprARMImpl::get_ElementIDBASE_SARM(void)
{
return Object->ElementIDBASE_SARM;
}
//---------------------------------------------------------------
void TDMSprARMImpl::set_ElementIDBASE_SARM(TFIBLargeIntField * ElementIDBASE_SARM)
{
Object->ElementIDBASE_SARM=ElementIDBASE_SARM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprARMImpl::get_ElementIDACTCATEGORY_SARM(void)
{
return Object->ElementIDACTCATEGORY_SARM;
}
//---------------------------------------------------------------
void TDMSprARMImpl::set_ElementIDACTCATEGORY_SARM(TFIBLargeIntField * ElementIDACTCATEGORY_SARM)
{
Object->ElementIDACTCATEGORY_SARM=ElementIDACTCATEGORY_SARM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprARMImpl::get_ElementNAMEFIRM(void)
{
return Object->ElementNAMEFIRM;
}
//---------------------------------------------------------------
void TDMSprARMImpl::set_ElementNAMEFIRM(TFIBWideStringField * ElementNAMEFIRM)
{
Object->ElementNAMEFIRM=ElementNAMEFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprARMImpl::get_ElementNAMESKLAD(void)
{
return Object->ElementNAMESKLAD;
}
//---------------------------------------------------------------
void TDMSprARMImpl::set_ElementNAMESKLAD(TFIBWideStringField * ElementNAMESKLAD)
{
Object->ElementNAMESKLAD=ElementNAMESKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprARMImpl::get_ElementNAMEKKM(void)
{
return Object->ElementNAMEKKM;
}
//---------------------------------------------------------------
void TDMSprARMImpl::set_ElementNAMEKKM(TFIBWideStringField * ElementNAMEKKM)
{
Object->ElementNAMEKKM=ElementNAMEKKM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprARMImpl::get_ElementNAMEPOD(void)
{
return Object->ElementNAMEPOD;
}
//---------------------------------------------------------------
void TDMSprARMImpl::set_ElementNAMEPOD(TFIBWideStringField * ElementNAMEPOD)
{
Object->ElementNAMEPOD=ElementNAMEPOD;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprARMImpl::get_ElementIDTPRICEPOD(void)
{
return Object->ElementIDTPRICEPOD;
}
//---------------------------------------------------------------
void TDMSprARMImpl::set_ElementIDTPRICEPOD(TFIBLargeIntField * ElementIDTPRICEPOD)
{
Object->ElementIDTPRICEPOD=ElementIDTPRICEPOD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprARMImpl::get_ElementNAME_TPRICE(void)
{
return Object->ElementNAME_TPRICE;
}
//---------------------------------------------------------------
void TDMSprARMImpl::set_ElementNAME_TPRICE(TFIBWideStringField * ElementNAME_TPRICE)
{
Object->ElementNAME_TPRICE=ElementNAME_TPRICE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprARMImpl::get_ElementNAME_SINFBASE_OBMEN(void)
{
return Object->ElementNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void TDMSprARMImpl::set_ElementNAME_SINFBASE_OBMEN(TFIBWideStringField * ElementNAME_SINFBASE_OBMEN)
{
Object->ElementNAME_SINFBASE_OBMEN=ElementNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprARMImpl::get_ElementNAME_REM_SACTCATEGORY(void)
{
return Object->ElementNAME_REM_SACTCATEGORY;
}
//---------------------------------------------------------------
void TDMSprARMImpl::set_ElementNAME_REM_SACTCATEGORY(TFIBWideStringField * ElementNAME_REM_SACTCATEGORY)
{
Object->ElementNAME_REM_SACTCATEGORY=ElementNAME_REM_SACTCATEGORY;
}
//---------------------------------------------------------------
bool TDMSprARMImpl::get_flSaveElement(void)
{
return Object->flSaveElement;
}
//---------------------------------------------------------------
void TDMSprARMImpl::set_flSaveElement(bool flSaveElement)
{
Object->flSaveElement=flSaveElement;
}
//---------------------------------------------------------------
void TDMSprARMImpl::OpenTable(void)
{
return Object->OpenTable();
}
//---------------------------------------------------------------
int TDMSprARMImpl::OpenElement(__int64 Id)
{
return Object->OpenElement(Id);
}
//---------------------------------------------------------------
void TDMSprARMImpl::NewElement(void)
{
return Object->NewElement();
}
//---------------------------------------------------------------
bool TDMSprARMImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
void TDMSprARMImpl::DeleteElement(__int64 Id)
{
return Object->DeleteElement(Id);
}
//---------------------------------------------------------------
int TDMSprARMImpl::FindPoCodu(int code)
{
return Object->FindPoCodu(code);
}
//---------------------------------------------------------------
int TDMSprARMImpl::FindPoName(String name)
{
return Object->FindPoName(name);
}
//---------------------------------------------------------------
AnsiString TDMSprARMImpl::GetGIDElement(__int64 id)
{
return Object->GetGIDElement(id);
}
//---------------------------------------------------------------
AnsiString TDMSprARMImpl::GetParameter(AnsiString parameter)
{
return Object->GetParameter(parameter);
}
//---------------------------------------------------------------
int TDMSprARMImpl::GetMaxCode(void)
{
return Object->GetMaxCode();
}
//---------------------------------------------------------------
