#include <vcl.h>
#pragma hdrstop


#include "UDMSprStrObjectImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprStrObjectImpl::TDMSprStrObjectImpl()           
{                                            
Object=new TDMSprStrObject(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprStrObjectImpl::~TDMSprStrObjectImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprStrObjectImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprStrObjectImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprStrObject)                        
   {                                                                     
   *ppv=static_cast<IDMSprStrObject*> (this);                                
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
int TDMSprStrObjectImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}
//---------------------------------------------------------------
int TDMSprStrObjectImpl::kanRelease(void)
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
int  TDMSprStrObjectImpl::get_CodeError(void)                      
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprStrObjectImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprStrObjectImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprStrObjectImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprStrObjectImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object)
{
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl);
kanRelease();
Object->ClsIdImpl=CLSID_TDMSprStrObjectImpl;
Object->InterfaceMainObject=i_main_object;
Object->InterfaceOwnerObject=i_owner_object;
return Object->Init();
}
//---------------------------------------------------------------
int TDMSprStrObjectImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//INameModulEdit->Text
TDataSource * TDMSprStrObjectImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprStrObjectImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TDMSprStrObjectImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TDMSprStrObjectImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprStrObjectImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprStrObjectImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprStrObjectImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprStrObjectImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprStrObjectImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprStrObjectImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprStrObjectImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprStrObjectImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TIntegerField * TDMSprStrObjectImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TDMSprStrObjectImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprStrObjectImpl::get_Code(void)
{
return Object->Code;
}
//---------------------------------------------------------------
void TDMSprStrObjectImpl::set_Code(TpFIBDataSet * Code)
{
Object->Code=Code;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprStrObjectImpl::get_CodeMAXCODE(void)
{
return Object->CodeMAXCODE;
}
//---------------------------------------------------------------
void TDMSprStrObjectImpl::set_CodeMAXCODE(TFIBIntegerField * CodeMAXCODE)
{
Object->CodeMAXCODE=CodeMAXCODE;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprStrObjectImpl::get_TableID_STROB(void)
{
return Object->TableID_STROB;
}
//---------------------------------------------------------------
void TDMSprStrObjectImpl::set_TableID_STROB(TFIBBCDField * TableID_STROB)
{
Object->TableID_STROB=TableID_STROB;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprStrObjectImpl::get_TableIDGRP_STROB(void)
{
return Object->TableIDGRP_STROB;
}
//---------------------------------------------------------------
void TDMSprStrObjectImpl::set_TableIDGRP_STROB(TFIBBCDField * TableIDGRP_STROB)
{
Object->TableIDGRP_STROB=TableIDGRP_STROB;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprStrObjectImpl::get_TableGRP_STROB(void)
{
return Object->TableGRP_STROB;
}
//---------------------------------------------------------------
void TDMSprStrObjectImpl::set_TableGRP_STROB(TFIBSmallIntField * TableGRP_STROB)
{
Object->TableGRP_STROB=TableGRP_STROB;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprStrObjectImpl::get_ElementID_STROB(void)
{
return Object->ElementID_STROB;
}
//---------------------------------------------------------------
void TDMSprStrObjectImpl::set_ElementID_STROB(TFIBBCDField * ElementID_STROB)
{
Object->ElementID_STROB=ElementID_STROB;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprStrObjectImpl::get_ElementIDGRP_STROB(void)
{
return Object->ElementIDGRP_STROB;
}
//---------------------------------------------------------------
void TDMSprStrObjectImpl::set_ElementIDGRP_STROB(TFIBBCDField * ElementIDGRP_STROB)
{
Object->ElementIDGRP_STROB=ElementIDGRP_STROB;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprStrObjectImpl::get_ElementGRP_STROB(void)
{
return Object->ElementGRP_STROB;
}
//---------------------------------------------------------------
void TDMSprStrObjectImpl::set_ElementGRP_STROB(TFIBSmallIntField * ElementGRP_STROB)
{
Object->ElementGRP_STROB=ElementGRP_STROB;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprStrObjectImpl::get_TableNAME_STROB(void)
{
return Object->TableNAME_STROB;
}
//---------------------------------------------------------------
void TDMSprStrObjectImpl::set_TableNAME_STROB(TFIBWideStringField * TableNAME_STROB)
{
Object->TableNAME_STROB=TableNAME_STROB;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprStrObjectImpl::get_TableCODE_STROB(void)
{
return Object->TableCODE_STROB;
}
//---------------------------------------------------------------
void TDMSprStrObjectImpl::set_TableCODE_STROB(TFIBIntegerField * TableCODE_STROB)
{
Object->TableCODE_STROB=TableCODE_STROB;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprStrObjectImpl::get_TableGID_SSTROB(void)
{
return Object->TableGID_SSTROB;
}
//---------------------------------------------------------------
void TDMSprStrObjectImpl::set_TableGID_SSTROB(TFIBWideStringField * TableGID_SSTROB)
{
Object->TableGID_SSTROB=TableGID_SSTROB;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprStrObjectImpl::get_ElementNAME_STROB(void)
{
return Object->ElementNAME_STROB;
}
//---------------------------------------------------------------
void TDMSprStrObjectImpl::set_ElementNAME_STROB(TFIBWideStringField * ElementNAME_STROB)
{
Object->ElementNAME_STROB=ElementNAME_STROB;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprStrObjectImpl::get_ElementCODE_STROB(void)
{
return Object->ElementCODE_STROB;
}
//---------------------------------------------------------------
void TDMSprStrObjectImpl::set_ElementCODE_STROB(TFIBIntegerField * ElementCODE_STROB)
{
Object->ElementCODE_STROB=ElementCODE_STROB;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprStrObjectImpl::get_ElementGID_SSTROB(void)
{
return Object->ElementGID_SSTROB;
}
//---------------------------------------------------------------
void TDMSprStrObjectImpl::set_ElementGID_SSTROB(TFIBWideStringField * ElementGID_SSTROB)
{
Object->ElementGID_SSTROB=ElementGID_SSTROB;
}
//---------------------------------------------------------------
__int64 TDMSprStrObjectImpl::get_Id(void)
{
return Object->Id;
}
//---------------------------------------------------------------
void TDMSprStrObjectImpl::set_Id(__int64 Id)
{
Object->Id=Id;
}
//---------------------------------------------------------------
void TDMSprStrObjectImpl::OpenTable(void)
{
return Object->OpenTable();
}
//---------------------------------------------------------------
int TDMSprStrObjectImpl::OpenElement(__int64 Id)
{
return Object->OpenElement(Id);
}
//---------------------------------------------------------------
void TDMSprStrObjectImpl::NewElement(__int64 IdGrp)
{
return Object->NewElement(IdGrp);
}
//---------------------------------------------------------------
bool TDMSprStrObjectImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
void TDMSprStrObjectImpl::DeleteElement(__int64 Id)
{
return Object->DeleteElement(Id);
}
//---------------------------------------------------------------
__int64 TDMSprStrObjectImpl::FindPoCodu(int code)
{
return Object->FindPoCodu(code);
}
//---------------------------------------------------------------
