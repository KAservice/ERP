#include "vcl.h"
#pragma hdrstop


#include "UDMSprLossFactorImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprLossFactorImpl::TDMSprLossFactorImpl()           
{                                            
Object=new TDMSprLossFactor(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprLossFactorImpl::~TDMSprLossFactorImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprLossFactorImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprLossFactorImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprLossFactor)                        
   {                                                                     
   *ppv=static_cast<IDMSprLossFactor*> (this);                                
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
int TDMSprLossFactorImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprLossFactorImpl::kanRelease(void)                                  
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
int  TDMSprLossFactorImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprLossFactorImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprLossFactorImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprLossFactorImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprLossFactorImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMSprLossFactorImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMSprLossFactorImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMSprLossFactor
TDataSource * TDMSprLossFactorImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprLossFactorImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TDMSprLossFactorImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TDMSprLossFactorImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprLossFactorImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprLossFactorImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprLossFactorImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprLossFactorImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprLossFactorImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprLossFactorImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprLossFactorImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprLossFactorImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBQuery * TDMSprLossFactorImpl::get_Query(void)
{
return Object->Query;
}
//---------------------------------------------------------------
void TDMSprLossFactorImpl::set_Query(TpFIBQuery * Query)
{
Object->Query=Query;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprLossFactorImpl::get_TableID_SLOSS_FACTOR(void)
{
return Object->TableID_SLOSS_FACTOR;
}
//---------------------------------------------------------------
void TDMSprLossFactorImpl::set_TableID_SLOSS_FACTOR(TFIBLargeIntField * TableID_SLOSS_FACTOR)
{
Object->TableID_SLOSS_FACTOR=TableID_SLOSS_FACTOR;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprLossFactorImpl::get_TableGID_SLOSS_FACTOR(void)
{
return Object->TableGID_SLOSS_FACTOR;
}
//---------------------------------------------------------------
void TDMSprLossFactorImpl::set_TableGID_SLOSS_FACTOR(TFIBWideStringField * TableGID_SLOSS_FACTOR)
{
Object->TableGID_SLOSS_FACTOR=TableGID_SLOSS_FACTOR;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprLossFactorImpl::get_TableIDBASE_SLOSS_FACTOR(void)
{
return Object->TableIDBASE_SLOSS_FACTOR;
}
//---------------------------------------------------------------
void TDMSprLossFactorImpl::set_TableIDBASE_SLOSS_FACTOR(TFIBLargeIntField * TableIDBASE_SLOSS_FACTOR)
{
Object->TableIDBASE_SLOSS_FACTOR=TableIDBASE_SLOSS_FACTOR;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprLossFactorImpl::get_TableNAME_SLOSS_FACTOR(void)
{
return Object->TableNAME_SLOSS_FACTOR;
}
//---------------------------------------------------------------
void TDMSprLossFactorImpl::set_TableNAME_SLOSS_FACTOR(TFIBWideStringField * TableNAME_SLOSS_FACTOR)
{
Object->TableNAME_SLOSS_FACTOR=TableNAME_SLOSS_FACTOR;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprLossFactorImpl::get_TableCOMMENT_SLOSS_FACTOR(void)
{
return Object->TableCOMMENT_SLOSS_FACTOR;
}
//---------------------------------------------------------------
void TDMSprLossFactorImpl::set_TableCOMMENT_SLOSS_FACTOR(TFIBWideStringField * TableCOMMENT_SLOSS_FACTOR)
{
Object->TableCOMMENT_SLOSS_FACTOR=TableCOMMENT_SLOSS_FACTOR;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprLossFactorImpl::get_TableENCEN_SLOSS_FACTOR(void)
{
return Object->TableENCEN_SLOSS_FACTOR;
}
//---------------------------------------------------------------
void TDMSprLossFactorImpl::set_TableENCEN_SLOSS_FACTOR(TFIBBCDField * TableENCEN_SLOSS_FACTOR)
{
Object->TableENCEN_SLOSS_FACTOR=TableENCEN_SLOSS_FACTOR;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprLossFactorImpl::get_TableBELKI_SLOSS_FACTOR(void)
{
return Object->TableBELKI_SLOSS_FACTOR;
}
//---------------------------------------------------------------
void TDMSprLossFactorImpl::set_TableBELKI_SLOSS_FACTOR(TFIBBCDField * TableBELKI_SLOSS_FACTOR)
{
Object->TableBELKI_SLOSS_FACTOR=TableBELKI_SLOSS_FACTOR;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprLossFactorImpl::get_TableGIRI_SLOSS_FACTOR(void)
{
return Object->TableGIRI_SLOSS_FACTOR;
}
//---------------------------------------------------------------
void TDMSprLossFactorImpl::set_TableGIRI_SLOSS_FACTOR(TFIBBCDField * TableGIRI_SLOSS_FACTOR)
{
Object->TableGIRI_SLOSS_FACTOR=TableGIRI_SLOSS_FACTOR;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprLossFactorImpl::get_TableUGL_SLOSS_FACTOR(void)
{
return Object->TableUGL_SLOSS_FACTOR;
}
//---------------------------------------------------------------
void TDMSprLossFactorImpl::set_TableUGL_SLOSS_FACTOR(TFIBBCDField * TableUGL_SLOSS_FACTOR)
{
Object->TableUGL_SLOSS_FACTOR=TableUGL_SLOSS_FACTOR;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprLossFactorImpl::get_TableCODE_SLOSS_FACTOR(void)
{
return Object->TableCODE_SLOSS_FACTOR;
}
//---------------------------------------------------------------
void TDMSprLossFactorImpl::set_TableCODE_SLOSS_FACTOR(TFIBWideStringField * TableCODE_SLOSS_FACTOR)
{
Object->TableCODE_SLOSS_FACTOR=TableCODE_SLOSS_FACTOR;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprLossFactorImpl::get_TableIDGRP_SLOSS_FACTOR(void)
{
return Object->TableIDGRP_SLOSS_FACTOR;
}
//---------------------------------------------------------------
void TDMSprLossFactorImpl::set_TableIDGRP_SLOSS_FACTOR(TFIBLargeIntField * TableIDGRP_SLOSS_FACTOR)
{
Object->TableIDGRP_SLOSS_FACTOR=TableIDGRP_SLOSS_FACTOR;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprLossFactorImpl::get_ElementID_SLOSS_FACTOR(void)
{
return Object->ElementID_SLOSS_FACTOR;
}
//---------------------------------------------------------------
void TDMSprLossFactorImpl::set_ElementID_SLOSS_FACTOR(TFIBLargeIntField * ElementID_SLOSS_FACTOR)
{
Object->ElementID_SLOSS_FACTOR=ElementID_SLOSS_FACTOR;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprLossFactorImpl::get_ElementGID_SLOSS_FACTOR(void)
{
return Object->ElementGID_SLOSS_FACTOR;
}
//---------------------------------------------------------------
void TDMSprLossFactorImpl::set_ElementGID_SLOSS_FACTOR(TFIBWideStringField * ElementGID_SLOSS_FACTOR)
{
Object->ElementGID_SLOSS_FACTOR=ElementGID_SLOSS_FACTOR;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprLossFactorImpl::get_ElementIDBASE_SLOSS_FACTOR(void)
{
return Object->ElementIDBASE_SLOSS_FACTOR;
}
//---------------------------------------------------------------
void TDMSprLossFactorImpl::set_ElementIDBASE_SLOSS_FACTOR(TFIBLargeIntField * ElementIDBASE_SLOSS_FACTOR)
{
Object->ElementIDBASE_SLOSS_FACTOR=ElementIDBASE_SLOSS_FACTOR;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprLossFactorImpl::get_ElementNAME_SLOSS_FACTOR(void)
{
return Object->ElementNAME_SLOSS_FACTOR;
}
//---------------------------------------------------------------
void TDMSprLossFactorImpl::set_ElementNAME_SLOSS_FACTOR(TFIBWideStringField * ElementNAME_SLOSS_FACTOR)
{
Object->ElementNAME_SLOSS_FACTOR=ElementNAME_SLOSS_FACTOR;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprLossFactorImpl::get_ElementCOMMENT_SLOSS_FACTOR(void)
{
return Object->ElementCOMMENT_SLOSS_FACTOR;
}
//---------------------------------------------------------------
void TDMSprLossFactorImpl::set_ElementCOMMENT_SLOSS_FACTOR(TFIBWideStringField * ElementCOMMENT_SLOSS_FACTOR)
{
Object->ElementCOMMENT_SLOSS_FACTOR=ElementCOMMENT_SLOSS_FACTOR;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprLossFactorImpl::get_ElementENCEN_SLOSS_FACTOR(void)
{
return Object->ElementENCEN_SLOSS_FACTOR;
}
//---------------------------------------------------------------
void TDMSprLossFactorImpl::set_ElementENCEN_SLOSS_FACTOR(TFIBBCDField * ElementENCEN_SLOSS_FACTOR)
{
Object->ElementENCEN_SLOSS_FACTOR=ElementENCEN_SLOSS_FACTOR;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprLossFactorImpl::get_ElementBELKI_SLOSS_FACTOR(void)
{
return Object->ElementBELKI_SLOSS_FACTOR;
}
//---------------------------------------------------------------
void TDMSprLossFactorImpl::set_ElementBELKI_SLOSS_FACTOR(TFIBBCDField * ElementBELKI_SLOSS_FACTOR)
{
Object->ElementBELKI_SLOSS_FACTOR=ElementBELKI_SLOSS_FACTOR;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprLossFactorImpl::get_ElementGIRI_SLOSS_FACTOR(void)
{
return Object->ElementGIRI_SLOSS_FACTOR;
}
//---------------------------------------------------------------
void TDMSprLossFactorImpl::set_ElementGIRI_SLOSS_FACTOR(TFIBBCDField * ElementGIRI_SLOSS_FACTOR)
{
Object->ElementGIRI_SLOSS_FACTOR=ElementGIRI_SLOSS_FACTOR;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprLossFactorImpl::get_ElementUGL_SLOSS_FACTOR(void)
{
return Object->ElementUGL_SLOSS_FACTOR;
}
//---------------------------------------------------------------
void TDMSprLossFactorImpl::set_ElementUGL_SLOSS_FACTOR(TFIBBCDField * ElementUGL_SLOSS_FACTOR)
{
Object->ElementUGL_SLOSS_FACTOR=ElementUGL_SLOSS_FACTOR;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprLossFactorImpl::get_ElementCODE_SLOSS_FACTOR(void)
{
return Object->ElementCODE_SLOSS_FACTOR;
}
//---------------------------------------------------------------
void TDMSprLossFactorImpl::set_ElementCODE_SLOSS_FACTOR(TFIBWideStringField * ElementCODE_SLOSS_FACTOR)
{
Object->ElementCODE_SLOSS_FACTOR=ElementCODE_SLOSS_FACTOR;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprLossFactorImpl::get_ElementIDGRP_SLOSS_FACTOR(void)
{
return Object->ElementIDGRP_SLOSS_FACTOR;
}
//---------------------------------------------------------------
void TDMSprLossFactorImpl::set_ElementIDGRP_SLOSS_FACTOR(TFIBLargeIntField * ElementIDGRP_SLOSS_FACTOR)
{
Object->ElementIDGRP_SLOSS_FACTOR=ElementIDGRP_SLOSS_FACTOR;
}
//---------------------------------------------------------------
__int64 TDMSprLossFactorImpl::get_IdGrp(void)
{
return Object->IdGrp;
}
//---------------------------------------------------------------
void TDMSprLossFactorImpl::set_IdGrp(__int64 IdGrp)
{
Object->IdGrp=IdGrp;
}
//---------------------------------------------------------------
bool TDMSprLossFactorImpl::get_AllElement(void)
{
return Object->AllElement;
}
//---------------------------------------------------------------
void TDMSprLossFactorImpl::set_AllElement(bool AllElement)
{
Object->AllElement=AllElement;
}
//---------------------------------------------------------------
__int64 TDMSprLossFactorImpl::get_IdElement(void)
{
return Object->IdElement;
}
//---------------------------------------------------------------
void TDMSprLossFactorImpl::set_IdElement(__int64 IdElement)
{
Object->IdElement=IdElement;
}
//---------------------------------------------------------------
bool TDMSprLossFactorImpl::OpenTable(__int64 id_grp, bool all)
{
return Object->OpenTable(id_grp,all);
}
//---------------------------------------------------------------
UnicodeString TDMSprLossFactorImpl::GetTextQuery(__int64 id_grp, bool all)
{
return Object->GetTextQuery(id_grp,all);
}
//---------------------------------------------------------------
bool TDMSprLossFactorImpl::OpenElement(__int64 id )
{
return Object->OpenElement(id );
}
//---------------------------------------------------------------
bool TDMSprLossFactorImpl::NewElement(__int64 id_grp)
{
return Object->NewElement(id_grp);
}
//---------------------------------------------------------------
bool TDMSprLossFactorImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TDMSprLossFactorImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
bool TDMSprLossFactorImpl::ChancheGrp(__int64 id_new_grp,__int64 id_el)
{
return Object->ChancheGrp(id_new_grp,id_el);
}
//---------------------------------------------------------------
__int64 TDMSprLossFactorImpl::FindPoName(UnicodeString name)
{
return Object->FindPoName(name);
}
//---------------------------------------------------------------
__int64 TDMSprLossFactorImpl::GetIDElement(UnicodeString gid)
{
return Object->GetIDElement(gid);
}
//---------------------------------------------------------------
UnicodeString TDMSprLossFactorImpl::GetGIDElement(__int64 id)
{
return Object->GetGIDElement(id);
}
//---------------------------------------------------------------
__int64 TDMSprLossFactorImpl::GetIdGrp(__int64 id_el)
{
return Object->GetIdGrp(id_el);
}
//---------------------------------------------------------------
