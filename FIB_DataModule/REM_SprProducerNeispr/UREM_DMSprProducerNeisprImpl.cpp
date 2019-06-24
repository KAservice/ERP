#include "vcl.h"
#pragma hdrstop


#include "UREM_DMSprProducerNeisprImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_DMSprProducerNeisprImpl::TREM_DMSprProducerNeisprImpl()           
{                                            
Object=new TREM_DMSprProducerNeispr(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_DMSprProducerNeisprImpl::~TREM_DMSprProducerNeisprImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_DMSprProducerNeisprImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_DMSprProducerNeisprImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_DMSprProducerNeispr)                        
   {                                                                     
   *ppv=static_cast<IREM_DMSprProducerNeispr*> (this);                                
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
int TREM_DMSprProducerNeisprImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_DMSprProducerNeisprImpl::kanRelease(void)                                  
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
int  TREM_DMSprProducerNeisprImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMSprProducerNeisprImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_DMSprProducerNeisprImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMSprProducerNeisprImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_DMSprProducerNeisprImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_DMSprProducerNeisprImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_DMSprProducerNeisprImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IREM_DMSprProducerNeispr
TDataSource * TREM_DMSprProducerNeisprImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TREM_DMSprProducerNeisprImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMSprProducerNeisprImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TREM_DMSprProducerNeisprImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMSprProducerNeisprImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TREM_DMSprProducerNeisprImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMSprProducerNeisprImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TREM_DMSprProducerNeisprImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMSprProducerNeisprImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TREM_DMSprProducerNeisprImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TIntegerField * TREM_DMSprProducerNeisprImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TREM_DMSprProducerNeisprImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TDataSource * TREM_DMSprProducerNeisprImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TREM_DMSprProducerNeisprImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerNeisprImpl::get_TableID_REM_SPRNEISPR(void)
{
return Object->TableID_REM_SPRNEISPR;
}
//---------------------------------------------------------------
void TREM_DMSprProducerNeisprImpl::set_TableID_REM_SPRNEISPR(TFIBLargeIntField * TableID_REM_SPRNEISPR)
{
Object->TableID_REM_SPRNEISPR=TableID_REM_SPRNEISPR;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerNeisprImpl::get_TableCODE_REM_SPRNEISPR(void)
{
return Object->TableCODE_REM_SPRNEISPR;
}
//---------------------------------------------------------------
void TREM_DMSprProducerNeisprImpl::set_TableCODE_REM_SPRNEISPR(TFIBWideStringField * TableCODE_REM_SPRNEISPR)
{
Object->TableCODE_REM_SPRNEISPR=TableCODE_REM_SPRNEISPR;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerNeisprImpl::get_TableNAME_REM_SPRNEISPR(void)
{
return Object->TableNAME_REM_SPRNEISPR;
}
//---------------------------------------------------------------
void TREM_DMSprProducerNeisprImpl::set_TableNAME_REM_SPRNEISPR(TFIBWideStringField * TableNAME_REM_SPRNEISPR)
{
Object->TableNAME_REM_SPRNEISPR=TableNAME_REM_SPRNEISPR;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerNeisprImpl::get_TableNAME_REM_SNEISPR(void)
{
return Object->TableNAME_REM_SNEISPR;
}
//---------------------------------------------------------------
void TREM_DMSprProducerNeisprImpl::set_TableNAME_REM_SNEISPR(TFIBWideStringField * TableNAME_REM_SNEISPR)
{
Object->TableNAME_REM_SNEISPR=TableNAME_REM_SNEISPR;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerNeisprImpl::get_ElementID_REM_SPRNEISPR(void)
{
return Object->ElementID_REM_SPRNEISPR;
}
//---------------------------------------------------------------
void TREM_DMSprProducerNeisprImpl::set_ElementID_REM_SPRNEISPR(TFIBLargeIntField * ElementID_REM_SPRNEISPR)
{
Object->ElementID_REM_SPRNEISPR=ElementID_REM_SPRNEISPR;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerNeisprImpl::get_ElementIDBASE_REM_SPRNEISPR(void)
{
return Object->ElementIDBASE_REM_SPRNEISPR;
}
//---------------------------------------------------------------
void TREM_DMSprProducerNeisprImpl::set_ElementIDBASE_REM_SPRNEISPR(TFIBLargeIntField * ElementIDBASE_REM_SPRNEISPR)
{
Object->ElementIDBASE_REM_SPRNEISPR=ElementIDBASE_REM_SPRNEISPR;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerNeisprImpl::get_ElementGID_REM_SPRNEISPR(void)
{
return Object->ElementGID_REM_SPRNEISPR;
}
//---------------------------------------------------------------
void TREM_DMSprProducerNeisprImpl::set_ElementGID_REM_SPRNEISPR(TFIBWideStringField * ElementGID_REM_SPRNEISPR)
{
Object->ElementGID_REM_SPRNEISPR=ElementGID_REM_SPRNEISPR;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerNeisprImpl::get_ElementIDPR_REM_SPRNEISPR(void)
{
return Object->ElementIDPR_REM_SPRNEISPR;
}
//---------------------------------------------------------------
void TREM_DMSprProducerNeisprImpl::set_ElementIDPR_REM_SPRNEISPR(TFIBLargeIntField * ElementIDPR_REM_SPRNEISPR)
{
Object->ElementIDPR_REM_SPRNEISPR=ElementIDPR_REM_SPRNEISPR;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerNeisprImpl::get_ElementIDGRP_REM_SPRNEISPR(void)
{
return Object->ElementIDGRP_REM_SPRNEISPR;
}
//---------------------------------------------------------------
void TREM_DMSprProducerNeisprImpl::set_ElementIDGRP_REM_SPRNEISPR(TFIBLargeIntField * ElementIDGRP_REM_SPRNEISPR)
{
Object->ElementIDGRP_REM_SPRNEISPR=ElementIDGRP_REM_SPRNEISPR;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerNeisprImpl::get_ElementIDNEISPR_REM_SPRNEISPR(void)
{
return Object->ElementIDNEISPR_REM_SPRNEISPR;
}
//---------------------------------------------------------------
void TREM_DMSprProducerNeisprImpl::set_ElementIDNEISPR_REM_SPRNEISPR(TFIBLargeIntField * ElementIDNEISPR_REM_SPRNEISPR)
{
Object->ElementIDNEISPR_REM_SPRNEISPR=ElementIDNEISPR_REM_SPRNEISPR;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerNeisprImpl::get_ElementCODE_REM_SPRNEISPR(void)
{
return Object->ElementCODE_REM_SPRNEISPR;
}
//---------------------------------------------------------------
void TREM_DMSprProducerNeisprImpl::set_ElementCODE_REM_SPRNEISPR(TFIBWideStringField * ElementCODE_REM_SPRNEISPR)
{
Object->ElementCODE_REM_SPRNEISPR=ElementCODE_REM_SPRNEISPR;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerNeisprImpl::get_ElementNAME_REM_SPRNEISPR(void)
{
return Object->ElementNAME_REM_SPRNEISPR;
}
//---------------------------------------------------------------
void TREM_DMSprProducerNeisprImpl::set_ElementNAME_REM_SPRNEISPR(TFIBWideStringField * ElementNAME_REM_SPRNEISPR)
{
Object->ElementNAME_REM_SPRNEISPR=ElementNAME_REM_SPRNEISPR;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerNeisprImpl::get_ElementNAME_REM_SNEISPR(void)
{
return Object->ElementNAME_REM_SNEISPR;
}
//---------------------------------------------------------------
void TREM_DMSprProducerNeisprImpl::set_ElementNAME_REM_SNEISPR(TFIBWideStringField * ElementNAME_REM_SNEISPR)
{
Object->ElementNAME_REM_SNEISPR=ElementNAME_REM_SNEISPR;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerNeisprImpl::get_TableIDPR_REM_SPRNEISPR(void)
{
return Object->TableIDPR_REM_SPRNEISPR;
}
//---------------------------------------------------------------
void TREM_DMSprProducerNeisprImpl::set_TableIDPR_REM_SPRNEISPR(TFIBLargeIntField * TableIDPR_REM_SPRNEISPR)
{
Object->TableIDPR_REM_SPRNEISPR=TableIDPR_REM_SPRNEISPR;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerNeisprImpl::get_TableIDGRP_REM_SPRNEISPR(void)
{
return Object->TableIDGRP_REM_SPRNEISPR;
}
//---------------------------------------------------------------
void TREM_DMSprProducerNeisprImpl::set_TableIDGRP_REM_SPRNEISPR(TFIBLargeIntField * TableIDGRP_REM_SPRNEISPR)
{
Object->TableIDGRP_REM_SPRNEISPR=TableIDGRP_REM_SPRNEISPR;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerNeisprImpl::get_TableIDNEISPR_REM_SPRNEISPR(void)
{
return Object->TableIDNEISPR_REM_SPRNEISPR;
}
//---------------------------------------------------------------
void TREM_DMSprProducerNeisprImpl::set_TableIDNEISPR_REM_SPRNEISPR(TFIBLargeIntField * TableIDNEISPR_REM_SPRNEISPR)
{
Object->TableIDNEISPR_REM_SPRNEISPR=TableIDNEISPR_REM_SPRNEISPR;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerNeisprImpl::get_TableNAME_ENG_REM_SPRNEISPR(void)
{
return Object->TableNAME_ENG_REM_SPRNEISPR;
}
//---------------------------------------------------------------
void TREM_DMSprProducerNeisprImpl::set_TableNAME_ENG_REM_SPRNEISPR(TFIBWideStringField * TableNAME_ENG_REM_SPRNEISPR)
{
Object->TableNAME_ENG_REM_SPRNEISPR=TableNAME_ENG_REM_SPRNEISPR;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerNeisprImpl::get_ElementNAME_ENG_REM_SPRNEISPR(void)
{
return Object->ElementNAME_ENG_REM_SPRNEISPR;
}
//---------------------------------------------------------------
void TREM_DMSprProducerNeisprImpl::set_ElementNAME_ENG_REM_SPRNEISPR(TFIBWideStringField * ElementNAME_ENG_REM_SPRNEISPR)
{
Object->ElementNAME_ENG_REM_SPRNEISPR=ElementNAME_ENG_REM_SPRNEISPR;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMSprProducerNeisprImpl::get_Query(void)
{
return Object->Query;
}
//---------------------------------------------------------------
void TREM_DMSprProducerNeisprImpl::set_Query(TpFIBQuery * Query)
{
Object->Query=Query;
}
//---------------------------------------------------------------
__int64 TREM_DMSprProducerNeisprImpl::get_IdGroupElement(void)
{
return Object->IdGroupElement;
}
//---------------------------------------------------------------
void TREM_DMSprProducerNeisprImpl::set_IdGroupElement(__int64 IdGroupElement)
{
Object->IdGroupElement=IdGroupElement;
}
//---------------------------------------------------------------
__int64 TREM_DMSprProducerNeisprImpl::get_IdGrp(void)
{
return Object->IdGrp;
}
//---------------------------------------------------------------
void TREM_DMSprProducerNeisprImpl::set_IdGrp(__int64 IdGrp)
{
Object->IdGrp=IdGrp;
}
//---------------------------------------------------------------
bool TREM_DMSprProducerNeisprImpl::get_AllElement(void)
{
return Object->AllElement;
}
//---------------------------------------------------------------
void TREM_DMSprProducerNeisprImpl::set_AllElement(bool AllElement)
{
Object->AllElement=AllElement;
}
//---------------------------------------------------------------
void TREM_DMSprProducerNeisprImpl::OpenTable(__int64 id_group_element, __int64 id_grp, bool all)
{
return Object->OpenTable(id_group_element,id_grp, all);
}
//---------------------------------------------------------------
bool TREM_DMSprProducerNeisprImpl::NewElement(__int64 id_group_element, __int64 id_grp)
{
return Object->NewElement(id_group_element,id_grp);
}
//---------------------------------------------------------------
bool TREM_DMSprProducerNeisprImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
bool TREM_DMSprProducerNeisprImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
bool TREM_DMSprProducerNeisprImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
void TREM_DMSprProducerNeisprImpl::ChancheGrp(__int64 id_new_grp,__int64 id_element)
{
return Object->ChancheGrp(id_new_grp,id_element);
}
//---------------------------------------------------------------
__int64 TREM_DMSprProducerNeisprImpl::FindPoCodu(__int64 id_group_element, UnicodeString code)
{
return Object->FindPoCodu(id_group_element,code);
}
//---------------------------------------------------------------
__int64 TREM_DMSprProducerNeisprImpl::FindPoName(__int64 id_group_element, UnicodeString name)
{
return Object->FindPoName(id_group_element,name);
}
//---------------------------------------------------------------
__int64 TREM_DMSprProducerNeisprImpl::FindPoNameEng(__int64 id_group_element, UnicodeString name)
{
return Object->FindPoNameEng( id_group_element,name);
}
//---------------------------------------------------------------
__int64 TREM_DMSprProducerNeisprImpl::GetIdGrp(__int64 id_el)
{
return Object->GetIdGrp(id_el);
}
//---------------------------------------------------------------
