#include "vcl.h"
#pragma hdrstop


#include "UREM_DMSprNeisprImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_DMSprNeisprImpl::TREM_DMSprNeisprImpl()           
{                                            
Object=new TREM_DMSprNeispr(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_DMSprNeisprImpl::~TREM_DMSprNeisprImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_DMSprNeisprImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_DMSprNeisprImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_DMSprNeispr)                        
   {                                                                     
   *ppv=static_cast<IREM_DMSprNeispr*> (this);                                
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
int TREM_DMSprNeisprImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_DMSprNeisprImpl::kanRelease(void)                                  
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
int  TREM_DMSprNeisprImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMSprNeisprImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_DMSprNeisprImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMSprNeisprImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_DMSprNeisprImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_DMSprNeisprImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_DMSprNeisprImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IREM_DMSprNeispr
TDataSource * TREM_DMSprNeisprImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TREM_DMSprNeisprImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TREM_DMSprNeisprImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TREM_DMSprNeisprImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMSprNeisprImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TREM_DMSprNeisprImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMSprNeisprImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TREM_DMSprNeisprImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMSprNeisprImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TREM_DMSprNeisprImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMSprNeisprImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TREM_DMSprNeisprImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMSprNeisprImpl::get_pFIBQuery(void)
{
return Object->pFIBQuery;
}
//---------------------------------------------------------------
void TREM_DMSprNeisprImpl::set_pFIBQuery(TpFIBQuery * pFIBQuery)
{
Object->pFIBQuery=pFIBQuery;
}
//---------------------------------------------------------------
TIntegerField * TREM_DMSprNeisprImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TREM_DMSprNeisprImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprNeisprImpl::get_TableID_REM_SNEISPR(void)
{
return Object->TableID_REM_SNEISPR;
}
//---------------------------------------------------------------
void TREM_DMSprNeisprImpl::set_TableID_REM_SNEISPR(TFIBLargeIntField * TableID_REM_SNEISPR)
{
Object->TableID_REM_SNEISPR=TableID_REM_SNEISPR;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprNeisprImpl::get_TableGID_REM_SNEISPR(void)
{
return Object->TableGID_REM_SNEISPR;
}
//---------------------------------------------------------------
void TREM_DMSprNeisprImpl::set_TableGID_REM_SNEISPR(TFIBWideStringField * TableGID_REM_SNEISPR)
{
Object->TableGID_REM_SNEISPR=TableGID_REM_SNEISPR;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprNeisprImpl::get_TableIDGRP_REM_SNEISPR(void)
{
return Object->TableIDGRP_REM_SNEISPR;
}
//---------------------------------------------------------------
void TREM_DMSprNeisprImpl::set_TableIDGRP_REM_SNEISPR(TFIBLargeIntField * TableIDGRP_REM_SNEISPR)
{
Object->TableIDGRP_REM_SNEISPR=TableIDGRP_REM_SNEISPR;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprNeisprImpl::get_TableNAME_REM_SNEISPR(void)
{
return Object->TableNAME_REM_SNEISPR;
}
//---------------------------------------------------------------
void TREM_DMSprNeisprImpl::set_TableNAME_REM_SNEISPR(TFIBWideStringField * TableNAME_REM_SNEISPR)
{
Object->TableNAME_REM_SNEISPR=TableNAME_REM_SNEISPR;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprNeisprImpl::get_TableIDBASE_REM_SNEISPR(void)
{
return Object->TableIDBASE_REM_SNEISPR;
}
//---------------------------------------------------------------
void TREM_DMSprNeisprImpl::set_TableIDBASE_REM_SNEISPR(TFIBLargeIntField * TableIDBASE_REM_SNEISPR)
{
Object->TableIDBASE_REM_SNEISPR=TableIDBASE_REM_SNEISPR;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprNeisprImpl::get_ElementID_REM_SNEISPR(void)
{
return Object->ElementID_REM_SNEISPR;
}
//---------------------------------------------------------------
void TREM_DMSprNeisprImpl::set_ElementID_REM_SNEISPR(TFIBLargeIntField * ElementID_REM_SNEISPR)
{
Object->ElementID_REM_SNEISPR=ElementID_REM_SNEISPR;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprNeisprImpl::get_ElementGID_REM_SNEISPR(void)
{
return Object->ElementGID_REM_SNEISPR;
}
//---------------------------------------------------------------
void TREM_DMSprNeisprImpl::set_ElementGID_REM_SNEISPR(TFIBWideStringField * ElementGID_REM_SNEISPR)
{
Object->ElementGID_REM_SNEISPR=ElementGID_REM_SNEISPR;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprNeisprImpl::get_ElementIDGRP_REM_SNEISPR(void)
{
return Object->ElementIDGRP_REM_SNEISPR;
}
//---------------------------------------------------------------
void TREM_DMSprNeisprImpl::set_ElementIDGRP_REM_SNEISPR(TFIBLargeIntField * ElementIDGRP_REM_SNEISPR)
{
Object->ElementIDGRP_REM_SNEISPR=ElementIDGRP_REM_SNEISPR;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprNeisprImpl::get_ElementNAME_REM_SNEISPR(void)
{
return Object->ElementNAME_REM_SNEISPR;
}
//---------------------------------------------------------------
void TREM_DMSprNeisprImpl::set_ElementNAME_REM_SNEISPR(TFIBWideStringField * ElementNAME_REM_SNEISPR)
{
Object->ElementNAME_REM_SNEISPR=ElementNAME_REM_SNEISPR;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprNeisprImpl::get_ElementIDBASE_REM_SNEISPR(void)
{
return Object->ElementIDBASE_REM_SNEISPR;
}
//---------------------------------------------------------------
void TREM_DMSprNeisprImpl::set_ElementIDBASE_REM_SNEISPR(TFIBLargeIntField * ElementIDBASE_REM_SNEISPR)
{
Object->ElementIDBASE_REM_SNEISPR=ElementIDBASE_REM_SNEISPR;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprNeisprImpl::get_TableNAME_ENG_REM_SNEISPR(void)
{
return Object->TableNAME_ENG_REM_SNEISPR;
}
//---------------------------------------------------------------
void TREM_DMSprNeisprImpl::set_TableNAME_ENG_REM_SNEISPR(TFIBWideStringField * TableNAME_ENG_REM_SNEISPR)
{
Object->TableNAME_ENG_REM_SNEISPR=TableNAME_ENG_REM_SNEISPR;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprNeisprImpl::get_ElementNAME_ENG_REM_SNEISPR(void)
{
return Object->ElementNAME_ENG_REM_SNEISPR;
}
//---------------------------------------------------------------
void TREM_DMSprNeisprImpl::set_ElementNAME_ENG_REM_SNEISPR(TFIBWideStringField * ElementNAME_ENG_REM_SNEISPR)
{
Object->ElementNAME_ENG_REM_SNEISPR=ElementNAME_ENG_REM_SNEISPR;
}
//---------------------------------------------------------------
__int64 TREM_DMSprNeisprImpl::get_IdGrp(void)
{
return Object->IdGrp;
}
//---------------------------------------------------------------
void TREM_DMSprNeisprImpl::set_IdGrp(__int64 IdGrp)
{
Object->IdGrp=IdGrp;
}
//---------------------------------------------------------------
bool TREM_DMSprNeisprImpl::get_AllElement(void)
{
return Object->AllElement;
}
//---------------------------------------------------------------
void TREM_DMSprNeisprImpl::set_AllElement(bool AllElement)
{
Object->AllElement=AllElement;
}
//---------------------------------------------------------------
UnicodeString TREM_DMSprNeisprImpl::GetTextQuery(__int64 id_grp, bool all)
{
return Object->GetTextQuery(id_grp,all);
}
//---------------------------------------------------------------
void TREM_DMSprNeisprImpl::OpenTable(__int64 id_grp, bool all)
{
return Object->OpenTable(id_grp,all);
}
//---------------------------------------------------------------
int TREM_DMSprNeisprImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
bool TREM_DMSprNeisprImpl::NewElement(__int64 id_grp)
{
return Object->NewElement(id_grp);
}
//---------------------------------------------------------------
bool TREM_DMSprNeisprImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TREM_DMSprNeisprImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
void TREM_DMSprNeisprImpl::ChancheGrp(__int64 id_new_grp)
{
return Object->ChancheGrp(id_new_grp);
}
//---------------------------------------------------------------
__int64 TREM_DMSprNeisprImpl::GetIDElement(UnicodeString gid)
{
return Object->GetIDElement(gid);
}
//---------------------------------------------------------------
UnicodeString TREM_DMSprNeisprImpl::GetGIDElement(__int64 id)
{
return Object->GetGIDElement(id);
}
//---------------------------------------------------------------
__int64 TREM_DMSprNeisprImpl::GetIdGrpNom(__int64 id)
{
return Object->GetIdGrpNom(id);
}
//---------------------------------------------------------------
