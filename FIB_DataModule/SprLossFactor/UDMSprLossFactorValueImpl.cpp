#include "vcl.h"
#pragma hdrstop


#include "UDMSprLossFactorValueImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprLossFactorValueImpl::TDMSprLossFactorValueImpl()           
{                                            
Object=new TDMSprLossFactorValue(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprLossFactorValueImpl::~TDMSprLossFactorValueImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprLossFactorValueImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprLossFactorValueImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprLossFactorValue)                        
   {                                                                     
   *ppv=static_cast<IDMSprLossFactorValue*> (this);                                
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
int TDMSprLossFactorValueImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprLossFactorValueImpl::kanRelease(void)                                  
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
int  TDMSprLossFactorValueImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprLossFactorValueImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprLossFactorValueImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprLossFactorValueImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprLossFactorValueImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMSprLossFactorValueImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMSprLossFactorValueImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMSprLossFactorValue
TDataSource * TDMSprLossFactorValueImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprLossFactorValueImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprLossFactorValueImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprLossFactorValueImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprLossFactorValueImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprLossFactorValueImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprLossFactorValueImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprLossFactorValueImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprLossFactorValueImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprLossFactorValueImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBQuery * TDMSprLossFactorValueImpl::get_Query(void)
{
return Object->Query;
}
//---------------------------------------------------------------
void TDMSprLossFactorValueImpl::set_Query(TpFIBQuery * Query)
{
Object->Query=Query;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprLossFactorValueImpl::get_FactorList(void)
{
return Object->FactorList;
}
//---------------------------------------------------------------
void TDMSprLossFactorValueImpl::set_FactorList(TpFIBDataSet * FactorList)
{
Object->FactorList=FactorList;
}
//---------------------------------------------------------------
TDataSource * TDMSprLossFactorValueImpl::get_DataSourceFactorList(void)
{
return Object->DataSourceFactorList;
}
//---------------------------------------------------------------
void TDMSprLossFactorValueImpl::set_DataSourceFactorList(TDataSource * DataSourceFactorList)
{
Object->DataSourceFactorList=DataSourceFactorList;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprLossFactorValueImpl::get_FactorListID_SFACTOR(void)
{
return Object->FactorListID_SFACTOR;
}
//---------------------------------------------------------------
void TDMSprLossFactorValueImpl::set_FactorListID_SFACTOR(TFIBLargeIntField * FactorListID_SFACTOR)
{
Object->FactorListID_SFACTOR=FactorListID_SFACTOR;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprLossFactorValueImpl::get_FactorListNAME_SFACTOR(void)
{
return Object->FactorListNAME_SFACTOR;
}
//---------------------------------------------------------------
void TDMSprLossFactorValueImpl::set_FactorListNAME_SFACTOR(TFIBWideStringField * FactorListNAME_SFACTOR)
{
Object->FactorListNAME_SFACTOR=FactorListNAME_SFACTOR;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprLossFactorValueImpl::get_TableID_SLOSS_FACTOR_VAL(void)
{
return Object->TableID_SLOSS_FACTOR_VAL;
}
//---------------------------------------------------------------
void TDMSprLossFactorValueImpl::set_TableID_SLOSS_FACTOR_VAL(TFIBLargeIntField * TableID_SLOSS_FACTOR_VAL)
{
Object->TableID_SLOSS_FACTOR_VAL=TableID_SLOSS_FACTOR_VAL;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprLossFactorValueImpl::get_TableGID_SLOSS_FACTOR_VAL(void)
{
return Object->TableGID_SLOSS_FACTOR_VAL;
}
//---------------------------------------------------------------
void TDMSprLossFactorValueImpl::set_TableGID_SLOSS_FACTOR_VAL(TFIBWideStringField * TableGID_SLOSS_FACTOR_VAL)
{
Object->TableGID_SLOSS_FACTOR_VAL=TableGID_SLOSS_FACTOR_VAL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprLossFactorValueImpl::get_TableIDBASE_SLOSS_FACTOR_VAL(void)
{
return Object->TableIDBASE_SLOSS_FACTOR_VAL;
}
//---------------------------------------------------------------
void TDMSprLossFactorValueImpl::set_TableIDBASE_SLOSS_FACTOR_VAL(TFIBLargeIntField * TableIDBASE_SLOSS_FACTOR_VAL)
{
Object->TableIDBASE_SLOSS_FACTOR_VAL=TableIDBASE_SLOSS_FACTOR_VAL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprLossFactorValueImpl::get_TableIDFACTOR_SLOSS_FACTOR_VAL(void)
{
return Object->TableIDFACTOR_SLOSS_FACTOR_VAL;
}
//---------------------------------------------------------------
void TDMSprLossFactorValueImpl::set_TableIDFACTOR_SLOSS_FACTOR_VAL(TFIBLargeIntField * TableIDFACTOR_SLOSS_FACTOR_VAL)
{
Object->TableIDFACTOR_SLOSS_FACTOR_VAL=TableIDFACTOR_SLOSS_FACTOR_VAL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprLossFactorValueImpl::get_TableIDLOSS_FACTOR_SLOSS_FACTOR_VAL(void)
{
return Object->TableIDLOSS_FACTOR_SLOSS_FACTOR_VAL;
}
//---------------------------------------------------------------
void TDMSprLossFactorValueImpl::set_TableIDLOSS_FACTOR_SLOSS_FACTOR_VAL(TFIBLargeIntField * TableIDLOSS_FACTOR_SLOSS_FACTOR_VAL)
{
Object->TableIDLOSS_FACTOR_SLOSS_FACTOR_VAL=TableIDLOSS_FACTOR_SLOSS_FACTOR_VAL;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprLossFactorValueImpl::get_TableVAL_SLOSS_FACTOR_VAL(void)
{
return Object->TableVAL_SLOSS_FACTOR_VAL;
}
//---------------------------------------------------------------
void TDMSprLossFactorValueImpl::set_TableVAL_SLOSS_FACTOR_VAL(TFIBBCDField * TableVAL_SLOSS_FACTOR_VAL)
{
Object->TableVAL_SLOSS_FACTOR_VAL=TableVAL_SLOSS_FACTOR_VAL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprLossFactorValueImpl::get_ElementID_SLOSS_FACTOR_VAL(void)
{
return Object->ElementID_SLOSS_FACTOR_VAL;
}
//---------------------------------------------------------------
void TDMSprLossFactorValueImpl::set_ElementID_SLOSS_FACTOR_VAL(TFIBLargeIntField * ElementID_SLOSS_FACTOR_VAL)
{
Object->ElementID_SLOSS_FACTOR_VAL=ElementID_SLOSS_FACTOR_VAL;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprLossFactorValueImpl::get_ElementGID_SLOSS_FACTOR_VAL(void)
{
return Object->ElementGID_SLOSS_FACTOR_VAL;
}
//---------------------------------------------------------------
void TDMSprLossFactorValueImpl::set_ElementGID_SLOSS_FACTOR_VAL(TFIBWideStringField * ElementGID_SLOSS_FACTOR_VAL)
{
Object->ElementGID_SLOSS_FACTOR_VAL=ElementGID_SLOSS_FACTOR_VAL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprLossFactorValueImpl::get_ElementIDBASE_SLOSS_FACTOR_VAL(void)
{
return Object->ElementIDBASE_SLOSS_FACTOR_VAL;
}
//---------------------------------------------------------------
void TDMSprLossFactorValueImpl::set_ElementIDBASE_SLOSS_FACTOR_VAL(TFIBLargeIntField * ElementIDBASE_SLOSS_FACTOR_VAL)
{
Object->ElementIDBASE_SLOSS_FACTOR_VAL=ElementIDBASE_SLOSS_FACTOR_VAL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprLossFactorValueImpl::get_ElementIDFACTOR_SLOSS_FACTOR_VAL(void)
{
return Object->ElementIDFACTOR_SLOSS_FACTOR_VAL;
}
//---------------------------------------------------------------
void TDMSprLossFactorValueImpl::set_ElementIDFACTOR_SLOSS_FACTOR_VAL(TFIBLargeIntField * ElementIDFACTOR_SLOSS_FACTOR_VAL)
{
Object->ElementIDFACTOR_SLOSS_FACTOR_VAL=ElementIDFACTOR_SLOSS_FACTOR_VAL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprLossFactorValueImpl::get_ElementIDLOSS_FACTOR_SLOSS_FACTOR_VAL(void)
{
return Object->ElementIDLOSS_FACTOR_SLOSS_FACTOR_VAL;
}
//---------------------------------------------------------------
void TDMSprLossFactorValueImpl::set_ElementIDLOSS_FACTOR_SLOSS_FACTOR_VAL(TFIBLargeIntField * ElementIDLOSS_FACTOR_SLOSS_FACTOR_VAL)
{
Object->ElementIDLOSS_FACTOR_SLOSS_FACTOR_VAL=ElementIDLOSS_FACTOR_SLOSS_FACTOR_VAL;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprLossFactorValueImpl::get_ElementVAL_SLOSS_FACTOR_VAL(void)
{
return Object->ElementVAL_SLOSS_FACTOR_VAL;
}
//---------------------------------------------------------------
void TDMSprLossFactorValueImpl::set_ElementVAL_SLOSS_FACTOR_VAL(TFIBBCDField * ElementVAL_SLOSS_FACTOR_VAL)
{
Object->ElementVAL_SLOSS_FACTOR_VAL=ElementVAL_SLOSS_FACTOR_VAL;
}
//---------------------------------------------------------------
__int64 TDMSprLossFactorValueImpl::get_IdFactor(void)
{
return Object->IdFactor;
}
//---------------------------------------------------------------
void TDMSprLossFactorValueImpl::set_IdFactor(__int64 IdFactor)
{
Object->IdFactor=IdFactor;
}
//---------------------------------------------------------------
__int64 TDMSprLossFactorValueImpl::get_IdLossFactor(void)
{
return Object->IdLossFactor;
}
//---------------------------------------------------------------
void TDMSprLossFactorValueImpl::set_IdLossFactor(__int64 IdLossFactor)
{
Object->IdLossFactor=IdLossFactor;
}
//---------------------------------------------------------------
bool TDMSprLossFactorValueImpl::OpenTable(__int64 id_loss_factor)
{
return Object->OpenTable(id_loss_factor);
}
//---------------------------------------------------------------
bool TDMSprLossFactorValueImpl::SaveIsmen(void)
{
return Object->SaveIsmen();
}
//---------------------------------------------------------------
void TDMSprLossFactorValueImpl::CancelIsmen(void)
{
return Object->CancelIsmen();
}
//---------------------------------------------------------------
bool TDMSprLossFactorValueImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
bool TDMSprLossFactorValueImpl::NewElement(void)
{
return Object->NewElement();
}
//---------------------------------------------------------------
bool TDMSprLossFactorValueImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TDMSprLossFactorValueImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
__int64 TDMSprLossFactorValueImpl::FindElement(__int64 id_factor, __int64 id_loss_factor)
{
return Object->FindElement(id_factor,id_loss_factor);
}
//---------------------------------------------------------------
bool TDMSprLossFactorValueImpl::UpdateSpisokFactors(void)
{
return Object->UpdateSpisokFactors();
}
//---------------------------------------------------------------
