#include <vcl.h>
#pragma hdrstop


#include "UDMSprImportSetImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprImportSetImpl::TDMSprImportSetImpl()           
{                                            
Object=new TDMSprImportSet(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprImportSetImpl::~TDMSprImportSetImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprImportSetImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprImportSetImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprImportSet)                        
   {                                                                     
   *ppv=static_cast<IDMSprImportSet*> (this);                                
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
int TDMSprImportSetImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprImportSetImpl::kanRelease(void)                                  
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

//---------------------------------------------------------------
int  TDMSprImportSetImpl::get_CodeError(void)                      
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprImportSetImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprImportSetImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprImportSetImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprImportSetImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object)
{
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl);
kanRelease();
Object->ClsIdImpl=CLSID_TDMSprImportSetImpl;
Object->InterfaceMainObject=i_main_object;
Object->InterfaceOwnerObject=i_owner_object;
return Object->Init();
}
//---------------------------------------------------------------
int TDMSprImportSetImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//INameModulEdit->Text
TDataSource * TDMSprImportSetImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprImportSetImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TDMSprImportSetImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TDMSprImportSetImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprImportSetImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprImportSetImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprImportSetImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprImportSetImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprImportSetImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprImportSetImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprImportSetImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprImportSetImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBQuery * TDMSprImportSetImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TDMSprImportSetImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprImportSetImpl::get_TableID_SIMPORTSET(void)
{
return Object->TableID_SIMPORTSET;
}
//---------------------------------------------------------------
void TDMSprImportSetImpl::set_TableID_SIMPORTSET(TFIBBCDField * TableID_SIMPORTSET)
{
Object->TableID_SIMPORTSET=TableID_SIMPORTSET;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprImportSetImpl::get_TableIDBASE_SIMPORTSET(void)
{
return Object->TableIDBASE_SIMPORTSET;
}
//---------------------------------------------------------------
void TDMSprImportSetImpl::set_TableIDBASE_SIMPORTSET(TFIBBCDField * TableIDBASE_SIMPORTSET)
{
Object->TableIDBASE_SIMPORTSET=TableIDBASE_SIMPORTSET;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprImportSetImpl::get_TableTYPE_SEARCH_SIMPORTSET(void)
{
return Object->TableTYPE_SEARCH_SIMPORTSET;
}
//---------------------------------------------------------------
void TDMSprImportSetImpl::set_TableTYPE_SEARCH_SIMPORTSET(TFIBSmallIntField * TableTYPE_SEARCH_SIMPORTSET)
{
Object->TableTYPE_SEARCH_SIMPORTSET=TableTYPE_SEARCH_SIMPORTSET;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprImportSetImpl::get_TableTYPE_OBR_SIMPORTSET(void)
{
return Object->TableTYPE_OBR_SIMPORTSET;
}
//---------------------------------------------------------------
void TDMSprImportSetImpl::set_TableTYPE_OBR_SIMPORTSET(TFIBSmallIntField * TableTYPE_OBR_SIMPORTSET)
{
Object->TableTYPE_OBR_SIMPORTSET=TableTYPE_OBR_SIMPORTSET;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprImportSetImpl::get_ElementID_SIMPORTSET(void)
{
return Object->ElementID_SIMPORTSET;
}
//---------------------------------------------------------------
void TDMSprImportSetImpl::set_ElementID_SIMPORTSET(TFIBBCDField * ElementID_SIMPORTSET)
{
Object->ElementID_SIMPORTSET=ElementID_SIMPORTSET;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprImportSetImpl::get_ElementIDBASE_SIMPORTSET(void)
{
return Object->ElementIDBASE_SIMPORTSET;
}
//---------------------------------------------------------------
void TDMSprImportSetImpl::set_ElementIDBASE_SIMPORTSET(TFIBBCDField * ElementIDBASE_SIMPORTSET)
{
Object->ElementIDBASE_SIMPORTSET=ElementIDBASE_SIMPORTSET;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprImportSetImpl::get_ElementTYPE_SEARCH_SIMPORTSET(void)
{
return Object->ElementTYPE_SEARCH_SIMPORTSET;
}
//---------------------------------------------------------------
void TDMSprImportSetImpl::set_ElementTYPE_SEARCH_SIMPORTSET(TFIBSmallIntField * ElementTYPE_SEARCH_SIMPORTSET)
{
Object->ElementTYPE_SEARCH_SIMPORTSET=ElementTYPE_SEARCH_SIMPORTSET;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprImportSetImpl::get_ElementTYPE_OBR_SIMPORTSET(void)
{
return Object->ElementTYPE_OBR_SIMPORTSET;
}
//---------------------------------------------------------------
void TDMSprImportSetImpl::set_ElementTYPE_OBR_SIMPORTSET(TFIBSmallIntField * ElementTYPE_OBR_SIMPORTSET)
{
Object->ElementTYPE_OBR_SIMPORTSET=ElementTYPE_OBR_SIMPORTSET;
}
//---------------------------------------------------------------
TIntegerField * TDMSprImportSetImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TDMSprImportSetImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprImportSetImpl::get_TableNAME_SIMPORTSET(void)
{
return Object->TableNAME_SIMPORTSET;
}
//---------------------------------------------------------------
void TDMSprImportSetImpl::set_TableNAME_SIMPORTSET(TFIBWideStringField * TableNAME_SIMPORTSET)
{
Object->TableNAME_SIMPORTSET=TableNAME_SIMPORTSET;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprImportSetImpl::get_TableSTRPAR_SIMPORTSET(void)
{
return Object->TableSTRPAR_SIMPORTSET;
}
//---------------------------------------------------------------
void TDMSprImportSetImpl::set_TableSTRPAR_SIMPORTSET(TFIBWideStringField * TableSTRPAR_SIMPORTSET)
{
Object->TableSTRPAR_SIMPORTSET=TableSTRPAR_SIMPORTSET;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprImportSetImpl::get_TableDIR_SIMPORTSET(void)
{
return Object->TableDIR_SIMPORTSET;
}
//---------------------------------------------------------------
void TDMSprImportSetImpl::set_TableDIR_SIMPORTSET(TFIBWideStringField * TableDIR_SIMPORTSET)
{
Object->TableDIR_SIMPORTSET=TableDIR_SIMPORTSET;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprImportSetImpl::get_ElementNAME_SIMPORTSET(void)
{
return Object->ElementNAME_SIMPORTSET;
}
//---------------------------------------------------------------
void TDMSprImportSetImpl::set_ElementNAME_SIMPORTSET(TFIBWideStringField * ElementNAME_SIMPORTSET)
{
Object->ElementNAME_SIMPORTSET=ElementNAME_SIMPORTSET;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprImportSetImpl::get_ElementSTRPAR_SIMPORTSET(void)
{
return Object->ElementSTRPAR_SIMPORTSET;
}
//---------------------------------------------------------------
void TDMSprImportSetImpl::set_ElementSTRPAR_SIMPORTSET(TFIBWideStringField * ElementSTRPAR_SIMPORTSET)
{
Object->ElementSTRPAR_SIMPORTSET=ElementSTRPAR_SIMPORTSET;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprImportSetImpl::get_ElementDIR_SIMPORTSET(void)
{
return Object->ElementDIR_SIMPORTSET;
}
//---------------------------------------------------------------
void TDMSprImportSetImpl::set_ElementDIR_SIMPORTSET(TFIBWideStringField * ElementDIR_SIMPORTSET)
{
Object->ElementDIR_SIMPORTSET=ElementDIR_SIMPORTSET;
}
//---------------------------------------------------------------
int TDMSprImportSetImpl::get_TypeObr(void)
{
return Object->TypeObr;
}
//---------------------------------------------------------------
void TDMSprImportSetImpl::set_TypeObr(int TypeObr)
{
Object->TypeObr=TypeObr;
}
//---------------------------------------------------------------
void TDMSprImportSetImpl::OpenTable(void)
{
return Object->OpenTable();
}
//---------------------------------------------------------------
int TDMSprImportSetImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
bool TDMSprImportSetImpl::NewElement(void)
{
return Object->NewElement();
}
//---------------------------------------------------------------
bool TDMSprImportSetImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
void TDMSprImportSetImpl::CloseElement(void)
{
return Object->CloseElement();
}
//---------------------------------------------------------------
bool TDMSprImportSetImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
__int64 TDMSprImportSetImpl::GetIDElement(String gid)
{
return Object->GetIDElement(gid);
}
//---------------------------------------------------------------
AnsiString TDMSprImportSetImpl::GetGIDElement(__int64 id)
{
return Object->GetGIDElement(id);
}
//---------------------------------------------------------------
int TDMSprImportSetImpl::GetIndexElementaPoID(__int64 id)
{
return Object->GetIndexElementaPoID(id);
}
//---------------------------------------------------------------
AnsiString TDMSprImportSetImpl::GetParameter(AnsiString parameter)
{
return Object->GetParameter(parameter);
}
//---------------------------------------------------------------
