#include <vcl.h>
#pragma hdrstop


#include "UDMSprOKEIImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprOKEIImpl::TDMSprOKEIImpl()           
{                                            
Object=new TDMSprOKEI(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprOKEIImpl::~TDMSprOKEIImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprOKEIImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprOKEIImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprOKEI)                        
   {                                                                     
   *ppv=static_cast<IDMSprOKEI*> (this);                                
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
int TDMSprOKEIImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprOKEIImpl::kanRelease(void)                                  
{                                                                      
if (--NumRefs==0)                                                     
   {                                                                  
   delete this;                                                       
   }                                                                  
return NumRefs;                                                       
}                                                                     
//---------------------------------------------------------------

//IMainInterface 

//---------------------------------------------------------------
int  TDMSprOKEIImpl::get_CodeError(void)                      
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprOKEIImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprOKEIImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprOKEIImpl::set_TextError(UnicodeString  TextError)
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprOKEIImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object)
{
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl);
kanRelease();
Object->ClsIdImpl=CLSID_TDMSprOKEIImpl;
Object->InterfaceMainObject=i_main_object;
Object->InterfaceOwnerObject=i_owner_object;
return Object->Init();
}
//---------------------------------------------------------------
int TDMSprOKEIImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//INameModulEdit->Text
TDataSource * TDMSprOKEIImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprOKEIImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TDMSprOKEIImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TDMSprOKEIImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprOKEIImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprOKEIImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprOKEIImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprOKEIImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprOKEIImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprOKEIImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprOKEIImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprOKEIImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TIntegerField * TDMSprOKEIImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TDMSprOKEIImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprOKEIImpl::get_TableIDOKEI(void)
{
return Object->TableIDOKEI;
}
//---------------------------------------------------------------
void TDMSprOKEIImpl::set_TableIDOKEI(TFIBBCDField * TableIDOKEI)
{
Object->TableIDOKEI=TableIDOKEI;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprOKEIImpl::get_ElementIDOKEI(void)
{
return Object->ElementIDOKEI;
}
//---------------------------------------------------------------
void TDMSprOKEIImpl::set_ElementIDOKEI(TFIBBCDField * ElementIDOKEI)
{
Object->ElementIDOKEI=ElementIDOKEI;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprOKEIImpl::get_TableNAMEOKEI(void)
{
return Object->TableNAMEOKEI;
}
//---------------------------------------------------------------
void TDMSprOKEIImpl::set_TableNAMEOKEI(TFIBWideStringField * TableNAMEOKEI)
{
Object->TableNAMEOKEI=TableNAMEOKEI;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprOKEIImpl::get_TableCODEOKEI(void)
{
return Object->TableCODEOKEI;
}
//---------------------------------------------------------------
void TDMSprOKEIImpl::set_TableCODEOKEI(TFIBIntegerField * TableCODEOKEI)
{
Object->TableCODEOKEI=TableCODEOKEI;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprOKEIImpl::get_TableGID_SOKEI(void)
{
return Object->TableGID_SOKEI;
}
//---------------------------------------------------------------
void TDMSprOKEIImpl::set_TableGID_SOKEI(TFIBWideStringField * TableGID_SOKEI)
{
Object->TableGID_SOKEI=TableGID_SOKEI;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprOKEIImpl::get_TableIDBASE_SOKEI(void)
{
return Object->TableIDBASE_SOKEI;
}
//---------------------------------------------------------------
void TDMSprOKEIImpl::set_TableIDBASE_SOKEI(TFIBBCDField * TableIDBASE_SOKEI)
{
Object->TableIDBASE_SOKEI=TableIDBASE_SOKEI;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprOKEIImpl::get_ElementNAMEOKEI(void)
{
return Object->ElementNAMEOKEI;
}
//---------------------------------------------------------------
void TDMSprOKEIImpl::set_ElementNAMEOKEI(TFIBWideStringField * ElementNAMEOKEI)
{
Object->ElementNAMEOKEI=ElementNAMEOKEI;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprOKEIImpl::get_ElementCODEOKEI(void)
{
return Object->ElementCODEOKEI;
}
//---------------------------------------------------------------
void TDMSprOKEIImpl::set_ElementCODEOKEI(TFIBIntegerField * ElementCODEOKEI)
{
Object->ElementCODEOKEI=ElementCODEOKEI;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprOKEIImpl::get_ElementGID_SOKEI(void)
{
return Object->ElementGID_SOKEI;
}
//---------------------------------------------------------------
void TDMSprOKEIImpl::set_ElementGID_SOKEI(TFIBWideStringField * ElementGID_SOKEI)
{
Object->ElementGID_SOKEI=ElementGID_SOKEI;
}
//---------------------------------------------------------------
void TDMSprOKEIImpl::OpenTable()
{
return Object->OpenTable();
}
//---------------------------------------------------------------
int TDMSprOKEIImpl::OpenElement(__int64 Id)
{
return Object->OpenElement(Id);
}
//---------------------------------------------------------------
void TDMSprOKEIImpl::NewElement()
{
return Object->NewElement();
}
//---------------------------------------------------------------
bool TDMSprOKEIImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
void TDMSprOKEIImpl::DeleteElement(__int64 Id)
{
return Object->DeleteElement(Id);
}
//---------------------------------------------------------------
