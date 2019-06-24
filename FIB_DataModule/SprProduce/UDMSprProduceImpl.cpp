#include "vcl.h"
#pragma hdrstop


#include "UDMSprProduceImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprProduceImpl::TDMSprProduceImpl()           
{                                            
Object=new TDMSprProduce(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprProduceImpl::~TDMSprProduceImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprProduceImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprProduceImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprProduce)                        
   {                                                                     
   *ppv=static_cast<IDMSprProduce*> (this);                                
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
int TDMSprProduceImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprProduceImpl::kanRelease(void)                                  
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
int  TDMSprProduceImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprProduceImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprProduceImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprProduceImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprProduceImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMSprProduceImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMSprProduceImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMSprProduce
TDataSource * TDMSprProduceImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprProduceImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TDMSprProduceImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TDMSprProduceImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprProduceImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprProduceImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprProduceImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprProduceImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprProduceImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprProduceImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprProduceImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprProduceImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBQuery * TDMSprProduceImpl::get_Query(void)
{
return Object->Query;
}
//---------------------------------------------------------------
void TDMSprProduceImpl::set_Query(TpFIBQuery * Query)
{
Object->Query=Query;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprProduceImpl::get_ElementID_SPRODUCE(void)
{
return Object->ElementID_SPRODUCE;
}
//---------------------------------------------------------------
void TDMSprProduceImpl::set_ElementID_SPRODUCE(TFIBLargeIntField * ElementID_SPRODUCE)
{
Object->ElementID_SPRODUCE=ElementID_SPRODUCE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprProduceImpl::get_ElementGID_SPRODUCE(void)
{
return Object->ElementGID_SPRODUCE;
}
//---------------------------------------------------------------
void TDMSprProduceImpl::set_ElementGID_SPRODUCE(TFIBWideStringField * ElementGID_SPRODUCE)
{
Object->ElementGID_SPRODUCE=ElementGID_SPRODUCE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprProduceImpl::get_ElementIDBASE_SPRODUCE(void)
{
return Object->ElementIDBASE_SPRODUCE;
}
//---------------------------------------------------------------
void TDMSprProduceImpl::set_ElementIDBASE_SPRODUCE(TFIBLargeIntField * ElementIDBASE_SPRODUCE)
{
Object->ElementIDBASE_SPRODUCE=ElementIDBASE_SPRODUCE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprProduceImpl::get_ElementIDGRP_SPRODUCE(void)
{
return Object->ElementIDGRP_SPRODUCE;
}
//---------------------------------------------------------------
void TDMSprProduceImpl::set_ElementIDGRP_SPRODUCE(TFIBLargeIntField * ElementIDGRP_SPRODUCE)
{
Object->ElementIDGRP_SPRODUCE=ElementIDGRP_SPRODUCE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprProduceImpl::get_ElementNAME_SPRODUCE(void)
{
return Object->ElementNAME_SPRODUCE;
}
//---------------------------------------------------------------
void TDMSprProduceImpl::set_ElementNAME_SPRODUCE(TFIBWideStringField * ElementNAME_SPRODUCE)
{
Object->ElementNAME_SPRODUCE=ElementNAME_SPRODUCE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprProduceImpl::get_ElementCODE_SPRODUCE(void)
{
return Object->ElementCODE_SPRODUCE;
}
//---------------------------------------------------------------
void TDMSprProduceImpl::set_ElementCODE_SPRODUCE(TFIBWideStringField * ElementCODE_SPRODUCE)
{
Object->ElementCODE_SPRODUCE=ElementCODE_SPRODUCE;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprProduceImpl::get_ElementBELKI_SPRODUCE(void)
{
return Object->ElementBELKI_SPRODUCE;
}
//---------------------------------------------------------------
void TDMSprProduceImpl::set_ElementBELKI_SPRODUCE(TFIBBCDField * ElementBELKI_SPRODUCE)
{
Object->ElementBELKI_SPRODUCE=ElementBELKI_SPRODUCE;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprProduceImpl::get_ElementGIRI_SPRODUCE(void)
{
return Object->ElementGIRI_SPRODUCE;
}
//---------------------------------------------------------------
void TDMSprProduceImpl::set_ElementGIRI_SPRODUCE(TFIBBCDField * ElementGIRI_SPRODUCE)
{
Object->ElementGIRI_SPRODUCE=ElementGIRI_SPRODUCE;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprProduceImpl::get_ElementUGL_SPRODUCE(void)
{
return Object->ElementUGL_SPRODUCE;
}
//---------------------------------------------------------------
void TDMSprProduceImpl::set_ElementUGL_SPRODUCE(TFIBBCDField * ElementUGL_SPRODUCE)
{
Object->ElementUGL_SPRODUCE=ElementUGL_SPRODUCE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprProduceImpl::get_ElementCOMMENT_SPRODUCE(void)
{
return Object->ElementCOMMENT_SPRODUCE;
}
//---------------------------------------------------------------
void TDMSprProduceImpl::set_ElementCOMMENT_SPRODUCE(TFIBWideStringField * ElementCOMMENT_SPRODUCE)
{
Object->ElementCOMMENT_SPRODUCE=ElementCOMMENT_SPRODUCE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprProduceImpl::get_TableID_SPRODUCE(void)
{
return Object->TableID_SPRODUCE;
}
//---------------------------------------------------------------
void TDMSprProduceImpl::set_TableID_SPRODUCE(TFIBLargeIntField * TableID_SPRODUCE)
{
Object->TableID_SPRODUCE=TableID_SPRODUCE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprProduceImpl::get_TableGID_SPRODUCE(void)
{
return Object->TableGID_SPRODUCE;
}
//---------------------------------------------------------------
void TDMSprProduceImpl::set_TableGID_SPRODUCE(TFIBWideStringField * TableGID_SPRODUCE)
{
Object->TableGID_SPRODUCE=TableGID_SPRODUCE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprProduceImpl::get_TableIDBASE_SPRODUCE(void)
{
return Object->TableIDBASE_SPRODUCE;
}
//---------------------------------------------------------------
void TDMSprProduceImpl::set_TableIDBASE_SPRODUCE(TFIBLargeIntField * TableIDBASE_SPRODUCE)
{
Object->TableIDBASE_SPRODUCE=TableIDBASE_SPRODUCE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprProduceImpl::get_TableIDGRP_SPRODUCE(void)
{
return Object->TableIDGRP_SPRODUCE;
}
//---------------------------------------------------------------
void TDMSprProduceImpl::set_TableIDGRP_SPRODUCE(TFIBLargeIntField * TableIDGRP_SPRODUCE)
{
Object->TableIDGRP_SPRODUCE=TableIDGRP_SPRODUCE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprProduceImpl::get_TableNAME_SPRODUCE(void)
{
return Object->TableNAME_SPRODUCE;
}
//---------------------------------------------------------------
void TDMSprProduceImpl::set_TableNAME_SPRODUCE(TFIBWideStringField * TableNAME_SPRODUCE)
{
Object->TableNAME_SPRODUCE=TableNAME_SPRODUCE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprProduceImpl::get_TableCODE_SPRODUCE(void)
{
return Object->TableCODE_SPRODUCE;
}
//---------------------------------------------------------------
void TDMSprProduceImpl::set_TableCODE_SPRODUCE(TFIBWideStringField * TableCODE_SPRODUCE)
{
Object->TableCODE_SPRODUCE=TableCODE_SPRODUCE;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprProduceImpl::get_TableBELKI_SPRODUCE(void)
{
return Object->TableBELKI_SPRODUCE;
}
//---------------------------------------------------------------
void TDMSprProduceImpl::set_TableBELKI_SPRODUCE(TFIBBCDField * TableBELKI_SPRODUCE)
{
Object->TableBELKI_SPRODUCE=TableBELKI_SPRODUCE;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprProduceImpl::get_TableGIRI_SPRODUCE(void)
{
return Object->TableGIRI_SPRODUCE;
}
//---------------------------------------------------------------
void TDMSprProduceImpl::set_TableGIRI_SPRODUCE(TFIBBCDField * TableGIRI_SPRODUCE)
{
Object->TableGIRI_SPRODUCE=TableGIRI_SPRODUCE;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprProduceImpl::get_TableUGL_SPRODUCE(void)
{
return Object->TableUGL_SPRODUCE;
}
//---------------------------------------------------------------
void TDMSprProduceImpl::set_TableUGL_SPRODUCE(TFIBBCDField * TableUGL_SPRODUCE)
{
Object->TableUGL_SPRODUCE=TableUGL_SPRODUCE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprProduceImpl::get_TableCOMMENT_SPRODUCE(void)
{
return Object->TableCOMMENT_SPRODUCE;
}
//---------------------------------------------------------------
void TDMSprProduceImpl::set_TableCOMMENT_SPRODUCE(TFIBWideStringField * TableCOMMENT_SPRODUCE)
{
Object->TableCOMMENT_SPRODUCE=TableCOMMENT_SPRODUCE;
}
//---------------------------------------------------------------
__int64 TDMSprProduceImpl::get_IdGrp(void)
{
return Object->IdGrp;
}
//---------------------------------------------------------------
void TDMSprProduceImpl::set_IdGrp(__int64 IdGrp)
{
Object->IdGrp=IdGrp;
}
//---------------------------------------------------------------
bool TDMSprProduceImpl::get_AllElement(void)
{
return Object->AllElement;
}
//---------------------------------------------------------------
void TDMSprProduceImpl::set_AllElement(bool AllElement)
{
Object->AllElement=AllElement;
}
//---------------------------------------------------------------
__int64 TDMSprProduceImpl::get_IdElement(void)
{
return Object->IdElement;
}
//---------------------------------------------------------------
void TDMSprProduceImpl::set_IdElement(__int64 IdElement)
{
Object->IdElement=IdElement;
}
//---------------------------------------------------------------
bool TDMSprProduceImpl::OpenTable(__int64 id_grp, bool all)
{
return Object->OpenTable(id_grp,all);
}
//---------------------------------------------------------------
UnicodeString TDMSprProduceImpl::GetTextQuery(__int64 id_grp, bool all)
{
return Object->GetTextQuery(id_grp,all);
}
//---------------------------------------------------------------
bool TDMSprProduceImpl::OpenElement(__int64 id )
{
return Object->OpenElement(id );
}
//---------------------------------------------------------------
bool TDMSprProduceImpl::NewElement(__int64 id_grp)
{
return Object->NewElement(id_grp);
}
//---------------------------------------------------------------
bool TDMSprProduceImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TDMSprProduceImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
bool TDMSprProduceImpl::ChancheGrp(__int64 id_new_grp,__int64 id_el)
{
return Object->ChancheGrp(id_new_grp,id_el);
}
//---------------------------------------------------------------
__int64 TDMSprProduceImpl::FindPoName(UnicodeString name)
{
return Object->FindPoName(name);
}
//---------------------------------------------------------------
__int64 TDMSprProduceImpl::GetIDElement(UnicodeString gid)
{
return Object->GetIDElement(gid);
}
//---------------------------------------------------------------
UnicodeString TDMSprProduceImpl::GetGIDElement(__int64 id)
{
return Object->GetGIDElement(id);
}
//---------------------------------------------------------------
__int64 TDMSprProduceImpl::GetIdGrp(__int64 id_el)
{
return Object->GetIdGrp(id_el);
}
//---------------------------------------------------------------
