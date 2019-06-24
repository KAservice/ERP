#include "vcl.h"
#pragma hdrstop


#include "UREM_DMSprProducerConditionGrpImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_DMSprProducerConditionGrpImpl::TREM_DMSprProducerConditionGrpImpl()           
{                                            
Object=new TREM_DMSprProducerConditionGrp(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_DMSprProducerConditionGrpImpl::~TREM_DMSprProducerConditionGrpImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_DMSprProducerConditionGrpImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_DMSprProducerConditionGrpImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_DMSprProducerConditionGrp)                        
   {                                                                     
   *ppv=static_cast<IREM_DMSprProducerConditionGrp*> (this);                                
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
int TREM_DMSprProducerConditionGrpImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_DMSprProducerConditionGrpImpl::kanRelease(void)                                  
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
int  TREM_DMSprProducerConditionGrpImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMSprProducerConditionGrpImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_DMSprProducerConditionGrpImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMSprProducerConditionGrpImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_DMSprProducerConditionGrpImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_DMSprProducerConditionGrpImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_DMSprProducerConditionGrpImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IREM_DMSprProducerConditionGrp
TDataSource * TREM_DMSprProducerConditionGrpImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TREM_DMSprProducerConditionGrpImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TREM_DMSprProducerConditionGrpImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TREM_DMSprProducerConditionGrpImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMSprProducerConditionGrpImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TREM_DMSprProducerConditionGrpImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMSprProducerConditionGrpImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TREM_DMSprProducerConditionGrpImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMSprProducerConditionGrpImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TREM_DMSprProducerConditionGrpImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMSprProducerConditionGrpImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TREM_DMSprProducerConditionGrpImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TIntegerField * TREM_DMSprProducerConditionGrpImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TREM_DMSprProducerConditionGrpImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerConditionGrpImpl::get_TableID_REM_SPRCOND_GRP(void)
{
return Object->TableID_REM_SPRCOND_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprProducerConditionGrpImpl::set_TableID_REM_SPRCOND_GRP(TFIBLargeIntField * TableID_REM_SPRCOND_GRP)
{
Object->TableID_REM_SPRCOND_GRP=TableID_REM_SPRCOND_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerConditionGrpImpl::get_TableIDBASE_REM_SPRCOND_GRP(void)
{
return Object->TableIDBASE_REM_SPRCOND_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprProducerConditionGrpImpl::set_TableIDBASE_REM_SPRCOND_GRP(TFIBLargeIntField * TableIDBASE_REM_SPRCOND_GRP)
{
Object->TableIDBASE_REM_SPRCOND_GRP=TableIDBASE_REM_SPRCOND_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerConditionGrpImpl::get_TableGID_REM_SPRCOND_GRP(void)
{
return Object->TableGID_REM_SPRCOND_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprProducerConditionGrpImpl::set_TableGID_REM_SPRCOND_GRP(TFIBWideStringField * TableGID_REM_SPRCOND_GRP)
{
Object->TableGID_REM_SPRCOND_GRP=TableGID_REM_SPRCOND_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerConditionGrpImpl::get_TableIDPR_REM_SPRCOND_GRP(void)
{
return Object->TableIDPR_REM_SPRCOND_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprProducerConditionGrpImpl::set_TableIDPR_REM_SPRCOND_GRP(TFIBLargeIntField * TableIDPR_REM_SPRCOND_GRP)
{
Object->TableIDPR_REM_SPRCOND_GRP=TableIDPR_REM_SPRCOND_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerConditionGrpImpl::get_TableIDGRP_REM_SPRCOND_GRP(void)
{
return Object->TableIDGRP_REM_SPRCOND_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprProducerConditionGrpImpl::set_TableIDGRP_REM_SPRCOND_GRP(TFIBLargeIntField * TableIDGRP_REM_SPRCOND_GRP)
{
Object->TableIDGRP_REM_SPRCOND_GRP=TableIDGRP_REM_SPRCOND_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerConditionGrpImpl::get_TableCODE_REM_SPRCOND_GRP(void)
{
return Object->TableCODE_REM_SPRCOND_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprProducerConditionGrpImpl::set_TableCODE_REM_SPRCOND_GRP(TFIBWideStringField * TableCODE_REM_SPRCOND_GRP)
{
Object->TableCODE_REM_SPRCOND_GRP=TableCODE_REM_SPRCOND_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerConditionGrpImpl::get_TableNAME_REM_SPRCOND_GRP(void)
{
return Object->TableNAME_REM_SPRCOND_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprProducerConditionGrpImpl::set_TableNAME_REM_SPRCOND_GRP(TFIBWideStringField * TableNAME_REM_SPRCOND_GRP)
{
Object->TableNAME_REM_SPRCOND_GRP=TableNAME_REM_SPRCOND_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerConditionGrpImpl::get_TableNAME_ENG_REM_SPRCOND_GRP(void)
{
return Object->TableNAME_ENG_REM_SPRCOND_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprProducerConditionGrpImpl::set_TableNAME_ENG_REM_SPRCOND_GRP(TFIBWideStringField * TableNAME_ENG_REM_SPRCOND_GRP)
{
Object->TableNAME_ENG_REM_SPRCOND_GRP=TableNAME_ENG_REM_SPRCOND_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerConditionGrpImpl::get_ElementID_REM_SPRCOND_GRP(void)
{
return Object->ElementID_REM_SPRCOND_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprProducerConditionGrpImpl::set_ElementID_REM_SPRCOND_GRP(TFIBLargeIntField * ElementID_REM_SPRCOND_GRP)
{
Object->ElementID_REM_SPRCOND_GRP=ElementID_REM_SPRCOND_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerConditionGrpImpl::get_ElementIDBASE_REM_SPRCOND_GRP(void)
{
return Object->ElementIDBASE_REM_SPRCOND_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprProducerConditionGrpImpl::set_ElementIDBASE_REM_SPRCOND_GRP(TFIBLargeIntField * ElementIDBASE_REM_SPRCOND_GRP)
{
Object->ElementIDBASE_REM_SPRCOND_GRP=ElementIDBASE_REM_SPRCOND_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerConditionGrpImpl::get_ElementGID_REM_SPRCOND_GRP(void)
{
return Object->ElementGID_REM_SPRCOND_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprProducerConditionGrpImpl::set_ElementGID_REM_SPRCOND_GRP(TFIBWideStringField * ElementGID_REM_SPRCOND_GRP)
{
Object->ElementGID_REM_SPRCOND_GRP=ElementGID_REM_SPRCOND_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerConditionGrpImpl::get_ElementIDPR_REM_SPRCOND_GRP(void)
{
return Object->ElementIDPR_REM_SPRCOND_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprProducerConditionGrpImpl::set_ElementIDPR_REM_SPRCOND_GRP(TFIBLargeIntField * ElementIDPR_REM_SPRCOND_GRP)
{
Object->ElementIDPR_REM_SPRCOND_GRP=ElementIDPR_REM_SPRCOND_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerConditionGrpImpl::get_ElementIDGRP_REM_SPRCOND_GRP(void)
{
return Object->ElementIDGRP_REM_SPRCOND_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprProducerConditionGrpImpl::set_ElementIDGRP_REM_SPRCOND_GRP(TFIBLargeIntField * ElementIDGRP_REM_SPRCOND_GRP)
{
Object->ElementIDGRP_REM_SPRCOND_GRP=ElementIDGRP_REM_SPRCOND_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerConditionGrpImpl::get_ElementCODE_REM_SPRCOND_GRP(void)
{
return Object->ElementCODE_REM_SPRCOND_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprProducerConditionGrpImpl::set_ElementCODE_REM_SPRCOND_GRP(TFIBWideStringField * ElementCODE_REM_SPRCOND_GRP)
{
Object->ElementCODE_REM_SPRCOND_GRP=ElementCODE_REM_SPRCOND_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerConditionGrpImpl::get_ElementNAME_REM_SPRCOND_GRP(void)
{
return Object->ElementNAME_REM_SPRCOND_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprProducerConditionGrpImpl::set_ElementNAME_REM_SPRCOND_GRP(TFIBWideStringField * ElementNAME_REM_SPRCOND_GRP)
{
Object->ElementNAME_REM_SPRCOND_GRP=ElementNAME_REM_SPRCOND_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerConditionGrpImpl::get_ElementNAME_ENG_REM_SPRCOND_GRP(void)
{
return Object->ElementNAME_ENG_REM_SPRCOND_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprProducerConditionGrpImpl::set_ElementNAME_ENG_REM_SPRCOND_GRP(TFIBWideStringField * ElementNAME_ENG_REM_SPRCOND_GRP)
{
Object->ElementNAME_ENG_REM_SPRCOND_GRP=ElementNAME_ENG_REM_SPRCOND_GRP;
}
//---------------------------------------------------------------
__int64 TREM_DMSprProducerConditionGrpImpl::get_IdGroupElement(void)
{
return Object->IdGroupElement;
}
//---------------------------------------------------------------
void TREM_DMSprProducerConditionGrpImpl::set_IdGroupElement(__int64 IdGroupElement)
{
Object->IdGroupElement=IdGroupElement;
}
//---------------------------------------------------------------
void TREM_DMSprProducerConditionGrpImpl::OpenTable(__int64 id_group_element)
{
return Object->OpenTable(id_group_element);
}
//---------------------------------------------------------------
int TREM_DMSprProducerConditionGrpImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
bool TREM_DMSprProducerConditionGrpImpl::NewElement(__int64 id_group_element, __int64 id_grp)
{
return Object->NewElement(id_group_element,id_grp);
}
//---------------------------------------------------------------
bool TREM_DMSprProducerConditionGrpImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TREM_DMSprProducerConditionGrpImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
