#include "vcl.h"
#pragma hdrstop


#include "UREM_DMSprTypDefectImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_DMSprTypDefectImpl::TREM_DMSprTypDefectImpl()           
{                                            
Object=new TREM_DMSprTypDefect(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_DMSprTypDefectImpl::~TREM_DMSprTypDefectImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_DMSprTypDefectImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_DMSprTypDefectImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_DMSprTypDefect)                        
   {                                                                     
   *ppv=static_cast<IREM_DMSprTypDefect*> (this);                                
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
int TREM_DMSprTypDefectImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_DMSprTypDefectImpl::kanRelease(void)                                  
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
int  TREM_DMSprTypDefectImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMSprTypDefectImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_DMSprTypDefectImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMSprTypDefectImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_DMSprTypDefectImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_DMSprTypDefectImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_DMSprTypDefectImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IREM_DMSprTypDefect
TDataSource * TREM_DMSprTypDefectImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TREM_DMSprTypDefectImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TREM_DMSprTypDefectImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TREM_DMSprTypDefectImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMSprTypDefectImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TREM_DMSprTypDefectImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMSprTypDefectImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TREM_DMSprTypDefectImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMSprTypDefectImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TREM_DMSprTypDefectImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMSprTypDefectImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TREM_DMSprTypDefectImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMSprTypDefectImpl::get_pFIBQuery(void)
{
return Object->pFIBQuery;
}
//---------------------------------------------------------------
void TREM_DMSprTypDefectImpl::set_pFIBQuery(TpFIBQuery * pFIBQuery)
{
Object->pFIBQuery=pFIBQuery;
}
//---------------------------------------------------------------
TIntegerField * TREM_DMSprTypDefectImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TREM_DMSprTypDefectImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprTypDefectImpl::get_TableID_REM_STYPDEFECT(void)
{
return Object->TableID_REM_STYPDEFECT;
}
//---------------------------------------------------------------
void TREM_DMSprTypDefectImpl::set_TableID_REM_STYPDEFECT(TFIBLargeIntField * TableID_REM_STYPDEFECT)
{
Object->TableID_REM_STYPDEFECT=TableID_REM_STYPDEFECT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprTypDefectImpl::get_TableGID_REM_STYPDEFECT(void)
{
return Object->TableGID_REM_STYPDEFECT;
}
//---------------------------------------------------------------
void TREM_DMSprTypDefectImpl::set_TableGID_REM_STYPDEFECT(TFIBWideStringField * TableGID_REM_STYPDEFECT)
{
Object->TableGID_REM_STYPDEFECT=TableGID_REM_STYPDEFECT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprTypDefectImpl::get_TableNAME_REM_STYPDEFECT(void)
{
return Object->TableNAME_REM_STYPDEFECT;
}
//---------------------------------------------------------------
void TREM_DMSprTypDefectImpl::set_TableNAME_REM_STYPDEFECT(TFIBWideStringField * TableNAME_REM_STYPDEFECT)
{
Object->TableNAME_REM_STYPDEFECT=TableNAME_REM_STYPDEFECT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprTypDefectImpl::get_TableCODE_REM_STYPDEFECT(void)
{
return Object->TableCODE_REM_STYPDEFECT;
}
//---------------------------------------------------------------
void TREM_DMSprTypDefectImpl::set_TableCODE_REM_STYPDEFECT(TFIBWideStringField * TableCODE_REM_STYPDEFECT)
{
Object->TableCODE_REM_STYPDEFECT=TableCODE_REM_STYPDEFECT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprTypDefectImpl::get_TableDESCR_REM_STYPDEFECT(void)
{
return Object->TableDESCR_REM_STYPDEFECT;
}
//---------------------------------------------------------------
void TREM_DMSprTypDefectImpl::set_TableDESCR_REM_STYPDEFECT(TFIBWideStringField * TableDESCR_REM_STYPDEFECT)
{
Object->TableDESCR_REM_STYPDEFECT=TableDESCR_REM_STYPDEFECT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprTypDefectImpl::get_TableIDGRP_REM_STYPDEFECT(void)
{
return Object->TableIDGRP_REM_STYPDEFECT;
}
//---------------------------------------------------------------
void TREM_DMSprTypDefectImpl::set_TableIDGRP_REM_STYPDEFECT(TFIBLargeIntField * TableIDGRP_REM_STYPDEFECT)
{
Object->TableIDGRP_REM_STYPDEFECT=TableIDGRP_REM_STYPDEFECT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprTypDefectImpl::get_ElementID_REM_STYPDEFECT(void)
{
return Object->ElementID_REM_STYPDEFECT;
}
//---------------------------------------------------------------
void TREM_DMSprTypDefectImpl::set_ElementID_REM_STYPDEFECT(TFIBLargeIntField * ElementID_REM_STYPDEFECT)
{
Object->ElementID_REM_STYPDEFECT=ElementID_REM_STYPDEFECT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprTypDefectImpl::get_ElementGID_REM_STYPDEFECT(void)
{
return Object->ElementGID_REM_STYPDEFECT;
}
//---------------------------------------------------------------
void TREM_DMSprTypDefectImpl::set_ElementGID_REM_STYPDEFECT(TFIBWideStringField * ElementGID_REM_STYPDEFECT)
{
Object->ElementGID_REM_STYPDEFECT=ElementGID_REM_STYPDEFECT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprTypDefectImpl::get_ElementIDBASE_REM_STYPDEFECT(void)
{
return Object->ElementIDBASE_REM_STYPDEFECT;
}
//---------------------------------------------------------------
void TREM_DMSprTypDefectImpl::set_ElementIDBASE_REM_STYPDEFECT(TFIBLargeIntField * ElementIDBASE_REM_STYPDEFECT)
{
Object->ElementIDBASE_REM_STYPDEFECT=ElementIDBASE_REM_STYPDEFECT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprTypDefectImpl::get_ElementNAME_REM_STYPDEFECT(void)
{
return Object->ElementNAME_REM_STYPDEFECT;
}
//---------------------------------------------------------------
void TREM_DMSprTypDefectImpl::set_ElementNAME_REM_STYPDEFECT(TFIBWideStringField * ElementNAME_REM_STYPDEFECT)
{
Object->ElementNAME_REM_STYPDEFECT=ElementNAME_REM_STYPDEFECT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprTypDefectImpl::get_ElementCODE_REM_STYPDEFECT(void)
{
return Object->ElementCODE_REM_STYPDEFECT;
}
//---------------------------------------------------------------
void TREM_DMSprTypDefectImpl::set_ElementCODE_REM_STYPDEFECT(TFIBWideStringField * ElementCODE_REM_STYPDEFECT)
{
Object->ElementCODE_REM_STYPDEFECT=ElementCODE_REM_STYPDEFECT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprTypDefectImpl::get_ElementDESCR_REM_STYPDEFECT(void)
{
return Object->ElementDESCR_REM_STYPDEFECT;
}
//---------------------------------------------------------------
void TREM_DMSprTypDefectImpl::set_ElementDESCR_REM_STYPDEFECT(TFIBWideStringField * ElementDESCR_REM_STYPDEFECT)
{
Object->ElementDESCR_REM_STYPDEFECT=ElementDESCR_REM_STYPDEFECT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprTypDefectImpl::get_ElementIDGRP_REM_STYPDEFECT(void)
{
return Object->ElementIDGRP_REM_STYPDEFECT;
}
//---------------------------------------------------------------
void TREM_DMSprTypDefectImpl::set_ElementIDGRP_REM_STYPDEFECT(TFIBLargeIntField * ElementIDGRP_REM_STYPDEFECT)
{
Object->ElementIDGRP_REM_STYPDEFECT=ElementIDGRP_REM_STYPDEFECT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprTypDefectImpl::get_TableNAME_ENG_REM_STYPDEFECT(void)
{
return Object->TableNAME_ENG_REM_STYPDEFECT;
}
//---------------------------------------------------------------
void TREM_DMSprTypDefectImpl::set_TableNAME_ENG_REM_STYPDEFECT(TFIBWideStringField * TableNAME_ENG_REM_STYPDEFECT)
{
Object->TableNAME_ENG_REM_STYPDEFECT=TableNAME_ENG_REM_STYPDEFECT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprTypDefectImpl::get_ElementNAME_ENG_REM_STYPDEFECT(void)
{
return Object->ElementNAME_ENG_REM_STYPDEFECT;
}
//---------------------------------------------------------------
void TREM_DMSprTypDefectImpl::set_ElementNAME_ENG_REM_STYPDEFECT(TFIBWideStringField * ElementNAME_ENG_REM_STYPDEFECT)
{
Object->ElementNAME_ENG_REM_STYPDEFECT=ElementNAME_ENG_REM_STYPDEFECT;
}
//---------------------------------------------------------------
__int64 TREM_DMSprTypDefectImpl::get_IdGrp(void)
{
return Object->IdGrp;
}
//---------------------------------------------------------------
void TREM_DMSprTypDefectImpl::set_IdGrp(__int64 IdGrp)
{
Object->IdGrp=IdGrp;
}
//---------------------------------------------------------------
bool TREM_DMSprTypDefectImpl::get_AllElement(void)
{
return Object->AllElement;
}
//---------------------------------------------------------------
void TREM_DMSprTypDefectImpl::set_AllElement(bool AllElement)
{
Object->AllElement=AllElement;
}
//---------------------------------------------------------------
UnicodeString TREM_DMSprTypDefectImpl::GetTextQuery(__int64 id_grp, bool all)
{
return Object->GetTextQuery(id_grp,all);
}
//---------------------------------------------------------------
void TREM_DMSprTypDefectImpl::OpenTable(__int64 id_grp, bool all)
{
return Object->OpenTable(id_grp,all);
}
//---------------------------------------------------------------
int TREM_DMSprTypDefectImpl::OpenElement(__int64 id)
{
return Object->OpenElement( id);
}
//---------------------------------------------------------------
bool TREM_DMSprTypDefectImpl::NewElement(__int64 id_grp)
{
return Object->NewElement(id_grp);
}
//---------------------------------------------------------------
bool TREM_DMSprTypDefectImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TREM_DMSprTypDefectImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
void TREM_DMSprTypDefectImpl::ChancheGrp(__int64 id_new_grp, __int64 id_el)
{
return Object->ChancheGrp(id_new_grp,id_el);
}
//---------------------------------------------------------------
__int64 TREM_DMSprTypDefectImpl::GetIdGrpNom(__int64 id)
{
return Object->GetIdGrpNom(id);
}
//---------------------------------------------------------------
