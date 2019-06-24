#include "vcl.h"
#pragma hdrstop


#include "UDMSprPropertiesImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprPropertiesImpl::TDMSprPropertiesImpl()           
{                                            
Object=new TDMSprProperties(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprPropertiesImpl::~TDMSprPropertiesImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprPropertiesImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprPropertiesImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprProperties)                        
   {                                                                     
   *ppv=static_cast<IDMSprProperties*> (this);                                
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
int TDMSprPropertiesImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprPropertiesImpl::kanRelease(void)                                  
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
int  TDMSprPropertiesImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprPropertiesImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprPropertiesImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprPropertiesImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprPropertiesImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMSprPropertiesImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMSprPropertiesImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMSprProperties
TDataSource * TDMSprPropertiesImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprPropertiesImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TDMSprPropertiesImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TDMSprPropertiesImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprPropertiesImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprPropertiesImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprPropertiesImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprPropertiesImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprPropertiesImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprPropertiesImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprPropertiesImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprPropertiesImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprPropertiesImpl::get_TableID_SPROP(void)
{
return Object->TableID_SPROP;
}
//---------------------------------------------------------------
void TDMSprPropertiesImpl::set_TableID_SPROP(TFIBLargeIntField * TableID_SPROP)
{
Object->TableID_SPROP=TableID_SPROP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprPropertiesImpl::get_TableIDBASE_SPROP(void)
{
return Object->TableIDBASE_SPROP;
}
//---------------------------------------------------------------
void TDMSprPropertiesImpl::set_TableIDBASE_SPROP(TFIBLargeIntField * TableIDBASE_SPROP)
{
Object->TableIDBASE_SPROP=TableIDBASE_SPROP;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprPropertiesImpl::get_TableGID_SPROP(void)
{
return Object->TableGID_SPROP;
}
//---------------------------------------------------------------
void TDMSprPropertiesImpl::set_TableGID_SPROP(TFIBWideStringField * TableGID_SPROP)
{
Object->TableGID_SPROP=TableGID_SPROP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprPropertiesImpl::get_TableIDGRP_SPROP(void)
{
return Object->TableIDGRP_SPROP;
}
//---------------------------------------------------------------
void TDMSprPropertiesImpl::set_TableIDGRP_SPROP(TFIBLargeIntField * TableIDGRP_SPROP)
{
Object->TableIDGRP_SPROP=TableIDGRP_SPROP;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprPropertiesImpl::get_TableNAME_SPROP(void)
{
return Object->TableNAME_SPROP;
}
//---------------------------------------------------------------
void TDMSprPropertiesImpl::set_TableNAME_SPROP(TFIBWideStringField * TableNAME_SPROP)
{
Object->TableNAME_SPROP=TableNAME_SPROP;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprPropertiesImpl::get_TableFL_TYPE_SPROP(void)
{
return Object->TableFL_TYPE_SPROP;
}
//---------------------------------------------------------------
void TDMSprPropertiesImpl::set_TableFL_TYPE_SPROP(TFIBSmallIntField * TableFL_TYPE_SPROP)
{
Object->TableFL_TYPE_SPROP=TableFL_TYPE_SPROP;
}
//---------------------------------------------------------------
TIntegerField * TDMSprPropertiesImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TDMSprPropertiesImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprPropertiesImpl::get_ElementID_SPROP(void)
{
return Object->ElementID_SPROP;
}
//---------------------------------------------------------------
void TDMSprPropertiesImpl::set_ElementID_SPROP(TFIBLargeIntField * ElementID_SPROP)
{
Object->ElementID_SPROP=ElementID_SPROP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprPropertiesImpl::get_ElementIDBASE_SPROP(void)
{
return Object->ElementIDBASE_SPROP;
}
//---------------------------------------------------------------
void TDMSprPropertiesImpl::set_ElementIDBASE_SPROP(TFIBLargeIntField * ElementIDBASE_SPROP)
{
Object->ElementIDBASE_SPROP=ElementIDBASE_SPROP;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprPropertiesImpl::get_ElementGID_SPROP(void)
{
return Object->ElementGID_SPROP;
}
//---------------------------------------------------------------
void TDMSprPropertiesImpl::set_ElementGID_SPROP(TFIBWideStringField * ElementGID_SPROP)
{
Object->ElementGID_SPROP=ElementGID_SPROP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprPropertiesImpl::get_ElementIDGRP_SPROP(void)
{
return Object->ElementIDGRP_SPROP;
}
//---------------------------------------------------------------
void TDMSprPropertiesImpl::set_ElementIDGRP_SPROP(TFIBLargeIntField * ElementIDGRP_SPROP)
{
Object->ElementIDGRP_SPROP=ElementIDGRP_SPROP;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprPropertiesImpl::get_ElementNAME_SPROP(void)
{
return Object->ElementNAME_SPROP;
}
//---------------------------------------------------------------
void TDMSprPropertiesImpl::set_ElementNAME_SPROP(TFIBWideStringField * ElementNAME_SPROP)
{
Object->ElementNAME_SPROP=ElementNAME_SPROP;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprPropertiesImpl::get_ElementFL_TYPE_SPROP(void)
{
return Object->ElementFL_TYPE_SPROP;
}
//---------------------------------------------------------------
void TDMSprPropertiesImpl::set_ElementFL_TYPE_SPROP(TFIBSmallIntField * ElementFL_TYPE_SPROP)
{
Object->ElementFL_TYPE_SPROP=ElementFL_TYPE_SPROP;
}
//---------------------------------------------------------------
TpFIBQuery * TDMSprPropertiesImpl::get_Query(void)
{
return Object->Query;
}
//---------------------------------------------------------------
void TDMSprPropertiesImpl::set_Query(TpFIBQuery * Query)
{
Object->Query=Query;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprPropertiesImpl::get_ElementNAME_FOR_PRINT_SPROP(void)
{
return Object->ElementNAME_FOR_PRINT_SPROP;
}
//---------------------------------------------------------------
void TDMSprPropertiesImpl::set_ElementNAME_FOR_PRINT_SPROP(TFIBWideStringField * ElementNAME_FOR_PRINT_SPROP)
{
Object->ElementNAME_FOR_PRINT_SPROP=ElementNAME_FOR_PRINT_SPROP;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprPropertiesImpl::get_TableNAME_FOR_PRINT_SPROP(void)
{
return Object->TableNAME_FOR_PRINT_SPROP;
}
//---------------------------------------------------------------
void TDMSprPropertiesImpl::set_TableNAME_FOR_PRINT_SPROP(TFIBWideStringField * TableNAME_FOR_PRINT_SPROP)
{
Object->TableNAME_FOR_PRINT_SPROP=TableNAME_FOR_PRINT_SPROP;
}
//---------------------------------------------------------------
__int64 TDMSprPropertiesImpl::get_IdGrp(void)
{
return Object->IdGrp;
}
//---------------------------------------------------------------
void TDMSprPropertiesImpl::set_IdGrp(__int64 IdGrp)
{
Object->IdGrp=IdGrp;
}
//---------------------------------------------------------------
bool TDMSprPropertiesImpl::get_AllElement(void)
{
return Object->AllElement;
}
//---------------------------------------------------------------
void TDMSprPropertiesImpl::set_AllElement(bool AllElement)
{
Object->AllElement=AllElement;
}
//---------------------------------------------------------------
__int64 TDMSprPropertiesImpl::get_IdElement(void)
{
return Object->IdElement;
}
//---------------------------------------------------------------
void TDMSprPropertiesImpl::set_IdElement(__int64 IdElement)
{
Object->IdElement=IdElement;
}
//---------------------------------------------------------------
void TDMSprPropertiesImpl::OpenTable(__int64 id_grp, bool all)
{
return Object->OpenTable(id_grp,all);
}
//---------------------------------------------------------------
UnicodeString TDMSprPropertiesImpl::GetTextQuery(__int64 id_grp, bool all)
{
return Object->GetTextQuery(id_grp,all);
}
//---------------------------------------------------------------
int TDMSprPropertiesImpl::OpenElement(__int64 id )
{
return Object->OpenElement(id );
}
//---------------------------------------------------------------
bool TDMSprPropertiesImpl::NewElement(__int64 id_grp)
{
return Object->NewElement(id_grp);
}
//---------------------------------------------------------------
bool TDMSprPropertiesImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TDMSprPropertiesImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
void TDMSprPropertiesImpl::ChancheGrp(__int64 id_new_grp,__int64 id_prop)
{
return Object->ChancheGrp(id_new_grp,id_prop);
}
//---------------------------------------------------------------
__int64 TDMSprPropertiesImpl::FindPoName(UnicodeString name)
{
return Object->FindPoName(name);
}
//---------------------------------------------------------------
__int64 TDMSprPropertiesImpl::GetIdGrp(__int64 id_el)
{
return Object->GetIdGrp(id_el);
}
//---------------------------------------------------------------
