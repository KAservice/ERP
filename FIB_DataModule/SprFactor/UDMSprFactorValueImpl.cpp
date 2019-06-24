#include "vcl.h"
#pragma hdrstop


#include "UDMSprFactorValueImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprFactorValueImpl::TDMSprFactorValueImpl()           
{                                            
Object=new TDMSprFactorValue(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprFactorValueImpl::~TDMSprFactorValueImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprFactorValueImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprFactorValueImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprFactorValue)                        
   {                                                                     
   *ppv=static_cast<IDMSprFactorValue*> (this);                                
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
int TDMSprFactorValueImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprFactorValueImpl::kanRelease(void)                                  
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
int  TDMSprFactorValueImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprFactorValueImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprFactorValueImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprFactorValueImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprFactorValueImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMSprFactorValueImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMSprFactorValueImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMSprFactorValue
TDataSource * TDMSprFactorValueImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprFactorValueImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprFactorValueImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprFactorValueImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprFactorValueImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprFactorValueImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprFactorValueImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprFactorValueImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprFactorValueImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprFactorValueImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBQuery * TDMSprFactorValueImpl::get_Query(void)
{
return Object->Query;
}
//---------------------------------------------------------------
void TDMSprFactorValueImpl::set_Query(TpFIBQuery * Query)
{
Object->Query=Query;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprFactorValueImpl::get_FactorList(void)
{
return Object->FactorList;
}
//---------------------------------------------------------------
void TDMSprFactorValueImpl::set_FactorList(TpFIBDataSet * FactorList)
{
Object->FactorList=FactorList;
}
//---------------------------------------------------------------
TDataSource * TDMSprFactorValueImpl::get_DataSourceFactorList(void)
{
return Object->DataSourceFactorList;
}
//---------------------------------------------------------------
void TDMSprFactorValueImpl::set_DataSourceFactorList(TDataSource * DataSourceFactorList)
{
Object->DataSourceFactorList=DataSourceFactorList;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprFactorValueImpl::get_FactorListID_SFACTOR(void)
{
return Object->FactorListID_SFACTOR;
}
//---------------------------------------------------------------
void TDMSprFactorValueImpl::set_FactorListID_SFACTOR(TFIBLargeIntField * FactorListID_SFACTOR)
{
Object->FactorListID_SFACTOR=FactorListID_SFACTOR;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprFactorValueImpl::get_FactorListNAME_SFACTOR(void)
{
return Object->FactorListNAME_SFACTOR;
}
//---------------------------------------------------------------
void TDMSprFactorValueImpl::set_FactorListNAME_SFACTOR(TFIBWideStringField * FactorListNAME_SFACTOR)
{
Object->FactorListNAME_SFACTOR=FactorListNAME_SFACTOR;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprFactorValueImpl::get_TableID_SFACTOR_VAL(void)
{
return Object->TableID_SFACTOR_VAL;
}
//---------------------------------------------------------------
void TDMSprFactorValueImpl::set_TableID_SFACTOR_VAL(TFIBLargeIntField * TableID_SFACTOR_VAL)
{
Object->TableID_SFACTOR_VAL=TableID_SFACTOR_VAL;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprFactorValueImpl::get_TableGID_SFACTOR_VAL(void)
{
return Object->TableGID_SFACTOR_VAL;
}
//---------------------------------------------------------------
void TDMSprFactorValueImpl::set_TableGID_SFACTOR_VAL(TFIBWideStringField * TableGID_SFACTOR_VAL)
{
Object->TableGID_SFACTOR_VAL=TableGID_SFACTOR_VAL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprFactorValueImpl::get_TableIDBASE_SFACTOR_VAL(void)
{
return Object->TableIDBASE_SFACTOR_VAL;
}
//---------------------------------------------------------------
void TDMSprFactorValueImpl::set_TableIDBASE_SFACTOR_VAL(TFIBLargeIntField * TableIDBASE_SFACTOR_VAL)
{
Object->TableIDBASE_SFACTOR_VAL=TableIDBASE_SFACTOR_VAL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprFactorValueImpl::get_TableIDPRODUCE_SFACTOR_VAL(void)
{
return Object->TableIDPRODUCE_SFACTOR_VAL;
}
//---------------------------------------------------------------
void TDMSprFactorValueImpl::set_TableIDPRODUCE_SFACTOR_VAL(TFIBLargeIntField * TableIDPRODUCE_SFACTOR_VAL)
{
Object->TableIDPRODUCE_SFACTOR_VAL=TableIDPRODUCE_SFACTOR_VAL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprFactorValueImpl::get_TableIDFACTOR_SFACTOR_VAL(void)
{
return Object->TableIDFACTOR_SFACTOR_VAL;
}
//---------------------------------------------------------------
void TDMSprFactorValueImpl::set_TableIDFACTOR_SFACTOR_VAL(TFIBLargeIntField * TableIDFACTOR_SFACTOR_VAL)
{
Object->TableIDFACTOR_SFACTOR_VAL=TableIDFACTOR_SFACTOR_VAL;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprFactorValueImpl::get_TableVALUE_SFACTOR_VAL(void)
{
return Object->TableVALUE_SFACTOR_VAL;
}
//---------------------------------------------------------------
void TDMSprFactorValueImpl::set_TableVALUE_SFACTOR_VAL(TFIBBCDField * TableVALUE_SFACTOR_VAL)
{
Object->TableVALUE_SFACTOR_VAL=TableVALUE_SFACTOR_VAL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprFactorValueImpl::get_ElementID_SFACTOR_VAL(void)
{
return Object->ElementID_SFACTOR_VAL;
}
//---------------------------------------------------------------
void TDMSprFactorValueImpl::set_ElementID_SFACTOR_VAL(TFIBLargeIntField * ElementID_SFACTOR_VAL)
{
Object->ElementID_SFACTOR_VAL=ElementID_SFACTOR_VAL;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprFactorValueImpl::get_ElementGID_SFACTOR_VAL(void)
{
return Object->ElementGID_SFACTOR_VAL;
}
//---------------------------------------------------------------
void TDMSprFactorValueImpl::set_ElementGID_SFACTOR_VAL(TFIBWideStringField * ElementGID_SFACTOR_VAL)
{
Object->ElementGID_SFACTOR_VAL=ElementGID_SFACTOR_VAL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprFactorValueImpl::get_ElementIDBASE_SFACTOR_VAL(void)
{
return Object->ElementIDBASE_SFACTOR_VAL;
}
//---------------------------------------------------------------
void TDMSprFactorValueImpl::set_ElementIDBASE_SFACTOR_VAL(TFIBLargeIntField * ElementIDBASE_SFACTOR_VAL)
{
Object->ElementIDBASE_SFACTOR_VAL=ElementIDBASE_SFACTOR_VAL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprFactorValueImpl::get_ElementIDPRODUCE_SFACTOR_VAL(void)
{
return Object->ElementIDPRODUCE_SFACTOR_VAL;
}
//---------------------------------------------------------------
void TDMSprFactorValueImpl::set_ElementIDPRODUCE_SFACTOR_VAL(TFIBLargeIntField * ElementIDPRODUCE_SFACTOR_VAL)
{
Object->ElementIDPRODUCE_SFACTOR_VAL=ElementIDPRODUCE_SFACTOR_VAL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprFactorValueImpl::get_ElementIDFACTOR_SFACTOR_VAL(void)
{
return Object->ElementIDFACTOR_SFACTOR_VAL;
}
//---------------------------------------------------------------
void TDMSprFactorValueImpl::set_ElementIDFACTOR_SFACTOR_VAL(TFIBLargeIntField * ElementIDFACTOR_SFACTOR_VAL)
{
Object->ElementIDFACTOR_SFACTOR_VAL=ElementIDFACTOR_SFACTOR_VAL;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprFactorValueImpl::get_ElementVALUE_SFACTOR_VAL(void)
{
return Object->ElementVALUE_SFACTOR_VAL;
}
//---------------------------------------------------------------
void TDMSprFactorValueImpl::set_ElementVALUE_SFACTOR_VAL(TFIBBCDField * ElementVALUE_SFACTOR_VAL)
{
Object->ElementVALUE_SFACTOR_VAL=ElementVALUE_SFACTOR_VAL;
}
//---------------------------------------------------------------
__int64 TDMSprFactorValueImpl::get_IdFactor(void)
{
return Object->IdFactor;
}
//---------------------------------------------------------------
void TDMSprFactorValueImpl::set_IdFactor(__int64 IdFactor)
{
Object->IdFactor=IdFactor;
}
//---------------------------------------------------------------
__int64 TDMSprFactorValueImpl::get_IdProduce(void)
{
return Object->IdProduce;
}
//---------------------------------------------------------------
void TDMSprFactorValueImpl::set_IdProduce(__int64 IdProduce)
{
Object->IdProduce=IdProduce;
}
//---------------------------------------------------------------
bool TDMSprFactorValueImpl::OpenTable(__int64 id_produce)
{
return Object->OpenTable(id_produce);
}
//---------------------------------------------------------------
bool TDMSprFactorValueImpl::SaveIsmen(void)
{
return Object->SaveIsmen();
}
//---------------------------------------------------------------
void TDMSprFactorValueImpl::CancelIsmen(void)
{
return Object->CancelIsmen();
}
//---------------------------------------------------------------
bool TDMSprFactorValueImpl::OpenElement(__int64 Id)
{
return Object->OpenElement(Id);
}
//---------------------------------------------------------------
bool TDMSprFactorValueImpl::NewElement(void)
{
return Object->NewElement();
}
//---------------------------------------------------------------
bool TDMSprFactorValueImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TDMSprFactorValueImpl::DeleteElement(__int64 Id)
{
return Object->DeleteElement(Id);
}
//---------------------------------------------------------------
__int64 TDMSprFactorValueImpl::FindElement(__int64 id_factor, __int64 id_produce)
{
return Object->FindElement(id_factor,id_produce);
}
//---------------------------------------------------------------
bool TDMSprFactorValueImpl::UpdateSpisokFactors(void)
{
return Object->UpdateSpisokFactors();
}
//---------------------------------------------------------------
