#include <vcl.h>
#pragma hdrstop


#include "UDMSprBrandImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprBrandImpl::TDMSprBrandImpl()           
{                                            
Object=new TDMSprBrand(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprBrandImpl::~TDMSprBrandImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprBrandImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprBrandImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprBrand)                        
   {                                                                     
   *ppv=static_cast<IDMSprBrand*> (this);                                
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
int TDMSprBrandImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprBrandImpl::kanRelease(void)                                  
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
int  TDMSprBrandImpl::get_CodeError(void)                      
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprBrandImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprBrandImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprBrandImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprBrandImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object)
{
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl);
kanRelease();
Object->ClsIdImpl=CLSID_TDMSprBrandImpl;
Object->InterfaceMainObject=i_main_object;
Object->InterfaceOwnerObject=i_owner_object;
return Object->Init();
}
//---------------------------------------------------------------
int TDMSprBrandImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//INameModulEdit->Text
TDataSource * TDMSprBrandImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprBrandImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TDMSprBrandImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TDMSprBrandImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprBrandImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprBrandImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprBrandImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprBrandImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprBrandImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprBrandImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprBrandImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprBrandImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TIntegerField * TDMSprBrandImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TDMSprBrandImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprBrandImpl::get_TableID_SBRAND(void)
{
return Object->TableID_SBRAND;
}
//---------------------------------------------------------------
void TDMSprBrandImpl::set_TableID_SBRAND(TFIBBCDField * TableID_SBRAND)
{
Object->TableID_SBRAND=TableID_SBRAND;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprBrandImpl::get_TableIDBASE_SBRAND(void)
{
return Object->TableIDBASE_SBRAND;
}
//---------------------------------------------------------------
void TDMSprBrandImpl::set_TableIDBASE_SBRAND(TFIBBCDField * TableIDBASE_SBRAND)
{
Object->TableIDBASE_SBRAND=TableIDBASE_SBRAND;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprBrandImpl::get_ElementID_SBRAND(void)
{
return Object->ElementID_SBRAND;
}
//---------------------------------------------------------------
void TDMSprBrandImpl::set_ElementID_SBRAND(TFIBBCDField * ElementID_SBRAND)
{
Object->ElementID_SBRAND=ElementID_SBRAND;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprBrandImpl::get_ElementIDBASE_SBRAND(void)
{
return Object->ElementIDBASE_SBRAND;
}
//---------------------------------------------------------------
void TDMSprBrandImpl::set_ElementIDBASE_SBRAND(TFIBBCDField * ElementIDBASE_SBRAND)
{
Object->ElementIDBASE_SBRAND=ElementIDBASE_SBRAND;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprBrandImpl::get_TableNAME_SBRAND(void)
{
return Object->TableNAME_SBRAND;
}
//---------------------------------------------------------------
void TDMSprBrandImpl::set_TableNAME_SBRAND(TFIBWideStringField * TableNAME_SBRAND)
{
Object->TableNAME_SBRAND=TableNAME_SBRAND;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprBrandImpl::get_ElementNAME_SBRAND(void)
{
return Object->ElementNAME_SBRAND;
}
//---------------------------------------------------------------
void TDMSprBrandImpl::set_ElementNAME_SBRAND(TFIBWideStringField * ElementNAME_SBRAND)
{
Object->ElementNAME_SBRAND=ElementNAME_SBRAND;
}

//---------------------------------------------------------------
bool TDMSprBrandImpl::get_Error(void)
{
return Object->Error;
}
//---------------------------------------------------------------
void TDMSprBrandImpl::set_Error(bool Error)
{
Object->Error=Error;
}
//---------------------------------------------------------------
void TDMSprBrandImpl::OpenTable(void)
{
return Object->OpenTable();
}
//---------------------------------------------------------------
int TDMSprBrandImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
void TDMSprBrandImpl::NewElement(void)
{
return Object->NewElement();
}
//---------------------------------------------------------------
bool TDMSprBrandImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
void TDMSprBrandImpl::CloseElement(void)
{
return Object->CloseElement();
}
//---------------------------------------------------------------
bool TDMSprBrandImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
