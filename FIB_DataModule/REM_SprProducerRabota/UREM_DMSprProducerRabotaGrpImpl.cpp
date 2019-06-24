#include "vcl.h"
#pragma hdrstop


#include "UREM_DMSprProducerRabotaGrpImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_DMSprProducerRabotaGrpImpl::TREM_DMSprProducerRabotaGrpImpl()           
{                                            
Object=new TREM_DMSprProducerRabotaGrp(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_DMSprProducerRabotaGrpImpl::~TREM_DMSprProducerRabotaGrpImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_DMSprProducerRabotaGrpImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_DMSprProducerRabotaGrpImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_DMSprProducerRabotaGrp)                        
   {                                                                     
   *ppv=static_cast<IREM_DMSprProducerRabotaGrp*> (this);                                
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
int TREM_DMSprProducerRabotaGrpImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_DMSprProducerRabotaGrpImpl::kanRelease(void)                                  
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
int  TREM_DMSprProducerRabotaGrpImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMSprProducerRabotaGrpImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_DMSprProducerRabotaGrpImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMSprProducerRabotaGrpImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_DMSprProducerRabotaGrpImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_DMSprProducerRabotaGrpImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_DMSprProducerRabotaGrpImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IREM_DMSprProducerRabotaGrp
TDataSource * TREM_DMSprProducerRabotaGrpImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TREM_DMSprProducerRabotaGrpImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TREM_DMSprProducerRabotaGrpImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TREM_DMSprProducerRabotaGrpImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMSprProducerRabotaGrpImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TREM_DMSprProducerRabotaGrpImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMSprProducerRabotaGrpImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TREM_DMSprProducerRabotaGrpImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMSprProducerRabotaGrpImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TREM_DMSprProducerRabotaGrpImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMSprProducerRabotaGrpImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TREM_DMSprProducerRabotaGrpImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TIntegerField * TREM_DMSprProducerRabotaGrpImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TREM_DMSprProducerRabotaGrpImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerRabotaGrpImpl::get_TableID_REM_SPRRABOTA_GRP(void)
{
return Object->TableID_REM_SPRRABOTA_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprProducerRabotaGrpImpl::set_TableID_REM_SPRRABOTA_GRP(TFIBLargeIntField * TableID_REM_SPRRABOTA_GRP)
{
Object->TableID_REM_SPRRABOTA_GRP=TableID_REM_SPRRABOTA_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerRabotaGrpImpl::get_TableIDBASE_REM_SPRRABOTA_GRP(void)
{
return Object->TableIDBASE_REM_SPRRABOTA_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprProducerRabotaGrpImpl::set_TableIDBASE_REM_SPRRABOTA_GRP(TFIBLargeIntField * TableIDBASE_REM_SPRRABOTA_GRP)
{
Object->TableIDBASE_REM_SPRRABOTA_GRP=TableIDBASE_REM_SPRRABOTA_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerRabotaGrpImpl::get_TableGID_REM_SPRRABOTA_GRP(void)
{
return Object->TableGID_REM_SPRRABOTA_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprProducerRabotaGrpImpl::set_TableGID_REM_SPRRABOTA_GRP(TFIBWideStringField * TableGID_REM_SPRRABOTA_GRP)
{
Object->TableGID_REM_SPRRABOTA_GRP=TableGID_REM_SPRRABOTA_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerRabotaGrpImpl::get_TableIDPR_REM_SPRRABOTA_GRP(void)
{
return Object->TableIDPR_REM_SPRRABOTA_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprProducerRabotaGrpImpl::set_TableIDPR_REM_SPRRABOTA_GRP(TFIBLargeIntField * TableIDPR_REM_SPRRABOTA_GRP)
{
Object->TableIDPR_REM_SPRRABOTA_GRP=TableIDPR_REM_SPRRABOTA_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerRabotaGrpImpl::get_TableIDGRP_REM_SPRRABOTA_GRP(void)
{
return Object->TableIDGRP_REM_SPRRABOTA_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprProducerRabotaGrpImpl::set_TableIDGRP_REM_SPRRABOTA_GRP(TFIBLargeIntField * TableIDGRP_REM_SPRRABOTA_GRP)
{
Object->TableIDGRP_REM_SPRRABOTA_GRP=TableIDGRP_REM_SPRRABOTA_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerRabotaGrpImpl::get_TableNAME_REM_SPRRABOTA_GRP(void)
{
return Object->TableNAME_REM_SPRRABOTA_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprProducerRabotaGrpImpl::set_TableNAME_REM_SPRRABOTA_GRP(TFIBWideStringField * TableNAME_REM_SPRRABOTA_GRP)
{
Object->TableNAME_REM_SPRRABOTA_GRP=TableNAME_REM_SPRRABOTA_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerRabotaGrpImpl::get_TableNAME_ENG_REM_SPRRABOTA_GRP(void)
{
return Object->TableNAME_ENG_REM_SPRRABOTA_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprProducerRabotaGrpImpl::set_TableNAME_ENG_REM_SPRRABOTA_GRP(TFIBWideStringField * TableNAME_ENG_REM_SPRRABOTA_GRP)
{
Object->TableNAME_ENG_REM_SPRRABOTA_GRP=TableNAME_ENG_REM_SPRRABOTA_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerRabotaGrpImpl::get_ElementID_REM_SPRRABOTA_GRP(void)
{
return Object->ElementID_REM_SPRRABOTA_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprProducerRabotaGrpImpl::set_ElementID_REM_SPRRABOTA_GRP(TFIBLargeIntField * ElementID_REM_SPRRABOTA_GRP)
{
Object->ElementID_REM_SPRRABOTA_GRP=ElementID_REM_SPRRABOTA_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerRabotaGrpImpl::get_ElementIDBASE_REM_SPRRABOTA_GRP(void)
{
return Object->ElementIDBASE_REM_SPRRABOTA_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprProducerRabotaGrpImpl::set_ElementIDBASE_REM_SPRRABOTA_GRP(TFIBLargeIntField * ElementIDBASE_REM_SPRRABOTA_GRP)
{
Object->ElementIDBASE_REM_SPRRABOTA_GRP=ElementIDBASE_REM_SPRRABOTA_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerRabotaGrpImpl::get_ElementGID_REM_SPRRABOTA_GRP(void)
{
return Object->ElementGID_REM_SPRRABOTA_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprProducerRabotaGrpImpl::set_ElementGID_REM_SPRRABOTA_GRP(TFIBWideStringField * ElementGID_REM_SPRRABOTA_GRP)
{
Object->ElementGID_REM_SPRRABOTA_GRP=ElementGID_REM_SPRRABOTA_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerRabotaGrpImpl::get_ElementIDPR_REM_SPRRABOTA_GRP(void)
{
return Object->ElementIDPR_REM_SPRRABOTA_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprProducerRabotaGrpImpl::set_ElementIDPR_REM_SPRRABOTA_GRP(TFIBLargeIntField * ElementIDPR_REM_SPRRABOTA_GRP)
{
Object->ElementIDPR_REM_SPRRABOTA_GRP=ElementIDPR_REM_SPRRABOTA_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerRabotaGrpImpl::get_ElementIDGRP_REM_SPRRABOTA_GRP(void)
{
return Object->ElementIDGRP_REM_SPRRABOTA_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprProducerRabotaGrpImpl::set_ElementIDGRP_REM_SPRRABOTA_GRP(TFIBLargeIntField * ElementIDGRP_REM_SPRRABOTA_GRP)
{
Object->ElementIDGRP_REM_SPRRABOTA_GRP=ElementIDGRP_REM_SPRRABOTA_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerRabotaGrpImpl::get_ElementNAME_REM_SPRRABOTA_GRP(void)
{
return Object->ElementNAME_REM_SPRRABOTA_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprProducerRabotaGrpImpl::set_ElementNAME_REM_SPRRABOTA_GRP(TFIBWideStringField * ElementNAME_REM_SPRRABOTA_GRP)
{
Object->ElementNAME_REM_SPRRABOTA_GRP=ElementNAME_REM_SPRRABOTA_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerRabotaGrpImpl::get_ElementNAME_ENG_REM_SPRRABOTA_GRP(void)
{
return Object->ElementNAME_ENG_REM_SPRRABOTA_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprProducerRabotaGrpImpl::set_ElementNAME_ENG_REM_SPRRABOTA_GRP(TFIBWideStringField * ElementNAME_ENG_REM_SPRRABOTA_GRP)
{
Object->ElementNAME_ENG_REM_SPRRABOTA_GRP=ElementNAME_ENG_REM_SPRRABOTA_GRP;
}
//---------------------------------------------------------------
__int64 TREM_DMSprProducerRabotaGrpImpl::get_IdGroupElement(void)
{
return Object->IdGroupElement;
}
//---------------------------------------------------------------
void TREM_DMSprProducerRabotaGrpImpl::set_IdGroupElement(__int64 IdGroupElement)
{
Object->IdGroupElement=IdGroupElement;
}
//---------------------------------------------------------------
void TREM_DMSprProducerRabotaGrpImpl::OpenTable(__int64 id_group_element)
{
return Object->OpenTable(id_group_element);
}
//---------------------------------------------------------------
int TREM_DMSprProducerRabotaGrpImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
bool TREM_DMSprProducerRabotaGrpImpl::NewElement(__int64 id_group_element, __int64 id_grp)
{
return Object->NewElement(id_group_element,id_grp);
}
//---------------------------------------------------------------
bool TREM_DMSprProducerRabotaGrpImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TREM_DMSprProducerRabotaGrpImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
