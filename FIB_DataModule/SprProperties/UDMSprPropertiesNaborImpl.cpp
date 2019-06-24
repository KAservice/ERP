#include "vcl.h"
#pragma hdrstop


#include "UDMSprPropertiesNaborImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprPropertiesNaborImpl::TDMSprPropertiesNaborImpl()           
{                                            
Object=new TDMSprPropertiesNabor(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprPropertiesNaborImpl::~TDMSprPropertiesNaborImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprPropertiesNaborImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprPropertiesNaborImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprPropertiesNabor)                        
   {                                                                     
   *ppv=static_cast<IDMSprPropertiesNabor*> (this);                                
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
int TDMSprPropertiesNaborImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprPropertiesNaborImpl::kanRelease(void)                                  
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
int  TDMSprPropertiesNaborImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprPropertiesNaborImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprPropertiesNaborImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprPropertiesNaborImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprPropertiesNaborImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMSprPropertiesNaborImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMSprPropertiesNaborImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMSprPropertiesNabor
TDataSource * TDMSprPropertiesNaborImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprPropertiesNaborImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TDMSprPropertiesNaborImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TDMSprPropertiesNaborImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprPropertiesNaborImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprPropertiesNaborImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprPropertiesNaborImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprPropertiesNaborImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprPropertiesNaborImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprPropertiesNaborImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprPropertiesNaborImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprPropertiesNaborImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TIntegerField * TDMSprPropertiesNaborImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TDMSprPropertiesNaborImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TpFIBQuery * TDMSprPropertiesNaborImpl::get_Query(void)
{
return Object->Query;
}
//---------------------------------------------------------------
void TDMSprPropertiesNaborImpl::set_Query(TpFIBQuery * Query)
{
Object->Query=Query;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprPropertiesNaborImpl::get_TableID_SPROPNABOR(void)
{
return Object->TableID_SPROPNABOR;
}
//---------------------------------------------------------------
void TDMSprPropertiesNaborImpl::set_TableID_SPROPNABOR(TFIBLargeIntField * TableID_SPROPNABOR)
{
Object->TableID_SPROPNABOR=TableID_SPROPNABOR;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprPropertiesNaborImpl::get_TableIDBASE_SPROPNABOR(void)
{
return Object->TableIDBASE_SPROPNABOR;
}
//---------------------------------------------------------------
void TDMSprPropertiesNaborImpl::set_TableIDBASE_SPROPNABOR(TFIBLargeIntField * TableIDBASE_SPROPNABOR)
{
Object->TableIDBASE_SPROPNABOR=TableIDBASE_SPROPNABOR;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprPropertiesNaborImpl::get_TableGID_SPROPNABOR(void)
{
return Object->TableGID_SPROPNABOR;
}
//---------------------------------------------------------------
void TDMSprPropertiesNaborImpl::set_TableGID_SPROPNABOR(TFIBWideStringField * TableGID_SPROPNABOR)
{
Object->TableGID_SPROPNABOR=TableGID_SPROPNABOR;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprPropertiesNaborImpl::get_TableIDGRP_SPROPNABOR(void)
{
return Object->TableIDGRP_SPROPNABOR;
}
//---------------------------------------------------------------
void TDMSprPropertiesNaborImpl::set_TableIDGRP_SPROPNABOR(TFIBLargeIntField * TableIDGRP_SPROPNABOR)
{
Object->TableIDGRP_SPROPNABOR=TableIDGRP_SPROPNABOR;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprPropertiesNaborImpl::get_TableNAME_SPROPNABOR(void)
{
return Object->TableNAME_SPROPNABOR;
}
//---------------------------------------------------------------
void TDMSprPropertiesNaborImpl::set_TableNAME_SPROPNABOR(TFIBWideStringField * TableNAME_SPROPNABOR)
{
Object->TableNAME_SPROPNABOR=TableNAME_SPROPNABOR;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprPropertiesNaborImpl::get_ElementID_SPROPNABOR(void)
{
return Object->ElementID_SPROPNABOR;
}
//---------------------------------------------------------------
void TDMSprPropertiesNaborImpl::set_ElementID_SPROPNABOR(TFIBLargeIntField * ElementID_SPROPNABOR)
{
Object->ElementID_SPROPNABOR=ElementID_SPROPNABOR;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprPropertiesNaborImpl::get_ElementIDBASE_SPROPNABOR(void)
{
return Object->ElementIDBASE_SPROPNABOR;
}
//---------------------------------------------------------------
void TDMSprPropertiesNaborImpl::set_ElementIDBASE_SPROPNABOR(TFIBLargeIntField * ElementIDBASE_SPROPNABOR)
{
Object->ElementIDBASE_SPROPNABOR=ElementIDBASE_SPROPNABOR;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprPropertiesNaborImpl::get_ElementGID_SPROPNABOR(void)
{
return Object->ElementGID_SPROPNABOR;
}
//---------------------------------------------------------------
void TDMSprPropertiesNaborImpl::set_ElementGID_SPROPNABOR(TFIBWideStringField * ElementGID_SPROPNABOR)
{
Object->ElementGID_SPROPNABOR=ElementGID_SPROPNABOR;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprPropertiesNaborImpl::get_ElementIDGRP_SPROPNABOR(void)
{
return Object->ElementIDGRP_SPROPNABOR;
}
//---------------------------------------------------------------
void TDMSprPropertiesNaborImpl::set_ElementIDGRP_SPROPNABOR(TFIBLargeIntField * ElementIDGRP_SPROPNABOR)
{
Object->ElementIDGRP_SPROPNABOR=ElementIDGRP_SPROPNABOR;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprPropertiesNaborImpl::get_ElementNAME_SPROPNABOR(void)
{
return Object->ElementNAME_SPROPNABOR;
}
//---------------------------------------------------------------
void TDMSprPropertiesNaborImpl::set_ElementNAME_SPROPNABOR(TFIBWideStringField * ElementNAME_SPROPNABOR)
{
Object->ElementNAME_SPROPNABOR=ElementNAME_SPROPNABOR;
}
//---------------------------------------------------------------
__int64 TDMSprPropertiesNaborImpl::get_IdGrp(void)
{
return Object->IdGrp;
}
//---------------------------------------------------------------
void TDMSprPropertiesNaborImpl::set_IdGrp(__int64 IdGrp)
{
Object->IdGrp=IdGrp;
}
//---------------------------------------------------------------
bool TDMSprPropertiesNaborImpl::get_AllElement(void)
{
return Object->AllElement;
}
//---------------------------------------------------------------
void TDMSprPropertiesNaborImpl::set_AllElement(bool AllElement)
{
Object->AllElement=AllElement;
}
//---------------------------------------------------------------
__int64 TDMSprPropertiesNaborImpl::get_IdElement(void)
{
return Object->IdElement;
}
//---------------------------------------------------------------
void TDMSprPropertiesNaborImpl::set_IdElement(__int64 IdElement)
{
Object->IdElement=IdElement;
}
//---------------------------------------------------------------
void TDMSprPropertiesNaborImpl::OpenTable(__int64 id_grp, bool all)
{
return Object->OpenTable(id_grp,all);
}
//---------------------------------------------------------------
UnicodeString TDMSprPropertiesNaborImpl::GetTextQuery(__int64 id_grp, bool all)
{
return Object->GetTextQuery(id_grp, all);
}
//---------------------------------------------------------------
int TDMSprPropertiesNaborImpl::OpenElement(__int64 id )
{
return Object->OpenElement(id );
}
//---------------------------------------------------------------
bool TDMSprPropertiesNaborImpl::NewElement(__int64 id_grp)
{
return Object->NewElement(id_grp);
}
//---------------------------------------------------------------
bool TDMSprPropertiesNaborImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TDMSprPropertiesNaborImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
void TDMSprPropertiesNaborImpl::ChancheGrp(__int64 id_new_grp,__int64 id_element)
{
return Object->ChancheGrp(id_new_grp,id_element);
}
//---------------------------------------------------------------
__int64 TDMSprPropertiesNaborImpl::FindPoName(UnicodeString name)
{
return Object->FindPoName(name);
}
//---------------------------------------------------------------
__int64 TDMSprPropertiesNaborImpl::GetIdGrp(__int64 id_el)
{
return Object->GetIdGrp(id_el);
}
//---------------------------------------------------------------
