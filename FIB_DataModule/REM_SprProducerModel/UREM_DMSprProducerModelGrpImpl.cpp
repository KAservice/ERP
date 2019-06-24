#include "vcl.h"
#pragma hdrstop


#include "UREM_DMSprProducerModelGrpImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_DMSprProducerModelGrpImpl::TREM_DMSprProducerModelGrpImpl()           
{                                            
Object=new TREM_DMSprProducerModelGrp(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_DMSprProducerModelGrpImpl::~TREM_DMSprProducerModelGrpImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_DMSprProducerModelGrpImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_DMSprProducerModelGrpImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_DMSprProducerModelGrp)                        
   {                                                                     
   *ppv=static_cast<IREM_DMSprProducerModelGrp*> (this);                                
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
int TREM_DMSprProducerModelGrpImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_DMSprProducerModelGrpImpl::kanRelease(void)                                  
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
int  TREM_DMSprProducerModelGrpImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMSprProducerModelGrpImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_DMSprProducerModelGrpImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMSprProducerModelGrpImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_DMSprProducerModelGrpImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_DMSprProducerModelGrpImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_DMSprProducerModelGrpImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IREM_DMSprProducerModelGrp
TDataSource * TREM_DMSprProducerModelGrpImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelGrpImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TREM_DMSprProducerModelGrpImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelGrpImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMSprProducerModelGrpImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelGrpImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMSprProducerModelGrpImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelGrpImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMSprProducerModelGrpImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelGrpImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMSprProducerModelGrpImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelGrpImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TIntegerField * TREM_DMSprProducerModelGrpImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelGrpImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerModelGrpImpl::get_TableID_REM_SPRMODEL_GRP(void)
{
return Object->TableID_REM_SPRMODEL_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelGrpImpl::set_TableID_REM_SPRMODEL_GRP(TFIBLargeIntField * TableID_REM_SPRMODEL_GRP)
{
Object->TableID_REM_SPRMODEL_GRP=TableID_REM_SPRMODEL_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerModelGrpImpl::get_TableIDBASE_REM_SPRMODEL_GRP(void)
{
return Object->TableIDBASE_REM_SPRMODEL_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelGrpImpl::set_TableIDBASE_REM_SPRMODEL_GRP(TFIBLargeIntField * TableIDBASE_REM_SPRMODEL_GRP)
{
Object->TableIDBASE_REM_SPRMODEL_GRP=TableIDBASE_REM_SPRMODEL_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerModelGrpImpl::get_TableGID_REM_SPRMODEL_GRP(void)
{
return Object->TableGID_REM_SPRMODEL_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelGrpImpl::set_TableGID_REM_SPRMODEL_GRP(TFIBWideStringField * TableGID_REM_SPRMODEL_GRP)
{
Object->TableGID_REM_SPRMODEL_GRP=TableGID_REM_SPRMODEL_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerModelGrpImpl::get_TableIDPR_REM_SPRMODEL_GRP(void)
{
return Object->TableIDPR_REM_SPRMODEL_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelGrpImpl::set_TableIDPR_REM_SPRMODEL_GRP(TFIBLargeIntField * TableIDPR_REM_SPRMODEL_GRP)
{
Object->TableIDPR_REM_SPRMODEL_GRP=TableIDPR_REM_SPRMODEL_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerModelGrpImpl::get_TableIDGRP_REM_SPRMODEL_GRP(void)
{
return Object->TableIDGRP_REM_SPRMODEL_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelGrpImpl::set_TableIDGRP_REM_SPRMODEL_GRP(TFIBLargeIntField * TableIDGRP_REM_SPRMODEL_GRP)
{
Object->TableIDGRP_REM_SPRMODEL_GRP=TableIDGRP_REM_SPRMODEL_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerModelGrpImpl::get_TableNAME_REM_SPRMODEL_GRP(void)
{
return Object->TableNAME_REM_SPRMODEL_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelGrpImpl::set_TableNAME_REM_SPRMODEL_GRP(TFIBWideStringField * TableNAME_REM_SPRMODEL_GRP)
{
Object->TableNAME_REM_SPRMODEL_GRP=TableNAME_REM_SPRMODEL_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerModelGrpImpl::get_ElementID_REM_SPRMODEL_GRP(void)
{
return Object->ElementID_REM_SPRMODEL_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelGrpImpl::set_ElementID_REM_SPRMODEL_GRP(TFIBLargeIntField * ElementID_REM_SPRMODEL_GRP)
{
Object->ElementID_REM_SPRMODEL_GRP=ElementID_REM_SPRMODEL_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerModelGrpImpl::get_ElementIDBASE_REM_SPRMODEL_GRP(void)
{
return Object->ElementIDBASE_REM_SPRMODEL_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelGrpImpl::set_ElementIDBASE_REM_SPRMODEL_GRP(TFIBLargeIntField * ElementIDBASE_REM_SPRMODEL_GRP)
{
Object->ElementIDBASE_REM_SPRMODEL_GRP=ElementIDBASE_REM_SPRMODEL_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerModelGrpImpl::get_ElementGID_REM_SPRMODEL_GRP(void)
{
return Object->ElementGID_REM_SPRMODEL_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelGrpImpl::set_ElementGID_REM_SPRMODEL_GRP(TFIBWideStringField * ElementGID_REM_SPRMODEL_GRP)
{
Object->ElementGID_REM_SPRMODEL_GRP=ElementGID_REM_SPRMODEL_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerModelGrpImpl::get_ElementIDPR_REM_SPRMODEL_GRP(void)
{
return Object->ElementIDPR_REM_SPRMODEL_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelGrpImpl::set_ElementIDPR_REM_SPRMODEL_GRP(TFIBLargeIntField * ElementIDPR_REM_SPRMODEL_GRP)
{
Object->ElementIDPR_REM_SPRMODEL_GRP=ElementIDPR_REM_SPRMODEL_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerModelGrpImpl::get_ElementIDGRP_REM_SPRMODEL_GRP(void)
{
return Object->ElementIDGRP_REM_SPRMODEL_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelGrpImpl::set_ElementIDGRP_REM_SPRMODEL_GRP(TFIBLargeIntField * ElementIDGRP_REM_SPRMODEL_GRP)
{
Object->ElementIDGRP_REM_SPRMODEL_GRP=ElementIDGRP_REM_SPRMODEL_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerModelGrpImpl::get_ElementNAME_REM_SPRMODEL_GRP(void)
{
return Object->ElementNAME_REM_SPRMODEL_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelGrpImpl::set_ElementNAME_REM_SPRMODEL_GRP(TFIBWideStringField * ElementNAME_REM_SPRMODEL_GRP)
{
Object->ElementNAME_REM_SPRMODEL_GRP=ElementNAME_REM_SPRMODEL_GRP;
}
//---------------------------------------------------------------
__int64 TREM_DMSprProducerModelGrpImpl::get_IdGroupElement(void)
{
return Object->IdGroupElement;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelGrpImpl::set_IdGroupElement(__int64 IdGroupElement)
{
Object->IdGroupElement=IdGroupElement;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelGrpImpl::OpenTable(__int64 id_group_element)
{
return Object->OpenTable(id_group_element);
}
//---------------------------------------------------------------
int TREM_DMSprProducerModelGrpImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
bool TREM_DMSprProducerModelGrpImpl::NewElement(__int64 id_group_element, __int64 id_grp)
{
return Object->NewElement(id_group_element,id_grp);
}
//---------------------------------------------------------------
bool TREM_DMSprProducerModelGrpImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TREM_DMSprProducerModelGrpImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
