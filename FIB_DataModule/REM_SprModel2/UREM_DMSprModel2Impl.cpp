#include "vcl.h"
#pragma hdrstop


#include "UREM_DMSprModel2Impl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_DMSprModel2Impl::TREM_DMSprModel2Impl()           
{                                            
Object=new TREM_DMSprModel2(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_DMSprModel2Impl::~TREM_DMSprModel2Impl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_DMSprModel2Impl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_DMSprModel2Impl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_DMSprModel2)                        
   {                                                                     
   *ppv=static_cast<IREM_DMSprModel2*> (this);                                
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
int TREM_DMSprModel2Impl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_DMSprModel2Impl::kanRelease(void)                                  
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
int  TREM_DMSprModel2Impl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMSprModel2Impl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_DMSprModel2Impl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMSprModel2Impl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_DMSprModel2Impl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_DMSprModel2Impl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_DMSprModel2Impl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IREM_DMSprModel2
TDataSource * TREM_DMSprModel2Impl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TREM_DMSprModel2Impl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TREM_DMSprModel2Impl::get_DataSourcePodr(void)
{
return Object->DataSourcePodr;
}
//---------------------------------------------------------------
void TREM_DMSprModel2Impl::set_DataSourcePodr(TDataSource * DataSourcePodr)
{
Object->DataSourcePodr=DataSourcePodr;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMSprModel2Impl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TREM_DMSprModel2Impl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMSprModel2Impl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TREM_DMSprModel2Impl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMSprModel2Impl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TREM_DMSprModel2Impl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TIntegerField * TREM_DMSprModel2Impl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TREM_DMSprModel2Impl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMSprModel2Impl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TREM_DMSprModel2Impl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprModel2Impl::get_TableID_REM_SMODEL2(void)
{
return Object->TableID_REM_SMODEL2;
}
//---------------------------------------------------------------
void TREM_DMSprModel2Impl::set_TableID_REM_SMODEL2(TFIBLargeIntField * TableID_REM_SMODEL2)
{
Object->TableID_REM_SMODEL2=TableID_REM_SMODEL2;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprModel2Impl::get_TableGID_REM_SMODEL2(void)
{
return Object->TableGID_REM_SMODEL2;
}
//---------------------------------------------------------------
void TREM_DMSprModel2Impl::set_TableGID_REM_SMODEL2(TFIBWideStringField * TableGID_REM_SMODEL2)
{
Object->TableGID_REM_SMODEL2=TableGID_REM_SMODEL2;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprModel2Impl::get_TableIDBASE_REM_SMODEL2(void)
{
return Object->TableIDBASE_REM_SMODEL2;
}
//---------------------------------------------------------------
void TREM_DMSprModel2Impl::set_TableIDBASE_REM_SMODEL2(TFIBLargeIntField * TableIDBASE_REM_SMODEL2)
{
Object->TableIDBASE_REM_SMODEL2=TableIDBASE_REM_SMODEL2;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprModel2Impl::get_TableNAME_REM_SMODEL2(void)
{
return Object->TableNAME_REM_SMODEL2;
}
//---------------------------------------------------------------
void TREM_DMSprModel2Impl::set_TableNAME_REM_SMODEL2(TFIBWideStringField * TableNAME_REM_SMODEL2)
{
Object->TableNAME_REM_SMODEL2=TableNAME_REM_SMODEL2;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprModel2Impl::get_TableIDTYPEDEV_REM_SMODEL2(void)
{
return Object->TableIDTYPEDEV_REM_SMODEL2;
}
//---------------------------------------------------------------
void TREM_DMSprModel2Impl::set_TableIDTYPEDEV_REM_SMODEL2(TFIBLargeIntField * TableIDTYPEDEV_REM_SMODEL2)
{
Object->TableIDTYPEDEV_REM_SMODEL2=TableIDTYPEDEV_REM_SMODEL2;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprModel2Impl::get_TableIDMODEL_REM_SMODEL2(void)
{
return Object->TableIDMODEL_REM_SMODEL2;
}
//---------------------------------------------------------------
void TREM_DMSprModel2Impl::set_TableIDMODEL_REM_SMODEL2(TFIBLargeIntField * TableIDMODEL_REM_SMODEL2)
{
Object->TableIDMODEL_REM_SMODEL2=TableIDMODEL_REM_SMODEL2;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprModel2Impl::get_TableIDGRP_REM_SMODEL2(void)
{
return Object->TableIDGRP_REM_SMODEL2;
}
//---------------------------------------------------------------
void TREM_DMSprModel2Impl::set_TableIDGRP_REM_SMODEL2(TFIBLargeIntField * TableIDGRP_REM_SMODEL2)
{
Object->TableIDGRP_REM_SMODEL2=TableIDGRP_REM_SMODEL2;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprModel2Impl::get_TableSTRCODE_REM_SMODEL(void)
{
return Object->TableSTRCODE_REM_SMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprModel2Impl::set_TableSTRCODE_REM_SMODEL(TFIBWideStringField * TableSTRCODE_REM_SMODEL)
{
Object->TableSTRCODE_REM_SMODEL=TableSTRCODE_REM_SMODEL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprModel2Impl::get_TableNAME_REM_SMODEL(void)
{
return Object->TableNAME_REM_SMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprModel2Impl::set_TableNAME_REM_SMODEL(TFIBWideStringField * TableNAME_REM_SMODEL)
{
Object->TableNAME_REM_SMODEL=TableNAME_REM_SMODEL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprModel2Impl::get_ElementID_REM_SMODEL2(void)
{
return Object->ElementID_REM_SMODEL2;
}
//---------------------------------------------------------------
void TREM_DMSprModel2Impl::set_ElementID_REM_SMODEL2(TFIBLargeIntField * ElementID_REM_SMODEL2)
{
Object->ElementID_REM_SMODEL2=ElementID_REM_SMODEL2;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprModel2Impl::get_ElementGID_REM_SMODEL2(void)
{
return Object->ElementGID_REM_SMODEL2;
}
//---------------------------------------------------------------
void TREM_DMSprModel2Impl::set_ElementGID_REM_SMODEL2(TFIBWideStringField * ElementGID_REM_SMODEL2)
{
Object->ElementGID_REM_SMODEL2=ElementGID_REM_SMODEL2;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprModel2Impl::get_ElementIDBASE_REM_SMODEL2(void)
{
return Object->ElementIDBASE_REM_SMODEL2;
}
//---------------------------------------------------------------
void TREM_DMSprModel2Impl::set_ElementIDBASE_REM_SMODEL2(TFIBLargeIntField * ElementIDBASE_REM_SMODEL2)
{
Object->ElementIDBASE_REM_SMODEL2=ElementIDBASE_REM_SMODEL2;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprModel2Impl::get_ElementNAME_REM_SMODEL2(void)
{
return Object->ElementNAME_REM_SMODEL2;
}
//---------------------------------------------------------------
void TREM_DMSprModel2Impl::set_ElementNAME_REM_SMODEL2(TFIBWideStringField * ElementNAME_REM_SMODEL2)
{
Object->ElementNAME_REM_SMODEL2=ElementNAME_REM_SMODEL2;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprModel2Impl::get_ElementIDTYPEDEV_REM_SMODEL2(void)
{
return Object->ElementIDTYPEDEV_REM_SMODEL2;
}
//---------------------------------------------------------------
void TREM_DMSprModel2Impl::set_ElementIDTYPEDEV_REM_SMODEL2(TFIBLargeIntField * ElementIDTYPEDEV_REM_SMODEL2)
{
Object->ElementIDTYPEDEV_REM_SMODEL2=ElementIDTYPEDEV_REM_SMODEL2;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprModel2Impl::get_ElementIDMODEL_REM_SMODEL2(void)
{
return Object->ElementIDMODEL_REM_SMODEL2;
}
//---------------------------------------------------------------
void TREM_DMSprModel2Impl::set_ElementIDMODEL_REM_SMODEL2(TFIBLargeIntField * ElementIDMODEL_REM_SMODEL2)
{
Object->ElementIDMODEL_REM_SMODEL2=ElementIDMODEL_REM_SMODEL2;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprModel2Impl::get_ElementIDGRP_REM_SMODEL2(void)
{
return Object->ElementIDGRP_REM_SMODEL2;
}
//---------------------------------------------------------------
void TREM_DMSprModel2Impl::set_ElementIDGRP_REM_SMODEL2(TFIBLargeIntField * ElementIDGRP_REM_SMODEL2)
{
Object->ElementIDGRP_REM_SMODEL2=ElementIDGRP_REM_SMODEL2;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprModel2Impl::get_ElementSTRCODE_REM_SMODEL(void)
{
return Object->ElementSTRCODE_REM_SMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprModel2Impl::set_ElementSTRCODE_REM_SMODEL(TFIBWideStringField * ElementSTRCODE_REM_SMODEL)
{
Object->ElementSTRCODE_REM_SMODEL=ElementSTRCODE_REM_SMODEL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprModel2Impl::get_ElementNAME_REM_SMODEL(void)
{
return Object->ElementNAME_REM_SMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprModel2Impl::set_ElementNAME_REM_SMODEL(TFIBWideStringField * ElementNAME_REM_SMODEL)
{
Object->ElementNAME_REM_SMODEL=ElementNAME_REM_SMODEL;
}
//---------------------------------------------------------------
__int64 TREM_DMSprModel2Impl::get_IdGroupElement(void)
{
return Object->IdGroupElement;
}
//---------------------------------------------------------------
void TREM_DMSprModel2Impl::set_IdGroupElement(__int64 IdGroupElement)
{
Object->IdGroupElement=IdGroupElement;
}
//---------------------------------------------------------------
__int64 TREM_DMSprModel2Impl::get_IdGrp(void)
{
return Object->IdGrp;
}
//---------------------------------------------------------------
void TREM_DMSprModel2Impl::set_IdGrp(__int64 IdGrp)
{
Object->IdGrp=IdGrp;
}
//---------------------------------------------------------------
__int64 TREM_DMSprModel2Impl::get_IdElement(void)
{
return Object->IdElement;
}
//---------------------------------------------------------------
void TREM_DMSprModel2Impl::set_IdElement(__int64 IdElement)
{
Object->IdElement=IdElement;
}
//---------------------------------------------------------------
bool TREM_DMSprModel2Impl::get_AllElement(void)
{
return Object->AllElement;
}
//---------------------------------------------------------------
void TREM_DMSprModel2Impl::set_AllElement(bool AllElement)
{
Object->AllElement=AllElement;
}
//---------------------------------------------------------------
bool TREM_DMSprModel2Impl::NewElement(__int64 id_group_element, __int64 id_grp)
{
return Object->NewElement(id_group_element,id_grp);
}
//---------------------------------------------------------------
bool TREM_DMSprModel2Impl::InsertElement(__int64 id_group_element, __int64 id_grp, __int64 id_model)
{
return Object->InsertElement(id_group_element,id_grp,id_model);
}
//---------------------------------------------------------------
bool TREM_DMSprModel2Impl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
bool TREM_DMSprModel2Impl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
bool TREM_DMSprModel2Impl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TREM_DMSprModel2Impl::ChancheGrp(__int64 id_new_grp,__int64 id_element)
{
return Object->ChancheGrp(id_new_grp,id_element);
}
//---------------------------------------------------------------
bool TREM_DMSprModel2Impl::OpenTable(__int64 id_group_element, __int64 id_grp, bool all)
{
return Object->OpenTable(id_group_element,id_grp,all);
}
//---------------------------------------------------------------
bool TREM_DMSprModel2Impl::TableSaveIsmen(void)
{
return Object->TableSaveIsmen();
}
//---------------------------------------------------------------
bool TREM_DMSprModel2Impl::TableCancelIsmen(void)
{
return Object->TableCancelIsmen();
}
//---------------------------------------------------------------
bool TREM_DMSprModel2Impl::TableNewElement(__int64 id_group_element, __int64 id_grp)
{
return Object->TableNewElement(id_group_element,id_grp);
}
//---------------------------------------------------------------
bool TREM_DMSprModel2Impl::TableAppend(void)
{
return Object->TableAppend();
}
//---------------------------------------------------------------
bool TREM_DMSprModel2Impl::TableDelete(void)
{
return Object->TableDelete();
}
//---------------------------------------------------------------
bool TREM_DMSprModel2Impl::TableEdit(void)
{
return Object->TableEdit();
}
//---------------------------------------------------------------
bool TREM_DMSprModel2Impl::TablePost(void)
{
return Object->TablePost();
}
//---------------------------------------------------------------
