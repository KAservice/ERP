#include "vcl.h"
#pragma hdrstop


#include "UDMSprTypeNomImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprTypeNomImpl::TDMSprTypeNomImpl()           
{                                            
Object=new TDMSprTypeNom(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprTypeNomImpl::~TDMSprTypeNomImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprTypeNomImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprTypeNomImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprTypeNom)                        
   {                                                                     
   *ppv=static_cast<IDMSprTypeNom*> (this);                                
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
int TDMSprTypeNomImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprTypeNomImpl::kanRelease(void)                                  
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
int  TDMSprTypeNomImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprTypeNomImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprTypeNomImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprTypeNomImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprTypeNomImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMSprTypeNomImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMSprTypeNomImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMSprTypeNom
TDataSource * TDMSprTypeNomImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprTypeNomImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TDMSprTypeNomImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TDMSprTypeNomImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprTypeNomImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprTypeNomImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprTypeNomImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprTypeNomImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprTypeNomImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprTypeNomImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprTypeNomImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprTypeNomImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TIntegerField * TDMSprTypeNomImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TDMSprTypeNomImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TpFIBQuery * TDMSprTypeNomImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TDMSprTypeNomImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprTypeNomImpl::get_TableID_STNOM(void)
{
return Object->TableID_STNOM;
}
//---------------------------------------------------------------
void TDMSprTypeNomImpl::set_TableID_STNOM(TFIBLargeIntField * TableID_STNOM)
{
Object->TableID_STNOM=TableID_STNOM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprTypeNomImpl::get_TableIDBASE_STNOM(void)
{
return Object->TableIDBASE_STNOM;
}
//---------------------------------------------------------------
void TDMSprTypeNomImpl::set_TableIDBASE_STNOM(TFIBLargeIntField * TableIDBASE_STNOM)
{
Object->TableIDBASE_STNOM=TableIDBASE_STNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprTypeNomImpl::get_TableNAME_STNOM(void)
{
return Object->TableNAME_STNOM;
}
//---------------------------------------------------------------
void TDMSprTypeNomImpl::set_TableNAME_STNOM(TFIBWideStringField * TableNAME_STNOM)
{
Object->TableNAME_STNOM=TableNAME_STNOM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprTypeNomImpl::get_ElementID_STNOM(void)
{
return Object->ElementID_STNOM;
}
//---------------------------------------------------------------
void TDMSprTypeNomImpl::set_ElementID_STNOM(TFIBLargeIntField * ElementID_STNOM)
{
Object->ElementID_STNOM=ElementID_STNOM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprTypeNomImpl::get_ElementIDBASE_STNOM(void)
{
return Object->ElementIDBASE_STNOM;
}
//---------------------------------------------------------------
void TDMSprTypeNomImpl::set_ElementIDBASE_STNOM(TFIBLargeIntField * ElementIDBASE_STNOM)
{
Object->ElementIDBASE_STNOM=ElementIDBASE_STNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprTypeNomImpl::get_ElementNAME_STNOM(void)
{
return Object->ElementNAME_STNOM;
}
//---------------------------------------------------------------
void TDMSprTypeNomImpl::set_ElementNAME_STNOM(TFIBWideStringField * ElementNAME_STNOM)
{
Object->ElementNAME_STNOM=ElementNAME_STNOM;
}
//---------------------------------------------------------------
bool TDMSprTypeNomImpl::OpenTable(void)
{
return Object->OpenTable();
}
//---------------------------------------------------------------
bool TDMSprTypeNomImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
bool TDMSprTypeNomImpl::NewElement(void)
{
return Object->NewElement();
}
//---------------------------------------------------------------
bool TDMSprTypeNomImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
void TDMSprTypeNomImpl::CloseElement(void)
{
return Object->CloseElement();
}
//---------------------------------------------------------------
bool TDMSprTypeNomImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
__int64 TDMSprTypeNomImpl::GetIdElementPoName(UnicodeString   name)
{
return Object->GetIdElementPoName(name);
}
//---------------------------------------------------------------
int TDMSprTypeNomImpl::GetIndexInTablePoId(__int64 id_element)
{
return Object->GetIndexInTablePoId(id_element);
}
//---------------------------------------------------------------
__int64 TDMSprTypeNomImpl::GetIdElementPoGid(UnicodeString gid)
{
return Object->GetIdElementPoGid(gid);
}
//---------------------------------------------------------------
UnicodeString TDMSprTypeNomImpl::GetGidElementPoId(__int64 id)
{
return Object->GetGidElementPoId(id);
}
//---------------------------------------------------------------
