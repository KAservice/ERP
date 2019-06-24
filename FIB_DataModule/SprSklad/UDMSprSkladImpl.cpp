#include "vcl.h"
#pragma hdrstop


#include "UDMSprSkladImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprSkladImpl::TDMSprSkladImpl()           
{                                            
Object=new TDMSprSklad(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprSkladImpl::~TDMSprSkladImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprSkladImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprSkladImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprSklad)                        
   {                                                                     
   *ppv=static_cast<IDMSprSklad*> (this);                                
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
int TDMSprSkladImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprSkladImpl::kanRelease(void)                                  
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
int  TDMSprSkladImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprSkladImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprSkladImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprSkladImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprSkladImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMSprSkladImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMSprSkladImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMSprSklad
TDataSource * TDMSprSkladImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprSkladImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TDMSprSkladImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TDMSprSkladImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprSkladImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprSkladImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprSkladImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprSkladImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprSkladImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprSkladImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprSkladImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprSkladImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprSkladImpl::get_TableTSKLAD(void)
{
return Object->TableTSKLAD;
}
//---------------------------------------------------------------
void TDMSprSkladImpl::set_TableTSKLAD(TFIBIntegerField * TableTSKLAD)
{
Object->TableTSKLAD=TableTSKLAD;
}
//---------------------------------------------------------------
TIntegerField * TDMSprSkladImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TDMSprSkladImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprSkladImpl::get_ElementTSKLAD(void)
{
return Object->ElementTSKLAD;
}
//---------------------------------------------------------------
void TDMSprSkladImpl::set_ElementTSKLAD(TFIBIntegerField * ElementTSKLAD)
{
Object->ElementTSKLAD=ElementTSKLAD;
}
//---------------------------------------------------------------
TpFIBQuery * TDMSprSkladImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TDMSprSkladImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprSkladImpl::get_TableNAMESKLAD(void)
{
return Object->TableNAMESKLAD;
}
//---------------------------------------------------------------
void TDMSprSkladImpl::set_TableNAMESKLAD(TFIBWideStringField * TableNAMESKLAD)
{
Object->TableNAMESKLAD=TableNAMESKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprSkladImpl::get_TableMOLSKLAD(void)
{
return Object->TableMOLSKLAD;
}
//---------------------------------------------------------------
void TDMSprSkladImpl::set_TableMOLSKLAD(TFIBWideStringField * TableMOLSKLAD)
{
Object->TableMOLSKLAD=TableMOLSKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprSkladImpl::get_TableADRSKLAD(void)
{
return Object->TableADRSKLAD;
}
//---------------------------------------------------------------
void TDMSprSkladImpl::set_TableADRSKLAD(TFIBWideStringField * TableADRSKLAD)
{
Object->TableADRSKLAD=TableADRSKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprSkladImpl::get_TableGID_SSKLAD(void)
{
return Object->TableGID_SSKLAD;
}
//---------------------------------------------------------------
void TDMSprSkladImpl::set_TableGID_SSKLAD(TFIBWideStringField * TableGID_SSKLAD)
{
Object->TableGID_SSKLAD=TableGID_SSKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprSkladImpl::get_ElementNAMESKLAD(void)
{
return Object->ElementNAMESKLAD;
}
//---------------------------------------------------------------
void TDMSprSkladImpl::set_ElementNAMESKLAD(TFIBWideStringField * ElementNAMESKLAD)
{
Object->ElementNAMESKLAD=ElementNAMESKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprSkladImpl::get_ElementMOLSKLAD(void)
{
return Object->ElementMOLSKLAD;
}
//---------------------------------------------------------------
void TDMSprSkladImpl::set_ElementMOLSKLAD(TFIBWideStringField * ElementMOLSKLAD)
{
Object->ElementMOLSKLAD=ElementMOLSKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprSkladImpl::get_ElementADRSKLAD(void)
{
return Object->ElementADRSKLAD;
}
//---------------------------------------------------------------
void TDMSprSkladImpl::set_ElementADRSKLAD(TFIBWideStringField * ElementADRSKLAD)
{
Object->ElementADRSKLAD=ElementADRSKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprSkladImpl::get_ElementGID_SSKLAD(void)
{
return Object->ElementGID_SSKLAD;
}
//---------------------------------------------------------------
void TDMSprSkladImpl::set_ElementGID_SSKLAD(TFIBWideStringField * ElementGID_SSKLAD)
{
Object->ElementGID_SSKLAD=ElementGID_SSKLAD;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprSkladImpl::get_ElementDBLUCHETALLNOM_SSKLAD(void)
{
return Object->ElementDBLUCHETALLNOM_SSKLAD;
}
//---------------------------------------------------------------
void TDMSprSkladImpl::set_ElementDBLUCHETALLNOM_SSKLAD(TFIBSmallIntField * ElementDBLUCHETALLNOM_SSKLAD)
{
Object->ElementDBLUCHETALLNOM_SSKLAD=ElementDBLUCHETALLNOM_SSKLAD;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprSkladImpl::get_ElementDBLUCHET_SSKLAD(void)
{
return Object->ElementDBLUCHET_SSKLAD;
}
//---------------------------------------------------------------
void TDMSprSkladImpl::set_ElementDBLUCHET_SSKLAD(TFIBSmallIntField * ElementDBLUCHET_SSKLAD)
{
Object->ElementDBLUCHET_SSKLAD=ElementDBLUCHET_SSKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprSkladImpl::get_ElementPREFIKS_NUM_SSKLAD(void)
{
return Object->ElementPREFIKS_NUM_SSKLAD;
}
//---------------------------------------------------------------
void TDMSprSkladImpl::set_ElementPREFIKS_NUM_SSKLAD(TFIBWideStringField * ElementPREFIKS_NUM_SSKLAD)
{
Object->ElementPREFIKS_NUM_SSKLAD=ElementPREFIKS_NUM_SSKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprSkladImpl::get_ElementPHONE_SSKLAD(void)
{
return Object->ElementPHONE_SSKLAD;
}
//---------------------------------------------------------------
void TDMSprSkladImpl::set_ElementPHONE_SSKLAD(TFIBWideStringField * ElementPHONE_SSKLAD)
{
Object->ElementPHONE_SSKLAD=ElementPHONE_SSKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprSkladImpl::get_ElementEMAIL_SSKLAD(void)
{
return Object->ElementEMAIL_SSKLAD;
}
//---------------------------------------------------------------
void TDMSprSkladImpl::set_ElementEMAIL_SSKLAD(TFIBWideStringField * ElementEMAIL_SSKLAD)
{
Object->ElementEMAIL_SSKLAD=ElementEMAIL_SSKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprSkladImpl::get_ElementVKONTAKTE_SSKLAD(void)
{
return Object->ElementVKONTAKTE_SSKLAD;
}
//---------------------------------------------------------------
void TDMSprSkladImpl::set_ElementVKONTAKTE_SSKLAD(TFIBWideStringField * ElementVKONTAKTE_SSKLAD)
{
Object->ElementVKONTAKTE_SSKLAD=ElementVKONTAKTE_SSKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprSkladImpl::get_ElementWEBSITE_SSKLAD(void)
{
return Object->ElementWEBSITE_SSKLAD;
}
//---------------------------------------------------------------
void TDMSprSkladImpl::set_ElementWEBSITE_SSKLAD(TFIBWideStringField * ElementWEBSITE_SSKLAD)
{
Object->ElementWEBSITE_SSKLAD=ElementWEBSITE_SSKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprSkladImpl::get_ElementDOPINFO_SSKLAD(void)
{
return Object->ElementDOPINFO_SSKLAD;
}
//---------------------------------------------------------------
void TDMSprSkladImpl::set_ElementDOPINFO_SSKLAD(TFIBWideStringField * ElementDOPINFO_SSKLAD)
{
Object->ElementDOPINFO_SSKLAD=ElementDOPINFO_SSKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprSkladImpl::get_ElementREGIM_RABOTI_SSKLAD(void)
{
return Object->ElementREGIM_RABOTI_SSKLAD;
}
//---------------------------------------------------------------
void TDMSprSkladImpl::set_ElementREGIM_RABOTI_SSKLAD(TFIBWideStringField * ElementREGIM_RABOTI_SSKLAD)
{
Object->ElementREGIM_RABOTI_SSKLAD=ElementREGIM_RABOTI_SSKLAD;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprSkladImpl::get_TableIDSKLAD(void)
{
return Object->TableIDSKLAD;
}
//---------------------------------------------------------------
void TDMSprSkladImpl::set_TableIDSKLAD(TFIBLargeIntField * TableIDSKLAD)
{
Object->TableIDSKLAD=TableIDSKLAD;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprSkladImpl::get_TableIDBASE_SSKLAD(void)
{
return Object->TableIDBASE_SSKLAD;
}
//---------------------------------------------------------------
void TDMSprSkladImpl::set_TableIDBASE_SSKLAD(TFIBLargeIntField * TableIDBASE_SSKLAD)
{
Object->TableIDBASE_SSKLAD=TableIDBASE_SSKLAD;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprSkladImpl::get_TableDBLUCHETALLNOM_SSKLAD(void)
{
return Object->TableDBLUCHETALLNOM_SSKLAD;
}
//---------------------------------------------------------------
void TDMSprSkladImpl::set_TableDBLUCHETALLNOM_SSKLAD(TFIBSmallIntField * TableDBLUCHETALLNOM_SSKLAD)
{
Object->TableDBLUCHETALLNOM_SSKLAD=TableDBLUCHETALLNOM_SSKLAD;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprSkladImpl::get_TableDBLUCHET_SSKLAD(void)
{
return Object->TableDBLUCHET_SSKLAD;
}
//---------------------------------------------------------------
void TDMSprSkladImpl::set_TableDBLUCHET_SSKLAD(TFIBSmallIntField * TableDBLUCHET_SSKLAD)
{
Object->TableDBLUCHET_SSKLAD=TableDBLUCHET_SSKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprSkladImpl::get_TablePREFIKS_NUM_SSKLAD(void)
{
return Object->TablePREFIKS_NUM_SSKLAD;
}
//---------------------------------------------------------------
void TDMSprSkladImpl::set_TablePREFIKS_NUM_SSKLAD(TFIBWideStringField * TablePREFIKS_NUM_SSKLAD)
{
Object->TablePREFIKS_NUM_SSKLAD=TablePREFIKS_NUM_SSKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprSkladImpl::get_TablePHONE_SSKLAD(void)
{
return Object->TablePHONE_SSKLAD;
}
//---------------------------------------------------------------
void TDMSprSkladImpl::set_TablePHONE_SSKLAD(TFIBWideStringField * TablePHONE_SSKLAD)
{
Object->TablePHONE_SSKLAD=TablePHONE_SSKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprSkladImpl::get_TableEMAIL_SSKLAD(void)
{
return Object->TableEMAIL_SSKLAD;
}
//---------------------------------------------------------------
void TDMSprSkladImpl::set_TableEMAIL_SSKLAD(TFIBWideStringField * TableEMAIL_SSKLAD)
{
Object->TableEMAIL_SSKLAD=TableEMAIL_SSKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprSkladImpl::get_TableVKONTAKTE_SSKLAD(void)
{
return Object->TableVKONTAKTE_SSKLAD;
}
//---------------------------------------------------------------
void TDMSprSkladImpl::set_TableVKONTAKTE_SSKLAD(TFIBWideStringField * TableVKONTAKTE_SSKLAD)
{
Object->TableVKONTAKTE_SSKLAD=TableVKONTAKTE_SSKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprSkladImpl::get_TableWEBSITE_SSKLAD(void)
{
return Object->TableWEBSITE_SSKLAD;
}
//---------------------------------------------------------------
void TDMSprSkladImpl::set_TableWEBSITE_SSKLAD(TFIBWideStringField * TableWEBSITE_SSKLAD)
{
Object->TableWEBSITE_SSKLAD=TableWEBSITE_SSKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprSkladImpl::get_TableDOPINFO_SSKLAD(void)
{
return Object->TableDOPINFO_SSKLAD;
}
//---------------------------------------------------------------
void TDMSprSkladImpl::set_TableDOPINFO_SSKLAD(TFIBWideStringField * TableDOPINFO_SSKLAD)
{
Object->TableDOPINFO_SSKLAD=TableDOPINFO_SSKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprSkladImpl::get_TableREGIM_RABOTI_SSKLAD(void)
{
return Object->TableREGIM_RABOTI_SSKLAD;
}
//---------------------------------------------------------------
void TDMSprSkladImpl::set_TableREGIM_RABOTI_SSKLAD(TFIBWideStringField * TableREGIM_RABOTI_SSKLAD)
{
Object->TableREGIM_RABOTI_SSKLAD=TableREGIM_RABOTI_SSKLAD;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprSkladImpl::get_ElementIDSKLAD(void)
{
return Object->ElementIDSKLAD;
}
//---------------------------------------------------------------
void TDMSprSkladImpl::set_ElementIDSKLAD(TFIBLargeIntField * ElementIDSKLAD)
{
Object->ElementIDSKLAD=ElementIDSKLAD;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprSkladImpl::get_ElementIDBASE_SSKLAD(void)
{
return Object->ElementIDBASE_SSKLAD;
}
//---------------------------------------------------------------
void TDMSprSkladImpl::set_ElementIDBASE_SSKLAD(TFIBLargeIntField * ElementIDBASE_SSKLAD)
{
Object->ElementIDBASE_SSKLAD=ElementIDBASE_SSKLAD;
}
//---------------------------------------------------------------
void TDMSprSkladImpl::OpenTable(void)
{
return Object->OpenTable();
}
//---------------------------------------------------------------
int TDMSprSkladImpl::OpenElement(__int64 Id)
{
return Object->OpenElement(Id);
}
//---------------------------------------------------------------
void TDMSprSkladImpl::NewElement(void)
{
return Object->NewElement();
}
//---------------------------------------------------------------
bool TDMSprSkladImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
void TDMSprSkladImpl::CloseElement(void)
{
return Object->CloseElement();
}
//---------------------------------------------------------------
void TDMSprSkladImpl::DeleteElement(__int64 Id)
{
return Object->DeleteElement(Id);
}
//---------------------------------------------------------------
__int64 TDMSprSkladImpl::GetIDElement(String gid)
{
return Object->GetIDElement(gid);
}
//---------------------------------------------------------------
AnsiString TDMSprSkladImpl::GetGIDElement(__int64 id)
{
return Object->GetGIDElement(id);
}
//---------------------------------------------------------------
int TDMSprSkladImpl::GetIndexElementaPoID(__int64 id)
{
return Object->GetIndexElementaPoID(id);
}
//---------------------------------------------------------------
