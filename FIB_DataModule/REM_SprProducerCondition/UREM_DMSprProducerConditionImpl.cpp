#include "vcl.h"
#pragma hdrstop


#include "UREM_DMSprProducerConditionImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_DMSprProducerConditionImpl::TREM_DMSprProducerConditionImpl()           
{                                            
Object=new TREM_DMSprProducerCondition(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_DMSprProducerConditionImpl::~TREM_DMSprProducerConditionImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_DMSprProducerConditionImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_DMSprProducerConditionImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_DMSprProducerCondition)                        
   {                                                                     
   *ppv=static_cast<IREM_DMSprProducerCondition*> (this);                                
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
int TREM_DMSprProducerConditionImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_DMSprProducerConditionImpl::kanRelease(void)                                  
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
int  TREM_DMSprProducerConditionImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMSprProducerConditionImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_DMSprProducerConditionImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMSprProducerConditionImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_DMSprProducerConditionImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_DMSprProducerConditionImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_DMSprProducerConditionImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IREM_DMSprProducerCondition
TDataSource * TREM_DMSprProducerConditionImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TREM_DMSprProducerConditionImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMSprProducerConditionImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TREM_DMSprProducerConditionImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMSprProducerConditionImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TREM_DMSprProducerConditionImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMSprProducerConditionImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TREM_DMSprProducerConditionImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMSprProducerConditionImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TREM_DMSprProducerConditionImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TIntegerField * TREM_DMSprProducerConditionImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TREM_DMSprProducerConditionImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TDataSource * TREM_DMSprProducerConditionImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TREM_DMSprProducerConditionImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMSprProducerConditionImpl::get_Query(void)
{
return Object->Query;
}
//---------------------------------------------------------------
void TREM_DMSprProducerConditionImpl::set_Query(TpFIBQuery * Query)
{
Object->Query=Query;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerConditionImpl::get_TableID_REM_SPRCONDITION(void)
{
return Object->TableID_REM_SPRCONDITION;
}
//---------------------------------------------------------------
void TREM_DMSprProducerConditionImpl::set_TableID_REM_SPRCONDITION(TFIBLargeIntField * TableID_REM_SPRCONDITION)
{
Object->TableID_REM_SPRCONDITION=TableID_REM_SPRCONDITION;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerConditionImpl::get_TableIDBASE_REM_SPRCONDITION(void)
{
return Object->TableIDBASE_REM_SPRCONDITION;
}
//---------------------------------------------------------------
void TREM_DMSprProducerConditionImpl::set_TableIDBASE_REM_SPRCONDITION(TFIBLargeIntField * TableIDBASE_REM_SPRCONDITION)
{
Object->TableIDBASE_REM_SPRCONDITION=TableIDBASE_REM_SPRCONDITION;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerConditionImpl::get_TableGID_REM_SPRCONDITION(void)
{
return Object->TableGID_REM_SPRCONDITION;
}
//---------------------------------------------------------------
void TREM_DMSprProducerConditionImpl::set_TableGID_REM_SPRCONDITION(TFIBWideStringField * TableGID_REM_SPRCONDITION)
{
Object->TableGID_REM_SPRCONDITION=TableGID_REM_SPRCONDITION;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerConditionImpl::get_TableIDPR_REM_SPRCONDITION(void)
{
return Object->TableIDPR_REM_SPRCONDITION;
}
//---------------------------------------------------------------
void TREM_DMSprProducerConditionImpl::set_TableIDPR_REM_SPRCONDITION(TFIBLargeIntField * TableIDPR_REM_SPRCONDITION)
{
Object->TableIDPR_REM_SPRCONDITION=TableIDPR_REM_SPRCONDITION;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerConditionImpl::get_TableIDGRP_REM_SPRCONDITION(void)
{
return Object->TableIDGRP_REM_SPRCONDITION;
}
//---------------------------------------------------------------
void TREM_DMSprProducerConditionImpl::set_TableIDGRP_REM_SPRCONDITION(TFIBLargeIntField * TableIDGRP_REM_SPRCONDITION)
{
Object->TableIDGRP_REM_SPRCONDITION=TableIDGRP_REM_SPRCONDITION;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerConditionImpl::get_TableCODE_REM_SPRCONDITION(void)
{
return Object->TableCODE_REM_SPRCONDITION;
}
//---------------------------------------------------------------
void TREM_DMSprProducerConditionImpl::set_TableCODE_REM_SPRCONDITION(TFIBWideStringField * TableCODE_REM_SPRCONDITION)
{
Object->TableCODE_REM_SPRCONDITION=TableCODE_REM_SPRCONDITION;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerConditionImpl::get_TableNAME_REM_SPRCONDITION(void)
{
return Object->TableNAME_REM_SPRCONDITION;
}
//---------------------------------------------------------------
void TREM_DMSprProducerConditionImpl::set_TableNAME_REM_SPRCONDITION(TFIBWideStringField * TableNAME_REM_SPRCONDITION)
{
Object->TableNAME_REM_SPRCONDITION=TableNAME_REM_SPRCONDITION;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerConditionImpl::get_TableNAME_ENG_REM_SPRCONDITION(void)
{
return Object->TableNAME_ENG_REM_SPRCONDITION;
}
//---------------------------------------------------------------
void TREM_DMSprProducerConditionImpl::set_TableNAME_ENG_REM_SPRCONDITION(TFIBWideStringField * TableNAME_ENG_REM_SPRCONDITION)
{
Object->TableNAME_ENG_REM_SPRCONDITION=TableNAME_ENG_REM_SPRCONDITION;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerConditionImpl::get_ElementID_REM_SPRCONDITION(void)
{
return Object->ElementID_REM_SPRCONDITION;
}
//---------------------------------------------------------------
void TREM_DMSprProducerConditionImpl::set_ElementID_REM_SPRCONDITION(TFIBLargeIntField * ElementID_REM_SPRCONDITION)
{
Object->ElementID_REM_SPRCONDITION=ElementID_REM_SPRCONDITION;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerConditionImpl::get_ElementIDBASE_REM_SPRCONDITION(void)
{
return Object->ElementIDBASE_REM_SPRCONDITION;
}
//---------------------------------------------------------------
void TREM_DMSprProducerConditionImpl::set_ElementIDBASE_REM_SPRCONDITION(TFIBLargeIntField * ElementIDBASE_REM_SPRCONDITION)
{
Object->ElementIDBASE_REM_SPRCONDITION=ElementIDBASE_REM_SPRCONDITION;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerConditionImpl::get_ElementGID_REM_SPRCONDITION(void)
{
return Object->ElementGID_REM_SPRCONDITION;
}
//---------------------------------------------------------------
void TREM_DMSprProducerConditionImpl::set_ElementGID_REM_SPRCONDITION(TFIBWideStringField * ElementGID_REM_SPRCONDITION)
{
Object->ElementGID_REM_SPRCONDITION=ElementGID_REM_SPRCONDITION;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerConditionImpl::get_ElementIDPR_REM_SPRCONDITION(void)
{
return Object->ElementIDPR_REM_SPRCONDITION;
}
//---------------------------------------------------------------
void TREM_DMSprProducerConditionImpl::set_ElementIDPR_REM_SPRCONDITION(TFIBLargeIntField * ElementIDPR_REM_SPRCONDITION)
{
Object->ElementIDPR_REM_SPRCONDITION=ElementIDPR_REM_SPRCONDITION;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerConditionImpl::get_ElementIDGRP_REM_SPRCONDITION(void)
{
return Object->ElementIDGRP_REM_SPRCONDITION;
}
//---------------------------------------------------------------
void TREM_DMSprProducerConditionImpl::set_ElementIDGRP_REM_SPRCONDITION(TFIBLargeIntField * ElementIDGRP_REM_SPRCONDITION)
{
Object->ElementIDGRP_REM_SPRCONDITION=ElementIDGRP_REM_SPRCONDITION;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerConditionImpl::get_ElementCODE_REM_SPRCONDITION(void)
{
return Object->ElementCODE_REM_SPRCONDITION;
}
//---------------------------------------------------------------
void TREM_DMSprProducerConditionImpl::set_ElementCODE_REM_SPRCONDITION(TFIBWideStringField * ElementCODE_REM_SPRCONDITION)
{
Object->ElementCODE_REM_SPRCONDITION=ElementCODE_REM_SPRCONDITION;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerConditionImpl::get_ElementNAME_REM_SPRCONDITION(void)
{
return Object->ElementNAME_REM_SPRCONDITION;
}
//---------------------------------------------------------------
void TREM_DMSprProducerConditionImpl::set_ElementNAME_REM_SPRCONDITION(TFIBWideStringField * ElementNAME_REM_SPRCONDITION)
{
Object->ElementNAME_REM_SPRCONDITION=ElementNAME_REM_SPRCONDITION;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerConditionImpl::get_ElementNAME_ENG_REM_SPRCONDITION(void)
{
return Object->ElementNAME_ENG_REM_SPRCONDITION;
}
//---------------------------------------------------------------
void TREM_DMSprProducerConditionImpl::set_ElementNAME_ENG_REM_SPRCONDITION(TFIBWideStringField * ElementNAME_ENG_REM_SPRCONDITION)
{
Object->ElementNAME_ENG_REM_SPRCONDITION=ElementNAME_ENG_REM_SPRCONDITION;
}
//---------------------------------------------------------------
void TREM_DMSprProducerConditionImpl::OpenTable(__int64 id_group_element, __int64 id_grp, bool all)
{
return Object->OpenTable(id_group_element,id_grp,all);
}
//---------------------------------------------------------------
bool TREM_DMSprProducerConditionImpl::NewElement(__int64 id_group_element, __int64 id_grp)
{
return Object->NewElement(id_group_element,id_grp);
}
//---------------------------------------------------------------
bool TREM_DMSprProducerConditionImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
bool TREM_DMSprProducerConditionImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
bool TREM_DMSprProducerConditionImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
void TREM_DMSprProducerConditionImpl::ChancheGrp(__int64 id_new_grp,__int64 id_element)
{
return Object->ChancheGrp(id_new_grp,id_element);
}
//---------------------------------------------------------------
__int64 TREM_DMSprProducerConditionImpl::FindPoCodu(__int64 id_group_element, UnicodeString code)
{
return Object->FindPoCodu(id_group_element,code);
}
//---------------------------------------------------------------
__int64 TREM_DMSprProducerConditionImpl::FindPoName(__int64 id_group_element, UnicodeString name)
{
return Object->FindPoName(id_group_element, name);
}
//---------------------------------------------------------------
__int64 TREM_DMSprProducerConditionImpl::FindPoNameEng(__int64 id_group_element, UnicodeString name)
{
return Object->FindPoNameEng(id_group_element,name);
}
//---------------------------------------------------------------
__int64 TREM_DMSprProducerConditionImpl::GetIdGrp(__int64 id_el)
{
return Object->GetIdGrp(id_el);
}
//---------------------------------------------------------------
