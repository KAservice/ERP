#include "vcl.h"
#pragma hdrstop


#include "UREM_DMSprModel2GrpImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_DMSprModel2GrpImpl::TREM_DMSprModel2GrpImpl()           
{                                            
Object=new TREM_DMSprModel2Grp(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_DMSprModel2GrpImpl::~TREM_DMSprModel2GrpImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_DMSprModel2GrpImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_DMSprModel2GrpImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_DMSprModel2Grp)                        
   {                                                                     
   *ppv=static_cast<IREM_DMSprModel2Grp*> (this);                                
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
int TREM_DMSprModel2GrpImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_DMSprModel2GrpImpl::kanRelease(void)                                  
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
int  TREM_DMSprModel2GrpImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMSprModel2GrpImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_DMSprModel2GrpImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMSprModel2GrpImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_DMSprModel2GrpImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_DMSprModel2GrpImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_DMSprModel2GrpImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IREM_DMSprModel2Grp
TDataSource * TREM_DMSprModel2GrpImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TREM_DMSprModel2GrpImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TREM_DMSprModel2GrpImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TREM_DMSprModel2GrpImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMSprModel2GrpImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TREM_DMSprModel2GrpImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMSprModel2GrpImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TREM_DMSprModel2GrpImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMSprModel2GrpImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TREM_DMSprModel2GrpImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMSprModel2GrpImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TREM_DMSprModel2GrpImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TIntegerField * TREM_DMSprModel2GrpImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TREM_DMSprModel2GrpImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprModel2GrpImpl::get_TableID_REM_SMODEL2_GRP(void)
{
return Object->TableID_REM_SMODEL2_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprModel2GrpImpl::set_TableID_REM_SMODEL2_GRP(TFIBLargeIntField * TableID_REM_SMODEL2_GRP)
{
Object->TableID_REM_SMODEL2_GRP=TableID_REM_SMODEL2_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprModel2GrpImpl::get_TableGID_REM_SMODEL2_GRP(void)
{
return Object->TableGID_REM_SMODEL2_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprModel2GrpImpl::set_TableGID_REM_SMODEL2_GRP(TFIBWideStringField * TableGID_REM_SMODEL2_GRP)
{
Object->TableGID_REM_SMODEL2_GRP=TableGID_REM_SMODEL2_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprModel2GrpImpl::get_TableIDBASE_REM_SMODEL2_GRP(void)
{
return Object->TableIDBASE_REM_SMODEL2_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprModel2GrpImpl::set_TableIDBASE_REM_SMODEL2_GRP(TFIBLargeIntField * TableIDBASE_REM_SMODEL2_GRP)
{
Object->TableIDBASE_REM_SMODEL2_GRP=TableIDBASE_REM_SMODEL2_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprModel2GrpImpl::get_TableIDGRP_REM_SMODEL2_GRP(void)
{
return Object->TableIDGRP_REM_SMODEL2_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprModel2GrpImpl::set_TableIDGRP_REM_SMODEL2_GRP(TFIBLargeIntField * TableIDGRP_REM_SMODEL2_GRP)
{
Object->TableIDGRP_REM_SMODEL2_GRP=TableIDGRP_REM_SMODEL2_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprModel2GrpImpl::get_TableNAME_REM_SMODEL2_GRP(void)
{
return Object->TableNAME_REM_SMODEL2_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprModel2GrpImpl::set_TableNAME_REM_SMODEL2_GRP(TFIBWideStringField * TableNAME_REM_SMODEL2_GRP)
{
Object->TableNAME_REM_SMODEL2_GRP=TableNAME_REM_SMODEL2_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprModel2GrpImpl::get_TableIDTYPEDEV_REM_SMODEL2_GRP(void)
{
return Object->TableIDTYPEDEV_REM_SMODEL2_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprModel2GrpImpl::set_TableIDTYPEDEV_REM_SMODEL2_GRP(TFIBLargeIntField * TableIDTYPEDEV_REM_SMODEL2_GRP)
{
Object->TableIDTYPEDEV_REM_SMODEL2_GRP=TableIDTYPEDEV_REM_SMODEL2_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprModel2GrpImpl::get_ElementID_REM_SMODEL2_GRP(void)
{
return Object->ElementID_REM_SMODEL2_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprModel2GrpImpl::set_ElementID_REM_SMODEL2_GRP(TFIBLargeIntField * ElementID_REM_SMODEL2_GRP)
{
Object->ElementID_REM_SMODEL2_GRP=ElementID_REM_SMODEL2_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprModel2GrpImpl::get_ElementGID_REM_SMODEL2_GRP(void)
{
return Object->ElementGID_REM_SMODEL2_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprModel2GrpImpl::set_ElementGID_REM_SMODEL2_GRP(TFIBWideStringField * ElementGID_REM_SMODEL2_GRP)
{
Object->ElementGID_REM_SMODEL2_GRP=ElementGID_REM_SMODEL2_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprModel2GrpImpl::get_ElementIDBASE_REM_SMODEL2_GRP(void)
{
return Object->ElementIDBASE_REM_SMODEL2_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprModel2GrpImpl::set_ElementIDBASE_REM_SMODEL2_GRP(TFIBLargeIntField * ElementIDBASE_REM_SMODEL2_GRP)
{
Object->ElementIDBASE_REM_SMODEL2_GRP=ElementIDBASE_REM_SMODEL2_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprModel2GrpImpl::get_ElementIDGRP_REM_SMODEL2_GRP(void)
{
return Object->ElementIDGRP_REM_SMODEL2_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprModel2GrpImpl::set_ElementIDGRP_REM_SMODEL2_GRP(TFIBLargeIntField * ElementIDGRP_REM_SMODEL2_GRP)
{
Object->ElementIDGRP_REM_SMODEL2_GRP=ElementIDGRP_REM_SMODEL2_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprModel2GrpImpl::get_ElementNAME_REM_SMODEL2_GRP(void)
{
return Object->ElementNAME_REM_SMODEL2_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprModel2GrpImpl::set_ElementNAME_REM_SMODEL2_GRP(TFIBWideStringField * ElementNAME_REM_SMODEL2_GRP)
{
Object->ElementNAME_REM_SMODEL2_GRP=ElementNAME_REM_SMODEL2_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprModel2GrpImpl::get_ElementIDTYPEDEV_REM_SMODEL2_GRP(void)
{
return Object->ElementIDTYPEDEV_REM_SMODEL2_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprModel2GrpImpl::set_ElementIDTYPEDEV_REM_SMODEL2_GRP(TFIBLargeIntField * ElementIDTYPEDEV_REM_SMODEL2_GRP)
{
Object->ElementIDTYPEDEV_REM_SMODEL2_GRP=ElementIDTYPEDEV_REM_SMODEL2_GRP;
}
//---------------------------------------------------------------
__int64 TREM_DMSprModel2GrpImpl::get_IdGroupElement(void)
{
return Object->IdGroupElement;
}
//---------------------------------------------------------------
void TREM_DMSprModel2GrpImpl::set_IdGroupElement(__int64 IdGroupElement)
{
Object->IdGroupElement=IdGroupElement;
}
//---------------------------------------------------------------
__int64 TREM_DMSprModel2GrpImpl::get_IdGrp(void)
{
return Object->IdGrp;
}
//---------------------------------------------------------------
void TREM_DMSprModel2GrpImpl::set_IdGrp(__int64 IdGrp)
{
Object->IdGrp=IdGrp;
}
//---------------------------------------------------------------
__int64 TREM_DMSprModel2GrpImpl::get_IdElement(void)
{
return Object->IdElement;
}
//---------------------------------------------------------------
void TREM_DMSprModel2GrpImpl::set_IdElement(__int64 IdElement)
{
Object->IdElement=IdElement;
}
//---------------------------------------------------------------
bool TREM_DMSprModel2GrpImpl::get_AllElement(void)
{
return Object->AllElement;
}
//---------------------------------------------------------------
void TREM_DMSprModel2GrpImpl::set_AllElement(bool AllElement)
{
Object->AllElement=AllElement;
}
//---------------------------------------------------------------
bool TREM_DMSprModel2GrpImpl::OpenTable(__int64 id_group_element)
{
return Object->OpenTable(id_group_element);
}
//---------------------------------------------------------------
bool TREM_DMSprModel2GrpImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
bool TREM_DMSprModel2GrpImpl::NewElement(__int64 id_group_element, __int64 id_grp)
{
return Object->NewElement(id_group_element,id_grp);
}
//---------------------------------------------------------------
bool TREM_DMSprModel2GrpImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TREM_DMSprModel2GrpImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
