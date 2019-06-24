#include "vcl.h"
#pragma hdrstop


#include "UREM_DMSprTypUslovImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_DMSprTypUslovImpl::TREM_DMSprTypUslovImpl()           
{                                            
Object=new TREM_DMSprTypUslov(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_DMSprTypUslovImpl::~TREM_DMSprTypUslovImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_DMSprTypUslovImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_DMSprTypUslovImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_DMSprTypUslov)                        
   {                                                                     
   *ppv=static_cast<IREM_DMSprTypUslov*> (this);                                
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
int TREM_DMSprTypUslovImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_DMSprTypUslovImpl::kanRelease(void)                                  
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
int  TREM_DMSprTypUslovImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMSprTypUslovImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_DMSprTypUslovImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMSprTypUslovImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_DMSprTypUslovImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_DMSprTypUslovImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_DMSprTypUslovImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IREM_DMSprTypUslov
TDataSource * TREM_DMSprTypUslovImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TREM_DMSprTypUslovImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TREM_DMSprTypUslovImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TREM_DMSprTypUslovImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMSprTypUslovImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TREM_DMSprTypUslovImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMSprTypUslovImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TREM_DMSprTypUslovImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMSprTypUslovImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TREM_DMSprTypUslovImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMSprTypUslovImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TREM_DMSprTypUslovImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMSprTypUslovImpl::get_pFIBQuery(void)
{
return Object->pFIBQuery;
}
//---------------------------------------------------------------
void TREM_DMSprTypUslovImpl::set_pFIBQuery(TpFIBQuery * pFIBQuery)
{
Object->pFIBQuery=pFIBQuery;
}
//---------------------------------------------------------------
TIntegerField * TREM_DMSprTypUslovImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TREM_DMSprTypUslovImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprTypUslovImpl::get_TableID_REM_STYPUSLOV(void)
{
return Object->TableID_REM_STYPUSLOV;
}
//---------------------------------------------------------------
void TREM_DMSprTypUslovImpl::set_TableID_REM_STYPUSLOV(TFIBLargeIntField * TableID_REM_STYPUSLOV)
{
Object->TableID_REM_STYPUSLOV=TableID_REM_STYPUSLOV;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprTypUslovImpl::get_TableGID_REM_STYPUSLOV(void)
{
return Object->TableGID_REM_STYPUSLOV;
}
//---------------------------------------------------------------
void TREM_DMSprTypUslovImpl::set_TableGID_REM_STYPUSLOV(TFIBWideStringField * TableGID_REM_STYPUSLOV)
{
Object->TableGID_REM_STYPUSLOV=TableGID_REM_STYPUSLOV;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprTypUslovImpl::get_TableIDGRP_REM_STYPUSLOV(void)
{
return Object->TableIDGRP_REM_STYPUSLOV;
}
//---------------------------------------------------------------
void TREM_DMSprTypUslovImpl::set_TableIDGRP_REM_STYPUSLOV(TFIBLargeIntField * TableIDGRP_REM_STYPUSLOV)
{
Object->TableIDGRP_REM_STYPUSLOV=TableIDGRP_REM_STYPUSLOV;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprTypUslovImpl::get_TableNAME_REM_STYPUSLOV(void)
{
return Object->TableNAME_REM_STYPUSLOV;
}
//---------------------------------------------------------------
void TREM_DMSprTypUslovImpl::set_TableNAME_REM_STYPUSLOV(TFIBWideStringField * TableNAME_REM_STYPUSLOV)
{
Object->TableNAME_REM_STYPUSLOV=TableNAME_REM_STYPUSLOV;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprTypUslovImpl::get_TableDESCR_REM_STYPUSLOV(void)
{
return Object->TableDESCR_REM_STYPUSLOV;
}
//---------------------------------------------------------------
void TREM_DMSprTypUslovImpl::set_TableDESCR_REM_STYPUSLOV(TFIBWideStringField * TableDESCR_REM_STYPUSLOV)
{
Object->TableDESCR_REM_STYPUSLOV=TableDESCR_REM_STYPUSLOV;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprTypUslovImpl::get_ElementID_REM_STYPUSLOV(void)
{
return Object->ElementID_REM_STYPUSLOV;
}
//---------------------------------------------------------------
void TREM_DMSprTypUslovImpl::set_ElementID_REM_STYPUSLOV(TFIBLargeIntField * ElementID_REM_STYPUSLOV)
{
Object->ElementID_REM_STYPUSLOV=ElementID_REM_STYPUSLOV;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprTypUslovImpl::get_ElementGID_REM_STYPUSLOV(void)
{
return Object->ElementGID_REM_STYPUSLOV;
}
//---------------------------------------------------------------
void TREM_DMSprTypUslovImpl::set_ElementGID_REM_STYPUSLOV(TFIBWideStringField * ElementGID_REM_STYPUSLOV)
{
Object->ElementGID_REM_STYPUSLOV=ElementGID_REM_STYPUSLOV;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprTypUslovImpl::get_ElementIDBASE_REM_STYPUSLOV(void)
{
return Object->ElementIDBASE_REM_STYPUSLOV;
}
//---------------------------------------------------------------
void TREM_DMSprTypUslovImpl::set_ElementIDBASE_REM_STYPUSLOV(TFIBLargeIntField * ElementIDBASE_REM_STYPUSLOV)
{
Object->ElementIDBASE_REM_STYPUSLOV=ElementIDBASE_REM_STYPUSLOV;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprTypUslovImpl::get_ElementIDGRP_REM_STYPUSLOV(void)
{
return Object->ElementIDGRP_REM_STYPUSLOV;
}
//---------------------------------------------------------------
void TREM_DMSprTypUslovImpl::set_ElementIDGRP_REM_STYPUSLOV(TFIBLargeIntField * ElementIDGRP_REM_STYPUSLOV)
{
Object->ElementIDGRP_REM_STYPUSLOV=ElementIDGRP_REM_STYPUSLOV;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprTypUslovImpl::get_ElementNAME_REM_STYPUSLOV(void)
{
return Object->ElementNAME_REM_STYPUSLOV;
}
//---------------------------------------------------------------
void TREM_DMSprTypUslovImpl::set_ElementNAME_REM_STYPUSLOV(TFIBWideStringField * ElementNAME_REM_STYPUSLOV)
{
Object->ElementNAME_REM_STYPUSLOV=ElementNAME_REM_STYPUSLOV;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprTypUslovImpl::get_ElementDESCR_REM_STYPUSLOV(void)
{
return Object->ElementDESCR_REM_STYPUSLOV;
}
//---------------------------------------------------------------
void TREM_DMSprTypUslovImpl::set_ElementDESCR_REM_STYPUSLOV(TFIBWideStringField * ElementDESCR_REM_STYPUSLOV)
{
Object->ElementDESCR_REM_STYPUSLOV=ElementDESCR_REM_STYPUSLOV;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprTypUslovImpl::get_TableNAME_ENG_REM_STYPUSLOV(void)
{
return Object->TableNAME_ENG_REM_STYPUSLOV;
}
//---------------------------------------------------------------
void TREM_DMSprTypUslovImpl::set_TableNAME_ENG_REM_STYPUSLOV(TFIBWideStringField * TableNAME_ENG_REM_STYPUSLOV)
{
Object->TableNAME_ENG_REM_STYPUSLOV=TableNAME_ENG_REM_STYPUSLOV;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprTypUslovImpl::get_ElementNAME_ENG_REM_STYPUSLOV(void)
{
return Object->ElementNAME_ENG_REM_STYPUSLOV;
}
//---------------------------------------------------------------
void TREM_DMSprTypUslovImpl::set_ElementNAME_ENG_REM_STYPUSLOV(TFIBWideStringField * ElementNAME_ENG_REM_STYPUSLOV)
{
Object->ElementNAME_ENG_REM_STYPUSLOV=ElementNAME_ENG_REM_STYPUSLOV;
}
//---------------------------------------------------------------
__int64 TREM_DMSprTypUslovImpl::get_IdGrp(void)
{
return Object->IdGrp;
}
//---------------------------------------------------------------
void TREM_DMSprTypUslovImpl::set_IdGrp(__int64 IdGrp)
{
Object->IdGrp=IdGrp;
}
//---------------------------------------------------------------
bool TREM_DMSprTypUslovImpl::get_AllElement(void)
{
return Object->AllElement;
}
//---------------------------------------------------------------
void TREM_DMSprTypUslovImpl::set_AllElement(bool AllElement)
{
Object->AllElement=AllElement;
}
//---------------------------------------------------------------
UnicodeString TREM_DMSprTypUslovImpl::GetTextQuery(__int64 id_grp, bool all)
{
return Object->GetTextQuery(id_grp,all);
}
//---------------------------------------------------------------
void TREM_DMSprTypUslovImpl::OpenTable(__int64 id_grp, bool all)
{
return Object->OpenTable(id_grp,all);
}
//---------------------------------------------------------------
int TREM_DMSprTypUslovImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
bool TREM_DMSprTypUslovImpl::NewElement(__int64 id_grp)
{
return Object->NewElement(id_grp);
}
//---------------------------------------------------------------
bool TREM_DMSprTypUslovImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TREM_DMSprTypUslovImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
void TREM_DMSprTypUslovImpl::ChancheGrp(__int64 id_new_grp, __int64 id_el)
{
return Object->ChancheGrp(id_new_grp, id_el);
}
//---------------------------------------------------------------
__int64 TREM_DMSprTypUslovImpl::GetIdGrpTypUsla(__int64 id)
{
return Object->GetIdGrpTypUsla(id);
}
//---------------------------------------------------------------
