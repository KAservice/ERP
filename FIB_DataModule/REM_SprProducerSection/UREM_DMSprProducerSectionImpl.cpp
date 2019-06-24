#include "vcl.h"
#pragma hdrstop


#include "UREM_DMSprProducerSectionImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_DMSprProducerSectionImpl::TREM_DMSprProducerSectionImpl()           
{                                            
Object=new TREM_DMSprProducerSection(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_DMSprProducerSectionImpl::~TREM_DMSprProducerSectionImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_DMSprProducerSectionImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_DMSprProducerSectionImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_DMSprProducerSection)                        
   {                                                                     
   *ppv=static_cast<IREM_DMSprProducerSection*> (this);                                
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
int TREM_DMSprProducerSectionImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_DMSprProducerSectionImpl::kanRelease(void)                                  
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
int  TREM_DMSprProducerSectionImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMSprProducerSectionImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_DMSprProducerSectionImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMSprProducerSectionImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_DMSprProducerSectionImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_DMSprProducerSectionImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_DMSprProducerSectionImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IREM_DMSprProducerSection
TDataSource * TREM_DMSprProducerSectionImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TREM_DMSprProducerSectionImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMSprProducerSectionImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TREM_DMSprProducerSectionImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMSprProducerSectionImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TREM_DMSprProducerSectionImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMSprProducerSectionImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TREM_DMSprProducerSectionImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMSprProducerSectionImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TREM_DMSprProducerSectionImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TIntegerField * TREM_DMSprProducerSectionImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TREM_DMSprProducerSectionImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TDataSource * TREM_DMSprProducerSectionImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TREM_DMSprProducerSectionImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMSprProducerSectionImpl::get_Query(void)
{
return Object->Query;
}
//---------------------------------------------------------------
void TREM_DMSprProducerSectionImpl::set_Query(TpFIBQuery * Query)
{
Object->Query=Query;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerSectionImpl::get_TableID_REM_SPRSECTION(void)
{
return Object->TableID_REM_SPRSECTION;
}
//---------------------------------------------------------------
void TREM_DMSprProducerSectionImpl::set_TableID_REM_SPRSECTION(TFIBLargeIntField * TableID_REM_SPRSECTION)
{
Object->TableID_REM_SPRSECTION=TableID_REM_SPRSECTION;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerSectionImpl::get_TableIDBASE_REM_SPRSECTION(void)
{
return Object->TableIDBASE_REM_SPRSECTION;
}
//---------------------------------------------------------------
void TREM_DMSprProducerSectionImpl::set_TableIDBASE_REM_SPRSECTION(TFIBLargeIntField * TableIDBASE_REM_SPRSECTION)
{
Object->TableIDBASE_REM_SPRSECTION=TableIDBASE_REM_SPRSECTION;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerSectionImpl::get_TableIDGRP_REM_SPRSECTION(void)
{
return Object->TableIDGRP_REM_SPRSECTION;
}
//---------------------------------------------------------------
void TREM_DMSprProducerSectionImpl::set_TableIDGRP_REM_SPRSECTION(TFIBLargeIntField * TableIDGRP_REM_SPRSECTION)
{
Object->TableIDGRP_REM_SPRSECTION=TableIDGRP_REM_SPRSECTION;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerSectionImpl::get_TableIDPR_REM_SPRSECTION(void)
{
return Object->TableIDPR_REM_SPRSECTION;
}
//---------------------------------------------------------------
void TREM_DMSprProducerSectionImpl::set_TableIDPR_REM_SPRSECTION(TFIBLargeIntField * TableIDPR_REM_SPRSECTION)
{
Object->TableIDPR_REM_SPRSECTION=TableIDPR_REM_SPRSECTION;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerSectionImpl::get_TableCODE_REM_SPRSECTION(void)
{
return Object->TableCODE_REM_SPRSECTION;
}
//---------------------------------------------------------------
void TREM_DMSprProducerSectionImpl::set_TableCODE_REM_SPRSECTION(TFIBWideStringField * TableCODE_REM_SPRSECTION)
{
Object->TableCODE_REM_SPRSECTION=TableCODE_REM_SPRSECTION;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerSectionImpl::get_TableNAME_REM_SPRSECTION(void)
{
return Object->TableNAME_REM_SPRSECTION;
}
//---------------------------------------------------------------
void TREM_DMSprProducerSectionImpl::set_TableNAME_REM_SPRSECTION(TFIBWideStringField * TableNAME_REM_SPRSECTION)
{
Object->TableNAME_REM_SPRSECTION=TableNAME_REM_SPRSECTION;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerSectionImpl::get_TableNAME_ENG_REM_SPRSECTION(void)
{
return Object->TableNAME_ENG_REM_SPRSECTION;
}
//---------------------------------------------------------------
void TREM_DMSprProducerSectionImpl::set_TableNAME_ENG_REM_SPRSECTION(TFIBWideStringField * TableNAME_ENG_REM_SPRSECTION)
{
Object->TableNAME_ENG_REM_SPRSECTION=TableNAME_ENG_REM_SPRSECTION;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerSectionImpl::get_ElementID_REM_SPRSECTION(void)
{
return Object->ElementID_REM_SPRSECTION;
}
//---------------------------------------------------------------
void TREM_DMSprProducerSectionImpl::set_ElementID_REM_SPRSECTION(TFIBLargeIntField * ElementID_REM_SPRSECTION)
{
Object->ElementID_REM_SPRSECTION=ElementID_REM_SPRSECTION;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerSectionImpl::get_ElementIDBASE_REM_SPRSECTION(void)
{
return Object->ElementIDBASE_REM_SPRSECTION;
}
//---------------------------------------------------------------
void TREM_DMSprProducerSectionImpl::set_ElementIDBASE_REM_SPRSECTION(TFIBLargeIntField * ElementIDBASE_REM_SPRSECTION)
{
Object->ElementIDBASE_REM_SPRSECTION=ElementIDBASE_REM_SPRSECTION;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerSectionImpl::get_ElementIDGRP_REM_SPRSECTION(void)
{
return Object->ElementIDGRP_REM_SPRSECTION;
}
//---------------------------------------------------------------
void TREM_DMSprProducerSectionImpl::set_ElementIDGRP_REM_SPRSECTION(TFIBLargeIntField * ElementIDGRP_REM_SPRSECTION)
{
Object->ElementIDGRP_REM_SPRSECTION=ElementIDGRP_REM_SPRSECTION;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerSectionImpl::get_ElementIDPR_REM_SPRSECTION(void)
{
return Object->ElementIDPR_REM_SPRSECTION;
}
//---------------------------------------------------------------
void TREM_DMSprProducerSectionImpl::set_ElementIDPR_REM_SPRSECTION(TFIBLargeIntField * ElementIDPR_REM_SPRSECTION)
{
Object->ElementIDPR_REM_SPRSECTION=ElementIDPR_REM_SPRSECTION;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerSectionImpl::get_ElementCODE_REM_SPRSECTION(void)
{
return Object->ElementCODE_REM_SPRSECTION;
}
//---------------------------------------------------------------
void TREM_DMSprProducerSectionImpl::set_ElementCODE_REM_SPRSECTION(TFIBWideStringField * ElementCODE_REM_SPRSECTION)
{
Object->ElementCODE_REM_SPRSECTION=ElementCODE_REM_SPRSECTION;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerSectionImpl::get_ElementNAME_REM_SPRSECTION(void)
{
return Object->ElementNAME_REM_SPRSECTION;
}
//---------------------------------------------------------------
void TREM_DMSprProducerSectionImpl::set_ElementNAME_REM_SPRSECTION(TFIBWideStringField * ElementNAME_REM_SPRSECTION)
{
Object->ElementNAME_REM_SPRSECTION=ElementNAME_REM_SPRSECTION;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerSectionImpl::get_ElementNAME_ENG_REM_SPRSECTION(void)
{
return Object->ElementNAME_ENG_REM_SPRSECTION;
}
//---------------------------------------------------------------
void TREM_DMSprProducerSectionImpl::set_ElementNAME_ENG_REM_SPRSECTION(TFIBWideStringField * ElementNAME_ENG_REM_SPRSECTION)
{
Object->ElementNAME_ENG_REM_SPRSECTION=ElementNAME_ENG_REM_SPRSECTION;
}
//---------------------------------------------------------------
__int64 TREM_DMSprProducerSectionImpl::get_IdGroupElement(void)
{
return Object->IdGroupElement;
}
//---------------------------------------------------------------
void TREM_DMSprProducerSectionImpl::set_IdGroupElement(__int64 IdGroupElement)
{
Object->IdGroupElement=IdGroupElement;
}
//---------------------------------------------------------------
__int64 TREM_DMSprProducerSectionImpl::get_IdGrp(void)
{
return Object->IdGrp;
}
//---------------------------------------------------------------
void TREM_DMSprProducerSectionImpl::set_IdGrp(__int64 IdGrp)
{
Object->IdGrp=IdGrp;
}
//---------------------------------------------------------------
bool TREM_DMSprProducerSectionImpl::get_AllElement(void)
{
return Object->AllElement;
}
//---------------------------------------------------------------
void TREM_DMSprProducerSectionImpl::set_AllElement(bool AllElement)
{
Object->AllElement=AllElement;
}
//---------------------------------------------------------------
void TREM_DMSprProducerSectionImpl::OpenTable(__int64 id_group_element, __int64 id_grp, bool all)
{
return Object->OpenTable(id_group_element,id_grp,all);
}
//---------------------------------------------------------------
bool TREM_DMSprProducerSectionImpl::NewElement(__int64 id_group_element, __int64 id_grp)
{
return Object->NewElement(id_group_element,id_grp);
}
//---------------------------------------------------------------
bool TREM_DMSprProducerSectionImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
bool TREM_DMSprProducerSectionImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
bool TREM_DMSprProducerSectionImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
void TREM_DMSprProducerSectionImpl::ChancheGrp(__int64 id_new_grp,__int64 id_element)
{
return Object->ChancheGrp(id_new_grp,id_element);
}
//---------------------------------------------------------------
__int64 TREM_DMSprProducerSectionImpl::FindPoCodu(__int64 id_group_element, UnicodeString code)
{
return Object->FindPoCodu(id_group_element, code);
}
//---------------------------------------------------------------
__int64 TREM_DMSprProducerSectionImpl::FindPoName(__int64 id_group_element, UnicodeString name)
{
return Object->FindPoName(id_group_element, name);
}
//---------------------------------------------------------------
__int64 TREM_DMSprProducerSectionImpl::FindPoNameEng(__int64 id_group_element, UnicodeString name)
{
return Object->FindPoNameEng(id_group_element,  name);
}
//---------------------------------------------------------------
__int64 TREM_DMSprProducerSectionImpl::GetIdGrp(__int64 id_el)
{
return Object->GetIdGrp(id_el);
}
//---------------------------------------------------------------
