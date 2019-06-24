#include "vcl.h"
#pragma hdrstop


#include "UREM_DMSprProducerRabotaImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_DMSprProducerRabotaImpl::TREM_DMSprProducerRabotaImpl()           
{                                            
Object=new TREM_DMSprProducerRabota(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_DMSprProducerRabotaImpl::~TREM_DMSprProducerRabotaImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_DMSprProducerRabotaImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_DMSprProducerRabotaImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_DMSprProducerRabota)                        
   {                                                                     
   *ppv=static_cast<IREM_DMSprProducerRabota*> (this);                                
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
int TREM_DMSprProducerRabotaImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_DMSprProducerRabotaImpl::kanRelease(void)                                  
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
int  TREM_DMSprProducerRabotaImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMSprProducerRabotaImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_DMSprProducerRabotaImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMSprProducerRabotaImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_DMSprProducerRabotaImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_DMSprProducerRabotaImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_DMSprProducerRabotaImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IREM_DMSprProducerRabota
TDataSource * TREM_DMSprProducerRabotaImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TREM_DMSprProducerRabotaImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMSprProducerRabotaImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TREM_DMSprProducerRabotaImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMSprProducerRabotaImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TREM_DMSprProducerRabotaImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMSprProducerRabotaImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TREM_DMSprProducerRabotaImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMSprProducerRabotaImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TREM_DMSprProducerRabotaImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TIntegerField * TREM_DMSprProducerRabotaImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TREM_DMSprProducerRabotaImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TDataSource * TREM_DMSprProducerRabotaImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TREM_DMSprProducerRabotaImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerRabotaImpl::get_TableID_REM_SPRRABOTA(void)
{
return Object->TableID_REM_SPRRABOTA;
}
//---------------------------------------------------------------
void TREM_DMSprProducerRabotaImpl::set_TableID_REM_SPRRABOTA(TFIBLargeIntField * TableID_REM_SPRRABOTA)
{
Object->TableID_REM_SPRRABOTA=TableID_REM_SPRRABOTA;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerRabotaImpl::get_TableIDBASE_REM_SPRRABOTA(void)
{
return Object->TableIDBASE_REM_SPRRABOTA;
}
//---------------------------------------------------------------
void TREM_DMSprProducerRabotaImpl::set_TableIDBASE_REM_SPRRABOTA(TFIBLargeIntField * TableIDBASE_REM_SPRRABOTA)
{
Object->TableIDBASE_REM_SPRRABOTA=TableIDBASE_REM_SPRRABOTA;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerRabotaImpl::get_TableGID_REM_SPRRABOTA(void)
{
return Object->TableGID_REM_SPRRABOTA;
}
//---------------------------------------------------------------
void TREM_DMSprProducerRabotaImpl::set_TableGID_REM_SPRRABOTA(TFIBWideStringField * TableGID_REM_SPRRABOTA)
{
Object->TableGID_REM_SPRRABOTA=TableGID_REM_SPRRABOTA;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerRabotaImpl::get_TableIDPR_REM_SPRRABOTA(void)
{
return Object->TableIDPR_REM_SPRRABOTA;
}
//---------------------------------------------------------------
void TREM_DMSprProducerRabotaImpl::set_TableIDPR_REM_SPRRABOTA(TFIBLargeIntField * TableIDPR_REM_SPRRABOTA)
{
Object->TableIDPR_REM_SPRRABOTA=TableIDPR_REM_SPRRABOTA;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerRabotaImpl::get_TableIDGRP_REM_SPRRABOTA(void)
{
return Object->TableIDGRP_REM_SPRRABOTA;
}
//---------------------------------------------------------------
void TREM_DMSprProducerRabotaImpl::set_TableIDGRP_REM_SPRRABOTA(TFIBLargeIntField * TableIDGRP_REM_SPRRABOTA)
{
Object->TableIDGRP_REM_SPRRABOTA=TableIDGRP_REM_SPRRABOTA;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerRabotaImpl::get_TableNAME_REM_SPRRABOTA(void)
{
return Object->TableNAME_REM_SPRRABOTA;
}
//---------------------------------------------------------------
void TREM_DMSprProducerRabotaImpl::set_TableNAME_REM_SPRRABOTA(TFIBWideStringField * TableNAME_REM_SPRRABOTA)
{
Object->TableNAME_REM_SPRRABOTA=TableNAME_REM_SPRRABOTA;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerRabotaImpl::get_TableNAME_ENG_REM_SPRRABOTA(void)
{
return Object->TableNAME_ENG_REM_SPRRABOTA;
}
//---------------------------------------------------------------
void TREM_DMSprProducerRabotaImpl::set_TableNAME_ENG_REM_SPRRABOTA(TFIBWideStringField * TableNAME_ENG_REM_SPRRABOTA)
{
Object->TableNAME_ENG_REM_SPRRABOTA=TableNAME_ENG_REM_SPRRABOTA;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerRabotaImpl::get_TableCODE_REM_SPRRABOTA(void)
{
return Object->TableCODE_REM_SPRRABOTA;
}
//---------------------------------------------------------------
void TREM_DMSprProducerRabotaImpl::set_TableCODE_REM_SPRRABOTA(TFIBWideStringField * TableCODE_REM_SPRRABOTA)
{
Object->TableCODE_REM_SPRRABOTA=TableCODE_REM_SPRRABOTA;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMSprProducerRabotaImpl::get_TableLEVEL_REM_SPRRABOTA(void)
{
return Object->TableLEVEL_REM_SPRRABOTA;
}
//---------------------------------------------------------------
void TREM_DMSprProducerRabotaImpl::set_TableLEVEL_REM_SPRRABOTA(TFIBIntegerField * TableLEVEL_REM_SPRRABOTA)
{
Object->TableLEVEL_REM_SPRRABOTA=TableLEVEL_REM_SPRRABOTA;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMSprProducerRabotaImpl::get_TableTYPECLIENT_REM_SPRRABOTA(void)
{
return Object->TableTYPECLIENT_REM_SPRRABOTA;
}
//---------------------------------------------------------------
void TREM_DMSprProducerRabotaImpl::set_TableTYPECLIENT_REM_SPRRABOTA(TFIBIntegerField * TableTYPECLIENT_REM_SPRRABOTA)
{
Object->TableTYPECLIENT_REM_SPRRABOTA=TableTYPECLIENT_REM_SPRRABOTA;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMSprProducerRabotaImpl::get_TableTYPEPRODUCT_REM_SPRRABOTA(void)
{
return Object->TableTYPEPRODUCT_REM_SPRRABOTA;
}
//---------------------------------------------------------------
void TREM_DMSprProducerRabotaImpl::set_TableTYPEPRODUCT_REM_SPRRABOTA(TFIBIntegerField * TableTYPEPRODUCT_REM_SPRRABOTA)
{
Object->TableTYPEPRODUCT_REM_SPRRABOTA=TableTYPEPRODUCT_REM_SPRRABOTA;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerRabotaImpl::get_TableLEVEL_STR_REM_SPRRABOTA(void)
{
return Object->TableLEVEL_STR_REM_SPRRABOTA;
}
//---------------------------------------------------------------
void TREM_DMSprProducerRabotaImpl::set_TableLEVEL_STR_REM_SPRRABOTA(TFIBWideStringField * TableLEVEL_STR_REM_SPRRABOTA)
{
Object->TableLEVEL_STR_REM_SPRRABOTA=TableLEVEL_STR_REM_SPRRABOTA;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerRabotaImpl::get_TableIDNOM_REM_SPRRABOTA(void)
{
return Object->TableIDNOM_REM_SPRRABOTA;
}
//---------------------------------------------------------------
void TREM_DMSprProducerRabotaImpl::set_TableIDNOM_REM_SPRRABOTA(TFIBLargeIntField * TableIDNOM_REM_SPRRABOTA)
{
Object->TableIDNOM_REM_SPRRABOTA=TableIDNOM_REM_SPRRABOTA;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerRabotaImpl::get_TableNAMENOM(void)
{
return Object->TableNAMENOM;
}
//---------------------------------------------------------------
void TREM_DMSprProducerRabotaImpl::set_TableNAMENOM(TFIBWideStringField * TableNAMENOM)
{
Object->TableNAMENOM=TableNAMENOM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerRabotaImpl::get_ElementID_REM_SPRRABOTA(void)
{
return Object->ElementID_REM_SPRRABOTA;
}
//---------------------------------------------------------------
void TREM_DMSprProducerRabotaImpl::set_ElementID_REM_SPRRABOTA(TFIBLargeIntField * ElementID_REM_SPRRABOTA)
{
Object->ElementID_REM_SPRRABOTA=ElementID_REM_SPRRABOTA;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerRabotaImpl::get_ElementIDBASE_REM_SPRRABOTA(void)
{
return Object->ElementIDBASE_REM_SPRRABOTA;
}
//---------------------------------------------------------------
void TREM_DMSprProducerRabotaImpl::set_ElementIDBASE_REM_SPRRABOTA(TFIBLargeIntField * ElementIDBASE_REM_SPRRABOTA)
{
Object->ElementIDBASE_REM_SPRRABOTA=ElementIDBASE_REM_SPRRABOTA;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerRabotaImpl::get_ElementGID_REM_SPRRABOTA(void)
{
return Object->ElementGID_REM_SPRRABOTA;
}
//---------------------------------------------------------------
void TREM_DMSprProducerRabotaImpl::set_ElementGID_REM_SPRRABOTA(TFIBWideStringField * ElementGID_REM_SPRRABOTA)
{
Object->ElementGID_REM_SPRRABOTA=ElementGID_REM_SPRRABOTA;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerRabotaImpl::get_ElementIDPR_REM_SPRRABOTA(void)
{
return Object->ElementIDPR_REM_SPRRABOTA;
}
//---------------------------------------------------------------
void TREM_DMSprProducerRabotaImpl::set_ElementIDPR_REM_SPRRABOTA(TFIBLargeIntField * ElementIDPR_REM_SPRRABOTA)
{
Object->ElementIDPR_REM_SPRRABOTA=ElementIDPR_REM_SPRRABOTA;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerRabotaImpl::get_ElementIDGRP_REM_SPRRABOTA(void)
{
return Object->ElementIDGRP_REM_SPRRABOTA;
}
//---------------------------------------------------------------
void TREM_DMSprProducerRabotaImpl::set_ElementIDGRP_REM_SPRRABOTA(TFIBLargeIntField * ElementIDGRP_REM_SPRRABOTA)
{
Object->ElementIDGRP_REM_SPRRABOTA=ElementIDGRP_REM_SPRRABOTA;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerRabotaImpl::get_ElementNAME_REM_SPRRABOTA(void)
{
return Object->ElementNAME_REM_SPRRABOTA;
}
//---------------------------------------------------------------
void TREM_DMSprProducerRabotaImpl::set_ElementNAME_REM_SPRRABOTA(TFIBWideStringField * ElementNAME_REM_SPRRABOTA)
{
Object->ElementNAME_REM_SPRRABOTA=ElementNAME_REM_SPRRABOTA;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerRabotaImpl::get_ElementNAME_ENG_REM_SPRRABOTA(void)
{
return Object->ElementNAME_ENG_REM_SPRRABOTA;
}
//---------------------------------------------------------------
void TREM_DMSprProducerRabotaImpl::set_ElementNAME_ENG_REM_SPRRABOTA(TFIBWideStringField * ElementNAME_ENG_REM_SPRRABOTA)
{
Object->ElementNAME_ENG_REM_SPRRABOTA=ElementNAME_ENG_REM_SPRRABOTA;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerRabotaImpl::get_ElementCODE_REM_SPRRABOTA(void)
{
return Object->ElementCODE_REM_SPRRABOTA;
}
//---------------------------------------------------------------
void TREM_DMSprProducerRabotaImpl::set_ElementCODE_REM_SPRRABOTA(TFIBWideStringField * ElementCODE_REM_SPRRABOTA)
{
Object->ElementCODE_REM_SPRRABOTA=ElementCODE_REM_SPRRABOTA;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMSprProducerRabotaImpl::get_ElementLEVEL_REM_SPRRABOTA(void)
{
return Object->ElementLEVEL_REM_SPRRABOTA;
}
//---------------------------------------------------------------
void TREM_DMSprProducerRabotaImpl::set_ElementLEVEL_REM_SPRRABOTA(TFIBIntegerField * ElementLEVEL_REM_SPRRABOTA)
{
Object->ElementLEVEL_REM_SPRRABOTA=ElementLEVEL_REM_SPRRABOTA;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMSprProducerRabotaImpl::get_ElementTYPECLIENT_REM_SPRRABOTA(void)
{
return Object->ElementTYPECLIENT_REM_SPRRABOTA;
}
//---------------------------------------------------------------
void TREM_DMSprProducerRabotaImpl::set_ElementTYPECLIENT_REM_SPRRABOTA(TFIBIntegerField * ElementTYPECLIENT_REM_SPRRABOTA)
{
Object->ElementTYPECLIENT_REM_SPRRABOTA=ElementTYPECLIENT_REM_SPRRABOTA;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMSprProducerRabotaImpl::get_ElementTYPEPRODUCT_REM_SPRRABOTA(void)
{
return Object->ElementTYPEPRODUCT_REM_SPRRABOTA;
}
//---------------------------------------------------------------
void TREM_DMSprProducerRabotaImpl::set_ElementTYPEPRODUCT_REM_SPRRABOTA(TFIBIntegerField * ElementTYPEPRODUCT_REM_SPRRABOTA)
{
Object->ElementTYPEPRODUCT_REM_SPRRABOTA=ElementTYPEPRODUCT_REM_SPRRABOTA;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerRabotaImpl::get_ElementLEVEL_STR_REM_SPRRABOTA(void)
{
return Object->ElementLEVEL_STR_REM_SPRRABOTA;
}
//---------------------------------------------------------------
void TREM_DMSprProducerRabotaImpl::set_ElementLEVEL_STR_REM_SPRRABOTA(TFIBWideStringField * ElementLEVEL_STR_REM_SPRRABOTA)
{
Object->ElementLEVEL_STR_REM_SPRRABOTA=ElementLEVEL_STR_REM_SPRRABOTA;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerRabotaImpl::get_ElementIDNOM_REM_SPRRABOTA(void)
{
return Object->ElementIDNOM_REM_SPRRABOTA;
}
//---------------------------------------------------------------
void TREM_DMSprProducerRabotaImpl::set_ElementIDNOM_REM_SPRRABOTA(TFIBLargeIntField * ElementIDNOM_REM_SPRRABOTA)
{
Object->ElementIDNOM_REM_SPRRABOTA=ElementIDNOM_REM_SPRRABOTA;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerRabotaImpl::get_ElementNAMENOM(void)
{
return Object->ElementNAMENOM;
}
//---------------------------------------------------------------
void TREM_DMSprProducerRabotaImpl::set_ElementNAMENOM(TFIBWideStringField * ElementNAMENOM)
{
Object->ElementNAMENOM=ElementNAMENOM;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMSprProducerRabotaImpl::get_Query(void)
{
return Object->Query;
}
//---------------------------------------------------------------
void TREM_DMSprProducerRabotaImpl::set_Query(TpFIBQuery * Query)
{
Object->Query=Query;
}
//---------------------------------------------------------------
__int64 TREM_DMSprProducerRabotaImpl::get_IdGroupElement(void)
{
return Object->IdGroupElement;
}
//---------------------------------------------------------------
void TREM_DMSprProducerRabotaImpl::set_IdGroupElement(__int64 IdGroupElement)
{
Object->IdGroupElement=IdGroupElement;
}
//---------------------------------------------------------------
__int64 TREM_DMSprProducerRabotaImpl::get_IdGrp(void)
{
return Object->IdGrp;
}
//---------------------------------------------------------------
void TREM_DMSprProducerRabotaImpl::set_IdGrp(__int64 IdGrp)
{
Object->IdGrp=IdGrp;
}
//---------------------------------------------------------------
bool TREM_DMSprProducerRabotaImpl::get_AllElement(void)
{
return Object->AllElement;
}
//---------------------------------------------------------------
void TREM_DMSprProducerRabotaImpl::set_AllElement(bool AllElement)
{
Object->AllElement=AllElement;
}
//---------------------------------------------------------------
void TREM_DMSprProducerRabotaImpl::OpenTable(__int64 id_group_element, __int64 id_grp, bool all)
{
return Object->OpenTable(id_group_element,id_grp,all);
}
//---------------------------------------------------------------
bool TREM_DMSprProducerRabotaImpl::NewElement(__int64 id_group_element, __int64 id_grp)
{
return Object->NewElement(id_group_element,id_grp);
}
//---------------------------------------------------------------
bool TREM_DMSprProducerRabotaImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
bool TREM_DMSprProducerRabotaImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
bool TREM_DMSprProducerRabotaImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
void TREM_DMSprProducerRabotaImpl::ChancheGrp(__int64 id_new_grp,__int64 id_element)
{
return Object->ChancheGrp(id_new_grp,id_element);
}
//---------------------------------------------------------------
__int64 TREM_DMSprProducerRabotaImpl::FindPoCodu(__int64 id_group_element, UnicodeString code)
{
return Object->FindPoCodu(id_group_element,code);
}
//---------------------------------------------------------------
__int64 TREM_DMSprProducerRabotaImpl::FindPoName(__int64 id_group_element, UnicodeString name)
{
return Object->FindPoName(id_group_element,name);
}
//---------------------------------------------------------------
__int64 TREM_DMSprProducerRabotaImpl::FindPoNameEng(__int64 id_group_element, UnicodeString name)
{
return Object->FindPoNameEng(id_group_element, name);
}
//---------------------------------------------------------------
__int64 TREM_DMSprProducerRabotaImpl::GetIdGrp(__int64 id_el)
{
return Object->GetIdGrp(id_el);
}
//---------------------------------------------------------------
