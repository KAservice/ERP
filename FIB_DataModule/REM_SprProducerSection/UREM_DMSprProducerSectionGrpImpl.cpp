#include "vcl.h"
#pragma hdrstop


#include "UREM_DMSprProducerSectionGrpImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_DMSprProducerSectionGrpImpl::TREM_DMSprProducerSectionGrpImpl()           
{                                            
Object=new TREM_DMSprProducerSectionGrp(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_DMSprProducerSectionGrpImpl::~TREM_DMSprProducerSectionGrpImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_DMSprProducerSectionGrpImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_DMSprProducerSectionGrpImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_DMSprProducerSectionGrp)                        
   {                                                                     
   *ppv=static_cast<IREM_DMSprProducerSectionGrp*> (this);                                
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
int TREM_DMSprProducerSectionGrpImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_DMSprProducerSectionGrpImpl::kanRelease(void)                                  
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
int  TREM_DMSprProducerSectionGrpImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMSprProducerSectionGrpImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_DMSprProducerSectionGrpImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMSprProducerSectionGrpImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_DMSprProducerSectionGrpImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_DMSprProducerSectionGrpImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_DMSprProducerSectionGrpImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IREM_DMSprProducerSectionGrp
TDataSource * TREM_DMSprProducerSectionGrpImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TREM_DMSprProducerSectionGrpImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TREM_DMSprProducerSectionGrpImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TREM_DMSprProducerSectionGrpImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMSprProducerSectionGrpImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TREM_DMSprProducerSectionGrpImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMSprProducerSectionGrpImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TREM_DMSprProducerSectionGrpImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMSprProducerSectionGrpImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TREM_DMSprProducerSectionGrpImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMSprProducerSectionGrpImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TREM_DMSprProducerSectionGrpImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TIntegerField * TREM_DMSprProducerSectionGrpImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TREM_DMSprProducerSectionGrpImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerSectionGrpImpl::get_TableID_REM_SPRSECTION_GRP(void)
{
return Object->TableID_REM_SPRSECTION_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprProducerSectionGrpImpl::set_TableID_REM_SPRSECTION_GRP(TFIBLargeIntField * TableID_REM_SPRSECTION_GRP)
{
Object->TableID_REM_SPRSECTION_GRP=TableID_REM_SPRSECTION_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerSectionGrpImpl::get_TableIDBASE_REM_SPRSECTION_GRP(void)
{
return Object->TableIDBASE_REM_SPRSECTION_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprProducerSectionGrpImpl::set_TableIDBASE_REM_SPRSECTION_GRP(TFIBLargeIntField * TableIDBASE_REM_SPRSECTION_GRP)
{
Object->TableIDBASE_REM_SPRSECTION_GRP=TableIDBASE_REM_SPRSECTION_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerSectionGrpImpl::get_TableGID_REM_SPRSECTION_GRP(void)
{
return Object->TableGID_REM_SPRSECTION_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprProducerSectionGrpImpl::set_TableGID_REM_SPRSECTION_GRP(TFIBWideStringField * TableGID_REM_SPRSECTION_GRP)
{
Object->TableGID_REM_SPRSECTION_GRP=TableGID_REM_SPRSECTION_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerSectionGrpImpl::get_TableIDPR_REM_SPRSECTION_GRP(void)
{
return Object->TableIDPR_REM_SPRSECTION_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprProducerSectionGrpImpl::set_TableIDPR_REM_SPRSECTION_GRP(TFIBLargeIntField * TableIDPR_REM_SPRSECTION_GRP)
{
Object->TableIDPR_REM_SPRSECTION_GRP=TableIDPR_REM_SPRSECTION_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerSectionGrpImpl::get_TableIDGRP_REM_SPRSECTION_GRP(void)
{
return Object->TableIDGRP_REM_SPRSECTION_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprProducerSectionGrpImpl::set_TableIDGRP_REM_SPRSECTION_GRP(TFIBLargeIntField * TableIDGRP_REM_SPRSECTION_GRP)
{
Object->TableIDGRP_REM_SPRSECTION_GRP=TableIDGRP_REM_SPRSECTION_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerSectionGrpImpl::get_TableCODE_REM_SPRSECTION_GRP(void)
{
return Object->TableCODE_REM_SPRSECTION_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprProducerSectionGrpImpl::set_TableCODE_REM_SPRSECTION_GRP(TFIBWideStringField * TableCODE_REM_SPRSECTION_GRP)
{
Object->TableCODE_REM_SPRSECTION_GRP=TableCODE_REM_SPRSECTION_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerSectionGrpImpl::get_TableNAME_REM_SPRSECTION_GRP(void)
{
return Object->TableNAME_REM_SPRSECTION_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprProducerSectionGrpImpl::set_TableNAME_REM_SPRSECTION_GRP(TFIBWideStringField * TableNAME_REM_SPRSECTION_GRP)
{
Object->TableNAME_REM_SPRSECTION_GRP=TableNAME_REM_SPRSECTION_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerSectionGrpImpl::get_TableNAME_ENG_REM_SPRSECTION_GRP(void)
{
return Object->TableNAME_ENG_REM_SPRSECTION_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprProducerSectionGrpImpl::set_TableNAME_ENG_REM_SPRSECTION_GRP(TFIBWideStringField * TableNAME_ENG_REM_SPRSECTION_GRP)
{
Object->TableNAME_ENG_REM_SPRSECTION_GRP=TableNAME_ENG_REM_SPRSECTION_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerSectionGrpImpl::get_ElementID_REM_SPRSECTION_GRP(void)
{
return Object->ElementID_REM_SPRSECTION_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprProducerSectionGrpImpl::set_ElementID_REM_SPRSECTION_GRP(TFIBLargeIntField * ElementID_REM_SPRSECTION_GRP)
{
Object->ElementID_REM_SPRSECTION_GRP=ElementID_REM_SPRSECTION_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerSectionGrpImpl::get_ElementIDBASE_REM_SPRSECTION_GRP(void)
{
return Object->ElementIDBASE_REM_SPRSECTION_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprProducerSectionGrpImpl::set_ElementIDBASE_REM_SPRSECTION_GRP(TFIBLargeIntField * ElementIDBASE_REM_SPRSECTION_GRP)
{
Object->ElementIDBASE_REM_SPRSECTION_GRP=ElementIDBASE_REM_SPRSECTION_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerSectionGrpImpl::get_ElementGID_REM_SPRSECTION_GRP(void)
{
return Object->ElementGID_REM_SPRSECTION_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprProducerSectionGrpImpl::set_ElementGID_REM_SPRSECTION_GRP(TFIBWideStringField * ElementGID_REM_SPRSECTION_GRP)
{
Object->ElementGID_REM_SPRSECTION_GRP=ElementGID_REM_SPRSECTION_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerSectionGrpImpl::get_ElementIDPR_REM_SPRSECTION_GRP(void)
{
return Object->ElementIDPR_REM_SPRSECTION_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprProducerSectionGrpImpl::set_ElementIDPR_REM_SPRSECTION_GRP(TFIBLargeIntField * ElementIDPR_REM_SPRSECTION_GRP)
{
Object->ElementIDPR_REM_SPRSECTION_GRP=ElementIDPR_REM_SPRSECTION_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerSectionGrpImpl::get_ElementIDGRP_REM_SPRSECTION_GRP(void)
{
return Object->ElementIDGRP_REM_SPRSECTION_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprProducerSectionGrpImpl::set_ElementIDGRP_REM_SPRSECTION_GRP(TFIBLargeIntField * ElementIDGRP_REM_SPRSECTION_GRP)
{
Object->ElementIDGRP_REM_SPRSECTION_GRP=ElementIDGRP_REM_SPRSECTION_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerSectionGrpImpl::get_ElementCODE_REM_SPRSECTION_GRP(void)
{
return Object->ElementCODE_REM_SPRSECTION_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprProducerSectionGrpImpl::set_ElementCODE_REM_SPRSECTION_GRP(TFIBWideStringField * ElementCODE_REM_SPRSECTION_GRP)
{
Object->ElementCODE_REM_SPRSECTION_GRP=ElementCODE_REM_SPRSECTION_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerSectionGrpImpl::get_ElementNAME_REM_SPRSECTION_GRP(void)
{
return Object->ElementNAME_REM_SPRSECTION_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprProducerSectionGrpImpl::set_ElementNAME_REM_SPRSECTION_GRP(TFIBWideStringField * ElementNAME_REM_SPRSECTION_GRP)
{
Object->ElementNAME_REM_SPRSECTION_GRP=ElementNAME_REM_SPRSECTION_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerSectionGrpImpl::get_ElementNAME_ENG_REM_SPRSECTION_GRP(void)
{
return Object->ElementNAME_ENG_REM_SPRSECTION_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprProducerSectionGrpImpl::set_ElementNAME_ENG_REM_SPRSECTION_GRP(TFIBWideStringField * ElementNAME_ENG_REM_SPRSECTION_GRP)
{
Object->ElementNAME_ENG_REM_SPRSECTION_GRP=ElementNAME_ENG_REM_SPRSECTION_GRP;
}
//---------------------------------------------------------------
__int64 TREM_DMSprProducerSectionGrpImpl::get_IdGroupElement(void)
{
return Object->IdGroupElement;
}
//---------------------------------------------------------------
void TREM_DMSprProducerSectionGrpImpl::set_IdGroupElement(__int64 IdGroupElement)
{
Object->IdGroupElement=IdGroupElement;
}
//---------------------------------------------------------------
void TREM_DMSprProducerSectionGrpImpl::OpenTable(__int64 id_group_element)
{
return Object->OpenTable(id_group_element);
}
//---------------------------------------------------------------
int TREM_DMSprProducerSectionGrpImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
bool TREM_DMSprProducerSectionGrpImpl::NewElement(__int64 id_group_element, __int64 id_grp)
{
return Object->NewElement(id_group_element,id_grp);
}
//---------------------------------------------------------------
bool TREM_DMSprProducerSectionGrpImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TREM_DMSprProducerSectionGrpImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
