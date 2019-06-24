#include <vcl.h>
#pragma hdrstop


#include "UDMSprProjectImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprProjectImpl::TDMSprProjectImpl()           
{                                            
Object=new TDMSprProject(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprProjectImpl::~TDMSprProjectImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprProjectImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprProjectImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprProject)                        
   {                                                                     
   *ppv=static_cast<IDMSprProject*> (this);                                
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
int TDMSprProjectImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprProjectImpl::kanRelease(void)                                  
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
int  TDMSprProjectImpl::get_CodeError(void)                      
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprProjectImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprProjectImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprProjectImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprProjectImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object)
{
Object->InterfaceMainObject=i_main_object;
Object->InterfaceOwnerObject=i_owner_object;
return Object->Init();
}
//---------------------------------------------------------------
int TDMSprProjectImpl::Done(void)
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//INameModulEdit->Text
TDataSource * TDMSprProjectImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprProjectImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TDMSprProjectImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TDMSprProjectImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprProjectImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprProjectImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprProjectImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprProjectImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprProjectImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprProjectImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprProjectImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprProjectImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprProjectImpl::get_TableID_SPROJECT(void)
{
return Object->TableID_SPROJECT;
}
//---------------------------------------------------------------
void TDMSprProjectImpl::set_TableID_SPROJECT(TFIBBCDField * TableID_SPROJECT)
{
Object->TableID_SPROJECT=TableID_SPROJECT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprProjectImpl::get_TableIDGRP_SPROJECT(void)
{
return Object->TableIDGRP_SPROJECT;
}
//---------------------------------------------------------------
void TDMSprProjectImpl::set_TableIDGRP_SPROJECT(TFIBBCDField * TableIDGRP_SPROJECT)
{
Object->TableIDGRP_SPROJECT=TableIDGRP_SPROJECT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprProjectImpl::get_ElementID_SPROJECT(void)
{
return Object->ElementID_SPROJECT;
}
//---------------------------------------------------------------
void TDMSprProjectImpl::set_ElementID_SPROJECT(TFIBBCDField * ElementID_SPROJECT)
{
Object->ElementID_SPROJECT=ElementID_SPROJECT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprProjectImpl::get_ElementIDGRP_SPROJECT(void)
{
return Object->ElementIDGRP_SPROJECT;
}
//---------------------------------------------------------------
void TDMSprProjectImpl::set_ElementIDGRP_SPROJECT(TFIBBCDField * ElementIDGRP_SPROJECT)
{
Object->ElementIDGRP_SPROJECT=ElementIDGRP_SPROJECT;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprProjectImpl::get_ElementCODE_SPROJECT(void)
{
return Object->ElementCODE_SPROJECT;
}
//---------------------------------------------------------------
void TDMSprProjectImpl::set_ElementCODE_SPROJECT(TFIBIntegerField * ElementCODE_SPROJECT)
{
Object->ElementCODE_SPROJECT=ElementCODE_SPROJECT;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprProjectImpl::get_Code(void)
{
return Object->Code;
}
//---------------------------------------------------------------
void TDMSprProjectImpl::set_Code(TpFIBDataSet * Code)
{
Object->Code=Code;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprProjectImpl::get_CodeMAXCODE(void)
{
return Object->CodeMAXCODE;
}
//---------------------------------------------------------------
void TDMSprProjectImpl::set_CodeMAXCODE(TFIBIntegerField * CodeMAXCODE)
{
Object->CodeMAXCODE=CodeMAXCODE;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprProjectImpl::get_TableCODE_SPROJECT(void)
{
return Object->TableCODE_SPROJECT;
}
//---------------------------------------------------------------
void TDMSprProjectImpl::set_TableCODE_SPROJECT(TFIBIntegerField * TableCODE_SPROJECT)
{
Object->TableCODE_SPROJECT=TableCODE_SPROJECT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprProjectImpl::get_TableNAME_SPROJECT(void)
{
return Object->TableNAME_SPROJECT;
}
//---------------------------------------------------------------
void TDMSprProjectImpl::set_TableNAME_SPROJECT(TFIBWideStringField * TableNAME_SPROJECT)
{
Object->TableNAME_SPROJECT=TableNAME_SPROJECT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprProjectImpl::get_ElementNAME_SPROJECT(void)
{
return Object->ElementNAME_SPROJECT;
}
//---------------------------------------------------------------
void TDMSprProjectImpl::set_ElementNAME_SPROJECT(TFIBWideStringField * ElementNAME_SPROJECT)
{
Object->ElementNAME_SPROJECT=ElementNAME_SPROJECT;
}

//---------------------------------------------------------------
__int64 TDMSprProjectImpl::get_IdGrp(void)
{
return Object->IdGrp;
}
//---------------------------------------------------------------
void TDMSprProjectImpl::set_IdGrp(__int64 IdGrp)
{
Object->IdGrp=IdGrp;
}
//---------------------------------------------------------------
bool TDMSprProjectImpl::get_AllElement(void)
{
return Object->AllElement;
}
//---------------------------------------------------------------
void TDMSprProjectImpl::set_AllElement(bool AllElement)
{
Object->AllElement=AllElement;
}
//---------------------------------------------------------------
__int64 TDMSprProjectImpl::get_IdElement(void)
{
return Object->IdElement;
}
//---------------------------------------------------------------
void TDMSprProjectImpl::set_IdElement(__int64 IdElement)
{
Object->IdElement=IdElement;
}
//---------------------------------------------------------------
AnsiString TDMSprProjectImpl::GetTextQuery(__int64 id_grp, bool all)
{
return Object->GetTextQuery(id_grp, all);
}
//---------------------------------------------------------------
void TDMSprProjectImpl::OpenTable(__int64 id_grp, bool all)
{
return Object->OpenTable(id_grp,  all);
}
//---------------------------------------------------------------
int TDMSprProjectImpl::OpenElement(__int64 id )
{
return Object->OpenElement(id );
}
//---------------------------------------------------------------
bool TDMSprProjectImpl::NewElement(__int64 id_grp)
{
return Object->NewElement(id_grp);
}
//---------------------------------------------------------------
bool TDMSprProjectImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TDMSprProjectImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
void TDMSprProjectImpl::ChancheGrp(__int64 new_id_grp)
{
return Object->ChancheGrp(new_id_grp);
}
//---------------------------------------------------------------
__int64 TDMSprProjectImpl::FindPoCodu(int code)
{
return Object->FindPoCodu(code);
}
//---------------------------------------------------------------
__int64 TDMSprProjectImpl::FindPoName(AnsiString name)
{
return Object->FindPoName(name);
}
//---------------------------------------------------------------
__int64 TDMSprProjectImpl::GetIdGrpProject(__int64 id_project)
{
return Object->GetIdGrpProject(id_project);
}
//---------------------------------------------------------------
int TDMSprProjectImpl::GetCodeProject(void)
{
return Object->GetCodeProject();
}
//---------------------------------------------------------------
bool TDMSprProjectImpl::CheckCode(__int64 id_project, int code)
{
return Object->CheckCode(id_project, code);
}
//---------------------------------------------------------------
