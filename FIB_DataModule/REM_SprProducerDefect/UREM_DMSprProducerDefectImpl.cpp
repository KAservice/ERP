#include "vcl.h"
#pragma hdrstop


#include "UREM_DMSprProducerDefectImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_DMSprProducerDefectImpl::TREM_DMSprProducerDefectImpl()           
{                                            
Object=new TREM_DMSprProducerDefect(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_DMSprProducerDefectImpl::~TREM_DMSprProducerDefectImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_DMSprProducerDefectImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_DMSprProducerDefectImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_DMSprProducerDefect)                        
   {                                                                     
   *ppv=static_cast<IREM_DMSprProducerDefect*> (this);                                
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
int TREM_DMSprProducerDefectImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_DMSprProducerDefectImpl::kanRelease(void)                                  
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
int  TREM_DMSprProducerDefectImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMSprProducerDefectImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_DMSprProducerDefectImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMSprProducerDefectImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_DMSprProducerDefectImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_DMSprProducerDefectImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_DMSprProducerDefectImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IREM_DMSprProducerDefect
TDataSource * TREM_DMSprProducerDefectImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TREM_DMSprProducerDefectImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMSprProducerDefectImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TREM_DMSprProducerDefectImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMSprProducerDefectImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TREM_DMSprProducerDefectImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMSprProducerDefectImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TREM_DMSprProducerDefectImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMSprProducerDefectImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TREM_DMSprProducerDefectImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TIntegerField * TREM_DMSprProducerDefectImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TREM_DMSprProducerDefectImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TDataSource * TREM_DMSprProducerDefectImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TREM_DMSprProducerDefectImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerDefectImpl::get_TableID_REM_SPRDEFECT(void)
{
return Object->TableID_REM_SPRDEFECT;
}
//---------------------------------------------------------------
void TREM_DMSprProducerDefectImpl::set_TableID_REM_SPRDEFECT(TFIBLargeIntField * TableID_REM_SPRDEFECT)
{
Object->TableID_REM_SPRDEFECT=TableID_REM_SPRDEFECT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerDefectImpl::get_TableCODE_REM_SPRDEFECT(void)
{
return Object->TableCODE_REM_SPRDEFECT;
}
//---------------------------------------------------------------
void TREM_DMSprProducerDefectImpl::set_TableCODE_REM_SPRDEFECT(TFIBWideStringField * TableCODE_REM_SPRDEFECT)
{
Object->TableCODE_REM_SPRDEFECT=TableCODE_REM_SPRDEFECT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerDefectImpl::get_TableNAME_REM_SPRDEFECT(void)
{
return Object->TableNAME_REM_SPRDEFECT;
}
//---------------------------------------------------------------
void TREM_DMSprProducerDefectImpl::set_TableNAME_REM_SPRDEFECT(TFIBWideStringField * TableNAME_REM_SPRDEFECT)
{
Object->TableNAME_REM_SPRDEFECT=TableNAME_REM_SPRDEFECT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerDefectImpl::get_TableIDPR_REM_SPRDEFECT(void)
{
return Object->TableIDPR_REM_SPRDEFECT;
}
//---------------------------------------------------------------
void TREM_DMSprProducerDefectImpl::set_TableIDPR_REM_SPRDEFECT(TFIBLargeIntField * TableIDPR_REM_SPRDEFECT)
{
Object->TableIDPR_REM_SPRDEFECT=TableIDPR_REM_SPRDEFECT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerDefectImpl::get_TableIDGRP_REM_SPRDEFECT(void)
{
return Object->TableIDGRP_REM_SPRDEFECT;
}
//---------------------------------------------------------------
void TREM_DMSprProducerDefectImpl::set_TableIDGRP_REM_SPRDEFECT(TFIBLargeIntField * TableIDGRP_REM_SPRDEFECT)
{
Object->TableIDGRP_REM_SPRDEFECT=TableIDGRP_REM_SPRDEFECT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerDefectImpl::get_ElementID_REM_SPRDEFECT(void)
{
return Object->ElementID_REM_SPRDEFECT;
}
//---------------------------------------------------------------
void TREM_DMSprProducerDefectImpl::set_ElementID_REM_SPRDEFECT(TFIBLargeIntField * ElementID_REM_SPRDEFECT)
{
Object->ElementID_REM_SPRDEFECT=ElementID_REM_SPRDEFECT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerDefectImpl::get_ElementIDBASE_REM_SPRDEFECT(void)
{
return Object->ElementIDBASE_REM_SPRDEFECT;
}
//---------------------------------------------------------------
void TREM_DMSprProducerDefectImpl::set_ElementIDBASE_REM_SPRDEFECT(TFIBLargeIntField * ElementIDBASE_REM_SPRDEFECT)
{
Object->ElementIDBASE_REM_SPRDEFECT=ElementIDBASE_REM_SPRDEFECT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerDefectImpl::get_ElementGID_REM_SPRDEFECT(void)
{
return Object->ElementGID_REM_SPRDEFECT;
}
//---------------------------------------------------------------
void TREM_DMSprProducerDefectImpl::set_ElementGID_REM_SPRDEFECT(TFIBWideStringField * ElementGID_REM_SPRDEFECT)
{
Object->ElementGID_REM_SPRDEFECT=ElementGID_REM_SPRDEFECT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerDefectImpl::get_ElementIDPR_REM_SPRDEFECT(void)
{
return Object->ElementIDPR_REM_SPRDEFECT;
}
//---------------------------------------------------------------
void TREM_DMSprProducerDefectImpl::set_ElementIDPR_REM_SPRDEFECT(TFIBLargeIntField * ElementIDPR_REM_SPRDEFECT)
{
Object->ElementIDPR_REM_SPRDEFECT=ElementIDPR_REM_SPRDEFECT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerDefectImpl::get_ElementIDGRP_REM_SPRDEFECT(void)
{
return Object->ElementIDGRP_REM_SPRDEFECT;
}
//---------------------------------------------------------------
void TREM_DMSprProducerDefectImpl::set_ElementIDGRP_REM_SPRDEFECT(TFIBLargeIntField * ElementIDGRP_REM_SPRDEFECT)
{
Object->ElementIDGRP_REM_SPRDEFECT=ElementIDGRP_REM_SPRDEFECT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerDefectImpl::get_ElementCODE_REM_SPRDEFECT(void)
{
return Object->ElementCODE_REM_SPRDEFECT;
}
//---------------------------------------------------------------
void TREM_DMSprProducerDefectImpl::set_ElementCODE_REM_SPRDEFECT(TFIBWideStringField * ElementCODE_REM_SPRDEFECT)
{
Object->ElementCODE_REM_SPRDEFECT=ElementCODE_REM_SPRDEFECT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerDefectImpl::get_ElementNAME_REM_SPRDEFECT(void)
{
return Object->ElementNAME_REM_SPRDEFECT;
}
//---------------------------------------------------------------
void TREM_DMSprProducerDefectImpl::set_ElementNAME_REM_SPRDEFECT(TFIBWideStringField * ElementNAME_REM_SPRDEFECT)
{
Object->ElementNAME_REM_SPRDEFECT=ElementNAME_REM_SPRDEFECT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerDefectImpl::get_TableNAME_ENG_REM_SPRDEFECT(void)
{
return Object->TableNAME_ENG_REM_SPRDEFECT;
}
//---------------------------------------------------------------
void TREM_DMSprProducerDefectImpl::set_TableNAME_ENG_REM_SPRDEFECT(TFIBWideStringField * TableNAME_ENG_REM_SPRDEFECT)
{
Object->TableNAME_ENG_REM_SPRDEFECT=TableNAME_ENG_REM_SPRDEFECT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerDefectImpl::get_ElementNAME_ENG_REM_SPRDEFECT(void)
{
return Object->ElementNAME_ENG_REM_SPRDEFECT;
}
//---------------------------------------------------------------
void TREM_DMSprProducerDefectImpl::set_ElementNAME_ENG_REM_SPRDEFECT(TFIBWideStringField * ElementNAME_ENG_REM_SPRDEFECT)
{
Object->ElementNAME_ENG_REM_SPRDEFECT=ElementNAME_ENG_REM_SPRDEFECT;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMSprProducerDefectImpl::get_Query(void)
{
return Object->Query;
}
//---------------------------------------------------------------
void TREM_DMSprProducerDefectImpl::set_Query(TpFIBQuery * Query)
{
Object->Query=Query;
}
//---------------------------------------------------------------
__int64 TREM_DMSprProducerDefectImpl::get_IdGroupElement(void)
{
return Object->IdGroupElement;
}
//---------------------------------------------------------------
void TREM_DMSprProducerDefectImpl::set_IdGroupElement(__int64 IdGroupElement)
{
Object->IdGroupElement=IdGroupElement;
}
//---------------------------------------------------------------
__int64 TREM_DMSprProducerDefectImpl::get_IdGrp(void)
{
return Object->IdGrp;
}
//---------------------------------------------------------------
void TREM_DMSprProducerDefectImpl::set_IdGrp(__int64 IdGrp)
{
Object->IdGrp=IdGrp;
}
//---------------------------------------------------------------
bool TREM_DMSprProducerDefectImpl::get_AllElement(void)
{
return Object->AllElement;
}
//---------------------------------------------------------------
void TREM_DMSprProducerDefectImpl::set_AllElement(bool AllElement)
{
Object->AllElement=AllElement;
}
//---------------------------------------------------------------
void TREM_DMSprProducerDefectImpl::OpenTable(__int64 id_group_element, __int64 id_grp, bool all)
{
return Object->OpenTable(id_group_element,id_grp,all);
}
//---------------------------------------------------------------
bool TREM_DMSprProducerDefectImpl::NewElement(__int64 id_group_element, __int64 id_grp)
{
return Object->NewElement(id_group_element,id_grp);
}
//---------------------------------------------------------------
bool TREM_DMSprProducerDefectImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
bool TREM_DMSprProducerDefectImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
bool TREM_DMSprProducerDefectImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
void TREM_DMSprProducerDefectImpl::ChancheGrp(__int64 id_new_grp,__int64 id_element)
{
return Object->ChancheGrp(id_new_grp,id_element);
}
//---------------------------------------------------------------
__int64 TREM_DMSprProducerDefectImpl::FindPoCodu(__int64 id_group_element, UnicodeString code)
{
return Object->FindPoCodu(id_group_element,code);
}
//---------------------------------------------------------------
__int64 TREM_DMSprProducerDefectImpl::FindPoName(__int64 id_group_element, UnicodeString name)
{
return Object->FindPoName(id_group_element,name);
}
//---------------------------------------------------------------
__int64 TREM_DMSprProducerDefectImpl::FindPoNameEng(__int64 id_group_element, UnicodeString name)
{
return Object->FindPoNameEng(id_group_element, name);
}
//---------------------------------------------------------------
__int64 TREM_DMSprProducerDefectImpl::GetIdGrp(__int64 id_el)
{
return Object->GetIdGrp(id_el);
}
//---------------------------------------------------------------
