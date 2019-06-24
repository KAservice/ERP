#include <vcl.h>
#pragma hdrstop


#include "UDMSprGrpBVNomImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprGrpBVNomImpl::TDMSprGrpBVNomImpl()           
{                                            
Object=new TDMSprGrpBVNom(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprGrpBVNomImpl::~TDMSprGrpBVNomImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprGrpBVNomImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprGrpBVNomImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprGrpBVNom)                        
   {                                                                     
   *ppv=static_cast<IDMSprGrpBVNom*> (this);                                
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
int TDMSprGrpBVNomImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprGrpBVNomImpl::kanRelease(void)
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
int  TDMSprGrpBVNomImpl::get_CodeError(void)                      
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprGrpBVNomImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprGrpBVNomImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprGrpBVNomImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprGrpBVNomImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object)
{
Object->InterfaceMainObject=i_main_object;
Object->InterfaceOwnerObject=i_owner_object;
return Object->Init();
}
//---------------------------------------------------------------
int TDMSprGrpBVNomImpl::Done(void)
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//INameModulEdit->Text
TDataSource * TDMSprGrpBVNomImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprGrpBVNomImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TDMSprGrpBVNomImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TDMSprGrpBVNomImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprGrpBVNomImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprGrpBVNomImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprGrpBVNomImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprGrpBVNomImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprGrpBVNomImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprGrpBVNomImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprGrpBVNomImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprGrpBVNomImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TIntegerField * TDMSprGrpBVNomImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TDMSprGrpBVNomImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprGrpBVNomImpl::get_TableID_GBVNOM(void)
{
return Object->TableID_GBVNOM;
}
//---------------------------------------------------------------
void TDMSprGrpBVNomImpl::set_TableID_GBVNOM(TFIBBCDField * TableID_GBVNOM)
{
Object->TableID_GBVNOM=TableID_GBVNOM;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprGrpBVNomImpl::get_TableIDGRP_GBVNOM(void)
{
return Object->TableIDGRP_GBVNOM;
}
//---------------------------------------------------------------
void TDMSprGrpBVNomImpl::set_TableIDGRP_GBVNOM(TFIBBCDField * TableIDGRP_GBVNOM)
{
Object->TableIDGRP_GBVNOM=TableIDGRP_GBVNOM;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprGrpBVNomImpl::get_TableIDPOD_GBVNOM(void)
{
return Object->TableIDPOD_GBVNOM;
}
//---------------------------------------------------------------
void TDMSprGrpBVNomImpl::set_TableIDPOD_GBVNOM(TFIBBCDField * TableIDPOD_GBVNOM)
{
Object->TableIDPOD_GBVNOM=TableIDPOD_GBVNOM;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprGrpBVNomImpl::get_ElementID_GBVNOM(void)
{
return Object->ElementID_GBVNOM;
}
//---------------------------------------------------------------
void TDMSprGrpBVNomImpl::set_ElementID_GBVNOM(TFIBBCDField * ElementID_GBVNOM)
{
Object->ElementID_GBVNOM=ElementID_GBVNOM;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprGrpBVNomImpl::get_ElementIDGRP_GBVNOM(void)
{
return Object->ElementIDGRP_GBVNOM;
}
//---------------------------------------------------------------
void TDMSprGrpBVNomImpl::set_ElementIDGRP_GBVNOM(TFIBBCDField * ElementIDGRP_GBVNOM)
{
Object->ElementIDGRP_GBVNOM=ElementIDGRP_GBVNOM;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprGrpBVNomImpl::get_ElementIDPOD_GBVNOM(void)
{
return Object->ElementIDPOD_GBVNOM;
}
//---------------------------------------------------------------
void TDMSprGrpBVNomImpl::set_ElementIDPOD_GBVNOM(TFIBBCDField * ElementIDPOD_GBVNOM)
{
Object->ElementIDPOD_GBVNOM=ElementIDPOD_GBVNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprGrpBVNomImpl::get_TableNAME_GBVNOM(void)
{
return Object->TableNAME_GBVNOM;
}
//---------------------------------------------------------------
void TDMSprGrpBVNomImpl::set_TableNAME_GBVNOM(TFIBWideStringField * TableNAME_GBVNOM)
{
Object->TableNAME_GBVNOM=TableNAME_GBVNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprGrpBVNomImpl::get_TableGID_SGBVNOM(void)
{
return Object->TableGID_SGBVNOM;
}
//---------------------------------------------------------------
void TDMSprGrpBVNomImpl::set_TableGID_SGBVNOM(TFIBWideStringField * TableGID_SGBVNOM)
{
Object->TableGID_SGBVNOM=TableGID_SGBVNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprGrpBVNomImpl::get_ElementNAME_GBVNOM(void)
{
return Object->ElementNAME_GBVNOM;
}
//---------------------------------------------------------------
void TDMSprGrpBVNomImpl::set_ElementNAME_GBVNOM(TFIBWideStringField * ElementNAME_GBVNOM)
{
Object->ElementNAME_GBVNOM=ElementNAME_GBVNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprGrpBVNomImpl::get_ElementGID_SGBVNOM(void)
{
return Object->ElementGID_SGBVNOM;
}
//---------------------------------------------------------------
void TDMSprGrpBVNomImpl::set_ElementGID_SGBVNOM(TFIBWideStringField * ElementGID_SGBVNOM)
{
Object->ElementGID_SGBVNOM=ElementGID_SGBVNOM;
}
//---------------------------------------------------------------
__int64 TDMSprGrpBVNomImpl::get_IdPod(void)
{
return Object->IdPod;
}
//---------------------------------------------------------------
void TDMSprGrpBVNomImpl::set_IdPod(__int64 IdPod)
{
Object->IdPod=IdPod;
}
//---------------------------------------------------------------
void TDMSprGrpBVNomImpl::OpenTable(__int64 Pod)
{
return Object->OpenTable(Pod);
}
//---------------------------------------------------------------
int TDMSprGrpBVNomImpl::OpenElement(__int64 Id)
{
return Object->OpenElement(Id);
}
//---------------------------------------------------------------
void TDMSprGrpBVNomImpl::NewElement(__int64 Pod, __int64 Grp)
{
return Object->NewElement(Pod,Grp);
}
//---------------------------------------------------------------
bool TDMSprGrpBVNomImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
void TDMSprGrpBVNomImpl::DeleteElement(__int64 Id)
{
return Object->DeleteElement(Id);
}
//---------------------------------------------------------------
