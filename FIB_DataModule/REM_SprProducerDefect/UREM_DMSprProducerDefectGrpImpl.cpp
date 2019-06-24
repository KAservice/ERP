#include "vcl.h"
#pragma hdrstop


#include "UREM_DMSprProducerDefectGrpImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_DMSprProducerDefectGrpImpl::TREM_DMSprProducerDefectGrpImpl()           
{                                            
Object=new TREM_DMSprProducerDefectGrp(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_DMSprProducerDefectGrpImpl::~TREM_DMSprProducerDefectGrpImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_DMSprProducerDefectGrpImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_DMSprProducerDefectGrpImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_DMSprProducerDefectGrp)                        
   {                                                                     
   *ppv=static_cast<IREM_DMSprProducerDefectGrp*> (this);                                
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
int TREM_DMSprProducerDefectGrpImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_DMSprProducerDefectGrpImpl::kanRelease(void)                                  
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
int  TREM_DMSprProducerDefectGrpImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMSprProducerDefectGrpImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_DMSprProducerDefectGrpImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMSprProducerDefectGrpImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_DMSprProducerDefectGrpImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_DMSprProducerDefectGrpImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_DMSprProducerDefectGrpImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IREM_DMSprProducerDefectGrp
TDataSource * TREM_DMSprProducerDefectGrpImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TREM_DMSprProducerDefectGrpImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TREM_DMSprProducerDefectGrpImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TREM_DMSprProducerDefectGrpImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMSprProducerDefectGrpImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TREM_DMSprProducerDefectGrpImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMSprProducerDefectGrpImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TREM_DMSprProducerDefectGrpImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMSprProducerDefectGrpImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TREM_DMSprProducerDefectGrpImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMSprProducerDefectGrpImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TREM_DMSprProducerDefectGrpImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TIntegerField * TREM_DMSprProducerDefectGrpImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TREM_DMSprProducerDefectGrpImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerDefectGrpImpl::get_TableID_REM_SPRDEFECT_GRP(void)
{
return Object->TableID_REM_SPRDEFECT_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprProducerDefectGrpImpl::set_TableID_REM_SPRDEFECT_GRP(TFIBLargeIntField * TableID_REM_SPRDEFECT_GRP)
{
Object->TableID_REM_SPRDEFECT_GRP=TableID_REM_SPRDEFECT_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerDefectGrpImpl::get_TableIDBASE_REM_SPRDEFECT_GRP(void)
{
return Object->TableIDBASE_REM_SPRDEFECT_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprProducerDefectGrpImpl::set_TableIDBASE_REM_SPRDEFECT_GRP(TFIBLargeIntField * TableIDBASE_REM_SPRDEFECT_GRP)
{
Object->TableIDBASE_REM_SPRDEFECT_GRP=TableIDBASE_REM_SPRDEFECT_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerDefectGrpImpl::get_TableGID_REM_SPRDEFECT_GRP(void)
{
return Object->TableGID_REM_SPRDEFECT_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprProducerDefectGrpImpl::set_TableGID_REM_SPRDEFECT_GRP(TFIBWideStringField * TableGID_REM_SPRDEFECT_GRP)
{
Object->TableGID_REM_SPRDEFECT_GRP=TableGID_REM_SPRDEFECT_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerDefectGrpImpl::get_TableIDPR_REM_SPRDEFECT_GRP(void)
{
return Object->TableIDPR_REM_SPRDEFECT_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprProducerDefectGrpImpl::set_TableIDPR_REM_SPRDEFECT_GRP(TFIBLargeIntField * TableIDPR_REM_SPRDEFECT_GRP)
{
Object->TableIDPR_REM_SPRDEFECT_GRP=TableIDPR_REM_SPRDEFECT_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerDefectGrpImpl::get_TableIDGRP_REM_SPRDEFECT_GRP(void)
{
return Object->TableIDGRP_REM_SPRDEFECT_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprProducerDefectGrpImpl::set_TableIDGRP_REM_SPRDEFECT_GRP(TFIBLargeIntField * TableIDGRP_REM_SPRDEFECT_GRP)
{
Object->TableIDGRP_REM_SPRDEFECT_GRP=TableIDGRP_REM_SPRDEFECT_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerDefectGrpImpl::get_TableNAME_REM_SPRDEFECT_GRP(void)
{
return Object->TableNAME_REM_SPRDEFECT_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprProducerDefectGrpImpl::set_TableNAME_REM_SPRDEFECT_GRP(TFIBWideStringField * TableNAME_REM_SPRDEFECT_GRP)
{
Object->TableNAME_REM_SPRDEFECT_GRP=TableNAME_REM_SPRDEFECT_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerDefectGrpImpl::get_ElementID_REM_SPRDEFECT_GRP(void)
{
return Object->ElementID_REM_SPRDEFECT_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprProducerDefectGrpImpl::set_ElementID_REM_SPRDEFECT_GRP(TFIBLargeIntField * ElementID_REM_SPRDEFECT_GRP)
{
Object->ElementID_REM_SPRDEFECT_GRP=ElementID_REM_SPRDEFECT_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerDefectGrpImpl::get_ElementIDBASE_REM_SPRDEFECT_GRP(void)
{
return Object->ElementIDBASE_REM_SPRDEFECT_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprProducerDefectGrpImpl::set_ElementIDBASE_REM_SPRDEFECT_GRP(TFIBLargeIntField * ElementIDBASE_REM_SPRDEFECT_GRP)
{
Object->ElementIDBASE_REM_SPRDEFECT_GRP=ElementIDBASE_REM_SPRDEFECT_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerDefectGrpImpl::get_ElementGID_REM_SPRDEFECT_GRP(void)
{
return Object->ElementGID_REM_SPRDEFECT_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprProducerDefectGrpImpl::set_ElementGID_REM_SPRDEFECT_GRP(TFIBWideStringField * ElementGID_REM_SPRDEFECT_GRP)
{
Object->ElementGID_REM_SPRDEFECT_GRP=ElementGID_REM_SPRDEFECT_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerDefectGrpImpl::get_ElementIDPR_REM_SPRDEFECT_GRP(void)
{
return Object->ElementIDPR_REM_SPRDEFECT_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprProducerDefectGrpImpl::set_ElementIDPR_REM_SPRDEFECT_GRP(TFIBLargeIntField * ElementIDPR_REM_SPRDEFECT_GRP)
{
Object->ElementIDPR_REM_SPRDEFECT_GRP=ElementIDPR_REM_SPRDEFECT_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerDefectGrpImpl::get_ElementIDGRP_REM_SPRDEFECT_GRP(void)
{
return Object->ElementIDGRP_REM_SPRDEFECT_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprProducerDefectGrpImpl::set_ElementIDGRP_REM_SPRDEFECT_GRP(TFIBLargeIntField * ElementIDGRP_REM_SPRDEFECT_GRP)
{
Object->ElementIDGRP_REM_SPRDEFECT_GRP=ElementIDGRP_REM_SPRDEFECT_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerDefectGrpImpl::get_ElementNAME_REM_SPRDEFECT_GRP(void)
{
return Object->ElementNAME_REM_SPRDEFECT_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprProducerDefectGrpImpl::set_ElementNAME_REM_SPRDEFECT_GRP(TFIBWideStringField * ElementNAME_REM_SPRDEFECT_GRP)
{
Object->ElementNAME_REM_SPRDEFECT_GRP=ElementNAME_REM_SPRDEFECT_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerDefectGrpImpl::get_TableNAME_ENG_REM_SPRDEFECT_GRP(void)
{
return Object->TableNAME_ENG_REM_SPRDEFECT_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprProducerDefectGrpImpl::set_TableNAME_ENG_REM_SPRDEFECT_GRP(TFIBWideStringField * TableNAME_ENG_REM_SPRDEFECT_GRP)
{
Object->TableNAME_ENG_REM_SPRDEFECT_GRP=TableNAME_ENG_REM_SPRDEFECT_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerDefectGrpImpl::get_ElementNAME_ENG_REM_SPRDEFECT_GRP(void)
{
return Object->ElementNAME_ENG_REM_SPRDEFECT_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprProducerDefectGrpImpl::set_ElementNAME_ENG_REM_SPRDEFECT_GRP(TFIBWideStringField * ElementNAME_ENG_REM_SPRDEFECT_GRP)
{
Object->ElementNAME_ENG_REM_SPRDEFECT_GRP=ElementNAME_ENG_REM_SPRDEFECT_GRP;
}
//---------------------------------------------------------------
__int64 TREM_DMSprProducerDefectGrpImpl::get_IdGroupElement(void)
{
return Object->IdGroupElement;
}
//---------------------------------------------------------------
void TREM_DMSprProducerDefectGrpImpl::set_IdGroupElement(__int64 IdGroupElement)
{
Object->IdGroupElement=IdGroupElement;
}
//---------------------------------------------------------------
void TREM_DMSprProducerDefectGrpImpl::OpenTable(__int64 id_group_element)
{
return Object->OpenTable(id_group_element);
}
//---------------------------------------------------------------
int TREM_DMSprProducerDefectGrpImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
bool TREM_DMSprProducerDefectGrpImpl::NewElement(__int64 id_group_element, __int64 id_grp)
{
return Object->NewElement(id_group_element,id_grp);
}
//---------------------------------------------------------------
bool TREM_DMSprProducerDefectGrpImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TREM_DMSprProducerDefectGrpImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
