#include "vcl.h"
#pragma hdrstop


#include "UREM_DMSprProducerNeisprGrpImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_DMSprProducerNeisprGrpImpl::TREM_DMSprProducerNeisprGrpImpl()           
{                                            
Object=new TREM_DMSprProducerNeisprGrp(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_DMSprProducerNeisprGrpImpl::~TREM_DMSprProducerNeisprGrpImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_DMSprProducerNeisprGrpImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_DMSprProducerNeisprGrpImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_DMSprProducerNeisprGrp)                        
   {                                                                     
   *ppv=static_cast<IREM_DMSprProducerNeisprGrp*> (this);                                
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
int TREM_DMSprProducerNeisprGrpImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_DMSprProducerNeisprGrpImpl::kanRelease(void)                                  
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
int  TREM_DMSprProducerNeisprGrpImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMSprProducerNeisprGrpImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_DMSprProducerNeisprGrpImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMSprProducerNeisprGrpImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_DMSprProducerNeisprGrpImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_DMSprProducerNeisprGrpImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_DMSprProducerNeisprGrpImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IREM_DMSprProducerNeisprGrp
TDataSource * TREM_DMSprProducerNeisprGrpImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TREM_DMSprProducerNeisprGrpImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TREM_DMSprProducerNeisprGrpImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TREM_DMSprProducerNeisprGrpImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMSprProducerNeisprGrpImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TREM_DMSprProducerNeisprGrpImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMSprProducerNeisprGrpImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TREM_DMSprProducerNeisprGrpImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMSprProducerNeisprGrpImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TREM_DMSprProducerNeisprGrpImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMSprProducerNeisprGrpImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TREM_DMSprProducerNeisprGrpImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TIntegerField * TREM_DMSprProducerNeisprGrpImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TREM_DMSprProducerNeisprGrpImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerNeisprGrpImpl::get_TableID_REM_SPRNEISPR_GRP(void)
{
return Object->TableID_REM_SPRNEISPR_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprProducerNeisprGrpImpl::set_TableID_REM_SPRNEISPR_GRP(TFIBLargeIntField * TableID_REM_SPRNEISPR_GRP)
{
Object->TableID_REM_SPRNEISPR_GRP=TableID_REM_SPRNEISPR_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerNeisprGrpImpl::get_TableIDBASE_REM_SPRNEISPR_GRP(void)
{
return Object->TableIDBASE_REM_SPRNEISPR_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprProducerNeisprGrpImpl::set_TableIDBASE_REM_SPRNEISPR_GRP(TFIBLargeIntField * TableIDBASE_REM_SPRNEISPR_GRP)
{
Object->TableIDBASE_REM_SPRNEISPR_GRP=TableIDBASE_REM_SPRNEISPR_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerNeisprGrpImpl::get_TableGID_REM_SPRNEISPR_GRP(void)
{
return Object->TableGID_REM_SPRNEISPR_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprProducerNeisprGrpImpl::set_TableGID_REM_SPRNEISPR_GRP(TFIBWideStringField * TableGID_REM_SPRNEISPR_GRP)
{
Object->TableGID_REM_SPRNEISPR_GRP=TableGID_REM_SPRNEISPR_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerNeisprGrpImpl::get_TableIDPR_REM_SPRNEISPR_GRP(void)
{
return Object->TableIDPR_REM_SPRNEISPR_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprProducerNeisprGrpImpl::set_TableIDPR_REM_SPRNEISPR_GRP(TFIBLargeIntField * TableIDPR_REM_SPRNEISPR_GRP)
{
Object->TableIDPR_REM_SPRNEISPR_GRP=TableIDPR_REM_SPRNEISPR_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerNeisprGrpImpl::get_TableNAME_REM_SPRNEISPR_GRP(void)
{
return Object->TableNAME_REM_SPRNEISPR_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprProducerNeisprGrpImpl::set_TableNAME_REM_SPRNEISPR_GRP(TFIBWideStringField * TableNAME_REM_SPRNEISPR_GRP)
{
Object->TableNAME_REM_SPRNEISPR_GRP=TableNAME_REM_SPRNEISPR_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerNeisprGrpImpl::get_TableIDGRP_REM_SPRNEISPR_GRP(void)
{
return Object->TableIDGRP_REM_SPRNEISPR_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprProducerNeisprGrpImpl::set_TableIDGRP_REM_SPRNEISPR_GRP(TFIBLargeIntField * TableIDGRP_REM_SPRNEISPR_GRP)
{
Object->TableIDGRP_REM_SPRNEISPR_GRP=TableIDGRP_REM_SPRNEISPR_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerNeisprGrpImpl::get_ElementID_REM_SPRNEISPR_GRP(void)
{
return Object->ElementID_REM_SPRNEISPR_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprProducerNeisprGrpImpl::set_ElementID_REM_SPRNEISPR_GRP(TFIBLargeIntField * ElementID_REM_SPRNEISPR_GRP)
{
Object->ElementID_REM_SPRNEISPR_GRP=ElementID_REM_SPRNEISPR_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerNeisprGrpImpl::get_ElementIDBASE_REM_SPRNEISPR_GRP(void)
{
return Object->ElementIDBASE_REM_SPRNEISPR_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprProducerNeisprGrpImpl::set_ElementIDBASE_REM_SPRNEISPR_GRP(TFIBLargeIntField * ElementIDBASE_REM_SPRNEISPR_GRP)
{
Object->ElementIDBASE_REM_SPRNEISPR_GRP=ElementIDBASE_REM_SPRNEISPR_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerNeisprGrpImpl::get_ElementGID_REM_SPRNEISPR_GRP(void)
{
return Object->ElementGID_REM_SPRNEISPR_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprProducerNeisprGrpImpl::set_ElementGID_REM_SPRNEISPR_GRP(TFIBWideStringField * ElementGID_REM_SPRNEISPR_GRP)
{
Object->ElementGID_REM_SPRNEISPR_GRP=ElementGID_REM_SPRNEISPR_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerNeisprGrpImpl::get_ElementIDPR_REM_SPRNEISPR_GRP(void)
{
return Object->ElementIDPR_REM_SPRNEISPR_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprProducerNeisprGrpImpl::set_ElementIDPR_REM_SPRNEISPR_GRP(TFIBLargeIntField * ElementIDPR_REM_SPRNEISPR_GRP)
{
Object->ElementIDPR_REM_SPRNEISPR_GRP=ElementIDPR_REM_SPRNEISPR_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerNeisprGrpImpl::get_ElementNAME_REM_SPRNEISPR_GRP(void)
{
return Object->ElementNAME_REM_SPRNEISPR_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprProducerNeisprGrpImpl::set_ElementNAME_REM_SPRNEISPR_GRP(TFIBWideStringField * ElementNAME_REM_SPRNEISPR_GRP)
{
Object->ElementNAME_REM_SPRNEISPR_GRP=ElementNAME_REM_SPRNEISPR_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerNeisprGrpImpl::get_ElementIDGRP_REM_SPRNEISPR_GRP(void)
{
return Object->ElementIDGRP_REM_SPRNEISPR_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprProducerNeisprGrpImpl::set_ElementIDGRP_REM_SPRNEISPR_GRP(TFIBLargeIntField * ElementIDGRP_REM_SPRNEISPR_GRP)
{
Object->ElementIDGRP_REM_SPRNEISPR_GRP=ElementIDGRP_REM_SPRNEISPR_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerNeisprGrpImpl::get_TableNAME_ENG_REM_SPRNEISPR_GRP(void)
{
return Object->TableNAME_ENG_REM_SPRNEISPR_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprProducerNeisprGrpImpl::set_TableNAME_ENG_REM_SPRNEISPR_GRP(TFIBWideStringField * TableNAME_ENG_REM_SPRNEISPR_GRP)
{
Object->TableNAME_ENG_REM_SPRNEISPR_GRP=TableNAME_ENG_REM_SPRNEISPR_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerNeisprGrpImpl::get_ElementNAME_ENG_REM_SPRNEISPR_GRP(void)
{
return Object->ElementNAME_ENG_REM_SPRNEISPR_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprProducerNeisprGrpImpl::set_ElementNAME_ENG_REM_SPRNEISPR_GRP(TFIBWideStringField * ElementNAME_ENG_REM_SPRNEISPR_GRP)
{
Object->ElementNAME_ENG_REM_SPRNEISPR_GRP=ElementNAME_ENG_REM_SPRNEISPR_GRP;
}
//---------------------------------------------------------------
__int64 TREM_DMSprProducerNeisprGrpImpl::get_IdGroupElement(void)
{
return Object->IdGroupElement;
}
//---------------------------------------------------------------
void TREM_DMSprProducerNeisprGrpImpl::set_IdGroupElement(__int64 IdGroupElement)
{
Object->IdGroupElement=IdGroupElement;
}
//---------------------------------------------------------------
void TREM_DMSprProducerNeisprGrpImpl::OpenTable(__int64 id_group_element)
{
return Object->OpenTable(id_group_element);
}
//---------------------------------------------------------------
int TREM_DMSprProducerNeisprGrpImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
bool TREM_DMSprProducerNeisprGrpImpl::NewElement(__int64 id_group_element, __int64 id_grp)
{
return Object->NewElement(id_group_element,id_grp);
}
//---------------------------------------------------------------
bool TREM_DMSprProducerNeisprGrpImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TREM_DMSprProducerNeisprGrpImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
