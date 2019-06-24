#include "vcl.h"
#pragma hdrstop


#include "UDMSprGrpLossFactorImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprGrpLossFactorImpl::TDMSprGrpLossFactorImpl()           
{                                            
Object=new TDMSprGrpLossFactor(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprGrpLossFactorImpl::~TDMSprGrpLossFactorImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprGrpLossFactorImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprGrpLossFactorImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprGrpLossFactor)                        
   {                                                                     
   *ppv=static_cast<IDMSprGrpLossFactor*> (this);                                
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
int TDMSprGrpLossFactorImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprGrpLossFactorImpl::kanRelease(void)                                  
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
int  TDMSprGrpLossFactorImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprGrpLossFactorImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprGrpLossFactorImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprGrpLossFactorImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprGrpLossFactorImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMSprGrpLossFactorImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMSprGrpLossFactorImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMSprGrpLossFactor
TDataSource * TDMSprGrpLossFactorImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprGrpLossFactorImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TDMSprGrpLossFactorImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TDMSprGrpLossFactorImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprGrpLossFactorImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprGrpLossFactorImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprGrpLossFactorImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprGrpLossFactorImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprGrpLossFactorImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprGrpLossFactorImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprGrpLossFactorImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprGrpLossFactorImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBQuery * TDMSprGrpLossFactorImpl::get_Query(void)
{
return Object->Query;
}
//---------------------------------------------------------------
void TDMSprGrpLossFactorImpl::set_Query(TpFIBQuery * Query)
{
Object->Query=Query;
}
//---------------------------------------------------------------
TIntegerField * TDMSprGrpLossFactorImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TDMSprGrpLossFactorImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}

//---------------------------------------------------------------
TFIBLargeIntField * TDMSprGrpLossFactorImpl::get_TableID_SLOSS_FACTOR_GRP(void)
{
return Object->TableID_SLOSS_FACTOR_GRP;
}
//---------------------------------------------------------------
void TDMSprGrpLossFactorImpl::set_TableID_SLOSS_FACTOR_GRP(TFIBLargeIntField * TableID_SLOSS_FACTOR_GRP)
{
Object->TableID_SLOSS_FACTOR_GRP=TableID_SLOSS_FACTOR_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprGrpLossFactorImpl::get_TableGID_SLOSS_FACTOR_GRP(void)
{
return Object->TableGID_SLOSS_FACTOR_GRP;
}
//---------------------------------------------------------------
void TDMSprGrpLossFactorImpl::set_TableGID_SLOSS_FACTOR_GRP(TFIBWideStringField * TableGID_SLOSS_FACTOR_GRP)
{
Object->TableGID_SLOSS_FACTOR_GRP=TableGID_SLOSS_FACTOR_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprGrpLossFactorImpl::get_TableIDBASE_SLOSS_FACTOR_GRP(void)
{
return Object->TableIDBASE_SLOSS_FACTOR_GRP;
}
//---------------------------------------------------------------
void TDMSprGrpLossFactorImpl::set_TableIDBASE_SLOSS_FACTOR_GRP(TFIBLargeIntField * TableIDBASE_SLOSS_FACTOR_GRP)
{
Object->TableIDBASE_SLOSS_FACTOR_GRP=TableIDBASE_SLOSS_FACTOR_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprGrpLossFactorImpl::get_TableIDGRP_SLOSS_FACTOR_GRP(void)
{
return Object->TableIDGRP_SLOSS_FACTOR_GRP;
}
//---------------------------------------------------------------
void TDMSprGrpLossFactorImpl::set_TableIDGRP_SLOSS_FACTOR_GRP(TFIBLargeIntField * TableIDGRP_SLOSS_FACTOR_GRP)
{
Object->TableIDGRP_SLOSS_FACTOR_GRP=TableIDGRP_SLOSS_FACTOR_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprGrpLossFactorImpl::get_TableNAME_SLOSS_FACTOR_GRP(void)
{
return Object->TableNAME_SLOSS_FACTOR_GRP;
}
//---------------------------------------------------------------
void TDMSprGrpLossFactorImpl::set_TableNAME_SLOSS_FACTOR_GRP(TFIBWideStringField * TableNAME_SLOSS_FACTOR_GRP)
{
Object->TableNAME_SLOSS_FACTOR_GRP=TableNAME_SLOSS_FACTOR_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprGrpLossFactorImpl::get_ElementID_SLOSS_FACTOR_GRP(void)
{
return Object->ElementID_SLOSS_FACTOR_GRP;
}
//---------------------------------------------------------------
void TDMSprGrpLossFactorImpl::set_ElementID_SLOSS_FACTOR_GRP(TFIBLargeIntField * ElementID_SLOSS_FACTOR_GRP)
{
Object->ElementID_SLOSS_FACTOR_GRP=ElementID_SLOSS_FACTOR_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprGrpLossFactorImpl::get_ElementGID_SLOSS_FACTOR_GRP(void)
{
return Object->ElementGID_SLOSS_FACTOR_GRP;
}
//---------------------------------------------------------------
void TDMSprGrpLossFactorImpl::set_ElementGID_SLOSS_FACTOR_GRP(TFIBWideStringField * ElementGID_SLOSS_FACTOR_GRP)
{
Object->ElementGID_SLOSS_FACTOR_GRP=ElementGID_SLOSS_FACTOR_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprGrpLossFactorImpl::get_ElementIDBASE_SLOSS_FACTOR_GRP(void)
{
return Object->ElementIDBASE_SLOSS_FACTOR_GRP;
}
//---------------------------------------------------------------
void TDMSprGrpLossFactorImpl::set_ElementIDBASE_SLOSS_FACTOR_GRP(TFIBLargeIntField * ElementIDBASE_SLOSS_FACTOR_GRP)
{
Object->ElementIDBASE_SLOSS_FACTOR_GRP=ElementIDBASE_SLOSS_FACTOR_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprGrpLossFactorImpl::get_ElementIDGRP_SLOSS_FACTOR_GRP(void)
{
return Object->ElementIDGRP_SLOSS_FACTOR_GRP;
}
//---------------------------------------------------------------
void TDMSprGrpLossFactorImpl::set_ElementIDGRP_SLOSS_FACTOR_GRP(TFIBLargeIntField * ElementIDGRP_SLOSS_FACTOR_GRP)
{
Object->ElementIDGRP_SLOSS_FACTOR_GRP=ElementIDGRP_SLOSS_FACTOR_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprGrpLossFactorImpl::get_ElementNAME_SLOSS_FACTOR_GRP(void)
{
return Object->ElementNAME_SLOSS_FACTOR_GRP;
}
//---------------------------------------------------------------
void TDMSprGrpLossFactorImpl::set_ElementNAME_SLOSS_FACTOR_GRP(TFIBWideStringField * ElementNAME_SLOSS_FACTOR_GRP)
{
Object->ElementNAME_SLOSS_FACTOR_GRP=ElementNAME_SLOSS_FACTOR_GRP;
}
//---------------------------------------------------------------
bool TDMSprGrpLossFactorImpl::OpenTable(void)
{
return Object->OpenTable();
}
//---------------------------------------------------------------
bool TDMSprGrpLossFactorImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
bool TDMSprGrpLossFactorImpl::NewElement(__int64 id_grp)
{
return Object->NewElement(id_grp);
}
//---------------------------------------------------------------
bool TDMSprGrpLossFactorImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TDMSprGrpLossFactorImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement( id);
}
//---------------------------------------------------------------
__int64 TDMSprGrpLossFactorImpl::GetIDElement(UnicodeString gid)
{
return Object->GetIDElement(gid);
}
//---------------------------------------------------------------
UnicodeString TDMSprGrpLossFactorImpl::GetGIDElement(__int64 id)
{
return Object->GetGIDElement(id);
}
//---------------------------------------------------------------
__int64 TDMSprGrpLossFactorImpl::FindPoName(UnicodeString name)
{
return Object->FindPoName(name);
}
//---------------------------------------------------------------
